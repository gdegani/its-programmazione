---
layout: cover
transition:
coverDate:

---

# 6 - Bit, enumerazioni e macchine a stati

Ing. Giancarlo Degani

---

---

# Codifiche numeriche

|Sistema|Base|Simboli|
|---|---|---|
|Binario|2|\{0,1\}|
|Ottale|8|\{0,1,2,3,4,5,6,7\}|
|Decimale|10|\{0,1,2,3,4,5,6,7,8,9\}|
|Esadecimale|16|\{0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F\}|

---

# Esempi

|Decimale|Binario|Esadecimale|
|---|---|---|
|2|10|2|
|10|1010|A|
|16|1 0000|10|
|255|1111 1111|FF|

---

# Codifica numerica posizionale

<br>

$$
n = \sum_{\substack{0 < i < m}} r_j \cdot b^j
$$

$$
1024 = 1 \times 10^3 + 0 \times 10^2 + 2 \times 10^1 + 4 \times 10^0 = 1024_{10}
$$

<br>

$$
10 = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0 = 1010_2
$$

<br>

$$
1024_{10} = 1 \times 2^{10} + 0 \times 2^9 + 0 \times 2^8 + 0 \times 2^7 + 0 \times 2^6 + 0 \times 2^5
\\+ 0 \times 2^4 + 0 \times 2^3 + 0 \times 2^2 + 0 \times 2^1 + 0 \times 2^0 = 100 0000 0000_2
$$

---
layout: two-cols

---

# Conversione IN BINARIO

- Per convertire un numero da base decimale a base binaria si utilizzano le operazioni di divisione intera e modulo (quoziente e resto):
  - Divido il numero per 2 e salvo il resto della divisione.
  - Ripeto fino a che il quoziente diventa zero.

$$
\begin{align*}
1972_{10} = 111;1011;0111_2
\end{align*}
$$

::right::

|N div B|N mod B||
|---|---|---|
|1972 / 2|986|0 ← LSB|
| 986 / 2  | 493    | 0       |
| 493 / 2  | 246    | 1       |
|…|…|…|
| 15 / 2   | 7      | 1       |
| 7 / 2    | 3      | 1       |
| 3 / 2    | 1      | 1       |
| 1 / 2    | 0      | 1 ← MSB |

---

# CONVERSIONE IN ESADECIMALE

- La stessa procedura usata per la conversione in binario può essere applicata anche alla conversione in base 16.
- Considerato che 16 è una potenza di 2, solitamente si converte prima in binario e poi si raggruppano i bit in gruppi di quattro (16 = 2⁴).

$${all}
255_{10} = 1111;1111_2 = FF_{16}
$$

---

# unità di misura

- In binario, l’unità di misura fondamentale è l’informazione rappresentabile con una sola cifra binaria, zero o uno, detta bit (Binary digIT).
- Una sequenza di 8 bit è definita Byte.

|Multipli|Valore|Valore|
|---|---:|---:|
|Kilobyte - KB|2<sup>10</sup>|1 024|
|Megabyte - MB|(2<sup>10</sup>)<sup>2</sup>|1 048 576|
|Gigabyte - GB|(2<sup>10</sup>)<sup>3</sup>|1 073 741 824|
|Terabyte - TB|(2<sup>10</sup>)<sup>4</sup>|1 099 511 627 776|

---

# Rappresentazione di interi in modulo e segno

- Supponiamo di avere un registro di 4 byte = 32 bit.
- I bit sono convenzionalmente numerati da 0 a 31 da destra verso sinistra, dove un indice maggiore corrisponde a un peso maggiore.
- Si utilizza il primo bit a sinistra per rappresentare il segno:
  - 0: numero positivo
  - 1: numero negativo
- I bit da 0 a 30 rappresentano il valore assoluto del numero.

---

# Rappresentazione di interi in modulo e segno

Si possono rappresentare i seguenti numeri:

- Positivi: da +0 a +2<sup>31</sup>-1 = 2.147.483.647
- Negativi: da -0 a -(2<sup>31</sup>-1) = -2.147.483.647

|Cifra|1|0|1|…|0|1|1|0|
|---|---|---|---|---|---|---|---|---|
|Indice|31|30|29|…|3|2|1|0|

---

# Il complemento a due

- Metodo per rappresentare numeri interi con segno nei computer.
- Calcolo del complemento a due:
  - Rappresentare il numero in forma binaria: 0000 0101 (5).
  - Invertire tutti i bit (sostituendo 0 con 1 e viceversa): 1111 1010
    - Ovvero eseguire il complemento a uno).
  - Aggiungere il valore 1: 1111 1011 (che rappresenta -5).

---

# Rappresentazione di interi in complemento a 2

- Nella codifica in complemento a due:
  - I numeri positivi sono rappresentati in modulo e segno.
  - I numeri negativi sono rappresentati in complemento a due.
- Con n bit si possono rappresentare numeri da -2<sup>n-1</sup> a 2<sup>n-1</sup>-1.
  - Con 8 bit, ad esempio, si possono rappresentare i numeri da -128 a +127.

---

# Codifica di caratteri

- La prima codifica utilizzata fu lo standard ASCII (American Standard Code for Information Technology).
- Prevedeva l’uso di 7 bit per rappresentare caratteri alfabetici, simboli grafici e alcuni caratteri speciali.
- Successivamente fu estesa a 8 bit.

---
layout: image
image: /ascii.png
backgroundSize: contain
title: Tabella ASCII

---

---

# UNICODE

- Unicode è uno standard per la rappresentazione e gestione di testi di ogni lingua e simboli utilizzati in tutto il mondo. È stato creato per risolvere i problemi di compatibilità tra i diversi sistemi di codifica (come ASCII o Latin-1).
- Ogni carattere in Unicode è identificato da un numero unico chiamato code-point. Questi numeri possono essere rappresentati nel computer con varie codifiche, tra cui le più comuni sono UTF-8, UTF-16 e UTF-32.
- Supporta anche la rappresentazione di alfabeti complessi come il cinese, il giapponese e il coreano.

---

# UNICODE - Codifiche

**UTF-8 (8-bit Unicode Transformation Format)**

- Codifica a lunghezza variabile: usa da 1 a 4 byte per carattere
- Retrocompatibile con ASCII (i primi 128 caratteri sono identici)
- Più efficiente per testi in lingue occidentali
- Standard dominante su Internet (oltre 98% dei siti web)

**UTF-16 (16-bit Unicode Transformation Format)**

- Codifica a lunghezza variabile: usa 2 o 4 byte per carattere
- Più efficiente per lingue asiatiche (cinese, giapponese, coreano)
- Utilizzato internamente da Java, C#, Windows e JavaScript
- Richiede più spazio per testi in lingue occidentali rispetto a UTF-8

---

# UNICODE

- Gestisce simboli matematici, emoticon e caratteri speciali.
- È essenziale per l’internazionalizzazione e lo sviluppo di applicazioni moderne, soprattutto con la diffusione di Internet.
- Esempi di code-point:
  - Carattere “A” → U+0041
  - Carattere “😊” → U+1F60A
  

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
