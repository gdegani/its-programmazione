#!/usr/bin/env node

/**
 * Check Language Script
 * 
 * This script scans all C source files in the snippets/ directory to identify
 * Italian words in:
 * - Variable/function names (identifiers)
 * - Comments
 * - String literals (printf messages, etc.)
 * 
 * According to project guidelines, all code should use English identifiers
 * and comments only. Italian is acceptable only in slide content (markdown).
 * 
 * Usage: node scripts/check-language.js
 */

import { readdirSync, statSync, readFileSync } from 'fs';
import { join, dirname } from 'path';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const SNIPPETS_DIR = join(__dirname, '..', 'snippets');
const PAGES_DIR = join(__dirname, '..', 'pages');

// Common Italian words used in code
const ITALIAN_PATTERNS = [
  // Variables/concepts
  'somma', 'numero', 'numeri', 'valore', 'valori', 'risultato', 'risultati',
  'contatore', 'elemento', 'elementi', 'utente', 'utenti',
  'nome', 'cognome', 'eta', 'età', 'anni', 'anno',
  'altezza', 'larghezza',
  'testo', 'stringa', 'carattere', 'caratteri',
  'totale', 'prezzo', 'costo', 'sconto', 'imponibile', 'iva',
  'carrello', 'oggetti', 'oggetto', 'quantita', 'quantità',
  'media', 'dispari', 'pari',
  'riga', 'righe', 'colonna', 'colonne',
  'matrice', 'vettore', 'vettori',
  'lunghezza', 'posizione', 'indice',
  'inizializzazione', 'incremento', 'decremento',
  'condizione', 'controllo',
  'maggiore', 'minore', 'uguale',
  'primo', 'secondo', 'terzo', 'ultimo',
  
  // Common Italian words in comments/strings
  'inserisci', 'inserire', 'dammi', 'scrivi', 'leggi',
  'stampa', 'visualizza', 'mostra',
  'calcola', 'calcolo',
  'richiede', 'richiedi',
  'ordina', 'ordinato', 'ordinare',
  'errore', 'sbagliato',
  'vero', 'falso',
  'inizio', 'fine',
  'palindroma', 'palindromo',
  'prelevato', 'prelevare',
  'lunga', 'lungo',
  'voto', 'voti', 'scegli', 'opzione', 'opzioni', 'esci', 'saluta',
  'conteggio', 'tentativi', 'tentativo', 'pagina', 'riepilogo',
];

// ANSI color codes
const colors = {
  reset: '\x1b[0m',
  green: '\x1b[32m',
  red: '\x1b[31m',
  yellow: '\x1b[33m',
  blue: '\x1b[34m',
  cyan: '\x1b[36m',
  gray: '\x1b[90m',
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

function getCFiles(dirPath) {
  try {
    return readdirSync(dirPath)
      .filter(file => file.endsWith('.c') || file.endsWith('.h'))
      .filter(file => !file.startsWith('.'));
  } catch {
    return [];
  }
}

function checkFileForItalian(filePath) {
  const content = readFileSync(filePath, 'utf-8');
  const lines = content.split('\n');
  const issues = [];

  lines.forEach((line, index) => {
    const lineNum = index + 1;
    const lowerLine = line.toLowerCase();

    ITALIAN_PATTERNS.forEach(pattern => {
      // Create word boundary regex
      const regex = new RegExp(`\\b${pattern}\\b`, 'gi');
      
      if (regex.test(lowerLine)) {
        const match = line.match(regex);
        if (match) {
          issues.push({
            line: lineNum,
            word: match[0],
            context: line.trim(),
          });
        }
      }
    });
  });

  return issues;
}

// Extract the lines of the ```c blocks of a slide file, as 'file:line' sources
function checkSlideFile(filePath) {
  const lines = readFileSync(filePath, 'utf-8').split('\n');
  const issues = [];
  let inC = false;
  let inOther = false;

  lines.forEach((line, index) => {
    const fence = line.match(/^\s*```(\w*)/);
    if (fence) {
      if (inC || inOther) {
        inC = inOther = false;
      } else if (fence[1] === 'c') {
        inC = true;
      } else {
        inOther = true;
      }
      return;
    }
    if (!inC) return;

    for (const pattern of ITALIAN_PATTERNS) {
      const match = line.match(new RegExp(`\\b${pattern}\\b`, 'i'));
      if (match) {
        issues.push({ line: index + 1, word: match[0], context: line.trim() });
        break;
      }
    }
  });

  return issues;
}

function main() {
  log('\n🔍 Checking C source files and slide code blocks for Italian language...\n', 'blue');

  const snippetDirs = getSnippetDirs();
  const results = {};
  let totalIssues = 0;

  for (const dir of snippetDirs) {
    const dirPath = join(SNIPPETS_DIR, dir);
    const cFiles = getCFiles(dirPath);

    for (const file of cFiles) {
      const filePath = join(dirPath, file);
      const issues = checkFileForItalian(filePath);

      if (issues.length > 0) {
        const key = `${dir}/${file}`;
        results[key] = issues;
        totalIssues += issues.length;
      }
    }
  }

  // Code blocks inside the slides
  for (const file of readdirSync(PAGES_DIR).filter(f => f.endsWith('.md')).sort()) {
    const issues = checkSlideFile(join(PAGES_DIR, file));
    if (issues.length > 0) {
      results[`pages/${file}`] = issues;
      totalIssues += issues.length;
    }
  }

  // Print results
  if (totalIssues === 0) {
    log('✅ No Italian words found in source files!', 'green');
    log('\nAll code follows the English-only guideline.\n', 'green');
    process.exit(0);
  }

  log(`Found Italian words in ${Object.keys(results).length} files:\n`, 'yellow');

  Object.entries(results).forEach(([file, issues]) => {
    log(`\n📄 ${file}`, 'cyan');
    
    // Group by line number to avoid duplicates
    const uniqueLines = new Map();
    issues.forEach(issue => {
      if (!uniqueLines.has(issue.line)) {
        uniqueLines.set(issue.line, issue);
      }
    });

    uniqueLines.forEach(issue => {
      log(`  Line ${issue.line}: ${colors.yellow}${issue.word}${colors.reset}`, 'gray');
      log(`    ${issue.context}`, 'gray');
    });
  });

  log('\n' + '='.repeat(60), 'blue');
  log(`\nTotal: ${totalIssues} Italian words found in ${Object.keys(results).length} files`, 'yellow');
  log('\n⚠️  Recommendation: Translate identifiers, comments, and string literals to English', 'yellow');
  log('   (Exception: Output messages shown to Italian-speaking users can remain in Italian)\n', 'gray');

  process.exit(1);
}

main();
