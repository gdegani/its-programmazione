---
layout: cover
transition:
coverDate:

---

# 2 - Variabili, tipi, operatori e input

Ing. Giancarlo Degani

---
level: 2

---

# Creazione di un eseguibile

Il processo di creazione di un eseguibile a partire dai sorgenti è composto da 2 fasi:

- **compilazione**: il preprocessore espande le direttive come `#include`, poi il compilatore traduce il sorgente. Mancano ancora alcune parti (le "funzioni di base", come `printf`) e viene generato un file intermedio detto file oggetto
- **linking**: il file oggetto e le librerie vengono unite (collegate, "link") così da aggiungere le parti mancanti e costituire un unico file eseguibile. Il link può unire più file oggetto e più librerie.

Le fasi nel dettaglio sono in lezione 5.

---
level: 2

---

# Processo di build di un programma C

```mermaid {scale: 0.8, alt: 'Compilation pipeline diagram showing source files and headers flowing through preprocessor and compiler, then, with libraries, through the linker to create the executable'}
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
level: 2

---

# Elementi base del linguaggio C

Vediamo gli elementi fondamentali del linguaggio:

- Tipi di dato primitivi: `int`, `float`, `double`, `char`
- Variabili e costanti: dichiarazione e inizializzazione
- Output: `printf()`
- Operatori di assegnamento e aritmetici
- Input: `scanf()`
- Operatori relazionali e logici

---
level: 2

---

# Tipi di dato primitivi in C

Il C fornisce alcuni tipi di dato di base per rappresentare numeri e caratteri:

| Tipo | Descrizione | Dimensione tipica | Range (esempio) |
| --- | --- | --- | --- |
| `char` | Carattere/byte | 1 byte | da -128 a 127 oppure da 0 a 255 |
| `int` | Intero | 4 byte | da -2.147.483.648 a 2.147.483.647 |
| `float` | Reale a precisione singola | 4 byte | $\pm 3.4 \times 10^{38}$ (circa 7 cifre) |
| `double` | Reale a precisione doppia | 8 byte | $\pm 1.7 \times 10^{308}$ (circa 15 cifre) |

## Nota

Le dimensioni dipendono dall'architettura (32 o 64 bit). `sizeof(tipo)` restituisce la dimensione esatta.

---
level: 2

---

# Modificatori di tipo

I modificatori `signed`, `unsigned`, `short`, `long` cambiano il range dei tipi interi:

| Tipo | Dimensione | Range |
| --- | --- | --- |
| `short int` (o `short`) | 2 byte | da -32.768 a 32.767 |
| `unsigned int` | 4 byte | da 0 a 4.294.967.295 |
| `long int` (o `long`) | 4 o 8 byte | dipende dall'architettura |
| `long long int` | 8 byte | da -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807 |

## Quando usare unsigned

- Quando il valore non può mai essere negativo (dimensioni, contatori)
- Per raddoppiare il massimo valore positivo rappresentabile

---
level: 2

---

# Dichiarazione di variabili

## Sintassi

```c
type variable_name;
```

## Esempi

```c
int rpm;
double voltage;
char status;
```

## Regole per i nomi

- Iniziano con una lettera o con underscore `_`
- Contengono lettere, cifre, underscore
- Distinguono maiuscole e minuscole: `count` ≠ `Count`
- Non possono essere parole chiave (`int`, `for`, `if`...)

---
level: 2

---

# Dichiarazione di variabili: buone pratiche

```c
// ✅ Descriptive names, snake_case
int motor_speed;
float max_temperature;

// ❌ Unclear names
int x;
float f;
```

---
level: 2

---

# Inizializzazione di variabili

## Senza inizializzazione

```c
int count;              // undefined value (garbage)
float temperature;      // ⚠️ not initialized!
```

## Con inizializzazione

```c
int count = 0;
float temperature = 20.5;
double v_ref = 3.3;
char status = 'R';
```

## Inizializzazione multipla

```c
int x = 10, y = 20, z = 30;
float a, b = 2.5, c;    // only b is initialized!
```

⚠️ Inizializzare sempre le variabili prima di usarle.

---
level: 2

---

# Costanti

Le costanti sono valori che non possono cambiare durante l'esecuzione.

## Metodo 1: #define (direttiva del preprocessore)

```c
#define ADC_MAX 4095
#define MAX_SENSORS 8
#define GREETING "Hello, world!"
```

## Metodo 2: const (qualificatore di tipo)

```c
const double V_REF = 3.3;
const int MAX_SENSORS = 8;

// V_REF = 5.0;  // ❌ ERROR: a constant cannot be modified
```

## Differenza

`#define` è una sostituzione di testo, `const` è una variabile in sola lettura con un tipo.

---
level: 2

---

# Output: printf()

`printf()` stampa testo formattato sullo standard output (il terminale):

```c
printf("format", arguments...);
```

## Specificatori di formato

| Specificatore | Tipo | Esempio |
| --- | --- | --- |
| `%d` o `%i` | `int` | `printf("%d", 42);` → `42` |
| `%u` | `unsigned int` | `printf("%u", 7u);` → `7` |
| `%ld` | `long` | `printf("%ld", 100000L);` → `100000` |
| `%f` | `float` e `double` | `printf("%f", 3.14);` → `3.140000` |
| `%c` | `char` | `printf("%c", 'A');` → `A` |
| `%s` | stringa | `printf("%s", "Hello");` → `Hello` |
| `%%` | il carattere `%` | `printf("%%");` → `%` |

---
level: 2

---

# printf(): esempio

<<< @/snippets/example36/main.c#snippet1 c {*}{lines:true}

## Output

```txt
Machine started
Speed: 1500 rpm
Temperature: 72.500000
Status: R
1500 rpm at 72.5 C, status R
```

---
level: 2

---

# printf(): controllo del formato

Larghezza del campo e numero di decimali:

<<< @/snippets/example36/main.c#snippet2 c {*}{lines:true}

## Output

```txt
[ 1500]
[1500  ]
[72.50]
[   72.50]
```

---
level: 2

---

# Operatore di assegnamento

L'operatore `=` assegna un valore a una variabile:

```c
int x;
x = 10;         // assign 10 to x

int y = 20;     // declaration + assignment

// multiple assignment (right to left)
int a, b, c;
a = b = c = 5;  // all three are 5
```

## Attenzione

`=` è l'assegnamento, `==` è il confronto:

```c
int x = 10;
x = 5;          // ✅ assignment: x becomes 5
if (x == 5)     // ✅ comparison: is x equal to 5?
```

---
level: 2

---

# Assegnamenti composti

Gli operatori composti combinano un'operazione aritmetica con l'assegnamento:

| Operatore | Equivalente | Esempio | Risultato |
| --- | --- | --- | --- |
| `+=` | `x = x + y` | `x += 5` | aggiunge 5 a x |
| `-=` | `x = x - y` | `x -= 3` | sottrae 3 da x |
| `*=` | `x = x * y` | `x *= 2` | moltiplica x per 2 |
| `/=` | `x = x / y` | `x /= 4` | divide x per 4 |
| `%=` | `x = x % y` | `x %= 3` | x diventa il resto di x / 3 |

```c
int count = 10;
count += 5;     // 15
count *= 2;     // 30
count -= 10;    // 20
count /= 4;     // 5
```

---
level: 2

---

# Operatori di incremento e decremento

Gli operatori `++` e `--` aumentano o diminuiscono di 1.

## Post-incremento e post-decremento

```c
int x = 5;
int y = x++;    // y = 5, then x = 6 (use, then increment)
int z = x--;    // z = 6, then x = 5 (use, then decrement)
```

## Pre-incremento e pre-decremento

```c
int x = 5;
int y = ++x;    // x = 6, then y = 6 (increment, then use)
int z = --x;    // x = 5, then z = 5 (decrement, then use)
```

## Uso tipico

```c
count++;        // same as count = count + 1
```

---
level: 2

---

# Operatori aritmetici

Il C fornisce gli operatori aritmetici standard:

| Operatore | Operazione | Esempio | Risultato |
| --- | --- | --- | --- |
| `+` | Addizione | `5 + 3` | `8` |
| `-` | Sottrazione | `5 - 3` | `2` |
| `*` | Moltiplicazione | `5 * 3` | `15` |
| `/` | Divisione | `7 / 2` | `3` (tra interi!) |
| `%` | Modulo (resto) | `7 % 2` | `1` |

## Divisione tra interi

```c
int a = 7 / 2;          // 3 (truncated, not rounded)
float b = 7 / 2;        // 3.0 (integer division, then conversion)
float c = 7.0 / 2;      // 3.5 (one real operand: real division)
```

---
level: 2

---

# Precedenza degli operatori aritmetici

Gli operatori seguono le regole della matematica.

## Precedenza (dalla più alta alla più bassa)

1. Parentesi `( )`
2. Unari `+`, `-`, `++`, `--`
3. Moltiplicazione, divisione, modulo `*`, `/`, `%`
4. Addizione, sottrazione `+`, `-`

```c
int result;
result = 2 + 3 * 4;         // 14 (not 20!)
result = (2 + 3) * 4;       // 20
result = 10 - 4 / 2;        // 8 (not 3!)
result = (10 - 4) / 2;      // 3
```

Nel dubbio, usare le parentesi: il codice è più chiaro.

---
level: 2

---

# Conversioni di tipo

Quando si mescolano tipi diversi, il C converte automaticamente.

## Conversione implicita (promozione)

```c
int i = 5;
float f = 2.0;
float result = i + f;   // i becomes float: 7.0
```

Il tipo "più piccolo" viene promosso al tipo "più grande":

```txt
char → int → long → float → double
```

## Conversione esplicita (cast)

```c
int a = 7, b = 2;
float r1 = (float)a / b;     // 3.5
float r2 = (float)(a / b);   // 2.0: integer division first, then cast!
```

---
level: 2

---

# Esempi di conversioni di tipo

<<< @/snippets/example40/main.c#snippet1 c {*}{lines:true}

## Il troncamento non arrotonda

`3.9` diventa `3`, non `4`.

---
level: 2

---

# Cos'è un ADC

Un ADC (Analog-to-Digital Converter) converte una tensione analogica in un numero intero, che il programma può leggere. Un sensore (temperatura, pressione, posizione...) produce una tensione che varia con continuità. L'ADC la misura e restituisce un valore grezzo (`raw`).

## Perché 4096 livelli

Il numero di livelli dipende dai bit del convertitore: con $N$ bit ci sono $2^N$ valori, da 0 a $2^N - 1$.

| Bit | Livelli | Valori |
| --- | --- | --- |
| 8 | $2^8 = 256$ | da 0 a 255 |
| 10 | $2^{10} = 1024$ | da 0 a 1023 |
| 12 | $2^{12} = 4096$ | da 0 a 4095 |

---
level: 2

---

# La tensione di riferimento

La tensione di riferimento $V_{REF}$ è il "metro" dell'ADC: la tensione massima che sa misurare, a cui corrisponde il valore grezzo massimo.

L'ADC divide l'intervallo da 0 V a $V_{REF}$ nei suoi livelli. Con $V_{REF} = 3.3$ V e 12 bit:

| Tensione sul pin | Valore grezzo |
| --- | --- |
| 0 V | 0 |
| 1,65 V (metà) | circa 2048 |
| 3,3 V ($V_{REF}$) | 4095 |

$$
V = \frac{raw}{4095} \times V_{REF}
$$

Una tensione maggiore di $V_{REF}$ non è misurabile: l'ADC restituisce sempre 4095.

---
level: 2

---

# Esempio: lettura di un ADC

Un convertitore analogico-digitale a 12 bit restituisce un valore da 0 a 4095. Con una tensione di riferimento di 3,3 V:

<<< @/snippets/example38/main.c#snippet1 c {*}{lines:true}

## Output

```txt
Raw value: 2048
Wrong voltage: 0.00 V
Right voltage: 1.65 V
```

La divisione tra interi azzera il risultato: basta un `(float)` per correggerlo.

---
level: 2

---

# Input: scanf()

`scanf()` legge input formattato dallo standard input (la tastiera):

```c
scanf("format", &variable);
```

⚠️ Prima del nome della variabile si scrive `&` (l'indirizzo della variabile).

## Specificatori

| Tipo | Specificatore | Esempio |
| --- | --- | --- |
| `int` | `%d` | `scanf("%d", &rpm);` |
| `float` | `%f` | `scanf("%f", &temperature);` |
| `double` | `%lf` | `scanf("%lf", &voltage);` |
| `char` | `" %c"` | `scanf(" %c", &status);` |

Lo spazio prima di `%c` ignora gli spazi e gli invii rimasti nell'input.

---
level: 2

---

# scanf(): esempio completo

<<< @/snippets/example37/main.c#snippet1 c {*}{lines:true}

## Esempio di esecuzione

```txt
Enter first temperature: 70
Enter second temperature: 73
Average: 71.50
```

---
level: 2

---

# scanf(): lettura multipla

## Più valori sulla stessa riga

```c
int x, y, z;
printf("Enter three numbers: ");
scanf("%d %d %d", &x, &y, &z);      // input: 10 20 30
```

## Separatori specifici

<<< @/snippets/example37/main.c#snippet2 c {*}{lines:true}

## Attenzione

`scanf()` non controlla che l'input sia valido: se si aspetta un numero e l'utente scrive una lettera, la variabile resta invariata. Le stringhe con `scanf` si vedranno in lezione 4.

---
level: 2

---

# Esercizio 1: da Celsius a Fahrenheit

Livello base, in coppia.

Scrivere un programma che:

- legge una temperatura in gradi Celsius (`float`)
- stampa il valore in gradi Fahrenheit con un decimale

La formula è `F = C * 9 / 5 + 32`. Attenzione all'ordine: `9 / 5` tra interi vale 1.

## Prove

- `0` → `32.0`
- `100` → `212.0`
- `-40` → `-40.0`

---
level: 2

---

# Esercizio 2: da ADC a temperatura

Livello standard, in coppia.

Un sensore di temperatura analogico fornisce 10 mV per ogni grado Celsius. Il convertitore è a 12 bit (0-4095) con riferimento a 3,3 V.

Scrivere un programma che:

- legge il valore grezzo dell'ADC (`int`)
- calcola la tensione in volt
- calcola e stampa la temperatura in gradi Celsius con un decimale

## Prove

- `0` → `0.0`
- `2048` → `165.0`
- `4095` → `330.0`

---
level: 2

---

# Operatori relazionali

Gli operatori relazionali confrontano due valori. In C `0` è falso e qualsiasi altro valore è vero:

| Operatore | Significato | Esempio | Risultato |
| --- | --- | --- | --- |
| `==` | uguale a | `5 == 5` | vero (1) |
| `!=` | diverso da | `5 != 3` | vero (1) |
| `<` | minore di | `3 < 5` | vero (1) |
| `>` | maggiore di | `5 > 3` | vero (1) |
| `<=` | minore o uguale | `3 <= 3` | vero (1) |
| `>=` | maggiore o uguale | `5 >= 5` | vero (1) |

⚠️ Non confondere il confronto `==` con l'assegnamento `=`: `if (x = 5)` è sempre vero.

---
level: 2

---

# Esempi di operatori relazionali

<<< @/snippets/example39/main.c#snippet1 c {*}{lines:true}

## Attenzione ai numeri reali

<<< @/snippets/example39/main.c#snippet3 c {*}{lines:true}

Il confronto di uguaglianza tra numeri reali è inaffidabile per via degli errori di arrotondamento.

---
level: 2

---

# Operatori logici

Gli operatori logici combinano espressioni:

| Operatore | Nome | Descrizione | Esempio | Risultato |
| --- | --- | --- | --- | --- |
| `&&` | AND | vero se **entrambi** veri | `1 && 1` | `1` |
| `\|\|` | OR | vero se **almeno uno** vero | `0 \|\| 1` | `1` |
| `!` | NOT | inverte il valore | `!1` | `0` |

## Esempi

```c
int a = 1, b = 0;

int r1 = a && b;   // 0
int r2 = a || b;   // 1
int r3 = !a;       // 0
int r4 = !b;       // 1
```

---
layout: two-cols-header
level: 2

---

# Tabelle di verità

`!` inverte il valore: `!0` è `1` e `!1` è `0`.

::left::

| A | B | A `&&` B |
| :-: | :-: | :-: |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

::right::

| A | B | A `\|\|` B |
| :-: | :-: | :-: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

---
level: 2

---

# Short-circuit evaluation

Gli operatori `&&` e `||` valutano da sinistra a destra e si fermano appena il risultato è noto.

## AND

```c
int x = 0, y = 5;
if (x != 0 && y / x > 2) {  // y / x is NOT evaluated: no division by zero
    // ...
}
```

Se il primo operando è falso, il secondo non viene valutato.

## OR

```c
if (temperature < 0 || temperature > 100) {  // the second test is skipped if the first is true
    // ...
}
```

Se il primo operando è vero, il secondo non viene valutato.

---
level: 2

---

# Esempio: condizioni di una macchina

<<< @/snippets/example39/main.c#snippet2 c {*}{lines:true}

## Output

```txt
Motor can run: 1
Must stop: 0
```

---
level: 2

---

# Precedenza degli operatori (completa)

## Dalla più alta alla più bassa

1. Parentesi e accesso `()` `[]`
2. Unari `!` `++` `--` `+` `-` `(tipo)`
3. Moltiplicativi `*` `/` `%`
4. Additivi `+` `-`
5. Relazionali `<` `<=` `>` `>=`
6. Uguaglianza `==` `!=`
7. AND logico `&&`
8. OR logico `||`
9. Assegnamento `=` `+=` `-=` `*=` `/=` `%=`

Nel dubbio, usare le parentesi:

```c
int x = 5 > 3 && 2 < 4;     // 1: comparisons first, then &&
int y = (5 > 3) && (2 < 4); // 1: clearer
```

---
level: 2

---

# Esercizio 3: controllo delle misure

Livello sfida, in coppia. Si usano solo espressioni: ogni risultato si stampa come `0` o `1`.

Scrivere un programma che legge due misure di temperatura (`float`) e stampa:

- `1` se entrambe sono comprese tra 0 e 100 (estremi inclusi), altrimenti `0`
- `1` se almeno una è fuori dall'intervallo, altrimenti `0`
- `1` se differiscono di più di 5 gradi, altrimenti `0`

Suggerimento: la differenza in valore assoluto si ottiene senza funzioni con due confronti.
