# Elementi di programmazione e gestione dati in linguaggio "C"

Questo repository contiene le slide e gli esempi usati per il corso di "Elementi di programmazione e gestione dati" presso l'[ITS Meccatronico Veneto](https://www.itsmeccatronico.it).

Le slide sono realizzate con il framework [Slidev](https://sli.dev).

## Indice

- [Struttura del repository](#struttura-del-repository)
- [Sviluppo locale](#sviluppo-locale)
  - [Requisiti](#requisiti)
  - [Comandi](#comandi)
- [Edizioni del corso](#edizioni-del-corso)
  - [Modello di versionamento](#modello-di-versionamento)
  - [Edizioni archiviate](#edizioni-archiviate)
- [Procedura di release](#procedura-di-release)
  - [Inizio di una nuova edizione](#inizio-di-una-nuova-edizione)
  - [Fine dell'edizione: archiviazione](#fine-delledizione-archiviazione)
  - [Cosa fa lo script](#cosa-fa-lo-script)
  - [Correggere un'edizione già archiviata](#correggere-unedizione-già-archiviata)
  - [Risoluzione dei problemi](#risoluzione-dei-problemi)
- [Licenza](#licenza)

## Struttura del repository

| Percorso | Contenuto |
| --- | --- |
| [`slides.md`](slides.md) | Punto di ingresso delle slide: configurazione e inclusione delle sezioni |
| [`pages/`](pages/) | Sezioni del corso (`slides_N.md`) |
| [`snippets/`](snippets/) | Esempi in C, un progetto CMake per cartella (`exampleNN/`) |
| [`layouts/`](layouts/) | Layout Vue personalizzati per Slidev |
| [`public/`](public/) | Immagini usate nelle slide |
| [`scripts/`](scripts/) | Script di supporto: verifica degli snippet, controllo della lingua, release |
| [`schedule.md`](schedule.md) | Programma del corso |

Gli esempi non sono mai copiati nelle slide: stanno in `snippets/` e vengono inclusi da lì, così ognuno si può compilare e provare da solo.

## Sviluppo locale

### Requisiti

- Node.js (versione LTS) con npm, l'unico gestore di pacchetti usato dal progetto
- Per l'export in PDF: il browser Chromium di Playwright. `npm install` lo scarica in automatico, perché lo script di installazione di `playwright-chromium` è autorizzato in `allowScripts` di [`package.json`](package.json). Se manca, si installa a mano:

  ```bash
  npx playwright install chromium
  ```

- Per la release: [GitHub CLI](https://cli.github.com) autenticata (`gh auth login`)

### Comandi

```bash
npm install                # install dependencies
npm run dev                # slides at http://localhost:3030
npm run build              # static site in dist/
npm run export             # PDF export (slides-export.pdf)
npm run check:snippets     # compile all C examples
npm run check:language     # check English identifiers/comments in examples
```

Ogni push su `master` pubblica le slide su GitHub Pages ([`deploy.yml`](.github/workflows/deploy.yml)).

## Edizioni del corso

### Modello di versionamento

- **`master` contiene l'edizione in corso.** Le lezioni si fanno da qui e GitHub Pages mostra sempre questa versione.
- **Ogni edizione conclusa viene archiviata con un tag** `ed-AAAA-AA` (anno accademico, es. `ed-2025-26`). Il tag è annotato e firmato, e non cambia più: è la fotografia esatta del materiale usato in aula.
- **Ogni tag ha una [GitHub Release](https://github.com/gdegani/its-programmazione/releases)** con il PDF delle slide allegato. GitHub aggiunge in automatico gli archivi dei sorgenti (slide ed esempi) a quel tag.
- **Nessun branch per le edizioni passate.** Se serve correggerne una, il branch si crea dal tag solo in quel momento (vedi [Correggere un'edizione già archiviata](#correggere-unedizione-già-archiviata)).

### Edizioni archiviate

| Tag | Edizione | Release |
| --- | --- | --- |
| `ed-2024-25` | 2024/25 | — (precedente all'introduzione delle release) |
| `ed-2025-26` | 2025/26 | — (precedente all'introduzione delle release) |

Per consultare un'edizione passata in locale:

```bash
git switch --detach ed-2025-26   # inspect the archived edition
git switch master                # back to the current edition
```

## Procedura di release

### Inizio di una nuova edizione

All'avvio di un nuovo anno accademico, su `master`:

1. Aggiornare `coverDate` in [`slides.md`](slides.md) (es. `coverDate: "2026-2027"`). Lo script di release lo controlla.
2. Aggiornare durata e modalità di verifica nella slide "Il corso" ([`pages/slides_1.md`](pages/slides_1.md)) e in [`schedule.md`](schedule.md).

### Fine dell'edizione: archiviazione

Quando il corso è terminato e tutte le modifiche sono su `master` (committate e pubblicate):

1. **Prova a vuoto.** Esegue i controlli, esporta il PDF e genera le note, ma non crea né tag né release:

   ```bash
   npm run release -- 2026-27 --dry-run
   ```

2. **Controlla il risultato** in `release/` (cartella ignorata da git):
   - `its-programmazione-ed-2026-27.pdf`: le slide esportate;
   - `notes-ed-2026-27.md`: una bozza delle note, generata dai messaggi di commit dall'edizione precedente. Conviene modificarla e riassumere le novità principali per chi la leggerà.

3. **Pubblica la release**, usando le note modificate:

   ```bash
   npm run release -- 2026-27 --notes-file release/notes-ed-2026-27.md
   ```

   Senza `--notes-file`, lo script rigenera la bozza e la usa così com'è.

Al termine lo script stampa l'indirizzo della release.

### Cosa fa lo script

[`scripts/release.sh`](scripts/release.sh) esegue in ordine i passi seguenti e si ferma al primo errore:

1. **Controlli preliminari**:
   - formato e coerenza dell'edizione (`2026-27`, non `2026-28`);
   - presenza di `git`, `gh`, `npm` e delle dipendenze, e autenticazione di `gh`;
   - siamo su `master`, senza modifiche non committate ai file tracciati, allineati con `origin/master`;
   - il tag `ed-AAAA-AA` non esiste né in locale né su GitHub;
   - `coverDate` in `slides.md` corrisponde all'edizione.
2. **Export** delle slide in `release/its-programmazione-ed-AAAA-AA.pdf`.
3. **Note di rilascio**: generate dai commit dall'ultimo tag `ed-*`, escludendo aggiornamenti di dipendenze, merge e pulizie. In alternativa usa quelle passate con `--notes-file`.
4. **Tag** annotato `ed-AAAA-AA` sul commit corrente e push su GitHub. Il tag è firmato se nella configurazione di git è attivo `tag.gpgSign`.
5. **GitHub Release** con titolo "Edizione AAAA/AA", le note e il PDF allegato.

Con `--dry-run` lo script si ferma dopo il passo 3.

### Correggere un'edizione già archiviata

Di norma non serve. Se capita (per esempio un errore da correggere per un appello di recupero):

```bash
git switch -c fix-2025-26 ed-2025-26     # branch from the archived edition
# ... fix, commit ...
git tag -a ed-2025-26.1 -m "Edizione 2025/26, revisione 1"
git push origin ed-2025-26.1
gh release create ed-2025-26.1 slides-export.pdf --verify-tag --title "Edizione 2025/26 (rev. 1)"
```

Se la correzione vale anche per l'edizione in corso, va riportata su `master` con `git cherry-pick`. Poi il branch si può cancellare: il tag basta.

### Risoluzione dei problemi

| Errore | Soluzione |
| --- | --- |
| `export failed` / `Executable doesn't exist` | `npx playwright install chromium` |
| `master is not in sync with origin/master` | `git push` o `git pull` |
| `uncommitted changes in tracked files` | Committare o mettere da parte (`git stash`) le modifiche |
| `coverDate in slides.md does not match` | Aggiornare `coverDate` e committare |
| `release creation failed; the tag is already pushed` | Il tag esiste già su GitHub: rilanciare solo il comando `gh release create` stampato dallo script |

## Licenza

Slide ed esempi sono distribuiti con licenza [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)](LICENSE).
