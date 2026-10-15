---
layout: cover
transition:
coverDate:

---

# 7 - Strutture, memoria dinamica, liste e file

Ing. Giancarlo Degani

---
level: 2

---

# Cos'è una struttura?

Una **struttura** (struct) è un tipo di dato composito che raggruppa variabili di tipi diversi sotto un unico nome.

## Problema senza struct

```c
// Data of one student
char name[50];
int age;
float grade;

char name2[50];  // For a second student...
int age2;
float grade2;
```

## Soluzione con struct

```c
struct Student {
    char name[50];
    int age;
    float grade;
};

struct Student student1, student2;  // Two variables of the same type
```

---
level: 2

---

# Dichiarazione di una struttura

## Sintassi base

```c
struct struct_name {
    type1 member1;
    type2 member2;
    // ... other members
};
```

## Esempio completo

<<< @/snippets/example81/main.c#demo c {*}{lines:true}

**Nota**: il `;` finale dopo la `}` è obbligatorio!

---
level: 2

---

# Inizializzazione di una struttura

## Dichiarazione e inizializzazione

<<< @/snippets/example80/main.c#demo c {*}{lines:true}

---
level: 2

---

# Accesso ai membri di una struttura

Si usa l'**operatore punto** `.` per accedere ai membri:

<<< @/snippets/example79/main.c#demo c {*}{lines:true}

**Attenzione**: per le stringhe (array di char) si usa `strcpy`, non l'assegnazione diretta!

**Nota sulla sicurezza**: `strcpy` può causare buffer overflow se la stringa sorgente è più lunga del buffer destinazione. In codice di produzione, preferire `strncpy` o controllare sempre la dimensione!

---
level: 2

---

# Esempio completo: struct Student

<<< @/snippets/example78/main.c#demo c {*}{lines:true}

---
level: 2

---

# Strutture e puntatori

L'**operatore freccia** `->` accede ai membri tramite puntatore:

<<< @/snippets/example77/main.c#demo c {*}{lines:true}

---
level: 2

---

# Strutture e funzioni

Le strutture possono essere passate alle funzioni **per valore** o **per riferimento**.

## Passaggio per valore

<<< @/snippets/example76/main.c#demo c {*}{lines:true}

**Nota**: passare per valore copia tutta la struttura (può essere costoso per strutture grandi!).

---
level: 2

---

# Operatori per le strutture

## Operatore punto `.`

Accede ai membri di una **variabile** di tipo struttura:

```c
struct Student s;
s.age = 20;
```

## Operatore freccia `->`

Accede ai membri tramite **puntatore** a struttura:

```c
struct Student *ptr = &s;
ptr->age = 20;           // Same as (*ptr).age = 20
```

**Regola**: usa `.` con variabili, `->` con puntatori.

---
level: 2

---

# Typedef con struct

`typedef` crea un alias per semplificare l'uso della struttura:

## Senza typedef

```c
struct Student {
    char name[50];
    int age;
};

struct Student s1;  // You must write "struct Student"
```

## Con typedef

```c
typedef struct {
    char name[50];
    int age;
} Student;

Student s1;  // Simpler!
```

---
layout: two-cols
level: 2

---

# Array di strutture

Puoi creare array di strutture per gestire collezioni di dati:

<<< @/snippets/example82/main.c#part1 c {*}{lines:true}

::right::

<<< @/snippets/example82/main.c#part2 c {*}{lines:true}

---
level: 2

---

# Files in C: concetto di stream

Un **file** è una sequenza di byte memorizzata su disco. In C, i file vengono gestiti tramite **stream**.

## Stream

Uno **stream** è un canale di comunicazione tra il programma e una sorgente/destinazione di dati:

- **stdin**: input standard (tastiera)
- **stdout**: output standard (schermo)
- **stderr**: errori standard (schermo)

## File pointer

Per lavorare con i file si usa un puntatore di tipo `FILE *`:

```c
FILE *file;
```

---
level: 2

---

# Apertura di un file: fopen()

La funzione `fopen()` apre un file e restituisce un puntatore `FILE *`:

```c
FILE *fopen(const char *filename, const char *mode);
```

## Esempio

```c
FILE *file;
file = fopen("data.txt", "r");

if (file == NULL) {
    printf("Error opening the file!\n");
    return 1;
}
```

**Importante**: controlla sempre se `fopen()` restituisce `NULL` (file non trovato, permessi insufficienti, ecc.).

---
level: 2

---

# Modalità di apertura dei file

| Modalità | Descrizione | Se il file esiste | Se non esiste |
|----------|-------------|-------------------|---------------|
| `"r"` | Lettura (read) | Apre | Errore |
| `"w"` | Scrittura (write) | Sovrascrive | Crea |
| `"a"` | Append | Aggiunge alla fine | Crea |
| `"r+"` | Lettura/Scrittura | Apre | Errore |
| `"w+"` | Lettura/Scrittura | Sovrascrive | Crea |
| `"a+"` | Lettura/Append | Aggiunge alla fine | Crea |

## Esempi

```c
FILE *f1 = fopen("input.txt", "r");    // Read only
FILE *f2 = fopen("output.txt", "w");   // Write (overwrites)
FILE *f3 = fopen("log.txt", "a");      // Appends at the end
```

---
level: 2

---

# Chiusura di un file: fclose()

Dopo aver usato un file, è **fondamentale** chiuderlo con `fclose()`:

```c
int fclose(FILE *stream);
```

## Esempio

```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    perror("Error opening file");
    return 1;
}

// ... operations on the file ...
fclose(file);  // Closes the file
```

**Perché è importante?**

- Libera le risorse di sistema
- Garantisce che i dati vengano scritti su disco
- Previene perdite di dati

---
level: 2

---

# Lettura da file: fgets()

`fgets()` legge una riga intera (fino a `\n` o EOF):

```c
char *fgets(char *str, int n, FILE *stream);
```

- `str`: buffer dove salvare la stringa
- `n`: dimensione massima del buffer
- Restituisce `NULL` se fine file o errore

## Esempio

<<< @/snippets/example75/main.c#demo c {*}{lines:true}

---
level: 2

---

# Lettura formattata: fscanf()

`fscanf()` legge dati formattati da file (come `scanf()` da tastiera):

```c
int fscanf(FILE *stream, const char *format, ...);
```

## Esempio: leggere numeri da file

<<< @/snippets/example74/main.c#demo c {*}{lines:true}

**Nota**: `fscanf()` restituisce il numero di elementi letti con successo.

---
level: 2

---

# Scrittura formattata: fprintf()

`fprintf()` scrive dati formattati su file (come `printf()` su schermo):

```c
int fprintf(FILE *stream, const char *format, ...);
```

## Esempio: scrivere una tabella

<<< @/snippets/example73/main.c#demo c {*}{lines:true}

---
level: 2

---

# Gestione degli errori: perror()

`perror()` stampa un messaggio di errore descrittivo:

```c
void perror(const char *msg);
```

## Esempio

```c
FILE *file = fopen("missing.txt", "r");
if (file == NULL) {
    perror("Error");  // Prints: "Error: No such file or directory"
    return 1;
}
```

## Alternativa: ferror()

Verifica se si è verificato un errore durante le operazioni:

```c
if (ferror(file)) {
    printf("An error occurred!\n");
}
```

---
level: 2

---

# Leggere una riga e scomporla: fgets() + sscanf()

`fgets()` legge una riga intera in un buffer; `sscanf()` ne estrae i campi, come `scanf()` ma da una stringa:

<<< @/snippets/example72/main.c#demo c {*}{lines:true}

- `sscanf()` restituisce il numero di campi letti: se non è 3, la riga è malformata
- Formato del file `readings.csv`: `timestamp;sensor_id;value`

---
level: 2

---

# Riepilogo: strutture

## Cosa abbiamo imparato

- **Definizione**: `struct Nome { membri };`
- **Accesso**: operatore `.` per variabili, `->` per puntatori
- **Typedef**: semplifica la sintassi
- **Funzioni**: passaggio per valore o per riferimento
- **Array**: collezioni di strutture
- **Memoria dinamica**: `malloc()` per strutture

## Quando usare le struct?

- Per rappresentare **entità complesse** (studente, punto, rettangolo, ...)
- Per **raggruppare dati correlati**
- Per **migliorare la leggibilità** del codice

---
level: 2

---

# Riepilogo: file

## Cosa abbiamo imparato

- **fopen()**: aprire un file con modalità (`r`, `w`, `a`, ...)
- **fclose()**: chiudere un file (sempre!)
- **fgets()**: lettura di una riga
- **sscanf()**: estrazione dei campi da una riga
- **fscanf()/fprintf()**: lettura/scrittura formattata
- **perror()**: gestione errori

## Buone pratiche

- Controlla sempre il valore di ritorno di `fopen()`
- Chiudi sempre i file con `fclose()`
- Usa `perror()` per messaggi di errore chiari

---
level: 2

---

# Allocazione della memoria

- **Allocare** memoria significa chiedere al sistema operativo di assegnare un blocco di memoria RAM ad un programma
- La memoria può essere allocata:
  - Al momento della compilazione (compile-time)
  - Durante l’esecuzione del programma (run-time)
- **Deallocare** memoria significa rilasciare questa memoria al sistema operativo per renderla disponibile ad altri programmi

---
level: 2

---

# Allocazione statica

- Usata per variabili globali
- Avviene durante la compilazione
- Non può essere rilasciata o deallocata durante l’esecuzione del programma

---
level: 2

---

# Allocazione automatica

- Usata per variabili locali
- Viene allocata durante l’esecuzione
- Viene gestita automaticamente dal compilatore

---
level: 2

---

# Allocazione dinamica

- La memoria viene allocata a run-time
- Può essere deallocata a run-time
- La responsabilità della deallocazione è del programmatore

---
level: 2

---

# Funzioni di gestione della memoria

- Riservano un generico blocco contiguo di byte
- Restituiscono l’indirizzo di memoria (di tipo puntatore-a-void) del primo byte del blocco
- Il blocco di byte non ha di per sé alcun tipo, il cast sul puntatore restituito fa sì che il blocco di byte sia considerato dal compilatore come avente il tipo indicato nel cast
- Non si può applicare l’operatore **sizeof** a un blocco di memoria allocato dinamicamente in quanto sizeof viene valutato durante la compilazione, non durante l'esecuzione.

---
level: 2

---

# <stdlib.h>

- **void \* malloc(size_t size);**
  - The malloc() function allocates size bytes of memory and returns a pointer to the allocated memory.
- **void \* calloc(size_t count, size_t size);**
  - The calloc() function contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.  The allocated memory is filled with bytes of value zero
- **void \* realloc(void *ptr, size_t size);**
  - The realloc() function changes the size of the memory block pointed to by ptr to size bytes, preserving the existing contents up to the minimum of the old and new sizes; if ptr is NULL, realloc() behaves like malloc().
- **void free(void \*ptr);**
  - The free() function deallocates the memory allocation pointed to by ptr. If ptr is a NULL pointer, no operation is performed.

---
level: 2

---

# Esempi di allocazione

## Variabile scalare

<br>

- Istanziazione di una variabile scalare:

```c
double *p;
p=(double *)malloc(sizeof(double));
```

- Utilizzo:

```c
*p = 1.9;
```

- Deallocazione:

```c
free(p);
```

---
level: 2

---

# Esempi di allocazione

## Vettore di interi

<br>

- Istanziazione di un vettore di int di dimensione 100:

```c
int *p = (int *)malloc(sizeof(int) * 100);
```

- Utilizzo:

```c
*(p + 12) = 19;
p[12] = 19;
```

- Deallocazione:

```c
free(p);
```

---
level: 2

---

# Esempi di allocazione

## Vettore di strutture

<br>

- Istanziazione di un vettore di strutture:

```c
typedef struct {
  double x;
  double y;
} Point;

Point *p = (Point *)malloc(sizeof(Point) * 100);
```

- Utilizzo:

```c
p[12].x = 1.5;
p[12].y = 2.5;
```

- Deallocazione:

```c
free(p);
```

---
level: 2

---

# Strutture e memoria dinamica

Esempio di allocazione dinamica di array di strutture:

<<< @/snippets/example83/main.c#part1 c {*}{lines:true}

::right::
  
<<< @/snippets/example83/main.c#part2 c {*}{lines:true}

---
layout: two-cols
level: 2

---

# Esempio

::right::

<<< @/snippets/example23/main.c c {all}{lines:true}

---
level: 2

---

# Esempio

<<< @/snippets/example22/main.c#part1 c {all}{lines:true}

---
level: 2

---

# Esempio

<<< @/snippets/example22/main.c#part2 c {all}{lines:true, startLine:17}

---
level: 2

---

# Esercizio

Si scriva un programma che ordini in senso crescente i valori contenuti in un file di testo e li scriva in un altro. Non è noto a priori quanti siano i valori contenuti nel file.
Si utilizzi una funzione per l’ordinamento. Il programma, per allocare un vettore dinamico di dimensione appropriata, nel main:

- conta quanti sono i valori leggendoli dal file
- crea il vettore dinamico di dimensione adeguata
- lo riempie rileggendo il file
- lo passa alla funzione di ordinamento
- scrive il file di output con il contenuto del vettore riordinato

---
level: 2

---

# Liste

- Si definisce lista una struttura dati in cui ogni oggetto ha un collegamento ad un altro oggetto (Linked list)
- Il collegamento è costituito da un puntatore all’area di memoria contenente l’elemento successivo della lista

![Liste](/list1.png)

---
level: 2

---

# Vantaggi e svantaggi rispetto ai vettori

- La dimensione della lista può essere modificata a runtime
- Lo spostamento di elementi è molto veloce
- L’accesso all’i-esimo elemento è più lento perchè devo scorrere tutta o parte della lista

---
layout: two-cols
level: 2

---

# Implementazione con struct

- **valore** è l’informazione contenuta nel singolo elemento della lista
- **head** è il puntatore al primo elemento della lista (testa della lista)
  - Inizialmente la lista è vuota, quindi head è NULL
- **next** è il puntatore al prossimo elemento della lista
  - next è NULL nell’ultimo elemento della lista (coda della lista)

::right::

<<< @/snippets/example24/simple_list.c#snippet1 c {*}{lines:true}

---
level: 2

---

# Inserimento in testa alla lista 1

Situazione iniziale con una lista non vuota

![Inserimento in testa alla lista](/list2.png)

---
level: 2

---

# Inserimento in testa alla lista 2

Creo una nuova variabile per contenere il nuovo elemento della lista

![Inserimento in testa alla lista](/list3.png)

---
level: 2

---

# Inserimento in testa alla lista 3

Copio il valore ed il puntatore alla testa della lista nel nuovo elemento

![Inserimento in testa alla lista](/list4.png)

---
level: 2

---

# Inserimento in testa alla lista 4

Cambio il valore di Head

![Inserimento in testa alla lista](/list5.png)

---
level: 2

---

# Rimozione dalla testa

- Copio il valore dell’elemento in testa in una variabile temporanea
- Copio il puntatore all’elemento in testa (head) in una variabile temporanea
- Copio il puntatore al secondo elemento in head
- Rilascio la memoria allocata per l’elemento rimosso

![Rimozione dalla testa](/list6.png)

---
layout: two-cols
level: 2

---

# Esempio: misure da file in una lista

Le misure del file `readings.csv` vengono caricate in una lista concatenata di `struct`:

```text
1000;1;21.5
1005;2;22.1
1010;1;21.9
1015;2;25.4
1020;1;22.3
```

::right::

<<< @/snippets/example30/main.c#snippet1 c {*}{lines:true}

---
level: 2

---

# Esempio: inserimento in testa

<<< @/snippets/example30/main.c#snippet3 c {*}{lines:true}

---
level: 2

---

# Esempio: liberare la lista

Ogni nodo allocato con `malloc` va liberato con `free`.

<<< @/snippets/example30/main.c#snippet4 c {*}{lines:true}

---
level: 2

---

# Esempio: lettura del file

<<< @/snippets/example30/main.c#snippet2 c {*}{lines:true}

---
level: 2

---

# Esempio: statistiche e pulizia

<<< @/snippets/example30/main.c#snippet5 c {*}{lines:true}

---
layout: two-cols
level: 2

---

# Esercizio

- Implementare delle funzioni per la gestione di una lista dinamica di numeri interi
  - lista.h  dichiarazione delle funzioni
  - lista.c implementazione delle funzioni
- Scrivere un main che proponga un menu per testarle.
- Ogni funzione, quando richiamata, deve stampare a video l'intera lista

::right::

<Transform :scale="1.7" >

<<< @/snippets/example24/demo.h#snippet1 c {*}{lines:true}

</Transform>

---
level: 2

---

# Esempio di menù

```txt

Available operations:
a. AddToHead
b. AddToTail
c. RemoveFromHead
d. RemoveFromTail
e. ClearAll
p. PrintAll
x. Exit

Choice:

```

---
level: 2

---

# Esempio di output

```txt


0) address: [0x6000039dc000], value: [22222], next: [0x6000039c4000]
1) address: [0x6000039c4000], value: [11111], next: [0x0]
Available operations:
a. AddToHead
b. AddToTail
c. RemoveFromHead
d. RemoveFromTail
e. ClearAll
p. PrintAll
x. Exit

Choice:

```

---
level: 2

---

# Soluzione 1/7

<<< @/snippets/example24/simple_list.c#snippet1 c

---
level: 2

---

# Soluzione 2/7

<<< @/snippets/example24/simple_list.c#snippet2 c

---
level: 2

---

# Soluzione 3/7

<<< @/snippets/example24/simple_list.c#snippet3 c

---
level: 2

---

# Soluzione 4/7

<<< @/snippets/example24/simple_list.c#snippet4 c

---
level: 2

---

# Soluzione 5/7

<<< @/snippets/example24/simple_list.c#snippet5 c

---
level: 2

---

# Soluzione 6/7

<<< @/snippets/example24/simple_list.c#snippet6 c

---
level: 2

---

# Soluzione 7/7

<<< @/snippets/example24/simple_list.c#snippet7 c

---
level: 2

---

# Liste bidirezionali

Situazione iniziale con una lista non vuota

![Rimozione dalla testa](/list7.png)

---
level: 2

---

# Liste di liste

- Posso suddividere la lista in parti per rendere più veloce la navigazione all’interno della lista
- Uso un algoritmo di hashing per definire il partizionamento e quindi la ricerca
<Transform :scale="0.7" >

![Rimozione dalla testa](/list8.png)

</Transform>

---
level: 2

---

# Esercizi aggiuntivi

- Scrivere un programma che legga da un file di testo una sequenza di interi (numero di valori ignoto), li memorizzi in un vettore allocato dinamicamente e stampi media, minimo e massimo. Usare `realloc` per crescere il vettore mentre si legge il file.
- Leggere da un file di testo una lista di nomi (max 30 caratteri ciascuno), salvarli in un array di stringhe allocato dinamicamente e scrivere su un secondo file solo i nomi che iniziano per vocale. Gestire correttamente la deallocazione di tutte le stringhe.
- Implementare una rubrica semplice: leggere righe "nome numero" da un file, memorizzarle in un array di struct allocato dinamicamente, ordinare per nome e riscrivere su un nuovo file la rubrica ordinata. Prevedere il controllo di errori di apertura file e di allocazione.
