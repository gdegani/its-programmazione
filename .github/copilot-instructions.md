# Project overview

Slides and examples for the course "Elementi di programmazione e gestione dati" (30 hours, 7 lessons of 4 hours and 1 of 2 hours), taught by
Ing. Giancarlo Degani at ITS Meccatronico Veneto. The slides are built with Slidev. The course has a mechatronics flavour: examples use
sensor readings, machine states and production data.

The AI is not covered here: it belongs to the follow-up module, in the `its-programmazione-ai` repository.

# Repository layout

* `slides.md`: entry point (configuration and lesson list)
* `pages/lezione_NN.md`: one file per lesson (01 to 08)
* `snippets/exampleNN/`: examples (`main.c` and `CMakeLists.txt`)
* `schedule.md`: course schedule and assessment
* `scripts/`: `build-snippets.js` (compile all examples), `check-language.js` (English identifiers and comments), `release.sh` (archive an edition)
* `public/`: images, `layouts/`: custom layouts

Useful commands: `npm run dev`, `npm run build`, `npm run check:snippets`, `npm run check:language`.

# Course-specific rules

* The final assessment is a multiple-choice test, so exercises and examples must be solvable by reading and running code, without external libraries.
* Automated tests, when shown, use `assert` and CTest only.

# Common conventions

This section is identical in `its-programmazione` and `its-programmazione-ai`: keep the two copies aligned.

## Language

* Slide text is in Italian.
* Code is C. Identifiers, comments and output strings in the examples are in English, with no Italian words in the code.

## Slides

* Slides are Slidev (Markdown + Vue). Prefer headers over bold or italics for emphasis.
* Avoid embedded HTML: use pure Markdown and Slidev/Vue components.
* Keep slides concise: few bullets, short lines. Every slide must be fully visible, with nothing overflowing or overlapping. Split long code over several slides, or use a two-column layout (in two columns keep code lines under about 55 characters).
* Use Mermaid for diagrams.
* Do not suggest external interactive tools (Miro and similar): use what Slidev provides.

## Examples

* Examples live in `snippets/*/`, one folder per example, each a standalone CMake project that compiles on its own. Slides include them with `<<< @/snippets/...`, using `// #region name` to show only a part. Inline code in slides is limited to tiny fragments.
* One example illustrates one concept, and uses only topics already covered in the course.

## Course setup

* All the exercises are done in class, in pairs (pair programming), on the classroom laptops with CLion. There is no homework.
* npm is the only package manager.

## Before finishing a change

* Run markdownlint (configuration in `.markdownlint.json`, identical in both repositories) and a full `npm run build`.
