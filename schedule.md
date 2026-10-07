# Corso: Elementi di programmazione e gestione dati

**Docente:** Ing. Giancarlo Degani  
**Durata totale:** 40 ore (10 lezioni da 4 ore)  
**Anno accademico:** 2026/2027

## Impostazione delle lezioni

Ogni lezione dura 4 ore: circa **1h30 di teoria**, divisa in blocchi da 20-30 minuti alternati a brevi esercizi, e circa **2h30 di pratica** al computer.

La classe ha preparazioni diverse: chi parte da zero, chi ha già visto Arduino, chi programma in un altro linguaggio. Per questo:

- gli esercizi sono proposti su tre livelli (*base*, *standard*, *sfida*);
- si lavora in coppia (pair programming), con ruoli che si alternano;
- un progetto, il "monitor di linea di produzione", cresce di lezione in lezione e collega gli argomenti al contesto meccatronico.

---

## Programma del corso

| Lezione | Argomenti | Contenuti principali | Materiale |
| :---: | --- | --- | --- |
| **1** | **Algoritmi e primo programma** | • Presentazione del corso e test d'ingresso<br>• Strumenti: CLion<br>• Algoritmi ed esecutori<br>• Diagrammi di flusso<br>• Primo programma in C: `printf` | Slides 1, Slides 2 (Hello World), Example 00-01 |
| **2** | **Variabili, tipi e input/output** | • Tipi primitivi e modificatori<br>• Variabili e costanti<br>• Operatori aritmetici e di assegnamento<br>• Conversioni di tipo<br>• `printf` e `scanf`<br>• Le fasi della compilazione, in breve | Slides 2, Examples 25-28 |
| **3** | **Istruzioni condizionali** | • Operatori relazionali e logici<br>• `if`, `if-else` e annidamento<br>• `switch`, `break`, fall-through<br>• Esercizi su tre livelli | Slides 3, Example 04 |
| **4** | **Cicli e debugger** | • `for`, `while`, `do-while`<br>• `break` e `continue`, cicli annidati<br>• Errori comuni nei cicli<br>• Debugger di CLion: breakpoint, esecuzione passo passo, watch | Slides 3, Example 03 |
| **5** | **Vettori, matrici e stringhe** | • Vettori: dichiarazione, accesso, iterazione<br>• Matrici<br>• Stringhe e terminatore `\0`<br>• `string.h`, `ctype.h`, sicurezza con le stringhe | Slides 4 |
| **6** | **Funzioni e progetti multi-file** | • Dichiarazione e definizione di funzioni<br>• Parametri, valori di ritorno, passaggio per valore<br>• Introduzione ai puntatori<br>• Header, include guards, progetti multi-file<br>• Build: preprocessing, linking, CMake | Slides 5, Slides 2 (build) |
| **7** | **Bit, registri e macchine a stati** | • Binario, esadecimale, complemento a 2<br>• `stdint.h`: tipi a dimensione fissa<br>• Operatori bit a bit e maschere<br>• `enum` e macchina a stati con `switch`<br>• Dal C ad Arduino (simulatore Wokwi) | Slides 1, Slides 5, nuove slide |
| **8** | **Strutture e file: gestione dati** | • `struct` e `typedef`<br>• Array di strutture<br>• Lettura e scrittura di file<br>• Analisi di dati di macchina da file CSV | Slides 6 |
| **9** | **Progetto integrato** | • Ripasso guidato degli argomenti del corso<br>• Sviluppo del progetto "monitor di linea"<br>• Debugging e test del proprio codice | Tutte le slide |
| **10** | **Chiusura del progetto e verifica** | • Completamento e presentazione del progetto<br>• Verifica finale | — |

### Approfondimento facoltativo

Per chi è più avanti: allocazione dinamica della memoria e liste concatenate (Slides 7).

---

## Obiettivi di apprendimento

- Comprendere i fondamenti della programmazione procedurale
- Usare correttamente tipi di dato, operatori e strutture di controllo
- Usare vettori, stringhe e funzioni
- Organizzare un programma in più file e compilarlo con CMake
- Manipolare bit e registri, modellare un comportamento con una macchina a stati
- Leggere, elaborare e salvare dati su file

---

## Modalità di valutazione

- **Verifica finale:** test a risposta multipla.
- **Pesi delle voci di valutazione:** da definire.

---

## Prerequisiti

- Conoscenze di base di informatica
- Capacità di utilizzo del computer
- Nessuna esperienza di programmazione richiesta

---

## Materiale didattico

- Slide del corso (repository GitHub e PDF nelle release di ogni edizione)
- Esempi di codice commentati (`snippets/exampleNN/`)
- Documentazione del C: [cppreference.com](https://cppreference.com/w/c.html)
