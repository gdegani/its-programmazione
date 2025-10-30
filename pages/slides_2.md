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

**File Header (.h)**

- Contiene **dichiarazioni**: firme di funzioni, definizioni di strutture, costanti
- Specifica "cosa" fa una funzione, non "come"
- Incluso con `#include` in altri file

**File Implementation (.c)**

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

**main.c** (Usage)

```c
#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int result = add(5, 3);
    printf("Result: %d\n", result);
    return 0;
}
```

**Compilazione:**

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

```mermaid {scale: 0.8, alt: 'Detailed compilation phases flowchart showing transformation from source C file through preprocessing, compilation to assembly, assembling to object code, and linking to executable'}
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

**Output:** File `.i` (codice C espanso)

::right::

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

**Make** (1976)

- Usa file `Makefile` con regole di dipendenza
- Ricompila solo i file modificati
- Standard su Unix/Linux

**CMake** (2000)

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

# CMakeLists.txt: struttura nel nostro progetto

Ogni esempio in `snippets/exampleNN/` usa questa struttura:

<<< @/snippets/example01/CMakeLists.txt cmake {all}{lines:true}

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
hide: true

---

## Codifica di una stringa

|           |    |   |   |   |   |   |   |
|---        |--- |---|---|---|---|---|---|
| **char**  | H  |e  | l | l | o |!  |\0 |
| **Dec**   | 72 |101|108|108|111| 33| 0 |
| **Hex**   | 48 | 65| 6C| 6C| 6F| 21| 0 |

---
hide: true

---

```mermaid {scale: 1, alt: 'Flowchart diagram showing if-else conditional branching control structure with true and false paths merging at end'}
flowchart TD
  %% classDef default fill:#FFFFC6,stroke:black,stroke-width:2px,color:black
    A@{ shape: stadium, label: "Inizio"}
    B@{ shape: stadium, label: "Fine"}
    C{{Valuta espressione}}
    D@{ shape: lean-r, label: "Blocco1" }
    E@{ shape: f-circ, label: ""}
    A --> C
    C -- vero --> D
    D --> E
    C -->|falso| E
    E --> B
```

---
hide: true

---

# Esempio for

```mermaid {scale: 0.7, alt: 'Sequence diagram showing interaction flow from user to main program calling printf and strlen library functions and returning'}
sequenceDiagram
    actor user
    user->>+program:main()
    program->>+library:printf()
    library->>-program:return
    program->>+library:strlen()
    library->>-program:return
    program->>-user:exit()
```
