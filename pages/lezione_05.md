---
layout: cover
transition:
coverDate:

---

# 5 - Funzioni, puntatori e progetti multi-file

Ing. Giancarlo Degani

---
level: 2

---

# Funzioni in C

## Perché usare le funzioni?

- **Riutilizzo** del codice
- **Modularità**: dividere problemi complessi in parti più semplici
- **Leggibilità**: codice più chiaro e organizzato
- **Manutenibilità**: più facile correggere e aggiornare

---
level: 2

---

## Struttura di un programma C

```c
#include <stdio.h>

// Helper functions
int add(int a, int b) {
    return a + b;
}

// Main function
int main(void) {
    int result = add(5, 3);
    printf("Result: %d\n", result);
    return 0;
}
```

---
level: 2

---

# Dichiarazione vs Definizione

## Dichiarazione (prototipo)

Indica al compilatore **come** chiamare la funzione (firma):

```c
float triangle_area(float base, float height);
```

## Definizione

Fornisce il **corpo** della funzione (implementazione):

```c
float triangle_area(float base, float height) {
    return base * height / 2.0f;
}
```

## Regola

Una funzione deve essere **dichiarata o definita** prima di essere chiamata

---
level: 2

---

# Esempio: dichiarazione e definizione

```c
#include <stdio.h>

// Declarations (prototypes) at the top
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main(void) {
    printf("5 + 3 = %d\n", add(5, 3));
    printf("5 - 3 = %d\n", subtract(5, 3));
    printf("5 * 3 = %d\n", multiply(5, 3));
    return 0;
}

// Definitions after main
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}
```

---
level: 2

---

# Componenti di una funzione

```c
return_type function_name(param_type1 param1, param_type2 param2) {
    // Function body
    return value;  // Optional for void
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
level: 2

---

# Chiamata di funzione

```c
#include <stdio.h>

int square(int n) {
    return n * n;
}

int main(void) {
    int x = 5;
    int result = square(x);  // Function call
    
    printf("The square of %d is %d\n", x, result);
    // Output: The square of 5 is 25
    
    // Direct call inside printf
    printf("The square of 7 is %d\n", square(7));
    // Output: The square of 7 is 49
    
    return 0;
}
```

## Nota

- Il chiamante si **ferma** finché la funzione non termina
- Il **valore di ritorno** può essere usato direttamente

---
layout: two-cols
level: 2

---

# Variabili locali

Le variabili dichiarate dentro una funzione sono **locali**:

```c
#include <stdio.h>

void function_a(void) {
    int x = 10;  // x local to function_a
    printf("function_a: x = %d\n", x);
}

void function_b(void) {
    int x = 20;  // x local to function_b (different from the x of function_a)
    printf("function_b: x = %d\n", x);
}

int main(void) {
    int x = 5;   // x local to main
    
    printf("main: x = %d\n", x);
    function_a();
    function_b();
    printf("main: x = %d\n", x);  // the x of main has not changed
    
    return 0;
}
```

::right::

**Output:**

```text
main: x = 5
function_a: x = 10
function_b: x = 20
main: x = 5
```

---
layout: two-cols
level: 2

---

# Passaggio per valore

In C, i parametri sono passati **per valore** (copia):

```c
#include <stdio.h>

void increment(int n) {
    n = n + 1;  // Changes the COPY of n
    printf("Inside the function: n = %d\n", n);
}

int main(void) {
    int x = 5;
    
    printf("Before: x = %d\n", x);
    increment(x);
    printf("After: x = %d\n", x);  // x has NOT changed!
    
    return 0;
}
```

::right::

**Output:**

```text
Before: x = 5
Inside the function: n = 6
After: x = 5
```

La funzione modifica solo la **copia** del parametro, non l'originale!

---
level: 2

---

# Introduzione ai Puntatori

Un **puntatore** è una variabile che memorizza l'**indirizzo di memoria** di un'altra variabile.

## Concetti chiave

**Indirizzo di memoria**: Ogni variabile è memorizzata a un indirizzo in RAM

- Operatore `&`: ottiene l'indirizzo di una variabile
- Operatore `*`: accede al valore memorizzato a un indirizzo (dereferenzazione)

## Dichiarazione di un puntatore

```c
int *ptr;        // ptr is a pointer to an int
char *ptr_char;  // pointer to a char
```

---
level: 2

---

# Introduzione ai Puntatori

## Esempio base

```c
int x = 10;
int *ptr = &x;   // ptr stores the address of x

printf("Value of x: %d\n", x);        // Output: 10
printf("Address of x: %p\n", &x);    // Output: 0x7fff5fbff8ac (example)
printf("Pointed value: %d\n", *ptr);  // Output: 10
```

---
level: 2

---

# Modificare variabili esterne: puntatori

Per modificare una variabile del chiamante, usa i **puntatori**:

```c
#include <stdio.h>

void increment(int *n) {
    *n = *n + 1;  // Changes the pointed value
}

int main(void) {
    int x = 5;
    
    printf("Before: x = %d\n", x);
    increment(&x);  // Passes the address of x
    printf("After: x = %d\n", x);  // x has changed!
    
    return 0;
}
```

**Output:**

```text
Before: x = 5
After: x = 6
```

---
level: 2

---

# Esempio: scambio di valori

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 10, y = 20;
    
    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

**Output:**

```text
Before: x = 10, y = 20
After: x = 20, y = 10
```

---
layout: two-cols
level: 2

---

# Array come parametri

Gli array sono sempre passati **per riferimento** (come puntatori):

```c
#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void multiply_by_2(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Changes the original array!
    }
}
```

::right::

```c
int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Original: ");
    print_array(numbers, size);
    
    multiply_by_2(numbers, size);
    
    printf("Modified: ");
    print_array(numbers, size);
    
    return 0;
}
```

---
layout: two-cols
level: 2

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
level: 2

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
level: 2

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
level: 2

---

# Include guards

Gli **include guards** prevengono inclusioni multiple:

```c
#ifndef FILE_NAME_H
#define FILE_NAME_H

// Declarations...

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
level: 2

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
level: 2

---

# Esempio: Errore di Compilazione

```c
// main.c
#include <stdio.h>

int main(void) {
    int x = 5;
    int y = "hello";  // ❌ Error!
    
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

// Declaration
int add(int a, int b);

int main(void) {
    int result = add(5, 3);
    printf("%d\n", result);
    return 0;
}

// ❌ The definition is missing!
```

**Output del linker:**

```txt
undefined reference to `add'
collect2: error: ld returned 
1 exit status
```

---
level: 2

---

# Come riconoscere gli errori

| Fase | Quando | Messaggio tipico | Soluzione |
|------|--------|------------------|-----------|
| **Preprocessore** | Prima della compilazione | `fatal error: file.h: No such file` | Verifica percorsi `#include` |
| **Compilazione** | Creazione file `.o` | `error: expected ';'`<br>`error: undeclared identifier` | Correggi sintassi e dichiarazioni |
| **Linking** | Creazione eseguibile | `undefined reference to 'func'`<br>`multiple definition of 'var'` | Implementa funzioni mancanti<br>Rimuovi definizioni duplicate |

---
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

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
level: 2

---

# Test automatici: perché

Finora abbiamo controllato i programmi **a mano**: eseguirli, guardare l'output, confrontarlo con quello atteso. Con molte funzioni diventa lento e si dimentica qualcosa.

Un **test automatico** è un piccolo programma che:

1. chiama una funzione con **valori noti**
2. confronta il risultato con quello **atteso**
3. segnala l'errore se i due valori sono diversi

```mermaid {scale: 0.8, alt: 'Test flow: known input to function, result compared with expected value'}
flowchart LR
    A[/Valori noti/] --> B[Funzione da testare]
    B --> C{Uguale all'atteso?}
    C -->|Sì| D([Test superato])
    C -->|No| E([Test fallito])
```

Ogni volta che si modifica il codice si rilanciano i test: se qualcosa si è rotto, lo si scopre subito.

---
level: 2

---

# assert

`assert` (da `assert.h`) controlla una condizione: se è vera il programma continua, se è falsa **si ferma** indicando condizione, file e riga.

```c
#include <assert.h>

int main(void) {
    assert(2 + 2 == 4);   // true: the program continues
    assert(2 + 2 == 5);   // false: the program stops here
    return 0;
}
```

- Un test fallito si nota perché il programma termina con un errore
- Il primo `assert` fallito interrompe il programma: gli altri non vengono eseguiti
- Con la compilazione in modalità *Release* gli `assert` vengono disattivati: i test si eseguono in *Debug*

---
layout: two-cols
level: 2

---

# La funzione da testare

Il modulo `sensor` converte la lettura di un sensore e controlla una soglia.

Sono **funzioni pure**: dato lo stesso ingresso restituiscono sempre lo stesso risultato, senza leggere dalla tastiera né stampare. Per questo sono facili da testare.

::right::

<<< @/snippets/example34/sensor.h c {*}{lines:true}

<<< @/snippets/example34/sensor.c c {*}{lines:true}

---
level: 2

---

# Esempio: il file di test

<<< @/snippets/example34/test_sensor.c c {*}{lines:true}

- Si testano i **valori noti** e i **casi limite**: il minimo, il massimo e il valore esattamente sulla soglia
- `main` restituisce `0` se tutti gli `assert` passano

---
layout: two-cols
level: 2

---

# CTest: eseguire i test

Due righe in `CMakeLists.txt` registrano il test; `ctest` lo esegue.

```sh
ctest
```

```text
1/1 Test #1: sensor ......   Passed
100% tests passed, 0 tests failed out of 1
```

Se un `assert` fallisce, `ctest` segnala il test come **Failed**. In CLion si usa la configurazione *All CTest*, che mostra i risultati in un pannello dedicato.

::right::

<<< @/snippets/example34/CMakeLists.txt cmake {*}{lines:true}

---
level: 2

---

# Esercizio in coppia: scrivere prima i test

Il *navigator* scrive i test (compresi i casi limite) **prima** che il *driver* scriva la funzione.

- **Base:** aggiungere a `test_sensor.c` un test per un valore intermedio di `adc_to_celsius` (per esempio `2048`)
- **Standard:** scrivere `is_in_range(value, min, max)` con almeno quattro test, bordi compresi
- **Sfida:** scrivere `average(const double *values, int n)` e decidere, con un test, che cosa restituire se `n` è 0

---
level: 2

---

# Librerie

- In un linguaggio ad alto livello le funzioni di base sono fornite dal linguaggio ( lettura da tastiera, scrittura su schermo, lettura/scrittura da file)
- Queste operazioni elementari sono disponibili sotto forma di funzioni
- Le funzioni sono raccolte e distribuite sotto forma di librerie

---
layout: two-cols
level: 2

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
level: 2

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
level: 2

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
level: 2

---

# Esercizio 1: Funzione potenza

Scrivi una funzione che calcola la potenza di un numero:

```c
int power(int base, int exponent);
```

**Requisiti:**

- Calcola `base^exponent` usando un ciclo
- Gestisci il caso esponente = 0 (risultato = 1)
- Testa con: `power(2, 3)` → 8, `power(5, 0)` → 1

**Esempio:**

```c
int main(void) {
    printf("2^3 = %d\n", power(2, 3));
    printf("5^0 = %d\n", power(5, 0));
    printf("3^4 = %d\n", power(3, 4));
    return 0;
}
```

---
level: 2

---

# Esercizio 2: Funzione media

Scrivi una funzione che calcola la media di un array:

```c
float average(int arr[], int size);
```

**Requisiti:**

- Somma tutti gli elementi dell'array
- Dividi per il numero di elementi
- Restituisci il risultato come `float`

**Esempio:**

```c
int main(void) {
    int grades[] = {18, 24, 30, 27, 22};
    float m = average(grades, 5);
    printf("Average grade: %.2f\n", m);  // Output: 24.20
    return 0;
}
```

---
level: 2

---

# Riepilogo

## Funzioni

- Dichiarazione (prototipo) vs Definizione (implementazione)
- Passaggio per valore (copia) vs passaggio per riferimento (puntatori)
- Array sempre passati per riferimento
- Progetti multi-file usano header (.h) e sorgenti (.c)
- Include guards prevengono inclusioni multiple
- CMake automatizza la compilazione di progetti con più file
- Un test automatico chiama una funzione con valori noti e controlla il risultato (`assert`, `ctest`)

---
level: 2

---

# Best practices

## Funzioni

1. **Una funzione = un compito specifico** - funzioni brevi e focalizzate
2. **Nomi descrittivi** - `calcola_area()` meglio di `calc()`
3. **Documentazione** - commenta cosa fa la funzione, non come
4. **Limita i parametri** - massimo 4-5 parametri per leggibilità
5. **Usa const** per parametri che non devono essere modificati
