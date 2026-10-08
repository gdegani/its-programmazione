---
layout: cover
transition:
coverDate:

---

# 2 - Variabili, tipi, operatori e input

Ing. Giancarlo Degani

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

```txt
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

# Esercizio: Calcola la media

**Obiettivo:** Scrivere un programma che legge 3 numeri dall'utente e calcola la loro media

**Passi da seguire:**

1. Crea un nuovo progetto C in CLion: `calcola_media`
2. Dichiara 3 variabili di tipo `float` per i numeri (esempio: `num1`, `num2`, `num3`)
3. Dichiara una variabile `float` per la media (esempio: `media`)
4. Usa `printf()` per chiedere all'utente di inserire il primo numero
5. Usa `scanf("%f", &num1)` per leggere il primo numero
6. Ripeti i passi 4-5 per il secondo e terzo numero
7. Calcola la media: `media = (num1 + num2 + num3) / 3.0`
8. Stampa il risultato con `printf("La media è: %.2f\n", media)`

---

# Esercizio: Calcola la media

**Esempio di esecuzione:**

```text
Inserisci il primo numero: 8.5
Inserisci il secondo numero: 7.0
Inserisci il terzo numero: 9.5
La media è: 8.33
```

**Suggerimento:** Ricorda di includere `#include <stdio.h>` all'inizio del file!
