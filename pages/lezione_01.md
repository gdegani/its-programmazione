---
layout: cover
transition:
coverDate:

---

# 1 - Fondamenti di informatica e primo programma

Ing. Giancarlo Degani

---
level: 2

---

# Il corso

- **Programma:**
  - Prima parte: cultura informatica
  - Seconda parte: programmazione in linguaggio 'C'
- **Durata:** 30 ore (7 lezioni da 4 ore e 1 da 2 ore)
- **Verifica:** test finale di 20 domande a risposta multipla
  - 10 domande di teoria: 1 punto ciascuna
  - 10 domande su un esempio di codice da interpretare: 2 punti ciascuna

---
level: 2

---

# Strumenti

- Dispense delle lezioni
- Classroom
- CLion

---
layout: image-right
image: /clion1.png
level: 2

---

# CLion

- [CLion Download](https://www.jetbrains.com/clion/)
- [Educational license](https://www.jetbrains.com/community/education/#students/)

---
layout: image-right
image: /clion_license.png
level: 2

---

# Licenza per STUDENTI

- Creare un account con l’email **@itsmeccatronico.it** e richiedere una licenza educational
- Scaricare ed installare CLion
- Aprire il programma e registrare la licenza inserendo le credenziali dell’account in **Help > Register**
- <https://www.jetbrains.com>

---
level: 2

---

# Riferimenti

- <https://cppreference.com/w/c.html>
- <https://en.wikibooks.org/wiki/C_Programming>

---
level: 2

---

# Pair Programming

**Tecnica collaborativa di sviluppo software**

Due programmatori lavorano insieme allo stesso computer per scrivere codice.

**Vantaggi:**

- Qualità del codice superiore (revisione continua)
- Apprendimento reciproco e condivisione di conoscenze
- Meno errori e bug
- Problem solving più veloce
- Maggiore concentrazione

**Durante le esercitazioni in aula lavorerete in coppia seguendo questa metodologia.**

---
level: 2

---

# Pair Programming: Driver e Navigator

## 🖥️ Driver (Pilota)

**Chi siede davanti al computer**

- Scrive il codice alla tastiera
- Si concentra sulla sintassi e sui dettagli tecnici
- Implementa ciò che viene discusso
- **Focus tattico**: come scrivere il codice

---
level: 2

---

# Pair Programming: Driver e Navigator

## 🧭 Navigator (Navigatore)

**Chi guida e supervisiona**

- Pensa alla strategia generale e all'architettura
- Rivede il codice in tempo reale
- Suggerisce miglioramenti e alternative
- Anticipa problemi e casi limite
- **Focus strategico**: cosa scrivere e perché

**⏱️ Importante:** Scambiatevi i ruoli ogni 15-20 minuti!

---
level: 2

---

# ALGORITMO

- Il termine deriva dalla trascrizione latina del nome del matematico persiano al-Khwarizmi, vissuto nel IX secolo d.C. È considerato uno dei primi autori ad aver fatto riferimento a questo concetto, scrivendo il libro “Regole di ripristino e riduzione”.
- In matematica e informatica, un algoritmo è la specificazione di una sequenza finita di operazioni (dette anche istruzioni) che consente di risolvere una classe di problemi specifici o di calcolare il risultato di un'espressione matematica.

---
layout: image-right
image: /pancake.png
level: 2

---

# Ricetta

- Input:
  - Lista di ingredienti
  - Procedimento da eseguire
- Output:
  - Pancake

---
level: 2

---

# Proprietà di un algoritmo

- **Finito:** costituito da un numero finito di istruzioni.
- **Deterministico:** partendo dagli stessi dati di ingresso, ottengo gli stessi risultati.
- **Generale:** applicabile a tutti i problemi della classe a cui si riferisce.
  - Ad esempio, l'algoritmo per il calcolo dell'area di un rettangolo deve essere applicabile a tutti i rettangoli.
- **Eseguibile:** esiste un esecutore in grado di eseguire tutte le istruzioni in un tempo finito.

---
layout: image-right
image: /human_computer.png
level: 2

---

# Caratteristiche degli Esecutori

- Il linguaggio che possono comprendere (italiano, inglese, C, TypeScript, ecc.)
- Le azioni che possono eseguire
- Le regole che associano alle istruzioni fornite le azioni da eseguire

---
level: 2

---

# Calcolatore COME ESECUTORE

<br>
<br>
<br>

```mermaid {scale: 1.2, alt: 'A diagram'}
flowchart LR
  A[/Dati in ingresso/] --> B[Computer]
  C[/Algoritmo/] --> B
  B --> D[/Risultato/]
```

---
level: 2

---

# ESEMPIO

<br>
<br>
<br>

```mermaid {scale: 0.9, alt: 'A diagram'}
flowchart LR
  A[/Base=7, Altezza=2/] -- Dati in ingresso --> B[Computer]
  C[/Area del rettangolo, A=B*H/] -- Algoritmo --> B
  B -- Risultato --> D[/A=14/]
```

---
level: 2

---

# STRUTTURE DATI

- I contenitori usati per contenere i dati in ingresso sono detti variabili.
- Le variabili:
  - Hanno un nome o identificatore.
  - Possono essere usate come parte di una istruzione.
  - Possono essere caratterizzate dal tipo di dato che contengono
    - es. variabili per numeri interi, numeri reali, sequenze di numeri, etc...

---
level: 2

---

# ISTRUZIONI DI ASSEGNAZIONE

- Consentono di inserire un valore all’interno di una variabile.
- Cambiano a seconda del linguaggio utilizzato, ma solitamente usano l’operatore “=”.
  - x=5 assegna il valore 5 alla variabile x.
  - y=x assegna il valore contenuto nella variabile x alla variabile y.

---
level: 2

---

# DIAGRAMMA DI FLUSSO/FLOW CHART

- Consentono di rappresentare visivamente un algoritmo.
- Sono indipendenti dal linguaggio di programmazione.
- Esistono diversi standard grafici.

---
layout: image
image: /flowchart.png
backgroundSize: contain
title: Simboli flowchart
level: 2

---

<div class="absolute bottom-2 left-4 text-xs text-gray-400">
source: wikipedia.org
</div>

---
level: 2

---

# Esempio di flowchart

```mermaid {scale: 0.7, alt: 'A diagram'}
flowchart LR

    Start([Inizio]) --> Input[/Input/]
    Input --> Process1[Elaborazione]
    Process1 --> Decision{Decisione}
    Decision -- Sì --> Process2[Elaborazione<br> Successiva]
    Decision -- No --> End([Fine])
    Process2 --> End([Fine])
```

---
layout: two-cols
level: 2

---

# Esempio: area di un rettangolo

- Calcolo dell’area di un rettangolo
- Input: base ed altezza
- Algoritmo: Area = base * altezza

::right::

```mermaid {scale: 0.9, alt: 'A diagram'}
flowchart TD
    Start([Inizio]) --> InputBase[/Inserisci la base/]
    InputBase --> InputAltezza[/Inserisci l'altezza/]
    InputAltezza --> CalcoloArea[Calcola Area = base * altezza]
    CalcoloArea --> OutputArea[/Visualizza l'area/]
    OutputArea --> End([Fine])
```

---
layout: two-cols
level: 2

---

# Selezione - IF THEN ELSE

- Viene valutata una condizione.
- Se la condizione è vera, l’elaborazione prosegue con il ramo di sinistra.
- Se la condizione è falsa, l’elaborazione prosegue con il ramo di destra.

::right::

```mermaid {scale: 0.9, alt: 'A diagram'}
flowchart TD
    Start([Inizio]) --> Condition{La condizione è verificata?}
    Condition -- Sì --> Action1[Azione se vera]
    Condition -- No --> Action2[Azione se falsa]
    Action1 --> End([Fine])
    Action2 --> End([Fine])
```

---
layout: two-cols
level: 2

---

# Iterazione - Ciclo while

- Viene valutata una condizione.
- Se la condizione è vera, viene eseguita l’azione e poi viene rivalutata la condizione.
- Si esce dal ciclo quando la condizione diventa falsa.

::right::

```mermaid {scale: 0.9, alt: 'A diagram'}
flowchart TD
    J1@{ shape: f-circ, label: ""}
    Start([Inizio]) --> J1
    J1 --> Controllo{Condizione Vera?}
    Controllo -- Sì --> Azione[Azioni da Eseguire]
    Azione --> J1
    Controllo -- No --> End([Fine])
```

---
layout: two-cols
level: 2

---

# Iterazione - Ciclo do while

- Viene eseguita l’azione.
- Se la condizione è vera, l’azione viene eseguita nuovamente e poi viene rivalutata la condizione.
- Si esce dal ciclo quando la condizione diventa falsa.
- Nel ciclo do-while l’azione viene eseguita almeno una volta.

::right::

```mermaid {scale: 0.8, alt: 'A diagram'}
flowchart TD
    J1@{ shape: f-circ, label: ""}
    Start([Inizio]) --> J1
    J1 --> Azione[Azioni da Eseguire]
    Azione --> Controllo{Condizione Vera?}
    Controllo -- Sì --> J1
    Controllo -- No --> End([Fine])
```

---
layout: two-cols
level: 2

---

# Iterazione - Ciclo for

- Viene valutata la condizione e, se vera, si esegue l’azione.
- L’azione viene eseguita un numero finito di volte.

::right::

```mermaid {scale: 0.6, alt: 'A diagram'}
flowchart TD
    J1@{ shape: f-circ, label: ""}
    Start([Inizio]) --> Inizializzazione[Inizializza Contatore=1]
    Inizializzazione --> J1
    J1 --> Controllo{Contatore <= Limite?}
    Controllo -- Sì --> Azione[Azioni da Eseguire]
    Azione --> Incremento[Incrementa Contatore]
    Incremento --> J1
    Controllo -- No ---> End([Fine])
```

---
layout: two-cols
level: 2

---

# Esempio: CALCOLO DEL FATTORIALE

Dato un numero intero, calcolarne il fattoriale.

- Input: un numero intero maggiore o uguale a zero
- Algoritmo: moltiplico n per tutti i numeri minori di n, fino a 2

::right::

<br>
<br>
<br>
<br>
<br>
<br>
<br>

$$
n! =
\begin{cases}
1 & \text{se } n = 0 \\
n \times (n-1) \times \cdots \times 2 \times 1 & \text{se } n > 0
\end{cases}
$$

---
level: 2

---

# Esempio: CALCOLO DEL FATTORIALE

```mermaid {scale: 0.5, alt: 'A diagram'}
flowchart LR
    Start([Inizio]) --> InputNum[/Leggi n/]
    InputNum --> Check{n >= 0?}
    Check -- No --> Error[/Mostra: n deve essere non negativo/]
    Error ---> End([Fine])
    Check -- Sì --> Initialize[fattoriale = 1<br>i = 1]
    Initialize --> LoopCheck{i <= n?}
    LoopCheck -- Sì --> Multiply[fattoriale = fattoriale * i]
    Multiply --> Increment[Incrementa i di 1]
    Increment --> LoopCheck
    LoopCheck -- No --> OutputResult[/Mostra fattoriale/]
    OutputResult ---> End([Fine])
```

---
level: 2

---

# ESERCIZIO

Rappresentare un algoritmo per il calcolo del costo di un prodotto che soddisfi i seguenti requisiti:

- Input: costo unitario, quantità acquistata
- Se il numero di elementi acquistati è superiore a 10, applicare uno sconto del 20%
- Output: costo totale

---
layout: two-cols
level: 2

---

# flow-chart

Flowchart della soluzione

::right::

```mermaid {scale: 0.6, alt: 'A diagram'}
flowchart TD
    A([Inizio]) --> B[/Leggi costo unitario<br>e quantità/]
    B --> C{Quantità > 10?}
    C -->|Sì| D[totale = costo * quantità * 0.8]
    C -->|No| E[totale = costo * quantità]
    D --> F[/Mostra il totale/]
    E --> F
    F --> G([Fine])
```

---
layout: center
level: 2

---

# “Algoritmi + Strutture Dati = Programmi”

## Niklaus Wirth

---
level: 2

---

# Programma e programmazione

- Il programma è una sequenza di istruzioni elementari che implementa un algoritmo e produce il risultato desiderato in un tempo finito.
- Il programma è scritto da un programmatore per risolvere un problema.
- La programmazione è il processo che porta alla realizzazione di un programma o software.

---
level: 2

---

# Problema

- Per fornire istruzioni a un computer è necessario utilizzare un linguaggio comune.
- Il computer comprende solo sequenze di 0 e 1, ovvero sequenze binarie.
- Il programmatore comprende il linguaggio naturale: “fai, leggi, scrivi.”
- Il linguaggio di programmazione è un linguaggio compreso sia dal computer che dal programmatore.

---
layout: image-right
image: /binary.png
level: 2

---

# Linguaggio macchina

Sequenza binaria comprensibile solo da uno specifico microprocessore o da una famiglia di microprocessori.

---
layout: two-cols
level: 2

---

# Linguaggio assembly

Stampa la scritta “hello world” in linguaggio assembly per microprocessore Intel 8086.

::right::

<<< @/snippets/example00/HelloWorld.asm asm {all}{lines:true}

---
layout: two-cols
level: 2

---

# Linguaggio C

Stampa la scritta “hello world”.

::right::

<<< @/snippets/example01/main.c c {all}{lines:true}

---
layout: two-cols
level: 2

---

# Linguaggio Python

Stampa la scritta “hello world” in Python.

::right::

<<< @/snippets/example00/hello.py py {all}{lines:true}

---
level: 2

---

# Linguaggi di programmazione

Calcolatore e programmatore, per comprendersi, devono avere un linguaggio comune:

- Linguaggi a basso livello: (es. Assembly)
- Linguaggi ad alto livello: (es. JavaScript, Python)
- Linguaggi compilati: (es. TypeScript, Java)
- Linguaggi interpretati: (es. JavaScript, Python)

Il documento contenente le istruzioni scritte in un linguaggio di programmazione si chiama **codice sorgente**.

---
level: 2

---

# Traduttori in linguaggio macchina

- **Interprete:** Le istruzioni vengono tradotte una alla volta ed eseguite immediatamente dal calcolatore.
- **Compilatore:** Tutte le istruzioni vengono tradotte in linguaggio macchina e memorizzate in un file eseguibile dal calcolatore (programma).

---
level: 2

---

# Pro e contro

Velocità di esecuzione:

- L’interprete deve tradurre il programma ogni volta che lo esegue.
- Il programma compilato viene tradotto solo una volta.
- Il compilatore è più efficiente ed ottimizza il codice tradotto.

---
layout: image-right
image: /kernighan.png
level: 2

---

# Il linguaggio C

- Sviluppato da Dennis Ritchie ai Bell Labs nel 1972 per realizzare il sistema operativo UNIX
- Linguaggio compilato
- Compilatore disponibile per tutte le piattaforme
- Codice molto efficiente

---
level: 2

---

# Il linguaggio C, caratteristiche

- Adatto sia come linguaggio ad alto livello che a basso livello (operazioni sui bit)
- Tantissime librerie disponibili
- Linguaggio procedurale, non ad oggetti (Aggiunti nel C++)
- Gestione della memoria “manuale” (Non c’è garbage collector)

---
level: 2

---

# Librerie

- In un linguaggio ad alto livello le funzioni di base sono fornite dal linguaggio ( lettura da tastiera, scrittura su schermo, lettura/scrittura da file)
- Queste operazioni elementari sono disponibili sotto forma di funzioni
- Le funzioni sono raccolte e distribuite sotto forma di librerie

---
level: 2

---

# Come si scrive un programma?

- Bastano un editor di testo per scrivere il file sorgente ed un compilatore o interprete per tradurre il sorgente in linguaggio macchina
- Solitamente si usa uno strumento definito Integrated Development Environment (IDE)
- CLion è un IDE specifico per C/C++

---
level: 2

---

# hello, world

<<< @/snippets/example01/main.c txt {all}{lines:true}

---
level: 2

---

# hello, world

<<< @/snippets/example01/main.c c {all|1-4|6-7|9-15|17-18|19|all}{lines:true}

---
level: 2

---

# Esercizio: Il tuo primo programma in CLion (parte 1)

**Obiettivo:** Creare ed eseguire il programma "Hello, World!" usando CLion

**Passi da seguire:**

1. Apri CLion
2. Crea un nuovo progetto: `File → New Project`
3. Seleziona **C Executable**
4. Imposta le seguenti opzioni:
   - Nome progetto: `hello_world`
   - Linguaggio: **C**
   - Standard: **C11**
5. Clicca su **Create**

---
level: 2

---

# Esercizio: Il tuo primo programma in CLion (parte 2)

6. Verifica che il file `main.c` contenga il codice Hello World
7. Clicca sul pulsante ▶️ verde (Run) oppure premi `Shift+F10` (Windows/Linux) o `Ctrl+R` (macOS)
8. Verifica l'output nella finestra **Run** in basso

**Risultato atteso nella console:**

```text
Hello, World!

Process finished with exit code 0
```

---
level: 2

---

# printf(): stampare testo

`printf()` stampa testo sullo standard output (terminale).

Alcuni caratteri speciali:

```c
printf("Line 1\nLine 2\n");     // \n = newline
printf("Tab\there\n");          // \t = tab
printf("Quote: \"\n");          // \" = double quote
printf("Backslash: \\\n");      // \\ = backslash
```

I valori numerici e la formattazione si vedono nella prossima lezione.

---
level: 2

---

# Esercizio: la scheda della macchina

Livello base, in coppia: scambiatevi i ruoli a metà esercizio.

Scrivere un programma che stampa con `printf()` esattamente questo testo:

```text
Machine: "Press 01"
Path: C:\factory\line1
Status: READY
```

## Suggerimento

Servono i caratteri speciali della slide precedente: `\n`, `\"` e `\\`.

## Per chi finisce prima

Stampare anche una quarta riga con un carattere di tabulazione tra `Status:` e `READY`.
