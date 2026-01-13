# Project Overview
This project contains the slides for the course "Elementi di programmazione e gestione dati" taught by Ing. Giancarlo Degani. The slides are created using Slidev, a framework for building presentation slides with Markdown and Vue.js.

# writing style and conventions
All the slides are written in Italian.
All the code examples and snippets in the slides are written in the C programming language with the purpose of teaching programming concepts and data management techniques. All the example and snippets must use english comments and identifiers to ensure clarity and consistency in coding practices.
Preferably use headers in the slides instead of enphasizing text with bold or italics.
Avoid using embedded HTML in the slides, prefer pure Markdown and Vue components when needed.
When adding a new example or snippet, ensure it does not require topic not yet covered in the course.

# Copilot instructions for this Slidev + C course repository

Purpose
- This file provides human-facing guidance about how GitHub Copilot is used
	in this repository. The machine-readable configuration is `.github/copilot.yml`.

Project context (Slidev specifics)
- Slides are authored with Slidev (sli.dev). Key entry files and locations:
	- primary slide entry: `slides.md`
	- modular slide pages: `pages/*.md` (imported into `slides.md`)
	- reusable UI: `components/*.vue` and `layouts/*.vue`
	- static assets: `public/`
	- examples/snippets: `snippets/*/` (one folder per example)
	- the examples should never be inlined in the slides; they are always
		 in separate files under `snippets/` and referenced from the slides in order to have a working code example that can be compiled and tested separately.
	- Slidev config: `slidev.config.js` / `slidev.config.ts` (or project `package.json` scripts)

Why this matters for Copilot
- Slidev combines Markdown and Vue. Copilot should prefer Markdown-focused
	suggestions when editing slides, and language-appropriate suggestions when
	editing snippets (C) or Vue components (Vue/JS).

Recommendations for snippet authors
- Use explicit code fences with a language tag for all code blocks to give
	Copilot the right context. For C code use:

	```c
	/* One-line header describing the objective
		 Expected function: int func(...)
		 Learning objective: explain what is being taught */
	int func(int a, int b) {
		// implementation
	}
	```

- Add a short README or header comment inside each `snippets/exampleNN/`
	folder describing the learning objective and expected entry point(s).

Header comment template (copy into `main.c` or the top C file)
/*
 * Example: Reverse a null-terminated string in-place
 * Expected function: void reverse_str(char *s);
 * Learning objective: pointer manipulation, loop invariants, edge cases
 */

How to test Copilot suggestion changes
1. Ensure you are signed into GitHub Copilot in your editor (VS Code).
2. Open a representative file:
	 - slide content: `slides.md` or a file in `pages/` to test Markdown suggestions.
	 - snippet code: `snippets/exampleNN/main.c` to test C suggestions.
3. For snippet tests: add the header comment template above and type the
	 expected function signature; trigger completion and accept the top suggestion.
4. When changing `.github/copilot.yml`, push the change to a branch and include
	 a short test plan in the PR describing which files you tested and the
	 observed suggestion differences (screenshot or short note is fine).

Recommended prompt examples for authors
- "Write a short, well-commented C function that reverses a string in-place.
	Keep it under 40 lines and add a short comment explaining time/space complexity."
- "Refactor the following C function to add boundary checks and explain the
	changes in comments above the function."

Suggested file globs for `.github/copilot.yml`
- include:
	- "**/*.md"
	- "slides.md"
	- "pages/**"
	- "components/**/*.vue"
	- "layouts/**/*.vue"
	- "snippets/**/**/*.c"
	- "slidev.config.*"
	- "package.json"
- exclude (build/IDE noise):
	- "**/cmake-build-debug/**"
	- "**/node_modules/**"
	- "**/.vscode/**"
	- "**/.git/**"
	- "**/*.png"
	- "**/*.jpg"

PR checklist for changes to Copilot config
- Edit `.github/copilot.yml` on a branch and open a PR.
- In the PR description include:
	- Motivation for the change (why adjust weights/rules).
	- Minimal test plan (which file(s) to open and what to type).
	- Expected effect on suggestions and a brief before/after note or screenshot.

Tooling and editor tips
- Recommend using the Slidev VS Code extension and the Slidev Prettier plugin
	for consistent formatting. Slidev uses Shiki for syntax highlighting; explicit
	language fences help both highlighting and suggestion context.

Licensing and safety
- If Copilot suggests long verbatim blocks that resemble third-party code,
	verify licenses and add attribution where required. Prefer short, original
	instructional examples.

Consolidation note
- We have `.github/COPILOT_README.md` and this `copilot-instructions.md`.
	Consider keeping a single, canonical human-facing file (or clearly
	cross-reference them) to avoid duplicated or inconsistent guidance.

Where things live (quick reference)
- Slides: `slides.md`, `pages/`, `components/`, `layouts/`
- Snippets/examples: `snippets/*/` (one folder per example)
- Machine config: `.github/copilot.yml`
- Human guidance: `.github/COPILOT_README.md` and this file

-- end
