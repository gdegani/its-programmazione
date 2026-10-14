# Project overview

Slides and examples for the course "Elementi di programmazione e gestione dati" (30 hours, 7 lessons of 4 hours and 1 of 2 hours), taught by
Ing. Giancarlo Degani at ITS Meccatronico Veneto. The slides are built with Slidev. The course has a mechatronics flavour: examples use
sensor readings, machine states and production data.

The AI is not covered here: it belongs to the follow-up module, in the `its-programmazione-ai` repository.

# Repository layout

* `slides.md`: entry point (configuration, table of contents and lesson list)
* `pages/lezione_NN.md`: one file per lesson (01 to 08)
* `snippets/exampleNN/`: examples (`main.c` and `CMakeLists.txt`)
* `schedule.md`: course schedule and assessment
* `scripts/`: `build-snippets.js` (compile all examples), `check-language.js` (English identifiers and comments), `release.sh` (archive
  an edition), `set-slide-level.mjs` (table of contents levels), `sync-agents.mjs` (shared AI assistant configuration)
* `public/`: images, `layouts/`: custom layouts, `style.css`: global styles
* `AGENTS.md`: instructions for AI assistants (this file); `agents/common.md`: source of the common section below, shared with
  `its-programmazione-ai`; `.agents/skills/`: project skills

Useful commands: `npm run dev`, `npm run build`, `npm run check:snippets`, `npm run check:language`, `npm run check:agents`.

# Course-specific rules

* The final assessment is a multiple-choice test, so exercises and examples must be solvable by reading and running code, without external
  libraries.
* Automated tests, when shown, use `assert` and CTest only.

<!-- BEGIN common: generated from its-programmazione/agents/common.md, edit the source and run npm run sync:agents -->

# Common conventions

This section is shared by `its-programmazione` and `its-programmazione-ai`. The source is `its-programmazione/agents/common.md`: edit it
there, then run `npm run sync:agents` in both repositories.

## Language

* Slide text and diagrams (Mermaid and similar) are in Italian.
* All code is in English, wherever it appears: inline in slides and in `snippets/`. Code is C. Identifiers, comments and output strings
  are in English, with no Italian words in the code.

## Slides

* Slides are Slidev (Markdown + Vue). Prefer headers over bold or italics for emphasis.
* Avoid embedded HTML: use pure Markdown and Slidev/Vue components.
* Keep slides concise: few bullets, short lines. Every slide must be fully visible, with nothing overflowing or overlapping. Split long
  code over several slides, or use a two-column layout (in two columns keep code lines under about 55 characters).
* Use Mermaid for diagrams. Check that each diagram fits the slide and lower its `scale` if it does not. Diagrams in a two-column layout
  are centered by `style.css`.
* Images taken from other sources carry a short citation (for example `source: wikipedia.org`).
* Do not suggest external interactive tools (Miro and similar): use what Slidev provides.

## Lesson structure and table of contents

* `slides.md` lists the lessons with `src:`; slide 2 is the table of contents, `<Toc maxDepth="1" listStyle="none" />`, with
  `hideInToc: true`. Do not use `layout: table-of-contents`: it adds a second, unfiltered list.
* Each lesson file starts with a `layout: cover` slide whose heading is the lesson title shown in the table of contents. Every other slide
  of the lesson has `level: 2` in its frontmatter: run `node scripts/set-slide-level.mjs <file> --write` after adding slides.
* In a slide's frontmatter, leave a blank line before the closing `---`, otherwise markdownlint reads the last key as a heading.
* Leave a blank line between HTML lines (such as `<br>`) and a following Mermaid or `$$` block, otherwise the block is shown as plain text.

## Examples

* Examples live in `snippets/*/`, one folder per example, each a standalone CMake project that compiles on its own. Slides include them
  with `<<< @/snippets/...`, using `// #region name` to show only a part. Inline code in slides is limited to tiny fragments.
* One example illustrates one concept, and uses only topics already covered in the course.

## Course setup

* All the exercises are done in class, in pairs (pair programming), on the classroom laptops with CLion. There is no homework.
* npm is the only package manager.

## Workflow

* `master` is protected and publishes the slides on GitHub Pages: work on a branch and open a pull request.
* When the user says "deploy", push the branch, open a pull request and merge it into `master`. Never push or merge otherwise.
* The revision plan for both courses is `../PIANO_REVISIONE_v2.md`, in the workspace folder that contains the two repositories: read it
  before working on course content and update its checkboxes and decisions when a phase is done.
* AI assistant configuration: `AGENTS.md` is the only source of instructions; `CLAUDE.md` and `.github/copilot-instructions.md` only
  point to it. Project skills live in `.agents/skills/` (`.claude/skills` links there).

## Before finishing a change

* Run markdownlint (configuration in `.markdownlint.json`, identical in both repositories), a full `npm run build` and
  `npm run check:agents`. In `its-programmazione` also run `npm run check:snippets` and `npm run check:language`.

<!-- END common -->
