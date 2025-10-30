#!/usr/bin/env node

/**
 * Build Snippets Script
 * 
 * This script builds all C code snippets in the snippets/ directory to verify
 * they compile correctly. It supports two build methods:
 * 
 * 1. CMake (preferred): Uses existing cmake-build-debug folders from CLion,
 *    or creates new build/ directories if CMake is available in PATH
 * 2. GCC fallback: If CMake is not available, compiles all .c files in each
 *    snippet directory directly with gcc
 * 
 * Note: The gcc fallback may fail for snippets with multiple .c files that
 * each contain a main() function, as these are meant to be separate examples.
 * Use CMake for accurate builds in such cases.
 * 
 * Usage: npm run check:snippets
 */

import { readdirSync, statSync, existsSync, readFileSync } from 'fs';
import { join, dirname } from 'path';
import { execSync } from 'child_process';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const SNIPPETS_DIR = join(__dirname, '..', 'snippets');
const BUILD_DIR_NAME = 'build';
const CLION_BUILD_DIR = 'cmake-build-debug';

// ANSI color codes
const colors = {
  reset: '\x1b[0m',
  green: '\x1b[32m',
  red: '\x1b[31m',
  yellow: '\x1b[33m',
  blue: '\x1b[34m',
  cyan: '\x1b[36m',
};

function log(message, color = 'reset') {
  console.log(`${colors[color]}${message}${colors.reset}`);
}

function getSnippetDirs() {
  return readdirSync(SNIPPETS_DIR)
    .filter(name => {
      const fullPath = join(SNIPPETS_DIR, name);
      return statSync(fullPath).isDirectory() && 
             name.startsWith('example') && 
             /^example\d+$/.test(name);
    })
    .sort((a, b) => {
      const numA = parseInt(a.replace('example', ''));
      const numB = parseInt(b.replace('example', ''));
      return numA - numB;
    });
}

function checkCMakeAvailable() {
  try {
    execSync('cmake --version', { stdio: 'pipe' });
    return true;
  } catch {
    return false;
  }
}

function getSourceFiles(snippetPath) {
  return readdirSync(snippetPath)
    .filter(file => file.endsWith('.c') && !file.startsWith('.'));
}

function buildWithGCC(snippetDir, snippetPath) {
  const sourceFiles = getSourceFiles(snippetPath);
  
  if (sourceFiles.length === 0) {
    return { status: 'skipped', reason: 'no .c files found' };
  }

  try {
    log(`  🔨 Building ${snippetDir} with gcc...`, 'cyan');
    
    const buildPath = join(snippetPath, BUILD_DIR_NAME);
    const outputBinary = join(buildPath, snippetDir);
    const sources = sourceFiles.map(f => join(snippetPath, f)).join(' ');
    
    // Create build directory
    execSync(`mkdir -p ${BUILD_DIR_NAME}`, { cwd: snippetPath, stdio: 'pipe' });
    
    // Compile with gcc
    execSync(`gcc -std=c11 -Wall -Wextra ${sources} -o ${outputBinary} -lm`, {
      stdio: 'pipe',
    });

    log(`  ✓ ${snippetDir} built successfully with gcc`, 'green');
    return { status: 'success', method: 'gcc' };
    
  } catch (error) {
    log(`  ✗ ${snippetDir} gcc build failed`, 'red');
    return { status: 'failed', error: error.message, method: 'gcc' };
  }
}

function buildWithCMake(snippetDir, snippetPath, useCLionDir = false) {
  const buildDirName = useCLionDir ? CLION_BUILD_DIR : BUILD_DIR_NAME;
  const buildPath = join(snippetPath, buildDirName);

  try {
    if (!useCLionDir) {
      log(`  ⚙ Configuring ${snippetDir} with cmake...`, 'cyan');
      
      // Create build directory and run cmake
      execSync(
        `mkdir -p ${buildDirName} && cd ${buildDirName} && cmake .. -DCMAKE_BUILD_TYPE=Release`,
        {
          cwd: snippetPath,
          stdio: 'pipe',
        }
      );
    } else {
      log(`  ⚙ Reconfiguring CLion build for ${snippetDir}...`, 'cyan');
      
      // Clean and reconfigure CLion build (remove CMakeCache to avoid path issues)
      execSync(
        `cd ${buildDirName} && rm -f CMakeCache.txt && cmake .. -DCMAKE_BUILD_TYPE=Release`,
        {
          cwd: snippetPath,
          stdio: 'pipe',
        }
      );
    }

    log(`  🔨 Building ${snippetDir} with cmake...`, 'cyan');
    
    // Build the project
    execSync(`cmake --build ${buildDirName} --config Release`, {
      cwd: snippetPath,
      stdio: 'pipe',
    });

    log(`  ✓ ${snippetDir} built successfully with cmake`, 'green');
    return { status: 'success', method: 'cmake' };
    
  } catch (error) {
    log(`  ✗ ${snippetDir} cmake build failed`, 'red');
    return { status: 'failed', error: error.message, method: 'cmake' };
  }
}

function buildSnippet(snippetDir, cmakeAvailable) {
  const snippetPath = join(SNIPPETS_DIR, snippetDir);
  const cmakeListsPath = join(snippetPath, 'CMakeLists.txt');
  const clionBuildPath = join(snippetPath, CLION_BUILD_DIR);
  
  if (!existsSync(cmakeListsPath)) {
    log(`  ⊘ Skipping ${snippetDir} - no CMakeLists.txt found`, 'yellow');
    return { status: 'skipped', reason: 'no CMakeLists.txt' };
  }

  // Try CMake if available
  if (cmakeAvailable) {
    // Use existing CLion build directory if it exists
    if (existsSync(clionBuildPath)) {
      return buildWithCMake(snippetDir, snippetPath, true);
    }
    return buildWithCMake(snippetDir, snippetPath, false);
  }
  
  // Fallback to gcc
  log(`  ⚠ CMake not available, trying gcc fallback for ${snippetDir}`, 'yellow');
  return buildWithGCC(snippetDir, snippetPath);
}

function main() {
  log('\n🔍 Checking C snippets...\n', 'blue');

  const cmakeAvailable = checkCMakeAvailable();
  
  if (cmakeAvailable) {
    log('✓ CMake is available\n', 'green');
  } else {
    log('⚠ CMake not found in PATH, will use gcc fallback\n', 'yellow');
  }

  const snippetDirs = getSnippetDirs();
  
  if (snippetDirs.length === 0) {
    log('No snippet directories found!', 'yellow');
    process.exit(1);
  }

  log(`Found ${snippetDirs.length} snippet projects to build\n`, 'cyan');

  const results = {
    success: [],
    failed: [],
    skipped: [],
  };

  for (const dir of snippetDirs) {
    const result = buildSnippet(dir, cmakeAvailable);
    
    if (result.status === 'success') {
      results.success.push({ dir, method: result.method });
    } else if (result.status === 'failed') {
      results.failed.push({ dir, error: result.error, method: result.method });
    } else if (result.status === 'skipped') {
      results.skipped.push({ dir, reason: result.reason });
    }
  }

  // Print summary
  log('\n' + '='.repeat(60), 'blue');
  log('BUILD SUMMARY', 'blue');
  log('='.repeat(60), 'blue');
  
  log(`\n✓ Successful builds: ${results.success.length}`, 'green');
  if (results.success.length > 0) {
    results.success.forEach(({ dir, method }) => 
      log(`  - ${dir} (${method})`, 'green')
    );
  }

  if (results.skipped.length > 0) {
    log(`\n⊘ Skipped: ${results.skipped.length}`, 'yellow');
    results.skipped.forEach(({ dir, reason }) => 
      log(`  - ${dir} (${reason})`, 'yellow')
    );
  }

  if (results.failed.length > 0) {
    log(`\n✗ Failed builds: ${results.failed.length}`, 'red');
    results.failed.forEach(({ dir, method }) => 
      log(`  - ${dir} (${method})`, 'red')
    );
  }

  log('\n' + '='.repeat(60) + '\n', 'blue');

  // Exit with error code if any builds failed
  if (results.failed.length > 0) {
    log('⚠ Some snippets failed to build!', 'red');
    process.exit(1);
  } else {
    log('🎉 All snippets built successfully!', 'green');
    process.exit(0);
  }
}

main();
