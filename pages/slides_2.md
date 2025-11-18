---
layout: cover
transition:
coverDate:

---

# 2 - Introduzione al “C”

Ing. Giancarlo Degani

---
layout: image-right
image: /kernighan.png

---
    
# Il linguaggio C

- Sviluppato da Dennis Ritchie ai Bell Labs nel 1972 per realizzare il sistema operativo UNIX
- Linguaggio compilato
- Compilatore disponibile per tutte le piattaforme
- Codice molto efficiente

---

# Il linguaggio C, caratteristiche

- Adatto sia come linguaggio ad alto livello che a basso livello (operazioni sui bit)
- Tantissime librerie disponibili
- Linguaggio procedurale, non ad oggetti (Aggiunti nel C++)
- Gestione della memoria “manuale” (Non c’è garbage collector)

---

# Librerie

- In un linguaggio ad alto livello le funzioni di base sono fornite dal linguaggio ( lettura da tastiera, scrittura su schermo, lettura/scrittura da file)
- Queste operazioni elementari sono disponibili sotto forma di funzioni
- Le funzioni sono raccolte e distribuite sotto forma di librerie

---

# Come si scrive un programma?

- Bastano un editor di testo per scrivere il file sorgente ed un compilatore o interprete per tradurre il sorgente in linguaggio macchina
- Solitamente si usa uno strumento definito Integrated Development Environment (IDE)
- CLion è un IDE specifico per C/C++

---

# hello, world

<<< @/snippets/example01/main.c txt {all}{lines:true}

---

# hello, world

<<< @/snippets/example01/main.c c {all|1-4|6-7|9-15|17-18|19|all}{lines:true}

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

## Compilazione:

```bash
gcc -c math_utils.c -o math_utils.o
gcc -c main.c -o main.o
gcc math_utils.o main.o -o program
```

---

# Creazione di un eseguibile

Il processo di creazione di un eseguibile a partire dai sorgenti è composto da 2 fasi:

- **compilazione**: il sorgente viene compilato, ma alcune parti (le “funzioni di base”) sono ancora mancanti; viene generato un file intermedio detto file oggetto
- **linking**: il file oggetto e le librerie vengono unite (collegate – “link”) così da aggiungere al file oggetto le parti mancanti e costituire un unico file eseguibile. La fase di link può creare un eseguibile collegando insieme più file oggetto e più librerie.

---

# Processo di build di un programma C

```mermaid {scale: 0.9, alt: 'Compilation pipeline diagram showing source files and headers flowing through preprocessor, compiler, assembler, and linker stages to create executable'}
flowchart LR
SF@{ shape: doc, label: "Source file" }
HF@{ shape: docs, label: "Header files" }
SF-->PP[Preprocessor]
HF-->PP
PP-->PF@{ shape: doc, label: "Pre-processed file" }
PF-->CC[Compiler]
CC-->OF@{ shape: doc, label: "Object file" }

    OFF@{ shape: docs, label: "Object files" }-->LN[Linker]
    LL@{ shape: docs, label: "Libraries" }--> LN
    LN -->EF@{ shape: doc, label: "Executable file" }
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

# Elementi base del linguaggio C

Dopo aver visto come si compila un programma C, vediamo ora gli elementi fondamentali del linguaggio:

- **Tipi di dato primitivi**: int, float, double, char
- **Variabili**: dichiarazione e inizializzazione
- **Operatori aritmetici**: +, -, *, /, %
- **Operatori di assegnamento**: =, +=, -=, *=, /=
- **Operatori relazionali**: ==, !=, <, >, <=, >=
- **Operatori logici**: &&, ||, !
- **Input/Output di base**: printf(), scanf()

---

# Tipi di dato primitivi in C

Il C fornisce alcuni tipi di dato di base per rappresentare numeri e caratteri:

| Tipo | Descrizione | Dimensione tipica | Range (esempio) |
|------|-------------|-------------------|-----------------|
| `char` | Carattere/byte | 1 byte | -128 a 127 o 0 a 255 |
| `int` | Intero | 4 byte | -2.147.483.648 a 2.147.483.647 |
| `float` | Numero reale precisione singola | 4 byte | ±3.4 × 10<sup>±38</sup> (~7 cifre) |
| `double` | Numero reale precisione doppia | 8 byte | ±1.7 × 10<sup>±308</sup> (~15 cifre) |

**Nota:** Le dimensioni possono variare a seconda dell'architettura (32/64 bit).  
Usa `sizeof(tipo)` per conoscere la dimensione esatta.

---

# Modificatori di tipo

I modificatori `signed`, `unsigned`, `short`, `long` cambiano il range dei tipi interi:

| Tipo | Dimensione | Range |
|------|------------|-------|
| `short int` (o `short`) | 2 byte | -32.768 a 32.767 |
| `unsigned int` | 4 byte | 0 a 4.294.967.295 |
| `long int` (o `long`) | 4 o 8 byte | Dipende dall'architettura |
| `long long int` | 8 byte | -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807 |

**Quando usare `unsigned`:**

- Quando il valore non può mai essere negativo (es. dimensioni, contatori)
- Per raddoppiare il massimo valore positivo rappresentabile

---

# Dichiarazione di variabili

**Sintassi:**

```c
tipo nome_variabile;
```

**Esempi:**

```c
int age;
double pi;
char initial;
```

**Regole per i nomi:**

- Iniziano con lettera o underscore `_`
- Contengono lettere, cifre, underscore
- Case-sensitive: `count` ≠ `Count`
- Non usare parole chiave C (`int`, `for`, `if`...)

---

# Dichiarazione di variabili

**Buone pratiche:**

```c
// ✅ Nomi descrittivi
int student_count;
float average_grade;
double exchange_rate;

// ❌ Nomi poco chiari
int x;
float f;
double d;

// ✅ Snake_case (comune in C)
int max_temperature;
float sensor_value;

// Costanti in MAIUSCOLO
#define MAX_SIZE 100
#define PI 3.14159
```

---

# Inizializzazione di variabili

**Dichiarazione senza inizializzazione:**

```c
int count;              // Valore indefinito (garbage)
float temperature;      // ⚠️ Non inizializzata!
```

**Dichiarazione con inizializzazione:**

```c
int count = 0;              // Inizializzata a 0
float temperature = 20.5;   // Inizializzata a 20.5
double pi = 3.14159;        // Inizializzata a 3.14159
char grade = 'A';           // Inizializzata a 'A'
```

**Inizializzazione multipla:**

```c
int x = 10, y = 20, z = 30;
float a, b = 2.5, c;    // Solo b è inizializzata!
```

**⚠️ IMPORTANTE:** Inizializzare sempre le variabili prima di usarle!

---

# Costanti

Le costanti sono valori che non possono essere modificati durante l'esecuzione:

**Metodo 1: `#define` (direttiva preprocessore)**

```c
#define PI 3.14159
#define MAX_STUDENTS 50
#define GREETING "Hello, World!"

// Uso:
float area = PI * radius * radius;
```

**Metodo 2: `const` (qualificatore di tipo)**

```c
const double PI = 3.14159;
const int MAX_STUDENTS = 50;
const char NEWLINE = '\n';

// PI = 3.14;  // ❌ ERRORE: non si può modificare
```

**Differenza:** `#define` è una sostituzione testuale, `const` è una variabile read-only con tipo.

---

# Operatore di assegnamento

L'operatore `=` assegna un valore a una variabile:

```c
int x;
x = 10;         // Assegna 10 a x

int y = 20;     // Dichiarazione + assegnamento

// Assegnamenti multipli (da destra a sinistra)
int a, b, c;
a = b = c = 5;  // Tutti valgono 5
```

**⚠️ Attenzione:** `=` è assegnamento, `==` è confronto!

```c
int x = 10;
x = 5;          // ✅ Assegnamento: x diventa 5
if (x == 5)     // ✅ Confronto: è vero?
```

---

# Assegnamenti composti

Gli operatori composti combinano un'operazione aritmetica con l'assegnamento:

| Operatore | Equivalente | Esempio | Risultato |
|-----------|-------------|---------|-----------|
| `+=` | `x = x + y` | `x += 5` | Aggiunge 5 a x |
| `-=` | `x = x - y` | `x -= 3` | Sottrae 3 da x |
| `*=` | `x = x * y` | `x *= 2` | Moltiplica x per 2 |
| `/=` | `x = x / y` | `x /= 4` | Divide x per 4 |
| `%=` | `x = x % y` | `x %= 3` | x = resto di x/3 |

---

# Esempio

```c
int count = 10;
count += 5;     // count = 15
count *= 2;     // count = 30
count -= 10;    // count = 20
count /= 4;     // count = 5
```

---

# Operatori di incremento e decremento

Gli operatori `++` e `--` aumentano o diminuiscono di 1:

**Post-incremento/decremento:**

```c
int x = 5;
int y = x++;    // y = 5, poi x = 6 (usa poi incrementa)
int z = x--;    // z = 6, poi x = 5 (usa poi decrementa)
```

**Pre-incremento/decremento:**

```c
int x = 5;
int y = ++x;    // x = 6, poi y = 6 (incrementa poi usa)
int z = --x;    // x = 5, poi z = 5 (decrementa poi usa)
```

**Uso tipico (equivalenti):**

```c
count = count + 1;
count += 1;
count++;            // ✅ Più idiomatico
++count;            // ✅ Stesso effetto se usato da solo
```

---

# Operatori aritmetici

Il C fornisce gli operatori aritmetici standard:

| Operatore | Operazione | Esempio | Risultato |
|-----------|------------|---------|-----------|
| `+` | Addizione | `5 + 3` | `8` |
| `-` | Sottrazione | `5 - 3` | `2` |
| `*` | Moltiplicazione | `5 * 3` | `15` |
| `/` | Divisione | `7 / 2` | `3` (interi!) |
| `%` | Modulo (resto) | `7 % 2` | `1` |

**⚠️ Divisione tra interi:**

```c
int a = 7 / 2;          // a = 3 (tronca, non arrotonda!)
float b = 7 / 2;        // b = 3.0 (divisione intera, poi conversione)
float c = 7.0 / 2;      // c = 3.5 (almeno un float → divisione reale)
float d = (float)7 / 2; // d = 3.5 (cast esplicito)
```

---

# Precedenza degli operatori aritmetici

Gli operatori seguono le regole matematiche standard:

**Precedenza (dal più alto al più basso):**

1. **Parentesi** `( )`
2. **Unari** `+`, `-`, `++`, `--`
3. **Moltiplicazione/Divisione/Modulo** `*`, `/`, `%`
4. **Addizione/Sottrazione** `+`, `-`

**Esempi:**

```c
int result;
result = 2 + 3 * 4;         // 14 (non 20!)
result = (2 + 3) * 4;       // 20
result = 10 - 4 / 2;        // 8 (non 3!)
result = (10 - 4) / 2;      // 3
result = 7 + 3 * 2 - 1;     // 12
```

**Consiglio:** Usa le parentesi per chiarezza, anche se non necessarie!

---

# Conversioni di tipo (cast)

Quando si mescolano tipi diversi, C effettua conversioni automatiche:

**Conversione implicita (promozione):**

```c
int i = 5;
float f = 2.0;
float result = i + f;   // i viene convertito a float → 7.0
```

**Regola generale:** Il tipo "più piccolo" viene promosso al tipo "più grande":

```
char → int → long → float → double
```

**Conversione esplicita (cast):**

```c
int a = 7, b = 2;
float result = (float)a / b;    // 3.5 (cast di a a float)
float result2 = a / (float)b;   // 3.5 (cast di b a float)
float result3 = (float)(a / b); // 3.0 (divisione intera, poi cast!)
```

---

# Esempi di conversioni di tipo

```c
int x = 5, y = 2;
float a, b;

// Divisione tra interi
a = x / y;              // a = 3.0 (divisione intera, poi conversione)

// Divisione con almeno un float
b = (float)x / y;       // b = 2.5 (x convertito a float)
b = x / (float)y;       // b = 2.5 (y convertito a float)
b = (float)x / (float)y;// b = 2.5 (entrambi convertiti)

// Troncamento da float a int
int z = 3.9;            // z = 3 (parte decimale scartata!)
int w = (int)3.9;       // w = 3 (cast esplicito)

// Promozione automatica
double d = 5 + 2.5;     // 5 → 5.0, poi 5.0 + 2.5 = 7.5
```

**⚠️ Il troncamento non arrotonda:** `3.9 → 3`, non `4`!

---

# Operatori relazionali

Gli operatori relazionali confrontano due valori e restituiscono un valore booleano:

| Operatore | Significato | Esempio | Risultato |
|-----------|-------------|---------|-----------|
| `==` | Uguale a | `5 == 5` | vero (1) |
| `!=` | Diverso da | `5 != 3` | vero (1) |
| `<` | Minore di | `3 < 5` | vero (1) |
| `>` | Maggiore di | `5 > 3` | vero (1) |
| `<=` | Minore o uguale | `3 <= 3` | vero (1) |
| `>=` | Maggiore o uguale | `5 >= 5` | vero (1) |

**In C:** `0` = falso, qualsiasi altro valore (tipicamente `1`) = vero

**⚠️ Errore comune:**

```c
if (x = 5)    // ❌ Assegnamento! (sempre vero, perché 5 ≠ 0)
if (x == 5)   // ✅ Confronto
```

---

# Esempi di operatori relazionali

```c
int a = 10, b = 20, c = 10;

// Confronti semplici
int result1 = (a == c);     // 1 (vero)
int result2 = (a == b);     // 0 (falso)
int result3 = (a != b);     // 1 (vero)
int result4 = (a < b);      // 1 (vero)
int result5 = (b > a);      // 1 (vero)
int result6 = (a <= c);     // 1 (vero)

// Confronti con espressioni
int x = 5, y = 10;
int result7 = (x + 5 == y);     // 1 (vero: 10 == 10)
int result8 = (x * 2 > y);      // 0 (falso: 10 > 10)

// ⚠️ Confronto tra float (problema di precisione)
float f1 = 0.1 + 0.2;
float f2 = 0.3;
int result9 = (f1 == f2);       // Potrebbe essere 0! (errore di arrotondamento)
```

---

# Operatori logici

Gli operatori logici combinano espressioni booleane:

| Operatore | Nome | Descrizione | Esempio | Risultato |
|-----------|------|-------------|---------|-----------|
| `&&` | AND logico | Vero se **entrambi** veri | `1 && 1` | `1` |
| `\|\|` | OR logico | Vero se **almeno uno** vero | `0 \|\| 1` | `1` |
| `!` | NOT logico | Inverte il valore | `!1` | `0` |

**Esempi:**

```c
int a = 1, b = 0;

int result1 = a && b;   // 0 (falso: non entrambi veri)
int result2 = a || b;   // 1 (vero: almeno uno vero)
int result3 = !a;       // 0 (falso: NOT di vero)
int result4 = !b;       // 1 (vero: NOT di falso)
int result5 = a && a;   // 1 (vero: entrambi veri)
```

---

# Tabelle di verità

**AND logico (`&&`):**

| A | B | A && B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**OR logico (`||`):**

| A | B | A \|\| B |
|---|---|---------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

**NOT logico (`!`):**

| A | !A |
|---|----|
| 0 | 1 |
| 1 | 0 |

---

# Short-circuit evaluation

Gli operatori `&&` e `||` valutano da sinistra a destra e si fermano appena possibile:

**AND logico (`&&`):**

```c
int x = 0, y = 5;
if (x != 0 && y / x > 2) {  // ✅ Non valuta y/x (x è 0, evita divisione per 0!)
    // ...
}
```

Se il primo operando è falso, il secondo **non viene valutato** (tanto il risultato è già falso).

**OR logico (`||`):**

```c
int age = 25;
if (age < 18 || age > 65) {  // Se age < 18 è vero, non controlla age > 65
    // ...
}
```

Se il primo operando è vero, il secondo **non viene valutato** (tanto il risultato è già vero).

**Utile per:** evitare errori (divisione per 0, accessi a puntatori NULL, ecc.)

---

# Esempi di operatori logici

```c
int age = 25;
int has_license = 1;  // vero
int has_car = 0;      // falso

// Combinazioni di condizioni
int can_drive = (age >= 18) && has_license;        // 1 (vero)
int needs_transport = !has_car || (age < 16);      // 1 (vero: non ha macchina)

// Espressioni complesse
int x = 10, y = 20, z = 30;
int result1 = (x < y) && (y < z);                  // 1 (vero: 10 < 20 < 30)
int result2 = (x > y) || (z > y);                  // 1 (vero: z > y)
int result3 = !(x == y);                           // 1 (vero: x diverso da y)
int result4 = (x < y) && (y < z) && (x < z);       // 1 (vero: tutti veri)

// Short-circuit
int a = 0;
int result5 = (a != 0) && (100 / a > 5);  // 0 (non valuta 100/a: evita errore!)
```

---

# Precedenza degli operatori (completa)

**Precedenza (dal più alto al più basso):**

1. **Parentesi, chiamate di funzione** `()` `[]`
2. **Unari** `!` `++` `--` `+` `-` `(tipo)` (cast)
3. **Moltiplicativi** `*` `/` `%`
4. **Additivi** `+` `-`
5. **Relazionali** `<` `<=` `>` `>=`
6. **Uguaglianza** `==` `!=`
7. **AND logico** `&&`
8. **OR logico** `||`
9. **Assegnamento** `=` `+=` `-=` `*=` `/=` `%=`

**Consiglio:** In caso di dubbio, usa le parentesi!

```c
int x = 5 > 3 && 2 < 4;     // 1 (vero: confronti prima, poi &&)
int y = (5 > 3) && (2 < 4); // 1 (più chiaro!)
```

---

# Input/Output: printf()

`printf()` stampa testo formattato sullo standard output (terminale):

**Sintassi:**

```c
printf("formato", argomenti...);
```

**Specificatori di formato:**

| Specificatore | Tipo | Esempio |
|---------------|------|---------|
| `%d` o `%i` | int | `printf("%d", 42);` → `42` |
| `%f` | float/double | `printf("%f", 3.14);` → `3.140000` |
| `%c` | char | `printf("%c", 'A');` → `A` |
| `%s` | stringa | `printf("%s", "Hello");` → `Hello` |
| `%lf` | double (con scanf) | `scanf("%lf", &d);` |
| `%%` | Carattere % | `printf("%%");` → `%` |

---

# printf(): esempi

```c
#include <stdio.h>

int main(void) {
    int age = 25;
    float height = 1.75;
    char grade = 'A';
    
    // Stampa semplice
    printf("Hello, World!\n");
    
    // Stampa con variabili
    printf("Age: %d\n", age);                    // Age: 25
    printf("Height: %f\n", height);              // Height: 1.750000
    printf("Grade: %c\n", grade);                // Grade: A
    
    // Formattazione decimali
    printf("Height: %.2f\n", height);            // Height: 1.75
    
    // Multipli argomenti
    printf("Age: %d, Height: %.2f, Grade: %c\n", age, height, grade);
    
    return 0;
}
```

---

# printf(): controllo formato

**Larghezza campo:**

```c
int x = 42;
printf("%5d\n", x);     //    42 (5 caratteri, allineato a destra)
printf("%-5d\n", x);    // 42    (5 caratteri, allineato a sinistra)
```

**Precisione decimali:**

```c
float pi = 3.14159265;
printf("%.2f\n", pi);   // 3.14 (2 decimali)
printf("%.4f\n", pi);   // 3.1416 (4 decimali, arrotonda!)
printf("%8.2f\n", pi);  //     3.14 (8 caratteri totali, 2 decimali)
```

**Caratteri speciali:**

```c
printf("Line 1\nLine 2\n");     // \n = newline
printf("Tab\there\n");          // \t = tab
printf("Quote: \"\n");          // \" = virgolette
printf("Backslash: \\\n");      // \\ = backslash
```

---

# Input/Output: scanf()

`scanf()` legge input formattato dallo standard input (tastiera):

**Sintassi:**

```c
scanf("formato", &variabile);
```

**⚠️ IMPORTANTE:** Si usa `&` (indirizzo) prima del nome della variabile!

**Esempi:**

```c
int age;
float height;
char grade;

printf("Enter age: ");
scanf("%d", &age);          // Legge un intero

printf("Enter height: ");
scanf("%f", &height);       // Legge un float

printf("Enter grade: ");
scanf(" %c", &grade);       // Legge un carattere (spazio prima per ignorare whitespace)
```

---

# scanf(): esempi completi

```c
#include <stdio.h>

int main(void) {
    int num1, num2;
    float result;
    
    // Legge due numeri
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Calcola la media
    result = (float)(num1 + num2) / 2;
    
    printf("Average: %.2f\n", result);
    
    return 0;
}
```

**⚠️ Validazione input:** `scanf()` non verifica che l'input sia valido!  
(Per esempio, se si aspetta un numero e l'utente inserisce una lettera)

---

# scanf(): lettura multipla

**Lettura multipla sulla stessa riga:**

```c
int x, y, z;
printf("Enter three numbers: ");
scanf("%d %d %d", &x, &y, &z);      // Input: 10 20 30
```

**Lettura con separatori specifici:**

```c
int day, month, year;
printf("Enter date (dd/mm/yyyy): ");
scanf("%d/%d/%d", &day, &month, &year);  // Input: 25/12/2023
```

**⚠️ Problemi comuni:**

```c
char name[50];
scanf("%s", name);      // ✅ Per array non serve &
scanf("%s", &name);     // ❌ ERRORE (name è già un puntatore)

// scanf("%s") si ferma al primo spazio!
// Input: "John Doe" → legge solo "John"
```

---

# Esempio completo: calcolatrice semplice

```c
#include <stdio.h>

int main(void) {
    float num1, num2, result;
    char operator;
    
    printf("Enter first number: ");
    scanf("%f", &num1);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Spazio prima per ignorare newline
    
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    // Calcola in base all'operatore (verrà spiegato con if/switch)
    result = num1 + num2;  // Semplificato per ora
    
    printf("Result: %.2f\n", result);
    
    return 0;
}
```

**Nota:** La gestione dei diversi operatori richiede `if` o `switch` (prossime lezioni).

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
