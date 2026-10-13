# Configurare Windows per il corso di C con VS Code

Guida per preparare da zero un portatile Windows 10/11 (64 bit) per il corso: compilatore C, CMake, debugger e VS Code.

> **Stato (2026-10-13):** sospesa. Il corso resta su CLion; questa guida serve se si riconsidera VS Code. Prove fatte su una VM ARM64: il debug con `gdb` si blocca (limite dell'emulazione x64) e la rete con Cato impedisce `pacman`; da riprovare su una macchina x64.
>
> Bozza da provare su una macchina virtuale. I comandi seguono la documentazione ufficiale di MSYS2 e di VS Code ma non sono ancora stati verificati su Windows. Gli esiti della prova vanno annotati nella tabella in fondo.

## Che cosa si installa

| Componente | A che cosa serve | Come |
| --- | --- | --- |
| Visual Studio Code | Editor | `winget` |
| Git | Scaricare gli esempi | `winget` |
| MSYS2 | Fornisce la toolchain MinGW-w64 | `winget` |
| `gcc`, `gdb`, `cmake`, `ninja` | Compilatore, debugger, sistema di build | `pacman` (dentro MSYS2) |
| Estensioni C/C++ e CMake Tools | Supporto al linguaggio, al debug e a CMake in VS Code | `code --install-extension` |

Si usa la toolchain **UCRT64** di MSYS2: è la variante moderna, con il runtime C universale di Windows e un buon supporto per UTF-8.

## Requisiti

- Windows 10 (21H2 o successivo) o Windows 11, a 64 bit.
- Diritti di amministratore per l'installazione.
- Connessione a Internet (circa 1,5 GB da scaricare).
- `winget` disponibile: è incluso in Windows 11 e nelle versioni recenti di Windows 10. Si controlla con `winget --version` in PowerShell. Se manca, installare "App Installer" dal Microsoft Store.

## 1. Installare i programmi

Aprire **PowerShell** (anche non amministratore: `winget` chiede i permessi quando servono) ed eseguire:

```powershell
winget install --id Microsoft.VisualStudioCode -e
winget install --id Git.Git -e
winget install --id MSYS2.MSYS2 -e
```

Chiudere e riaprire PowerShell al termine.

## 2. Installare la toolchain C in MSYS2

Dal menu Start aprire **MSYS2 UCRT64** (non "MSYS2 MSYS" né "MINGW64"). Eseguire:

```bash
pacman -Syu
```

Se chiede di chiudere la finestra, chiuderla, riaprire **MSYS2 UCRT64** e rilanciare `pacman -Syu`. Poi:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-toolchain \
                   mingw-w64-ucrt-x86_64-cmake \
                   mingw-w64-ucrt-x86_64-ninja
```

Confermare con invio quando chiede di installare tutti i pacchetti del gruppo `toolchain`. Il gruppo include `gcc` e `gdb`.

## 3. Aggiungere la toolchain al PATH di Windows

Perché VS Code e PowerShell trovino `gcc`, `gdb`, `cmake` e `ninja`, aggiungere `C:\msys64\ucrt64\bin` al PATH dell'utente. Da PowerShell:

```powershell
$bin = "C:\msys64\ucrt64\bin"
$path = [Environment]::GetEnvironmentVariable("Path", "User")
if ($path -notlike "*$bin*") {
    [Environment]::SetEnvironmentVariable("Path", "$path;$bin", "User")
}
```

Chiudere **tutte** le finestre di PowerShell e di VS Code e riaprirle: il PATH viene letto solo all'avvio.

Verifica (in una nuova PowerShell):

```powershell
gcc --version
gdb --version
cmake --version
ninja --version
```

Ogni comando deve stampare un numero di versione. Se uno risponde "non riconosciuto", il PATH non è stato aggiornato.

## 4. Installare le estensioni di VS Code

```powershell
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
```

Se `code` non viene trovato, riaprire PowerShell; se persiste, installare le estensioni dal pannello *Extensions* (`Ctrl+Shift+X`) cercando "C/C++" (Microsoft) e "CMake Tools" (Microsoft).

## 5. Scaricare gli esempi

```powershell
cd $HOME
git clone https://github.com/<utente>/its-programmazione.git
```

(Sostituire con l'indirizzo reale del repository. In alternativa, scaricare lo ZIP dal sito di GitHub ed estrarlo.)

Ogni cartella in `snippets/` è un progetto CMake indipendente. **In VS Code si apre la cartella del singolo esempio**, non l'intero repository:

```powershell
code "$HOME\its-programmazione\snippets\example01"
```

## 6. Prima compilazione ed esecuzione

1. All'apertura, CMake Tools chiede di scegliere un *kit*: scegliere quello che nel nome contiene `GCC` e il percorso `C:\msys64\ucrt64\bin\gcc.exe`. Se non compare, `Ctrl+Shift+P` → *CMake: Scan for Kits*.
2. Se chiede quale generatore usare, scegliere **Ninja**.
3. Compilare: `Ctrl+Shift+P` → *CMake: Build* (oppure il tasto *Build* nella barra di stato in basso).
4. Eseguire: *CMake: Run Without Debugging*, oppure dal terminale integrato `.\build\example01.exe`.

L'eseguibile si trova nella cartella `build/` dentro l'esempio.

## 7. Debug

1. Cliccare nel margine a sinistra di una riga per mettere un breakpoint.
2. `Ctrl+Shift+P` → *CMake: Debug* (o l'icona dell'insetto nella barra di stato).
3. Comandi: `F5` continua, `F10` *Step Over*, `F11` *Step Into*, `Shift+F11` *Step Out*.
4. Nel pannello *Run and Debug* a sinistra si vedono *Variables* e *Watch*.

Se il debug non parte con l'errore "Unable to start debugging" o non trova `gdb`, creare nell'esempio il file `.vscode/settings.json`:

```json
{
  "cmake.generator": "Ninja",
  "cmake.debugConfig": {
    "MIMode": "gdb",
    "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe"
  }
}
```

## 8. Verifiche da fare sulla macchina di prova

Provare almeno questi casi, perché sono quelli in cui Windows si comporta in modo diverso da macOS e Linux:

| Prova | Che cosa verificare |
| --- | --- |
| `example01` (hello world) | Compila, gira, esce senza errori |
| Caratteri accentati e simboli (`printf("è ✅\n")`) | Nel terminale integrato compaiono correttamente? Se compaiono caratteri strani, provare `chcp 65001` prima di eseguire e annotarlo |
| `scanf` con input numerico e testo | Il programma legge dalla tastiera nel terminale integrato |
| `example30` (legge `readings.csv`) | Il file viene trovato: dipende dalla cartella di lavoro dell'eseguibile (annotare dove va messo il CSV) |
| Debug con un breakpoint in un ciclo | Si ferma, le variabili si vedono, `F10` avanza |
| Programma con errore di compilazione volontario | Gli errori compaiono nel pannello *Problems* con la riga giusta |
| Chiudere e riaprire VS Code | Il kit selezionato si ricorda e non richiede altre scelte |

## 9. Se qualcosa non funziona

| Sintomo | Causa probabile | Rimedio |
| --- | --- | --- |
| `gcc` non riconosciuto | PATH non aggiornato o finestra non riaperta | Ripetere il passo 3 e riaprire le finestre |
| CMake non trova alcun kit | Toolchain non nel PATH di VS Code | Chiudere VS Code del tutto e riaprirlo da una nuova PowerShell |
| `pacman` non trova i pacchetti | Database non aggiornato | Rieseguire `pacman -Syu` in **MSYS2 UCRT64** |
| Errore di permessi nell'esecuzione | L'antivirus blocca l'eseguibile appena creato | Controllare la notifica di Windows Security e chiedere all'amministratore di autorizzare il singolo eseguibile; non escludere l'intera cartella |
| Il debug non parte | `gdb` non trovato | Usare il file `.vscode/settings.json` del passo 7 |
| Il terminale mostra solo l'output a fine programma | Buffer di `stdout` con output reindirizzato | Eseguire dal terminale integrato, non da *Debug Console*; annotare il caso |

## 10. Cose da annotare dopo la prova

- Tempo totale di installazione e dimensione scaricata.
- Quanti passaggi richiedono diritti di amministratore (importante per i portatili dell'ITS).
- Eventuali passaggi che uno studente principiante non riuscirebbe a fare da solo.
- Se conviene un'immagine preconfigurata dei portatili, oppure uno script `setup-windows.ps1` che esegua i passi 1–4 in automatico.
