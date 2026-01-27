---
layout: cover
transition:
coverDate: ""

---

# 7 -  Allocazione dinamica della memoria

Ing. Giancarlo Degani

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

- conta quanti sono i valori leggendoli dal file e scartandoli
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

---

# Esercizi aggiuntivi

- Scrivere un programma che legga da un file di testo una sequenza di interi (numero di valori ignoto), li memorizzi in un vettore allocato dinamicamente e stampi media, minimo e massimo. Usare `realloc` per crescere il vettore mentre si legge il file.
- Leggere da un file di testo una lista di nomi (max 30 caratteri ciascuno), salvarli in un array di stringhe allocato dinamicamente e scrivere su un secondo file solo i nomi che iniziano per vocale. Gestire correttamente la deallocazione di tutte le stringhe.
- Implementare una rubrica semplice: leggere righe "nome numero" da un file, memorizzarle in un array di struct allocato dinamicamente, ordinare per nome e riscrivere su un nuovo file la rubrica ordinata. Prevedere il controllo di errori di apertura file e di allocazione.
