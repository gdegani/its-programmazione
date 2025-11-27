# Corso: Elementi di programmazione e gestione dati

**Docente:** Ing. Giancarlo Degani  
**Durata totale:** 46 ore  
**Periodo:** Anno Accademico 2024/2025

**Struttura del corso:**

- **Programmazione in C:** 34 ore (lezioni 1-9)
- **AI-assisted development:** 10 ore (lezioni 10-11)
- **Verifica finale:** 2 ore (lezione 12)

**Nota:** Ogni lezione da 4 ore prevede **3 ore di teoria** + **1 ora di esercitazioni pratiche**

---

## Programma del Corso

| Lezione | Ore Teoria | Ore Pratica | Argomenti | Contenuti principali | Slides | Materiale |
|:-------:|:----------:|:-----------:|-----------|----------------------|:------:|-----------|
| **1** | 3h | 1h | **Fondamenti di informatica e rappresentazione dell'informazione** | • Presentazione del corso e strumenti (CLion)<br>• Algoritmi ed esecutori<br>• Strutture dati ed espressioni<br>• Diagrammi di flusso (flowchart)<br>• Codifica binaria e sistemi numerici<br>• Rappresentazione interi (complemento a 2)<br>• Codifica caratteri (ASCII, Unicode)<br>• **Esercizi**: flowchart e conversioni numeriche | 1-59 | Slides 1, Examples |
| **2** | 3h | 1h | **Linguaggio C: introduzione e compilazione** | • Storia del C e librerie<br>• Primo programma: Hello World<br>• Header files (.h) vs Implementation (.c)<br>• Processo di compilazione (preprocessing, compilation, assembly, linking)<br>• Errori di compilazione vs linking<br>• Build systems (Make, CMake)<br>• **Esercizi**: compilazione programmi, CMakeLists.txt | 60-118 | Slides 1-2, Example 1-2 |
| **3** | 3h | 1h | **Tipi di dato, variabili e operatori** | • Tipi primitivi: int, float, double, char<br>• Modificatori di tipo (signed, unsigned, short, long)<br>• Dichiarazione e inizializzazione variabili<br>• Costanti (#define vs const)<br>• Operatori di assegnamento (=, +=, -=, etc.)<br>• Incremento e decremento (++, --)<br>• Operatori aritmetici (+, -, *, /, %)<br>• Precedenza e conversioni di tipo (cast)<br>• **Esercizi**: programmi con variabili e calcoli | 119-145 | Slides 2, Examples 25-26 |
| **4** | 3h | 1h | **Operatori e Input/Output** | • Operatori relazionali (==, !=, <, >, <=, >=)<br>• Operatori logici (&&, \|\|, !)<br>• Tabelle di verità e short-circuit evaluation<br>• Precedenza completa degli operatori<br>• printf() e format specifiers<br>• scanf() e lettura input<br>• Formattazione output avanzata<br>• **Esercizi**: programmi interattivi con I/O | 146-159 | Slides 2, Examples 27-28 |
| **5** | 3h | 1h | **Istruzioni condizionali** | • Controllo del flusso di esecuzione<br>• Sintassi if, if-else e nested if<br>• Sintassi switch-case<br>• break e fall-through<br>• Quando usare if vs switch<br>• **Esercizio guidato**: Carrello della spesa<br>• **Esercizi**: menu interattivi e decisioni | TBD | Slides 3, Example 4 |
| **6** | 3h | 1h | **Iterazioni: cicli** | • Introduzione alle iterazioni<br>• Ciclo for: sintassi e varianti<br>• Ciclo while e do-while<br>• Differenze tra i cicli<br>• break e continue<br>• Cicli annidati (nested loops)<br>• Scope delle variabili nei cicli<br>• **Esercizi**: algoritmi iterativi (somme, prodotti, pattern) | TBD | Slides 3, Example 3 |
| **7** | 3h | 1h | **Debug e array** | • Errori comuni nei cicli (off-by-one, infinite loops)<br>• Tecniche di debugging<br>• Array monodimensionali: dichiarazione e uso<br>• Accesso agli elementi e iterazione<br>• Array multidimensionali e matrici<br>• Stringhe come array di char<br>• Terminatore null (\0)<br>• **Esercizi**: manipolazione array e stringhe | TBD | Slides 3-4 |
| **8** | 3h | 1h | **Funzioni e puntatori (parte 1)** | • Concetto di funzione e modularità<br>• Dichiarazione e definizione di funzioni<br>• Parametri e valori di ritorno<br>• Passaggio per valore<br>• Scope delle variabili (locali vs globali)<br>• Introduzione ai puntatori<br>• Operatori & e *<br>• **Esercizi**: funzioni con puntatori | TBD | Slides 4-5 |
| **9** | 2h | - | **Puntatori e allocazione dinamica** | • Relazione tra puntatori e array<br>• Aritmetica dei puntatori<br>• Passaggio per riferimento<br>• malloc(), calloc(), free()<br>• Gestione heap vs stack<br>• Struct e typedef<br>• File I/O base | TBD | Slides 5-7 |
| | | | **TOTALE PROGRAMMAZIONE C** | **26 ore teoria + 8 ore esercitazioni = 34 ore** | | |
| **10** | 3h | 1h | **AI-assisted development: fondamenti** | • Introduzione all'AI-assisted development<br>• GitHub Copilot, ChatGPT, Claude<br>• Installazione e configurazione<br>• Primi esempi di code completion<br>• Prompt engineering base<br>• Generazione codice semplice<br>• **Esercizi**: utilizzo AI per programmi C | TBD | AI Materials |
| **11** | 5h | 1h | **AI-assisted development: progetto** | • Prompt engineering avanzato per programmatori<br>• Generazione documentazione e commenti<br>• Testing e debugging assistito da AI<br>• Code review con AI<br>• Best practices e limiti<br>• **Progetto finale**: sviluppo completo di un programma C assistito da AI<br>• Discussione e presentazione progetti | TBD | AI Materials |
| | | | **TOTALE AI-ASSISTED DEVELOPMENT** | **8 ore teoria + 2 ore esercitazioni/progetto = 10 ore** | | |
| **12** | 2h | - | **Verifica finale** | • Test scritto e/o pratico<br>• Valutazione delle competenze acquisite<br>• Programmazione in C<br>• Utilizzo strumenti AI | - | Test |
| | | | **TOTALE CORSO** | **36 ore teoria + 10 ore esercitazioni = 46 ore** | | |

---

## Dettaglio Ore per Argomento

| Macro-Area | Ore Teoria | Ore Pratica | Ore Totali | Lezioni |
|------------|:----------:|:-----------:|:----------:|:-------:|
| **Programmazione in C** | 26h | 8h | **34h** | 1-9 |
| **AI-assisted development** | 8h | 2h | **10h** | 10-11 |
| **Verifica finale** | 2h | - | **2h** | 12 |
| **TOTALE** | **36h** | **10h** | **46h** | **12** |

---

## Obiettivi di Apprendimento

### Linguaggio C (34 ore)

- Comprendere i fondamenti della programmazione procedurale
- Padroneggiare tipi di dato, operatori e strutture di controllo
- Utilizzare array, stringhe e funzioni efficacemente
- Gestire la memoria con puntatori e allocazione dinamica
- Implementare programmi completi con I/O e gestione file

### AI-Assisted Development (4 ore)

- Comprendere il ruolo dell'AI nello sviluppo software moderno
- Utilizzare strumenti di AI per aumentare la produttività
- Scrivere prompt efficaci per la generazione di codice
- Validare e verificare il codice generato da AI
- Applicare best practices nell'uso di AI tools

---

## Obiettivi di Apprendimento

### Linguaggio C (34 ore)

- Comprendere i fondamenti della programmazione procedurale
- Padroneggiare tipi di dato, operatori e strutture di controllo
- Utilizzare array, stringhe e funzioni efficacemente
- Gestire la memoria con puntatori e allocazione dinamica
- Implementare programmi completi con I/O e gestione file

### AI-Assisted Development (10 ore)

- Comprendere il ruolo dell'AI nello sviluppo software moderno
- Utilizzare strumenti di AI per aumentare la produttività
- Scrivere prompt efficaci per la generazione di codice
- Validare e verificare il codice generato da AI
- Applicare best practices nell'uso di AI tools

### Verifica Finale (2 ore)

- Valutare le competenze acquisite in programmazione C
- Verificare la capacità di utilizzo degli strumenti AI
- Testare problem-solving e debugging skills
- Accertare la comprensione dei concetti fondamentali

---

## Modalità di Valutazione

- **Esercitazioni pratiche**: 25%
- **Progetto finale AI-assisted**: 35%
- **Verifica finale**: 40%

---

## Prerequisiti

- Conoscenze di base di informatica
- Capacità di utilizzo del computer
- Nessuna esperienza di programmazione richiesta

---

## Materiale Didattico

- Slide del corso (disponibili su repository GitHub)
- Esempi di codice commentati (snippets/exampleNN/)
- Esercizi pratici con soluzioni
- Documentazione C (cppreference.com)
- Risorse online per AI-assisted development
