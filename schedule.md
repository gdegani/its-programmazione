# Corso: Elementi di programmazione e gestione dati

**Docente:** Ing. Giancarlo Degani  
**Durata totale:** 30 ore (7 lezioni da 4 ore e 1 da 2 ore)  
**Anno accademico:** 2026/2027

Il corso è la prima parte di un percorso di 46 ore. Prosegue con il modulo "Programmazione assistita dall'AI" (16 ore), che usa come base il C imparato qui.

## Impostazione delle lezioni

Ogni lezione da 4 ore comprende circa **1h30 di teoria**, divisa in blocchi da 20-30 minuti alternati a brevi esercizi, e circa **2h30 di pratica** al computer.

Tutte le esercitazioni si svolgono in classe, sui portatili in dotazione, in **pair programming**: un portatile ogni due studenti, con i ruoli di *driver* e *navigator* che si alternano.

La classe ha preparazioni diverse: chi parte da zero, chi ha già nozioni di elettronica o di microcontrollori, chi programma in un altro linguaggio. Per questo:

- le coppie sono miste, formate in base a un breve test d'ingresso;
- gli esercizi sono proposti su tre livelli (*base*, *standard*, *sfida*);
- un progetto, il "monitor di linea di produzione", cresce di lezione in lezione e collega gli argomenti al contesto meccatronico.

---

## Programma del corso

| Lezione | Ore | Argomenti | Contenuti principali | Materiale |
| :---: | :---: | --- | --- | --- |
| **1** | 4 | **Algoritmi e primo programma** | • Presentazione del corso e test d'ingresso<br>• Strumenti: CLion<br>• Algoritmi ed esecutori<br>• Diagrammi di flusso<br>• Primo programma in C: `printf` | `lezione_01`, Example 00-01 |
| **2** | 4 | **Variabili, tipi e input/output** | • Tipi primitivi e modificatori<br>• Variabili e costanti<br>• Operatori aritmetici e di assegnamento<br>• Conversioni di tipo<br>• `printf` e `scanf`<br>• Le fasi della compilazione, in breve | `lezione_02`, Examples 25-28 |
| **3** | 4 | **Condizioni, cicli e debugger** | • Operatori relazionali e logici<br>• `if`, `if-else`, `switch`<br>• `for`, `while`, `do-while`, `break`, `continue`<br>• Errori comuni nei cicli<br>• Debugger di CLion: breakpoint, passo passo | `lezione_03`, Examples 03-04 |
| **4** | 4 | **Vettori, matrici e stringhe** | • Vettori: dichiarazione, accesso, iterazione<br>• Matrici<br>• Stringhe e terminatore `\0`<br>• `string.h`, `ctype.h`, sicurezza con le stringhe | `lezione_04` |
| **5** | 4 | **Funzioni, puntatori e test** | • Dichiarazione e definizione di funzioni<br>• Parametri e passaggio per valore<br>• Puntatori: operatori `&` e `*`<br>• Header, include guards, progetti multi-file<br>• Build e CMake<br>• Test automatici: `assert` e CTest | `lezione_05`, Example 34 |
| **6** | 4 | **Bit, registri e macchine a stati** | • Binario, esadecimale, complemento a 2<br>• `stdint.h`: tipi a dimensione fissa<br>• Operatori bit a bit e maschere<br>• `enum` e macchina a stati con `switch`<br>• Esempi: byte di stato e frame di un sensore | `lezione_06`, Examples 31-33, 35 |
| **7** | 4 | **Strutture, liste e file: gestione dati** | • `struct` e `typedef`<br>• Allocazione dinamica: `malloc` e `free`<br>• Liste concatenate<br>• Lettura di dati di macchina da file CSV<br>• Chiusura del progetto | `lezione_07`, Examples 24, 30 |
| **8** | 2 | **Verifica finale e discussione** | • Test finale a risposta multipla<br>• Correzione e discussione con la classe | `lezione_08` |

### Approfondimento facoltativo

Per chi è più avanti: liste bidirezionali e liste di liste (ultime slide di `lezione_07`).

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

Il voto è dato dalla verifica finale: un test di **20 domande a risposta multipla**, per un totale di **30 punti**.

| Tipo di domanda | Numero | Punti per domanda | Totale |
| --- | :---: | :---: | :---: |
| Teoria | 10 | 1 | 10 |
| Interpretazione di un esempio di codice | 10 | 2 | 20 |
| **Totale** | **20** | | **30** |

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
