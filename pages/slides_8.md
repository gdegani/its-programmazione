---
layout: cover
coverDate:
transition:
---

# 8 - Intelligenza Artificiale come Supporto allo Sviluppo C

Ing. Giancarlo Degani

---

# Modulo supplementare - 10 ore

Questo modulo è un **approfondimento facoltativo** rivolto agli studenti che hanno completato il corso base di programmazione C.

## Obiettivi del modulo

Imparare a usare strumenti di **Intelligenza Artificiale** (AI) come supporto allo sviluppo di software in C, con particolare focus su **JetBrains AI Assistant** in **CLion**.

## Struttura

**Cinque sessioni da 2 ore ciascuna**

1. Fondamenti dell'AI e uso responsabile
2. Setup e primi passi con AI Assistant
3. Prompting e generazione di codice
4. Debugging e refactoring con AI
5. Testing e progetto pratico

---

# Prerequisiti

Per partecipare a questo modulo è necessario:

## Competenze tecniche

- Aver completato il corso base di programmazione C
- Conoscere i concetti di variabili, funzioni, array, puntatori
- Saper compilare ed eseguire programmi C

## Strumenti richiesti

- **CLion** installato (licenza educativa gratuita disponibile)
- Account **JetBrains** (gratuito per studenti)
- Connessione internet per i servizi AI cloud

## Atteggiamento

- Curiosità verso le nuove tecnologie
- Capacità critica nel valutare i suggerimenti AI
- Disponibilità a sperimentare

---

# Risultati di apprendimento

Al termine del modulo sarai in grado di:

1. **Comprendere** come funzionano gli strumenti AI basati su LLM e i loro limiti

2. **Configurare** JetBrains AI Assistant in CLion e utilizzare le funzionalità principali

3. **Scrivere prompt efficaci** per generare e migliorare codice C

4. **Utilizzare AI** per comprendere errori di compilazione e migliorare il codice

5. **Generare test** con l'aiuto dell'AI e integrarli con CTest

6. **Applicare pratiche responsabili** nel uso dell'AI (privacy, integrità accademica)

---

# Cos'è l'AI nell'IDE?

## Large Language Models (LLM)

I **Large Language Models** sono sistemi di intelligenza artificiale addestrati su enormi quantità di codice e testo che possono:

- Completare il codice mentre scrivi
- Generare funzioni complete da descrizioni
- Spiegare codice esistente
- Suggerire correzioni e miglioramenti
- Generare documentazione e test

## JetBrains AI Assistant

In CLion, l'AI Assistant integra:

- **Completamento intelligente** del codice
- **AI Chat** con contesto del progetto
- **Azioni AI** contestuali nel codice
- **Suggerimenti** per la prossima modifica

---
layout: two-cols
---

# Punti di forza e limiti

## Punti di forza

- ✅ Generazione rapida di codice boilerplate
- ✅ Spiegazioni di codice non familiare
- ✅ Suggerimenti per test e refactoring
- ✅ Accelerazione dello sviluppo
- ✅ Apprendimento di nuovi pattern

::right::

## Limiti

- ❌ Può generare codice **errato** o inconsistente
- ❌ Richiede **prompt chiari** e contesto
- ❌ Non sostituisce la comprensione del programmatore
- ❌ **Tu rimani responsabile** della correttezza
- ❌ Può "allucinare" funzioni o API inesistenti

**Regola d'oro:** L'AI è uno strumento di supporto, non un sostituto del pensiero critico

---

# Uso responsabile: privacy e dati

## Privacy e sicurezza

- Il plugin AI Assistant **non è incluso** di default: devi installarlo e accettare i termini
- Quando usi funzionalità AI, i tuoi **prompt e codice** possono essere inviati al provider LLM selezionato
- La raccolta dettagliata di telemetria è **opt-in** e disabilitata di default

## Buone pratiche

- ⚠️ **Mai inviare** credenziali, password o dati sensibili
- ⚠️ Preferire **modelli locali** quando disponibili per codice sensibile
- ⚠️ Leggere la **privacy policy** del provider scelto
- ⚠️ **Tu sei responsabile** di ciò che invii

---

# Integrità accademica

## Regole per l'uso dell'AI nel corso

1. **Trasparenza**: Dichiara sempre quando hai usato l'AI
2. **Verifica**: L'output AI può essere errato - verificalo sempre
3. **Comprensione**: Devi capire il codice che consegni
4. **Attribuzione**: Indica quali parti sono state generate con AI
5. **Limiti**: Rispetta le regole specifiche di ogni esercizio/progetto

## Cosa è accettabile

- ✅ Usare AI per **spiegare** concetti
- ✅ Generare **test** e poi verificarli
- ✅ Chiedere **suggerimenti** per il refactoring
- ✅ Debugging di **errori di compilazione**

## Cosa non è accettabile

- ❌ Copiare soluzioni complete senza comprenderle
- ❌ Non dichiarare l'uso dell'AI quando richiesto
- ❌ Usare AI in esami se non esplicitamente permesso

---

# Sessione 1: Fondamenti e uso responsabile

**Durata:** 2 ore

## Contenuti

1. **Introduzione agli LLM** (30 min)
   - Cosa sono e come funzionano
   - Capacità e limitazioni
   - Casi d'uso nello sviluppo software

2. **Uso responsabile** (30 min)
   - Privacy e sicurezza dei dati
   - Integrità accademica
   - Quando usare e quando evitare l'AI

3. **Panoramica delle funzionalità** (30 min)
   - AI Chat, completamento inline, azioni AI
   - Demo dal vivo con esempi C

4. **Esercizio pratico** (30 min)
   - Scrivi un prompt per spiegare una funzione C
   - Valuta criticamente la risposta dell'AI
   - Discussione in gruppo

---

# Installazione di CLion + AI Assistant

## Passo 1: Installare il plugin

1. Apri CLion
2. Vai su **File → Settings** (Windows/Linux) o **CLion → Preferences** (macOS)
3. Seleziona **Plugins** nel menu a sinistra
4. Clicca su **Marketplace**
5. Cerca "**AI Assistant**"
6. Clicca **Install** e poi **Restart IDE**

## Passo 2: Configurazione iniziale

1. Dopo il riavvio, apparirà una finestra di benvenuto
2. **Sign in** con il tuo account JetBrains (registrazione gratuita)
3. Accetta i **termini del servizio AI**
4. Seleziona le **funzionalità** da abilitare
5. Scegli il **provider LLM** (es. OpenAI, Google, locale)

---

# Configurazione delle impostazioni AI

## Settings → Tools → AI Assistant

**Funzionalità da configurare:**

- **AI Chat**: Abilita la finestra di chat integrata
- **Inline Completion**: Suggerimenti durante la digitazione
- **Next Edit Suggestions**: Previsione della prossima modifica
- **Cloud/Local Models**: Scegli tra modelli cloud o locali

## Settings → Editor → Inline Completion

- Abilita/disabilita il completamento automatico
- Configura i tasti di scelta rapida
- Personalizza quando mostrare i suggerimenti

## Privacy e telemetria

**Settings → Tools → AI Assistant → Data Sharing**

- Mantieni **Detailed Data Collection** disabilitato a meno che non desideri condividere dati di utilizzo
- Rivedi la privacy policy del provider

---

# Sessione 2: Setup e primi passi

**Durata:** 2 ore

## Contenuti

1. **Installazione guidata** (30 min)
   - Install plugin passo-passo
   - Login e configurazione
   - Verifica del funzionamento

2. **Prima interazione con l'AI** (30 min)
   - AI Chat: porre domande
   - Completamento inline: accettare suggerimenti
   - Azioni AI sul codice selezionato

3. **Esercizio guidato** (45 min)
   - Implementare `sum_array()` con suggerimenti AI
   - Testare manualmente il risultato
   - Confrontare diverse soluzioni

4. **Q&A e troubleshooting** (15 min)

---

# 🎯 Esercizio Live: Il tuo primo prompt

## Obiettivo

Familiarizzare con AI Chat scrivendo il primo prompt efficace.

## Passo 1: Apri AI Assistant in CLion

1. Clicca sull'icona **AI Assistant** nella barra laterale
2. Oppure usa **Help → AI Assistant**

## Passo 2: Prova questo prompt

Copia e incolla nella chat AI:

```
Spiega questa funzione C in termini semplici e identifica 
3 possibili problemi o casi limite che dovrei testare:

int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
```

---

# 🎯 Esercizio Live: Analisi della risposta

## Cosa aspettarsi dall'AI

L'AI dovrebbe identificare problemi come:

1. **Nessun controllo su size**: Cosa succede se `size == 0`?
2. **Nessun controllo su arr**: Cosa succede se `arr == NULL`?
3. **Overflow con INT_MIN**: Se tutti gli elementi sono INT_MIN?

## Il tuo compito

1. ✅ Leggi attentamente la risposta AI
2. ✅ Verifica se ha identificato tutti i problemi
3. ✅ Se manca qualcosa, chiedi: "Ci sono altri problemi?"
4. ✅ Chiedi: "Mostrami una versione corretta"

## Riflessione

- La risposta AI era completa?
- Comprendi tutti i problemi identificati?
- Avresti trovato questi problemi da solo?

---

# Prime interazioni con l'AI in CLion

## 1. Completamento inline

- Inizia a scrivere codice
- L'AI suggerisce il completamento in grigio
- Premi **Tab** per accettare
- Premi **Esc** per rifiutare

```c
// Esempio: inizi a scrivere
int factorial(int n) {
    // L'AI suggerisce automaticamente:
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## 2. AI Chat

- Apri la finestra **AI Assistant** (pulsante laterale)
- Scrivi una domanda: "Come implementare una ricerca binaria in C?"
- L'AI risponde con spiegazioni e codice
- Puoi allegare file per dare contesto

---

# Azioni AI contestuali

## Come usarle

1. Seleziona del codice
2. Premi **Alt+Enter** (Windows/Linux) o **Option+Return** (macOS)
3. Nel menu che appare, seleziona **AI Actions**
4. Scegli un'azione:

## Azioni disponibili

- **Explain Code**: Spiega cosa fa il codice selezionato
- **Suggest Refactoring**: Propone miglioramenti
- **Generate Tests**: Crea test case
- **Generate Documentation**: Aggiunge commenti Doxygen
- **Find Problems**: Identifica possibili bug
- **Custom Prompt**: Scrivi un prompt personalizzato

---

# Sessione 3: Prompting e generazione di codice

**Durata:** 2 ore

## Contenuti

1. **Anatomia di un prompt efficace** (30 min)
   - Pattern di prompt per C
   - Esempi di prompt buoni vs cattivi
   - Come iterare e migliorare

2. **Generazione di codice** (45 min)
   - Generare funzioni da descrizione
   - Creare stub e scheletri
   - Aggiungere documentazione

3. **Esercizio pratico** (45 min)
   - Generare test per `remove_spaces()`
   - Implementare fino a quando tutti i test passano
   - Documentare con Doxygen usando AI

---

# 🎯 Esercizio Pratico: Genera la tua prima funzione

## Scenario

Devi creare una funzione che conta le vocali in una stringa.

## Step 1: Scrivi il prompt (5 min)

Prova a scrivere tu un prompt completo prima di guardare la soluzione!

**Pensa a:**
- Cosa deve fare la funzione?
- Quali parametri serve?
- Quali casi limite gestire?
- Quale documentazione aggiungere?

## Step 2: Confronta con il prompt suggerito

```
Scrivi una funzione C che conta le vocali (a,e,i,o,u) 
in una stringa, ignorando maiuscole/minuscole.

Requisiti:
- Nome: count_vowels
- Parametro: const char *str
- Ritorna: int (numero di vocali)
- Gestisci str == NULL (ritorna -1)
- Gestisci stringa vuota (ritorna 0)
- Documentazione Doxygen
- 5 test case con assert()
Standard: C11
```

---

# 🎯 Esercizio Pratico: Implementazione e test

## Step 3: Genera il codice (5 min)

1. Copia il prompt nella AI Chat
2. Ottieni la risposta
3. Copia il codice in CLion

## Step 4: Verifica e compila (5 min)

1. Leggi il codice generato - comprendi ogni riga!
2. Compila con `gcc -std=c11 -Wall -Wextra`
3. Correggi eventuali warning

## Step 5: Esegui i test (5 min)

1. Esegui il programma
2. Tutti i test passano?
3. Se no, chiedi all'AI: "Il test X fallisce, perché?"

## Step 6: Migliora (10 min)

Chiedi all'AI:
```
Aggiungi altri 3 test case che potrebbero fallire
```

Implementa i nuovi test e verifica.

---

# Pattern di prompt efficaci per C

## 1. Explain (Spiega)

**Esempio:**
```
Spiega questa funzione in termini semplici e 
elenca 3 casi limite che dovrebbe gestire:

[incolla il codice]
```

## 2. Constrain (Vincola)

**Esempio:**
```
Scrivi una funzione C safe_div che:
- NON usa allocazione dinamica
- È documentata con Doxygen
- Include validazione input
- Restituisce un codice di errore se divisione per zero
Standard: C11
```

---

# Pattern di prompt efficaci per C (continua)

## 3. Iterate (Itera)

**Esempio:**
```
Migliora la leggibilità di questa funzione senza 
cambiare il comportamento:
- Usa C11 standard
- Mantieni l'API pubblica stabile
- Aggiungi commenti significativi

[incolla il codice]
```

## 4. Review (Revisiona)

**Esempio:**
```
Agisci come code reviewer: identifica potenziali 
problemi in questo codice:
- Undefined Behavior (UB)
- Memory leak
- Problemi di naming
- Buffer overflow

Indica i numeri di riga specifici.

[incolla il codice]
```

---

# Esempi di prompt: buoni vs cattivi

## ❌ Prompt cattivo

```
scrivi una funzione
```

**Problema:** Troppo vago, manca il linguaggio, lo scopo, i requisiti

## ✅ Prompt buono

```
Scrivi una funzione C che calcola il massimo comune divisore (GCD) 
di due interi usando l'algoritmo di Euclide.

Requisiti:
- Standard C11
- Nome funzione: gcd
- Parametri: int a, int b
- Gestisci il caso b == 0
- Commenti Doxygen
- 3 test case con valori positivi, negativi e zero
```

**Perché funziona:** Specifico, chiaro, con vincoli e aspettative

---

# Generare codice con vincoli

## Esempio completo

**Prompt:**
```
Genera una funzione C per invertire una stringa in-place.

Vincoli:
- Solo <string.h> e <stdio.h>
- NO malloc/free
- Parametro: char *str
- Gestisci str == NULL
- Gestisci stringa vuota
- Documentazione Doxygen
- 5 test case con CTest
```

**L'AI genererà:**
- Prototipo della funzione
- Implementazione
- Documentazione
- Test case

**Il tuo compito:** Verificare, compilare, testare, correggere se necessario

---

# Sessione 4: Debugging e refactoring

**Durata:** 2 ore

## Contenuti

1. **Comprendere errori di compilazione** (30 min)
   - Copiare messaggi di errore e chiedere all'AI
   - Ottenere spiegazioni e soluzioni
   - Confrontare diverse fix

2. **Refactoring assistito** (45 min)
   - Migliorare naming
   - Estrarre funzioni
   - Semplificare logica complessa
   - Integrazione con clang-tidy

3. **Esercizio pratico** (45 min)
   - Correggere 5 warning di clang-tidy con AI
   - Refactoring di una funzione complessa
   - Scrivere commit message con AI

---

# Usare l'AI per comprendere errori

## Workflow tipico

1. **Compila** il programma e ottieni un errore
2. **Copia** il messaggio di errore completo
3. **Chiedi all'AI**:

```
Spiega questo errore di compilazione C e 
suggerisci 2 modi per risolverlo con pro e contro:

[incolla errore]

Codice sorgente:
[incolla il codice rilevante]
```

4. **Valuta** i suggerimenti criticamente
5. **Applica** la soluzione più appropriata
6. **Verifica** ricompilando

## Nota importante

L'AI può sbagliare! Usa sempre il tuo giudizio critico.

---

# Esempio: debugging con AI

## Codice con errore

```c
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum;
    for (int i = 0; i <= 5; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
    return 0;
}
```

## Errori

1. `sum` non inizializzato
2. Loop va da 0 a 5 (off-by-one: array ha indici 0-4)

## Prompt per l'AI

```
Questo codice ha dei bug. Identificali e spiega 
come correggerli:

[codice sopra]
```

L'AI dovrebbe identificare entrambi i problemi e suggerire le correzioni.

**Vedi esempio completo:** `snippets/ai_module/debug_case.c`

---

# Refactoring con AI

## Approccio sicuro

1. **Seleziona** il codice da refactorare
2. **Alt+Enter → AI Actions → Suggest Refactoring**
3. **Rivedi** i suggerimenti con attenzione
4. **Applica** le modifiche gradualmente
5. **Testa** dopo ogni modifica
6. **Usa git** per tracciare le modifiche

## Combinare con clang-tidy

CLion integra **clang-tidy** per analisi statica:

- **Settings → Editor → Inspections → Clang-Tidy**
- Abilita i check desiderati
- I warning appaiono nel codice
- Usa AI per spiegare e correggere

---

# Esempio di refactoring

## Prima

```c
int compute(int a, int b) {
    if(b==0) return a;
    return a%b==0?a/b:a;
}
```

## Dopo (con AI + revisione manuale)

```c
/**
 * Computes a safe division with modulo check.
 * 
 * @param dividend The numerator
 * @param divisor The denominator (must not be 0)
 * @return dividend / divisor if divisor divides dividend evenly,
 *         otherwise returns dividend
 */
int safe_division_with_check(int dividend, int divisor) {
    if (divisor == 0) {
        return dividend;  // Avoid division by zero
    }
    
    if (dividend % divisor == 0) {
        return dividend / divisor;
    }
    
    return dividend;
}
```

**Miglioramenti:** naming, spacing, documentazione, chiarezza logica

---

# Sessione 5: Testing e progetto finale

**Durata:** 2 ore

## Contenuti

1. **Testing con CTest in CLion** (30 min)
   - Configurare CTest nel CMakeLists.txt
   - Eseguire test dall'IDE
   - Generare test con AI

2. **Mini-progetto** (1h 15min)
   - Piccolo modulo C (es. utilità per stringhe)
   - Pianificare con AI
   - Implementare con supporto AI
   - Testare e documentare
   - Presentare il lavoro

3. **Riflessione e valutazione** (15 min)

---

# Testing con CTest in CLion

## Setup nel CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(MyProject C)

enable_testing()

# Executable principale
add_executable(my_app main.c utils.c)

# Test executable
add_executable(test_utils tests/test_utils.c utils.c)

# Registra i test
add_test(NAME utils_test COMMAND test_utils)
```

## Esecuzione

- CLion rileva automaticamente CTest
- Crea configurazione di run "All Tests"
- Puoi eseguire test singoli o tutti insieme
- I risultati appaiono nella finestra Run

---

# Generare test con AI

## Prompt esempio

```
Data la funzione:

int max2(int a, int b) {
    return a > b ? a : b;
}

Genera:
1. 5 test case usando assert() in C
2. Crea un main() che esegue i test
3. Include casi limite (INT_MAX, INT_MIN, uguali)
4. Registra con CTest

Standard: C11
```

## Il tuo compito

1. **Rivedi** i test generati
2. **Aggiungi** casi mancanti
3. **Compila** ed esegui
4. **Verifica** la copertura

---

# Mini-progetto: String Utilities

## Obiettivo

Creare una piccola libreria di utilità per stringhe in C.

## Funzioni da implementare

1. `trim()` - Rimuove spazi all'inizio e alla fine
2. `to_upper()` - Converte in maiuscolo
3. `count_words()` - Conta le parole
4. `reverse_words()` - Inverte l'ordine delle parole

## Requisiti

- ✅ Usa AI per pianificare l'approccio
- ✅ Genera test prima dell'implementazione (TDD)
- ✅ Implementa con supporto AI
- ✅ Documenta con Doxygen
- ✅ Crea file header (.h) e sorgente (.c) separati
- ✅ Usa CTest per i test

## Tempo

1h 15min

---

# Valutazione del mini-progetto

## Criteri (esempio)

| Criterio | Peso | Descrizione |
|----------|------|-------------|
| **Correttezza** | 40% | Tutti i test passano, copertura dei casi limite |
| **Qualità del codice** | 25% | Warning clang-tidy risolti, naming chiaro |
| **Processo** | 20% | Prompt documentati, iterazioni ragionate |
| **Integrità** | 15% | Uso AI dichiarato, comprensione dimostrata |

## Consegna

- Codice sorgente (.c, .h)
- CMakeLists.txt
- Test
- Documentazione Doxygen
- File README con:
  - Descrizione del progetto
  - Come compilare ed eseguire
  - Quali parti sono state generate con AI
  - Riflessioni sull'uso dell'AI

---

# Quick Reference - Comandi CLion + AI

## Scorciatoie da tastiera

- **Tab**: Accetta completamento inline
- **Esc**: Rifiuta completamento inline
- **Alt+Enter**: Menu azioni contestuali (incluso AI Actions)
- **Ctrl+Shift+A**: Cerca azioni (cerca "AI")

## Finestre

- **AI Assistant**: Tool window laterale per chat
- **Run**: Risultati test e compilazione
- **Problems**: Warning ed errori (clang-tidy)

## Impostazioni chiave

- **Settings → Tools → AI Assistant**: Configurazione principale
- **Settings → Editor → Inline Completion**: Completamento automatico
- **Settings → Editor → Inspections → Clang-Tidy**: Analisi statica

---

# Prompt pronti all'uso

Copia e personalizza questi prompt:

## 1. Spiegazione

```
Spiega questa funzione C in termini semplici e 
proponi 3 test che potrebbero fallire:

[codice]
```

## 2. Generazione

```
Genera una funzione C median(int[], size_t) con:
- Comportamento stabile per lunghezze pari
- Test CTest
- Documentazione Doxygen
Standard: C11
```

## 3. Refactoring

```
Refactoring: elimina stato globale, migliora naming.
Mantieni comportamento. Mostra solo il diff.

[codice]
```

## 4. Documentazione

```
Aggiungi documentazione Doxygen e sezione README 
che spiega la complessità computazionale.

[codice]
```

---

# Best practices per l'uso dell'AI

## ✅ Fare

1. **Inizia con prompt specifici** - Più dettagli = risultati migliori
2. **Itera gradualmente** - Piccoli miglioramenti incrementali
3. **Verifica sempre** - Compila, testa, rivedi
4. **Usa per apprendere** - Chiedi spiegazioni, non solo codice
5. **Documenta l'uso** - Traccia cosa hai chiesto e perché
6. **Combina con strumenti** - clang-tidy, sanitizers, debugger

## ❌ Evitare

1. **Fidarsi ciecamente** - L'AI può sbagliare
2. **Prompt vaghi** - "scrivi codice" non funziona
3. **Copiare senza capire** - Devi comprendere ogni riga
4. **Ignorare la privacy** - No credenziali o dati sensibili
5. **Saltare i test** - Verifica sempre il codice generato

---

# Risorse aggiuntive

## Documentazione ufficiale

- **JetBrains AI Assistant Documentation**
  - https://www.jetbrains.com/help/idea/ai-assistant.html

- **CLion Documentation**
  - https://www.jetbrains.com/help/clion/

- **CTest Documentation**
  - https://cmake.org/cmake/help/latest/manual/ctest.1.html

## Tutorial e guide

- **JetBrains AI Assistant Guide**
  - Prompt patterns e best practices

- **Clang-Tidy Checks**
  - https://clang.llvm.org/extra/clang-tidy/checks/list.html

---

# Prossimi passi

## Dopo questo modulo

1. **Pratica costante**
   - Usa AI nei tuoi progetti personali
   - Sperimenta con prompt diversi
   - Confronta risultati con e senza AI

2. **Approfondisci**
   - Studia pattern di prompt avanzati
   - Esplora modelli locali per privacy
   - Integra con altri strumenti (sanitizers, profilers)

3. **Condividi**
   - Discuti best practices con i compagni
   - Contribuisci a progetti open source
   - Documenta le tue scoperte

## Preparazione alla prossima sessione

- Installa CLion e AI Assistant prima della Sessione 2
- Porta un piccolo progetto C da testare con CTest
- Pensa a domande specifiche sull'uso dell'AI nello sviluppo

---

# ✅ Checklist dello studente

## Installazione e configurazione

- [ ] Ho installato JetBrains AI Assistant in CLion
- [ ] Ho effettuato il login con credenziali JetBrains
- [ ] Ho verificato che AI Chat e completamento inline funzionino
- [ ] Ho configurato le preferenze di privacy

## Uso di base

- [ ] So aprire AI Chat e fare domande
- [ ] So accettare/rifiutare suggerimenti inline
- [ ] So usare Alt+Enter → AI Actions sul codice selezionato
- [ ] Ho provato "Explain Code" su una funzione

## Prompt efficaci

- [ ] So scrivere un prompt con contesto, task e vincoli
- [ ] Ho generato almeno una funzione da zero con AI
- [ ] Ho iterato un prompt per migliorare il risultato
- [ ] Ho confrontato prompt vago vs prompt specifico

---

# ✅ Checklist dello studente (continua)

## Debugging e refactoring

- [ ] Ho usato AI per identificare bug in codice
- [ ] Ho fatto refactoring di una funzione con AI
- [ ] Ho verificato manualmente il codice refactorato
- [ ] Ho compreso i miglioramenti suggeriti dall'AI

## Test e qualità

- [ ] Ho generato test con AI per una mia funzione
- [ ] Ho compilato ed eseguito i test generati
- [ ] Ho corretto test falliti con aiuto AI
- [ ] Ho documentato codice con Doxygen + AI

## Uso responsabile

- [ ] Ho verificato ogni suggerimento AI prima di accettarlo
- [ ] Non ho condiviso dati sensibili con l'AI
- [ ] Ho citato l'AI quando ho usato codice generato
- [ ] Capisco i limiti dell'AI e quando non fidarmi

---

# Riepilogo del modulo

## Cosa abbiamo imparato

- ✅ Come funzionano gli LLM e i loro limiti
- ✅ Configurare e usare JetBrains AI Assistant in CLion
- ✅ Scrivere prompt efficaci per generare codice C
- ✅ Usare AI per debugging e refactoring
- ✅ Generare e gestire test con CTest
- ✅ Pratiche responsabili: privacy e integrità

## Punti chiave

**L'AI è un potente strumento di supporto, ma:**

- Non sostituisce la comprensione
- Richiede verifica critica
- Deve essere usato responsabilmente
- È più efficace con prompt chiari
- Migliora con la pratica

**Tu rimani sempre il programmatore responsabile!**

---
layout: center
---

# Domande?

**Contatti:**

Ing. Giancarlo Degani

Per dubbi o approfondimenti sul modulo AI, contattami via email o durante le ore di ricevimento.

---
layout: center
---

# Buon lavoro con l'AI!

Ricorda: l'intelligenza artificiale è uno strumento potente,
ma la **vera intelligenza** è la tua.

Usa l'AI per **amplificare** le tue capacità,
non per **sostituire** il tuo pensiero critico.
