---
layout: cover
transition:
coverDate:

---

# 5 - Funzioni, puntatori e progetti multi-file

Ing. Giancarlo Degani

---

# Funzioni in C

## Perché usare le funzioni?

- **Riutilizzo** del codice
- **Modularità**: dividere problemi complessi in parti più semplici
- **Leggibilità**: codice più chiaro e organizzato
- **Manutenibilità**: più facile correggere e aggiornare

---

## Struttura di un programma C

```c
#include <stdio.h>

// Funzioni ausiliarie
int somma(int a, int b) {
    return a + b;
}

// Funzione principale
int main(void) {
    int risultato = somma(5, 3);
    printf("Risultato: %d\n", risultato);
    return 0;
}
```

---

# Dichiarazione vs Definizione

## Dichiarazione (prototipo)

Indica al compilatore **come** chiamare la funzione (firma):

```c
float area_triangolo(float base, float altezza);
```

## Definizione

Fornisce il **corpo** della funzione (implementazione):

```c
float area_triangolo(float base, float altezza) {
    return base * altezza / 2.0f;
}
```

## Regola

Una funzione deve essere **dichiarata o definita** prima di essere chiamata

---

# Esempio: dichiarazione e definizione

```c
#include <stdio.h>

// Dichiarazioni (prototipi) all'inizio
int somma(int a, int b);
int sottrazione(int a, int b);
int moltiplicazione(int a, int b);

int main(void) {
    printf("5 + 3 = %d\n", somma(5, 3));
    printf("5 - 3 = %d\n", sottrazione(5, 3));
    printf("5 * 3 = %d\n", moltiplicazione(5, 3));
    return 0;
}

// Definizioni dopo il main
int somma(int a, int b) {
    return a + b;
}

int sottrazione(int a, int b) {
    return a - b;
}

int moltiplicazione(int a, int b) {
    return a * b;
}
```

---

# Componenti di una funzione

```c
tipo_ritorno nome_funzione(tipo_param1 param1, tipo_param2 param2) {
    // Corpo della funzione
    return valore;  // Opzionale per void
}
```

| Componente | Descrizione |
|------------|-------------|
| **tipo_ritorno** | Tipo del valore restituito (`int`, `float`, `void`, ecc.) |
| **nome_funzione** | Identificatore della funzione |
| **parametri** | Lista di input (può essere vuota) |
| **corpo** | Blocco di istruzioni |
| **return** | Valore restituito (obbligatorio se tipo_ritorno ≠ void) |

---

# Chiamata di funzione

```c
#include <stdio.h>

int quadrato(int n) {
    return n * n;
}

int main(void) {
    int x = 5;
    int risultato = quadrato(x);  // Chiamata alla funzione
    
    printf("Il quadrato di %d è %d\n", x, risultato);
    // Output: Il quadrato di 5 è 25
    
    // Chiamata diretta in printf
    printf("Il quadrato di 7 è %d\n", quadrato(7));
    // Output: Il quadrato di 7 è 49
    
    return 0;
}
```

## Nota

- Il chiamante si **ferma** finché la funzione non termina
- Il **valore di ritorno** può essere usato direttamente

---
layout: two-cols

---
# Variabili locali

Le variabili dichiarate dentro una funzione sono **locali**:

```c
#include <stdio.h>

void funzione_a(void) {
    int x = 10;  // x locale a funzione_a
    printf("funzione_a: x = %d\n", x);
}

void funzione_b(void) {
    int x = 20;  // x locale a funzione_b (diversa dalla x di funzione_a)
    printf("funzione_b: x = %d\n", x);
}

int main(void) {
    int x = 5;   // x locale a main
    
    printf("main: x = %d\n", x);
    funzione_a();
    funzione_b();
    printf("main: x = %d\n", x);  // x di main non è cambiato
    
    return 0;
}
```

::right::

**Output:**

```text
main: x = 5
funzione_a: x = 10
funzione_b: x = 20
main: x = 5
```

---
layout: two-cols

---

# Passaggio per valore

In C, i parametri sono passati **per valore** (copia):

```c
#include <stdio.h>

void incrementa(int n) {
    n = n + 1;  // Modifica la COPIA di n
    printf("Dentro la funzione: n = %d\n", n);
}

int main(void) {
    int x = 5;
    
    printf("Prima: x = %d\n", x);
    incrementa(x);
    printf("Dopo: x = %d\n", x);  // x NON è cambiato!
    
    return 0;
}
```

::right::

**Output:**

```text
Prima: x = 5
Dentro la funzione: n = 6
Dopo: x = 5
```

La funzione modifica solo la **copia** del parametro, non l'originale!

---

# Introduzione ai Puntatori

Un **puntatore** è una variabile che memorizza l'**indirizzo di memoria** di un'altra variabile.

## Concetti chiave

**Indirizzo di memoria**: Ogni variabile è memorizzata a un indirizzo in RAM
- Operatore `&`: ottiene l'indirizzo di una variabile
- Operatore `*`: accede al valore memorizzato a un indirizzo (dereferenzazione)

## Dichiarazione di un puntatore

```c
int *ptr;        // ptr è un puntatore a un intero
char *ptr_char;  // puntatore a un carattere
```

---

# Introduzione ai Puntatori

## Esempio base

```c
int x = 10;
int *ptr = &x;   // ptr memorizza l'indirizzo di x

printf("Valore di x: %d\n", x);        // Output: 10
printf("Indirizzo di x: %p\n", &x);    // Output: 0x7fff5fbff8ac (esempio)
printf("Valore puntato: %d\n", *ptr);  // Output: 10
```

---

# Modificare variabili esterne: puntatori

Per modificare una variabile del chiamante, usa i **puntatori**:

```c
#include <stdio.h>

void incrementa(int *n) {
    *n = *n + 1;  // Modifica il valore puntato
}

int main(void) {
    int x = 5;
    
    printf("Prima: x = %d\n", x);
    incrementa(&x);  // Passa l'indirizzo di x
    printf("Dopo: x = %d\n", x);  // x è cambiato!
    
    return 0;
}
```

**Output:**

```
Prima: x = 5
Dopo: x = 6
```

---

# Esempio: scambio di valori

```c
#include <stdio.h>

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 10, y = 20;
    
    printf("Prima: x = %d, y = %d\n", x, y);
    scambia(&x, &y);
    printf("Dopo: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

**Output:**

```
Prima: x = 10, y = 20
Dopo: x = 20, y = 10
```

---
layout: two-cols

---

# Array come parametri

Gli array sono sempre passati **per riferimento** (come puntatori):

```c
#include <stdio.h>

void stampa_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void moltiplica_per_2(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifica l'array originale!
    }
}
```

::right::

```c
int main(void) {
    int numeri[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Originale: ");
    stampa_array(numeri, size);
    
    moltiplica_per_2(numeri, size);
    
    printf("Modificato: ");
    stampa_array(numeri, size);
    
    return 0;
}
```

---
layout: two-cols

---

# Void Functions

Functions with `void` return type do not return any value:

```c
#include <stdio.h>

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

void print_line(void) {
    printf("====================\n");
}

int main(void) {
    print_line();
    greet("Mario");
    greet("Luigi");
    print_line();
    
    return 0;
}
```

::right::
**Output:**

```text
====================
Hello, Mario!
Hello, Luigi!
====================
```

---

# Progetti multi-file

Per progetti grandi, dividere il codice in più file:

## File header (utility.h)

```c
#ifndef UTILITY_H
#define UTILITY_H

int max(int a, int b);
int min(int a, int b);

#endif
```

## File sorgente (utility.c)

```c
#include "utility.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
```

---

# Multi-file Projects: Usage

## Main file (main.c)

```c
#include <stdio.h>
#include "utility.h"

int main(void) {
    int a = 10, b = 20;
    
    printf("Maximum of %d and %d: %d\n", a, b, max(a, b));
    printf("Minimum of %d and %d: %d\n", a, b, min(a, b));
    
    return 0;
}
```

## Compilation

```bash
gcc -c utility.c -o utility.o
gcc -c main.c -o main.o
gcc utility.o main.o -o program
```

Or in a single command:

```bash
gcc main.c utility.c -o program
```

---

# Include guards

Gli **include guards** prevengono inclusioni multiple:

```c
#ifndef NOME_FILE_H
#define NOME_FILE_H

// Dichiarazioni...

#endif
```

## Perché sono necessari?

Senza include guards, includere lo stesso file più volte causa errori di ridefinizione.

## Esempio

```c
// config.h
#ifndef CONFIG_H
#define CONFIG_H

#define MAX_SIZE 100
typedef struct { int x, y; } Point;

#endif
```

---

# Header files (.h) vs Implementation (.c)

Un programma C è solitamente diviso in due tipi di file:

## File Header (.h\)

- Contiene **dichiarazioni**: firme di funzioni, definizioni di strutture, costanti
- Specifica "cosa" fa una funzione, non "come"
- Incluso con `#include` in altri file

## File Implementation (.c)

- Contiene **definizioni**: il codice effettivo delle funzioni
- Specifica "come" è implementata una funzione
- Viene compilato in un file oggetto (.o)

---
layout: two-cols

---

# Esempio: math_utils

## math_utils.h (Header)

```c
// Declaration: what the function does
int add(int a, int b);
int multiply(int a, int b);
```

## math_utils.c (Implementation)

```c
#include "math_utils.h"

// Definition: how it works
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

::right::

## main.c (Usage)

```c
#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int result = add(5, 3);
    printf("Result: %d\n", result);
    return 0;
}
```

## Compilazione

```bash
gcc -c math_utils.c -o math_utils.o
gcc -c main.c -o main.o
gcc math_utils.o main.o -o program
```

---

# Errori di compilazione vs Errori di linking

È importante distinguere tra i due tipi di errori per debuggare efficacemente:

**Errori di Compilazione** (Compile-time errors)

- Si verificano durante la fase di compilazione (`.c` → `.o`)
- Causati da: sintassi errata, tipi incompatibili, variabili non dichiarate
- Esempio: `int x = "hello";` (tipo sbagliato)

**Errori di Linking** (Link-time errors)

- Si verificano durante la fase di linking (`.o` + librerie → eseguibile)
- Causati da: funzioni dichiarate ma non definite, librerie mancanti
- Esempio: funzione `int add(int, int);` dichiarata ma mai implementata

---
layout: two-cols

---

# Esempio: Errore di Compilazione

```c
// main.c
#include <stdio.h>

int main(void) {
    int x = 5;
    int y = "hello";  // ❌ Errore!
    
    printf("%d\n", x + y);
    return 0;
}
```

**Output del compilatore:**

```txt
main.c:5:13: error: incompatible 
types when initializing type 'int' 
using type 'char *'
    int y = "hello";
            ^
```

::right::

# Esempio: Errore di Linking

```c
// main.c
#include <stdio.h>

// Dichiarazione
int add(int a, int b);

int main(void) {
    int result = add(5, 3);
    printf("%d\n", result);
    return 0;
}

// ❌ Manca la definizione!
```

**Output del linker:**

```txt
undefined reference to `add'
collect2: error: ld returned 
1 exit status
```

---

# Come riconoscere gli errori

| Fase | Quando | Messaggio tipico | Soluzione |
|------|--------|------------------|-----------|
| **Preprocessore** | Prima della compilazione | `fatal error: file.h: No such file` | Verifica percorsi `#include` |
| **Compilazione** | Creazione file `.o` | `error: expected ';'`<br>`error: undeclared identifier` | Correggi sintassi e dichiarazioni |
| **Linking** | Creazione eseguibile | `undefined reference to 'func'`<br>`multiple definition of 'var'` | Implementa funzioni mancanti<br>Rimuovi definizioni duplicate |

---

# Le fasi dettagliate della compilazione

La compilazione è un processo multi-fase che trasforma il codice sorgente in codice macchina:

```mermaid {scale: 0.7, alt: 'Detailed compilation phases flowchart showing transformation from source C file through preprocessing, compilation to assembly, assembling to object code, and linking to executable'}
flowchart LR
    A[Source .c] -->|Preprocessor| B[Preprocessed .i]
    B -->|Compiler| C[Assembly .s/.asm]
    C -->|Assembler| D[Object .o]
    D -->|Linker| E[Executable]
```

**1. Preprocessore** → Espande macro, include header, rimuove commenti  
**2. Compilatore** → Traduce C in assembly (linguaggio mnemonico CPU)  
**3. Assemblatore** → Converte assembly in codice oggetto binario  
**4. Linker** → Collega file oggetto e librerie → eseguibile finale

---
layout: two-cols

---

# Fase 1: Preprocessing

Comando:

```sh
gcc -E hello.c -o hello.i
```

**Cosa fa:**

- Espande le direttive `#include`
- Processa le macro `#define`
- Rimuove i commenti
- Gestisce `#ifdef`, `#ifndef`

::right::

**Output:** File `.i` (codice C espanso)

<<< @/snippets/example02/main.i#snippet c {all}{lines:true}

---
layout: two-cols

---

# Fase 2: Compilazione → Assembly

Comando:

```sh
gcc -S hello.i -o hello.asm
```

**Cosa fa:**

- Analizza sintassi e semantica del C
- Ottimizza il codice
- Traduce in linguaggio assembly (mnemonico per CPU)

**Output:** File `.s`/`.asm` (assembly leggibile)

::right::

<<< @/snippets/example02/main.asm c {all}{lines:true}

---

# Fase 3: Assemblaggio

Comando:

```sh
gcc -c hello.c -o hello.o
```

oppure (da assembly):

```sh
as hello.asm -o hello.o
```

**Cosa fa:**

- Converte istruzioni assembly in codice binario (opcodes)
- Crea la tabella dei simboli (funzioni, variabili globali)
- Produce codice **relocatable** (indirizzi non ancora definitivi)

**Output:** File `.o` (binario non eseguibile, mancano i link)

---

# Fase 4: Linking

Comando:

```sh
gcc hello.o -o hello
```

**Cosa fa:**

- **Risolve i simboli esterni:** collega chiamate a funzioni (`printf`, librerie)
- **Rialloca indirizzi:** assegna indirizzi di memoria definitivi
- **Collega librerie:** include codice da librerie statiche o riferimenti a dinamiche
- **Crea l'entry point:** definisce dove inizia l'esecuzione (`_start` → `main`)

**Output:** File eseguibile (`a.out`, `hello.exe`)

---

# Build systems: automatizzare la compilazione

Compilare manualmente ogni file è impraticabile per progetti con molti file.  
I **build systems** automatizzano il processo:

## Make (1976)

- Usa file `Makefile` con regole di dipendenza
- Ricompila solo i file modificati
- Standard su Unix/Linux

## CMake (2000)

- Genera `Makefile` (o progetti IDE) da `CMakeLists.txt`
- Multipiattaforma (Windows, Linux, macOS)
- Usato da CLion e molti progetti moderni

---
layout: two-cols

---

# Make: esempio di Makefile

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

# Targets
all: program

program: main.o utils.o
 $(CC) $(CFLAGS) -o program main.o utils.o

main.o: main.c utils.h
 $(CC) $(CFLAGS) -c main.c

utils.o: utils.c utils.h
 $(CC) $(CFLAGS) -c utils.c

clean:
 rm -f *.o program
```

::right::

**Come funziona:**

```sh
# Compila tutto
make

# Ricompila solo se modificato
make

# Pulisce i file generati
make clean
```

**Regola di dipendenza:**

```makefile
target: dependencies
 command
```

- Se `dependencies` cambiano, `command` viene eseguito
- Make calcola automaticamente cosa ricompilare

---
layout: two-cols

---

# CMake: esempio di CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.28)
project(MyProgram C)

# Imposta lo standard C11
set(CMAKE_C_STANDARD 11)

# Aggiungi flag di warning
add_compile_options(-Wall -Wextra)

# Crea eseguibile da più file
add_executable(program 
    main.c 
    utils.c
)

# Collega libreria math (opzionale)
target_link_libraries(program m)
```

::right::

**Come usare CMake:**

```sh
# 1. Crea cartella build
mkdir build && cd build

# 2. Configura (genera Makefile)
cmake ..

# 3. Compila
cmake --build .

# 4. Esegui
./program
```

**Vantaggi:**

- Astrae dal sistema (genera Makefile, Visual Studio, Xcode...)
- CLion usa CMake per gestire progetti C
- Più facile da leggere rispetto a Makefile complessi

---

# CMakeLists.txt: struttura tipica

```cmake
# Versione minima di CMake richiesta
cmake_minimum_required(VERSION 3.28)

# Nome del progetto e linguaggio
project(MyApp C)

# Standard C (11, 99, ecc.)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Flag del compilatore (warning, ottimizzazioni)
add_compile_options(-Wall -Wextra -Wpedantic)

# Definisci l'eseguibile e i file sorgente
add_executable(my_app
    src/main.c
    src/module1.c
    src/module2.c
)

# Includi directory per header files
target_include_directories(my_app PRIVATE include)
# Collega librerie (esempio: libreria matematica)
target_link_libraries(my_app m)
```

---
layout: two-cols

---

# CMakeLists.txt: struttura nel nostro progetto

Ogni esempio in `snippets/exampleNN/` usa questa struttura:

<<< @/snippets/example01/CMakeLists.txt cmake {all}{lines:true}

::right::

**Come CLion usa CMake:**

1. Apri `snippets/example01/` in CLion
2. CLion rileva automaticamente `CMakeLists.txt`
3. Click su ▶️ per compilare ed eseguire
4. CLion esegue dietro le quinte:
   - `cmake ..` → genera Makefile
   - `make` → compila il programma
   - `./example01` → esegue

**Ogni esempio è indipendente** e può essere compilato separatamente.

---

# Librerie

- In un linguaggio ad alto livello le funzioni di base sono fornite dal linguaggio ( lettura da tastiera, scrittura su schermo, lettura/scrittura da file)
- Queste operazioni elementari sono disponibili sotto forma di funzioni
- Le funzioni sono raccolte e distribuite sotto forma di librerie

---
layout: two-cols

---

# Librerie statiche

Nella creazione del programma eseguibile, il codice oggetto e le librerie vengono uniti (collegati) a formare un unico file binario.

::right::

```mermaid {scale: 0.9, alt: 'Diagram showing static library code being linked and copied into a single executable program at compile time'}
flowchart TB
    subgraph Programma1
    direction TB
    a1[Codice oggetto]<-.->a2[Libreria statica]
    end
```

---
layout: two-cols

---

# Librerie statiche

Le librerie statiche vengono incluse in ogni programma che le usa:

- Spreco di memoria
- Manutenzione onerosa

::right::

```mermaid {scale: 0.9, alt: 'Diagram showing two separate programs each containing their own copy of the same static library, resulting in memory duplication'}
flowchart TB
    subgraph Programma2
    direction TB
    a1[Codice oggetto]<-.->a2[Libreria statica]
    end
    subgraph Programma1
    direction TB
    a3[Codice oggetto]<-.->a4[Libreria statica]
    end
```

---
layout: two-cols

---

# Librerie dinamiche

- Nella creazione del programma eseguibile le librerie vengono referenziate, non incluse
- La libreria viene caricata in memoria al momento dell'esecuzione
- La libreria può essere condivisa da più programmi eseguibili
- Manutenzione semplificata

::right::

```mermaid {scale: 0.9, alt: 'Diagram showing multiple programs sharing a single dynamic library loaded in system memory at runtime, avoiding duplication'}
flowchart TB

    subgraph Programma2
    direction TB
    a1[Codice oggetto]
    end

    subgraph Programma1
    direction TB
    a3[Codice oggetto]
    end

    subgraph Sistema
    direction TB
    a5[Librerie dinamica]
    end

    a1<-.->a5
    a3<-.->a5
```

---

# Esercizio 1: Funzione potenza

Scrivi una funzione che calcola la potenza di un numero:

```c
int potenza(int base, int esponente);
```

**Requisiti:**

- Calcola `base^esponente` usando un ciclo
- Gestisci il caso esponente = 0 (risultato = 1)
- Testa con: `potenza(2, 3)` → 8, `potenza(5, 0)` → 1

**Esempio:**

```c
int main(void) {
    printf("2^3 = %d\n", potenza(2, 3));
    printf("5^0 = %d\n", potenza(5, 0));
    printf("3^4 = %d\n", potenza(3, 4));
    return 0;
}
```

---

# Esercizio 2: Funzione media

Scrivi una funzione che calcola la media di un array:

```c
float media(int arr[], int size);
```

**Requisiti:**

- Somma tutti gli elementi dell'array
- Dividi per il numero di elementi
- Restituisci il risultato come `float`

**Esempio:**

```c
int main(void) {
    int voti[] = {18, 24, 30, 27, 22};
    float m = media(voti, 5);
    printf("Media voti: %.2f\n", m);  // Output: 24.20
    return 0;
}
```

---

# Esercizio 3: Validazione con enum

Crea un sistema di validazione età usando enum:

```c
typedef enum {
    MINORE,
    ADULTO,
    ANZIANO
} CategoriaEta;

CategoriaEta classifica_eta(int anni);
```

**Requisiti:**

- MINORE: età < 18
- ADULTO: 18 ≤ età < 65
- ANZIANO: età ≥ 65

**Bonus:** Usa switch per stampare un messaggio appropriato

---

# Riepilogo

## Enumerazioni

- Definiscono insiemi di costanti intere con nomi significativi
- Migliorano la leggibilità del codice
- Funzionano bene con `switch`
- `typedef` semplifica l'uso

## Funzioni

- Dichiarazione (prototipo) vs Definizione (implementazione)
- Passaggio per valore (copia) vs passaggio per riferimento (puntatori)
- Array sempre passati per riferimento
- Progetti multi-file usano header (.h) e sorgenti (.c)
- Include guards prevengono inclusioni multiple

---

# Best practices

## Funzioni

1. **Una funzione = un compito specifico** - funzioni brevi e focalizzate
2. **Nomi descrittivi** - `calcola_area()` meglio di `calc()`
3. **Documentazione** - commenta cosa fa la funzione, non come
4. **Limita i parametri** - massimo 4-5 parametri per leggibilità
5. **Usa const** per parametri che non devono essere modificati

## Enum

1. **Nomi in MAIUSCOLO** per i valori
2. **typedef** per tipi usati frequentemente
3. **Valori espliciti** quando il valore numerico è importante
4. **Commenti** per chiarire significati non ovvi
