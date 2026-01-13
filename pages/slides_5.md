---
layout: cover
coverDate:
transition:
---

# 5 - Enumerazioni e Funzioni

Ing. Giancarlo Degani

---

# Cos'è un'enumerazione?

Le **enumerazioni** (enum) permettono di definire un insieme di costanti intere con nomi significativi.

## Problema senza enum

```c
#define LUNEDI 0
#define MARTEDI 1
#define MERCOLEDI 2
// ... difficile da gestire
```

## Soluzione con enum

```c
enum giorni_settimana {
    LUNEDI,     // 0
    MARTEDI,    // 1
    MERCOLEDI,  // 2
    GIOVEDI,    // 3
    VENERDI,    // 4
    SABATO,     // 5
    DOMENICA    // 6
};
```

---

# Enumerazioni: sintassi

## Sintassi generale

```c
enum nome_tipo {
    VALORE1,
    VALORE2,
    VALORE3
};
```

## Caratteristiche

- Per default, il primo valore è **0**
- Ogni valore successivo è **incrementato di 1**
- I nomi devono essere **unici** nello stesso scope
- Migliorano la **leggibilità** del codice
- Evitano "numeri magici" nel codice

---

# Assegnazione di valori espliciti

È possibile assegnare valori espliciti agli elementi di un enum:

```c
enum ErrorCode {
    OK = 0,
    WARNING = 100,
    ERROR = 200,
    CRITICAL = 300
};

enum HttpStatus {
    HTTP_OK = 200,
    HTTP_NOT_FOUND = 404,
    HTTP_ERROR = 500
};
```

## Regola

- Se assegni un valore esplicito, il successivo sarà `valore + 1`
- Puoi mescolare valori espliciti e automatici

---

# Enumerazioni: valori duplicati

I **nomi** devono essere unici, ma i **valori** possono ripetersi:

```c
enum Stato {
    SPENTO = 0,
    OFF = 0,        // Stesso valore di SPENTO
    ACCESO = 1,
    ON = 1          // Stesso valore di ACCESO
};
```

## Nota

- `SPENTO` e `OFF` hanno lo stesso valore (0)
- Utile per alias o compatibilità

---

# Enum con switch: esempio pratico

```c
#include <stdio.h>

enum Semaforo {
    ROSSO,
    GIALLO,
    VERDE
};

void stampa_azione(enum Semaforo stato) {
    switch (stato) {
        case ROSSO:
            printf("STOP - Non passare!\n");
            break;
        case GIALLO:
            printf("ATTENZIONE - Rallenta\n");
            break;
        case VERDE:
            printf("VIA LIBERA - Puoi passare\n");
            break;
        default:
            printf("Stato sconosciuto\n");
    }
}
```

---

# Typedef con enum

`typedef` crea un alias per semplificare l'uso dell'enum:

## Senza typedef

```c
enum boolean { FALSO, VERO };
enum boolean flag = VERO;  // Devi scrivere "enum boolean"
```

## Con typedef

```c
typedef enum { FALSO, VERO } boolean;
boolean flag = VERO;  // Più semplice!
```

## Esempio completo

```c
typedef enum {
    GENNAIO = 1, FEBBRAIO, MARZO, APRILE,
    MAGGIO, GIUGNO, LUGLIO, AGOSTO,
    SETTEMBRE, OTTOBRE, NOVEMBRE, DICEMBRE
} Mese;

Mese corrente = MARZO;  // Tipo Mese invece di enum Mese
```

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

**Output:**

```
main: x = 5
funzione_a: x = 10
funzione_b: x = 20
main: x = 5
```

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

**Output:**

```
Prima: x = 5
Dentro la funzione: n = 6
Dopo: x = 5
```

La funzione modifica solo la **copia** del parametro, non l'originale!

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

# Funzioni void

Le funzioni `void` non restituiscono alcun valore:

```c
#include <stdio.h>

void saluta(const char *nome) {
    printf("Ciao, %s!\n", nome);
}

void stampa_linea(void) {
    printf("====================\n");
}

int main(void) {
    stampa_linea();
    saluta("Mario");
    saluta("Luigi");
    stampa_linea();
    
    return 0;
}
```

**Output:**

```
====================
Ciao, Mario!
Ciao, Luigi!
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

# Progetti multi-file: uso

## File principale (main.c)

```c
#include <stdio.h>
#include "utility.h"

int main(void) {
    int a = 10, b = 20;
    
    printf("Massimo tra %d e %d: %d\n", a, b, max(a, b));
    printf("Minimo tra %d e %d: %d\n", a, b, min(a, b));
    
    return 0;
}
```

## Compilazione

```bash
gcc -c utility.c -o utility.o
gcc -c main.c -o main.o
gcc utility.o main.o -o programma
```

O in un solo comando:

```bash
gcc main.c utility.c -o programma
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
