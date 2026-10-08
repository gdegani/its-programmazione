---
layout: cover
transition:
coverDate:

---

# 7 - Strutture, memoria dinamica, liste e file

Ing. Giancarlo Degani

---

# Cos'è una struttura?

Una **struttura** (struct) è un tipo di dato composito che raggruppa variabili di tipi diversi sotto un unico nome.

## Problema senza struct

```c
// Dati di uno studente
char nome[50];
int eta;
float voto;

char nome2[50];  // Per un secondo studente...
int eta2;
float voto2;
```

## Soluzione con struct

```c
struct Student {
    char nome[50];
    int eta;
    float voto;
};

struct Student studente1, studente2;  // Due variabili dello stesso tipo
```

---

# Dichiarazione di una struttura

## Sintassi base

```c
struct nome_struttura {
    tipo1 membro1;
    tipo2 membro2;
    // ... altri membri
};
```

## Esempio completo

```c
struct Punto {
    int x;
    int y;
};

struct Rettangolo {
    struct Punto alto_sx;
    struct Punto basso_dx;
};
```

**Nota**: il `;` finale dopo la `}` è obbligatorio!

---

# Inizializzazione di una struttura

## Dichiarazione e inizializzazione

```c
struct Student {
    char nome[50];
    int eta;
    float voto;
};

// Inizializzazione diretta
struct Student s1 = {"Marco Rossi", 20, 28.5};

// Inizializzazione parziale
struct Student s2 = {"Anna"}; // eta=0, voto=0.0

// Dichiarazione senza inizializzazione
struct Student s3;
```

---

# Accesso ai membri di una struttura

Si usa l'**operatore punto** `.` per accedere ai membri:

```c
struct Student s1;

// Assegnazione
s1.eta = 20;
s1.voto = 28.5;
strcpy(s1.nome, "Marco Rossi");

// Lettura
printf("Nome: %s\n", s1.nome);
printf("Età: %d\n", s1.eta);
printf("Voto: %.2f\n", s1.voto);

// Modifica
s1.voto = 30.0;
s1.eta++;
```

**Attenzione**: per le stringhe (array di char) si usa `strcpy`, non l'assegnazione diretta!

**Nota sulla sicurezza**: `strcpy` può causare buffer overflow se la stringa sorgente è più lunga del buffer destinazione. In codice di produzione, preferire `strncpy` o controllare sempre la dimensione!

---

# Esempio completo: struct Student

```c
#include <stdio.h>

struct Student {
    char nome[50];
    int eta;
    float voto;
};

int main() {
    struct Student studente1 = {"Marco Rossi", 20, 28.5};
    
    printf("Nome: %s\n", studente1.nome);
    printf("Età: %d\n", studente1.eta);
    printf("Voto: %.2f\n", studente1.voto);
    
    return 0;
}
```

---

# Esempio completo: struct Student

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char nome[50];
    int eta;
    float voto;
};

int main() {
    struct Student studente1;
    
    strcpy(studente1.nome, "Anna Verdi");
    studente1.eta = 19;
    studente1.voto = 27.0;
    
    printf("Nome: %s\n", studente1.nome);
    printf("Età: %d\n", studente1.eta);
    printf("Voto: %.2f\n", studente1.voto);
    
    return 0;
}
```

---

# Strutture e puntatori

L'**operatore freccia** `->` accede ai membri tramite puntatore:

```c
struct Student {
    char nome[50];
    int eta;
    float voto;
};

void modifyStudent(struct Student *s) {
    s->eta = 21;           // Equivale a (*s).eta = 21
    s->voto = 30.0;        // Equivale a (*s).voto = 30.0
}

int main() {
    struct Student s1 = {"Marco", 20, 28.5};
    modifyStudent(&s1);    // Passa l'indirizzo
    printf("Nuova età: %d\n", s1.eta);  // Stampa 21
    return 0;
}
```

---

# Strutture e funzioni

Le strutture possono essere passate alle funzioni **per valore** o **per riferimento**.

## Passaggio per valore

```c
void printStudent(struct Student s) {
    printf("Nome: %s\n", s.nome);
    printf("Età: %d\n", s.eta);
    printf("Voto: %.2f\n", s.voto);
}

int main() {
    struct Student s1 = {"Marco", 20, 28.5};
    printStudent(s1);  // Copia l'intera struttura
    return 0;
}
```

**Nota**: passare per valore copia tutta la struttura (può essere costoso per strutture grandi!).

---

# Operatori per le strutture

## Operatore punto `.`

Accede ai membri di una **variabile** di tipo struttura:

```c
struct Student s;
s.eta = 20;
```

## Operatore freccia `->`

Accede ai membri tramite **puntatore** a struttura:

```c
struct Student *ptr = &s;
ptr->eta = 20;           // Equivale a (*ptr).eta = 20
```

**Regola**: usa `.` con variabili, `->` con puntatori.

---

# Typedef con struct

`typedef` crea un alias per semplificare l'uso della struttura:

## Senza typedef

```c
struct Student {
    char nome[50];
    int eta;
};

struct Student s1;  // Devi scrivere "struct Student"
```

## Con typedef

```c
typedef struct {
    char nome[50];
    int eta;
} Student;

Student s1;  // Più semplice!
```

---

# Typedef: esempio completo

```c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Punto;

typedef struct {
    Punto alto_sx;
    Punto basso_dx;
} Rettangolo;

int main() {
    Punto p1 = {10, 20};
    Rettangolo r1 = {{0, 10}, {20, 0}};
    
    printf("Punto: (%d, %d)\n", p1.x, p1.y);
    printf("Rettangolo: (%d,%d) - (%d,%d)\n",
           r1.alto_sx.x, r1.alto_sx.y,
           r1.basso_dx.x, r1.basso_dx.y);
    
    return 0;
}
```

---
layout: two-cols

---

# Array di strutture

Puoi creare array di strutture per gestire collezioni di dati:

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int eta;
    float voto;
} Student;

int main() {
    Student classe[3];
    
    strcpy(classe[0].nome, "Marco");
    classe[0].eta = 20;
    classe[0].voto = 28.5;
    
    strcpy(classe[1].nome, "Anna");
    classe[1].eta = 19;
    classe[1].voto = 27.0;
```

::right::

```c
    // Stampa tutti gli studenti
    for (int i = 0; i < 2; i++) {
        printf("%s: %.1f\n", classe[i].nome, classe[i].voto);
    }
    
    return 0;
}
```

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

# Apertura di un file: fopen()

La funzione `fopen()` apre un file e restituisce un puntatore `FILE *`:

```c
FILE *fopen(const char *filename, const char *mode);
```

## Esempio

```c
FILE *file;
file = fopen("dati.txt", "r");

if (file == NULL) {
    printf("Errore nell'apertura del file!\n");
    return 1;
}
```

**Importante**: controlla sempre se `fopen()` restituisce `NULL` (file non trovato, permessi insufficienti, ecc.).

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
FILE *f1 = fopen("input.txt", "r");    // Solo lettura
FILE *f2 = fopen("output.txt", "w");   // Scrittura (sovrascrive)
FILE *f3 = fopen("log.txt", "a");      // Aggiunge alla fine
```

---

# Chiusura di un file: fclose()

Dopo aver usato un file, è **fondamentale** chiuderlo con `fclose()`:

```c
int fclose(FILE *stream);
```

## Esempio

```c
FILE *file = fopen("dati.txt", "r");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

// ... operazioni sul file ...
fclose(file);  // Chiude il file
```

**Perché è importante?**

- Libera le risorse di sistema
- Garantisce che i dati vengano scritti su disco
- Previene perdite di dati

---

# Lettura da file: fgetc()

`fgetc()` legge un carattere alla volta dal file:

```c
int fgetc(FILE *stream);
```

Restituisce il carattere letto come `int`, oppure `EOF` (End Of File) quando il file è terminato.

## Esempio: stampare il contenuto di un file

```c
FILE *file = fopen("input.txt", "r");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

int ch;
while ((ch = fgetc(file)) != EOF) {
    putchar(ch);  // Stampa a schermo
}

fclose(file);
```

---

# Scrittura su file: fputc()

`fputc()` scrive un carattere alla volta sul file:

```c
int fputc(int c, FILE *stream);
```

## Esempio: copiare un file carattere per carattere

```c
FILE *input = fopen("input.txt", "r");
FILE *output = fopen("output.txt", "w");

if (input == NULL || output == NULL) {
    perror("Errore apertura file");
    return 1;
}

int ch;
while ((ch = fgetc(input)) != EOF) {
    fputc(ch, output);
}

fclose(input);
fclose(output);
```

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

```c
FILE *file = fopen("input.txt", "r");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

char line[100];
while (fgets(line, 100, file) != NULL) {
    printf("%s", line);  // line contiene già \n
}

fclose(file);
```

---

# Scrittura su file: fputs()

`fputs()` scrive una stringa su file:

```c
int fputs(const char *str, FILE *stream);
```

**Nota**: `fputs()` **non** aggiunge automaticamente `\n`.

## Esempio

```c
FILE *file = fopen("output.txt", "w");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

fputs("Prima riga\n", file);
fputs("Seconda riga\n", file);
fputs("Terza riga\n", file);

fclose(file);
```

---

# Lettura formattata: fscanf()

`fscanf()` legge dati formattati da file (come `scanf()` da tastiera):

```c
int fscanf(FILE *stream, const char *format, ...);
```

## Esempio: leggere numeri da file

```c
FILE *file = fopen("numeri.txt", "r");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

int numero;
while (fscanf(file, "%d", &numero) == 1) {
    printf("Letto: %d\n", numero);
}

fclose(file);
```

**Nota**: `fscanf()` restituisce il numero di elementi letti con successo.

---

# Scrittura formattata: fprintf()

`fprintf()` scrive dati formattati su file (come `printf()` su schermo):

```c
int fprintf(FILE *stream, const char *format, ...);
```

## Esempio: scrivere una tabella

```c
FILE *file = fopen("tabella.txt", "w");
if (file == NULL) {
    perror("Errore apertura file");
    return 1;
}

fprintf(file, "%-10s %-5s\n", "Nome", "Voto");
fprintf(file, "%-10s %-5d\n", "Marco", 28);
fprintf(file, "%-10s %-5d\n", "Anna", 30);

fclose(file);
```

---

# Gestione degli errori: perror()

`perror()` stampa un messaggio di errore descrittivo:

```c
void perror(const char *msg);
```

## Esempio

```c
FILE *file = fopen("inesistente.txt", "r");
if (file == NULL) {
    perror("Errore");  // Stampa: "Errore: No such file or directory"
    return 1;
}
```

## Alternativa: ferror()

Verifica se si è verificato un errore durante le operazioni:

```c
if (ferror(file)) {
    printf("Si è verificato un errore!\n");
}
```

---
layout: two-cols

---

# Esempio completo: lettura file

```c
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.txt"

int main(void) {
    FILE *file;
    
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Errore apertura file");
        return EXIT_FAILURE;
    }
    
    char ch;
    printf("Contenuto del file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
```

::right::

```c
    if (ferror(file)) {
        printf("\nErrore durante la lettura!\n");
    } else if (feof(file)) {
        printf("\nFile letto completamente.\n");
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}
```

---
layout: two-cols

---

# Esempio: struct e file - parsing CSV

<Transform :scale="0.9">
```c
typedef struct {
    unsigned int id;
    char nome[50];
    unsigned int voto;
} Record;
void parseLine(char *line, Record *record) {
    int counter = 0;
    char *token = strtok(line, ";");
    while (token != NULL && counter < 3) {
        switch (counter) {
            case 0:
                record->id = atoi(token);
                break;
            case 1:
                strcpy(record->nome, token);
                break;
            case 2:
                record->voto = atoi(token);
                break;
        }
        counter++;
        token = strtok(NULL, ";");
    }
}
```
</Transform>
::right::

<Transform :scale="0.9">
```c
int main() {
    FILE *file = fopen("studenti.csv", "r");
    if (file == NULL) {
        perror("Errore apertura file");
        return EXIT_FAILURE;
    }

    char line[100];
    Record studente;
    
    while (fgets(line, 100, file) != NULL) {
        parseLine(line, &studente);
        printf("ID: %u, Nome: %s, Voto: %u\n",
               studente.id, studente.nome, studente.voto);
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}

```

</Transform>

---

# Ordinamento con qsort()

`qsort()` ordina un array generico usando una funzione di confronto:

```c
#include <stdlib.h>

int compareInt(const void *a, const void *b) {
    const int *pa = a;
    const int *pb = b;
    return (*pa > *pb) - (*pa < *pb);  // Ordine crescente
}

int main(void) {
    int values[] = {4, 1, 3};
    qsort(values, 3, sizeof(int), compareInt);
    return 0;
}
```

In `qsort(base, n, size, compare)`, `compare` riceve due puntatori a elementi e deve restituire un valore `<0`, `0` o `>0`.

---

# Esempio: filtrare e ordinare dati

Completo esempio che:

1. Legge record da file
2. Filtra i record con voto >= 18
3. Ordina i record per voto decrescente
4. Scrive i risultati su file output

```c
// File: input.txt
// 1;Marco;28
// 2;Anna;15
// 3;Luca;30
// 4;Sara;22
```

Vedi: `snippets/example20/main.c` per l'implementazione completa.

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

# Riepilogo: file

## Cosa abbiamo imparato

- **fopen()**: aprire un file con modalità (`r`, `w`, `a`, ...)
- **fclose()**: chiudere un file (sempre!)
- **fgetc()/fputc()**: lettura/scrittura carattere per carattere
- **fgets()/fputs()**: lettura/scrittura stringhe
- **fscanf()/fprintf()**: lettura/scrittura formattata
- **perror()**: gestione errori

## Buone pratiche

- Controlla sempre il valore di ritorno di `fopen()`
- Chiudi sempre i file con `fclose()`
- Usa `perror()` per messaggi di errore chiari

---

# Esercizi consigliati

## Strutture

1. Creare una struttura `Libro` con titolo, autore, anno e prezzo. Scrivere funzioni per stampare e modificare un libro.
2. Creare un array di strutture `Studente` e scrivere funzioni per calcolare la media dei voti.
3. Implementare una struttura `Data` con giorno, mese, anno e funzioni per validare e confrontare date.

## File

1. Scrivere un programma che legge un file di testo e conta il numero di parole.
2. Copiare un file di testo in un altro file, convertendo tutte le lettere in maiuscolo.
3. Leggere un file CSV con dati di studenti e calcolare la media dei voti.

## Combinati

1. Salvare un array di strutture su file e rileggerlo.
2. Implementare un semplice database di contatti (nome, telefono, email) con salvataggio su file.

---

# Allocazione della memoria

- **Allocare** memoria significa chiedere al sistema operativo di assegnare un blocco di memoria RAM ad un programma
- La memoria può essere allocata:
  - Al momento della compilazione (compile-time)
  - Durante l’esecuzione del programma (run-time)
- **Deallocare** memoria significa rilasciare questa memoria al sistema operativo per renderla disponibile ad altri programmi

---

# Allocazione statica

- Usata per variabili globali
- Avviene durante la compilazione
- Non può essere rilasciata o deallocata durante l’esecuzione del programma

---

# Allocazione automatica

- Usata per variabili locali
- Viene allocata durante l’esecuzione
- Viene gestita automaticamente dal compilatore

---

# Allocazione dinamica

- La memoria viene allocata a run-time
- Può essere deallocata a run-time
- La responsabilità della deallocazione è del programmatore

---

# Funzioni di gestione della memoria

- Riservano un generico blocco contiguo di byte
- Restituiscono l’indirizzo di memoria (di tipo puntatore-a-void) del primo byte del blocco
- Il blocco di byte non ha di per sé alcun tipo, il cast sul puntatore restituito fa sì che il blocco di byte sia considerato dal compilatore come avente il tipo indicato nel cast
- Non si può applicare l’operatore **sizeof** a un blocco di memoria allocato dinamicamente in quanto sizeof viene valutato durante la compilazione, non durante l'esecuzione.

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

# Strutture e memoria dinamica

Esempio di allocazione dinamica di array di strutture:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char materia[30];
  int voto;
} Corso;

int main() {
  int n;
  printf("Numero di corsi: ");
  scanf("%d", &n);
    
  // Alloca memoria per n corsi
  Corso *corsi = (Corso *)malloc(n * sizeof(Corso));
```

::right::
  
```c

  // Input dati
  for (int i = 0; i < n; i++) {
    printf("Materia %d: ", i+1);
    scanf("%s", corsi[i].materia);
    printf("Voto: ");
    scanf("%d", &corsi[i].voto);
  }
    
  // Visualizza
  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", corsi[i].materia, corsi[i].voto);
  }
    
  free(corsi);
  return 0;
}
```

---
layout: two-cols

---

# Esempio

::right::

<<< @/snippets/example23/main.c c {all}{lines:true}

---

# Esempio

<<< @/snippets/example22/main.c#part1 c {all}{lines:true}

---

# Esempio

<<< @/snippets/example22/main.c#part2 c {all}{lines:true, startLine:17}

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

# Liste

- Si definisce lista una struttura dati in cui ogni oggetto ha un collegamento ad un altro oggetto (Linked list)
- Il collegamento è costituito da un puntatore all’area di memoria contenente l’elemento successivo della lista

![Liste](/list1.png)

---

# Vantaggi e svantaggi rispetto ai vettori

- La dimensione della lista può essere modificata a runtime
- Lo spostamento di elementi è molto veloce
- L’accesso all’i-esimo elemento è più lento perchè devo scorrere tutta o parte della lista

---
layout: two-cols

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

# Inserimento in testa alla lista 1

Situazione iniziale con una lista non vuota

![Inserimento in testa alla lista](/list2.png)

---

# Inserimento in testa alla lista 2

Creo una nuova variabile per contenere il nuovo elemento della lista

![Inserimento in testa alla lista](/list3.png)

---

# Inserimento in testa alla lista 3

Copio il valore ed il puntatore alla testa della lista nel nuovo elemento

![Inserimento in testa alla lista](/list4.png)

---

# Inserimento in testa alla lista 4

Cambio il valore di Head

![Inserimento in testa alla lista](/list5.png)

---

# Rimozione dalla testa

- Copio il valore dell’elemento in testa in una variabile temporanea
- Copio il puntatore all’elemento in testa (head) in una variabile temporanea
- Copio il puntatore al secondo elemento in head
- Rilascio la memoria allocata per l’elemento rimosso

![Rimozione dalla testa](/list6.png)

---

# Liste bidirezionali

Situazione iniziale con una lista non vuota

![Rimozione dalla testa](/list7.png)

---

# Liste di liste

- Posso suddividere la lista in parti per rendere più veloce la navigazione all’interno della lista
- Uso un algoritmo di hashing per definire il partizionamento e quindi la ricerca
<Transform :scale="0.7" >

![Rimozione dalla testa](/list8.png)
</Transform>

---
layout: two-cols

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

# Esempio di menù

```txt

Operazioni possibili:
a. AddToHead
b. AddToTail
c. RemoveFromHead
d. RemoveFromTail
e. ClearAll
p. PrintAll
x. Exit

Scelta:

```

---

# Esempio di output

```txt


0) address: [0x6000039dc000], value: [22222], next: [0x6000039c4000]
1) address: [0x6000039c4000], value: [11111], next: [0x0]
Operazioni possibili:
a. AddToHead
b. AddToTail
c. RemoveFromHead
d. RemoveFromTail
e. ClearAll
p. PrintAll
x. Exit

Scelta:

```

---

# Soluzione 1/7

<<< @/snippets/example24/simple_list.c#snippet1 c

---

# Soluzione 2/7

<<< @/snippets/example24/simple_list.c#snippet2 c

---

# Soluzione 3/7

<<< @/snippets/example24/simple_list.c#snippet3 c

---

# Soluzione 4/7

<<< @/snippets/example24/simple_list.c#snippet4 c

---

# Soluzione 5/7

<<< @/snippets/example24/simple_list.c#snippet5 c

---

# Soluzione 6/7

<<< @/snippets/example24/simple_list.c#snippet6 c

---

# Soluzione 7/7

<<< @/snippets/example24/simple_list.c#snippet7 c

---

# Esercizio: indovina il numero

- Scrivere un programma “Indovina il numero” che:
  - chiede all’utente il valore massimo e il numero massimo di tentativi
  - genera un numero casuale in [0, max]
  - richiede i tentativi all’utente indicando se il numero inserito è troppo alto o troppo basso
  - termina con messaggio di successo o di esaurimento tentativi mostrando la soluzione
- Confrontare la propria soluzione con l’esempio in `snippets/example17/main.c`.

```c
    srand(time(NULL)); // Seed the random number generator
    number = rand() % (max_number + 1); // Generate a random number between 0 and max_number

```

---

# Esercizi aggiuntivi

- Scrivere un programma che legga da un file di testo una sequenza di interi (numero di valori ignoto), li memorizzi in un vettore allocato dinamicamente e stampi media, minimo e massimo. Usare `realloc` per crescere il vettore mentre si legge il file.
- Leggere da un file di testo una lista di nomi (max 30 caratteri ciascuno), salvarli in un array di stringhe allocato dinamicamente e scrivere su un secondo file solo i nomi che iniziano per vocale. Gestire correttamente la deallocazione di tutte le stringhe.
- Implementare una rubrica semplice: leggere righe "nome numero" da un file, memorizzarle in un array di struct allocato dinamicamente, ordinare per nome e riscrivere su un nuovo file la rubrica ordinata. Prevedere il controllo di errori di apertura file e di allocazione.
