---
layout: cover
transition:
coverDate:

---

# 8 - Ripasso e verifica finale

Ing. Giancarlo Degani

---

# La verifica finale

Test di **20 domande a risposta multipla**, 30 punti in totale.

| Tipo di domanda | Numero | Punti per domanda | Totale |
| --- | :---: | :---: | :---: |
| Teoria | 10 | 1 | 10 |
| Interpretazione di un esempio di codice | 10 | 2 | 20 |
| **Totale** | **20** | | **30** |

- Il voto del corso è il punteggio del test
- Prima del test: ripasso guidato, in coppia

---

# Esempio: domanda di teoria

Qual è la differenza tra `&` e `&&`?

- **A)** Nessuna, sono due modi di scrivere lo stesso operatore
- **B)** `&` agisce sui singoli bit, `&&` è l'AND logico tra due condizioni
- **C)** `&` lavora sui `char`, `&&` sugli `int`
- **D)** `&&` agisce sui singoli bit, `&` è l'AND logico

Risposta corretta: **B**.

---

# Esempio: domanda su un codice

```c
int a[4] = {3, 8, 1, 6};
int max = a[0];

for (int i = 1; i < 4; i++) {
    if (a[i] > max) {
        max = a[i];
    }
}
printf("%d\n", max);
```

Che cosa stampa il programma?

- **A)** 3
- **B)** 8
- **C)** 6
- **D)** 18

Risposta corretta: **B**. Per rispondere si segue il programma passo per passo, come con il debugger.

---

# Ripasso: lezioni 1 e 2

**Algoritmi e primo programma**

- Algoritmo, esecutore, flowchart (selezione e cicli)
- Struttura di un programma C, `#include`, `main`, `printf`

**Variabili, tipi e input**

- Tipi primitivi, variabili, costanti, `cast`
- Operatori aritmetici, relazionali, logici; precedenza
- `printf` e `scanf` con i formati

---

# Ripasso: lezioni 3 e 4

**Condizioni e cicli**

- `if`, `if-else`, `switch` (e `break`)
- `for`, `while`, `do-while`, `break`, `continue`
- Errori tipici: off-by-one, cicli infiniti

**Vettori, matrici e stringhe**

- Indici da 0, limiti, nessuna copia con `=`
- Stringhe: terminatore `\0`, `string.h`, sicurezza (`gets` mai)

---

# Ripasso: lezioni 5 e 6

**Funzioni e puntatori**

- Prototipo e definizione, passaggio per valore
- Puntatori: `&` e `*`, modifica di variabili esterne, array come parametri
- Header, include guards, CMake, test con `assert`

**Bit e macchine a stati**

- Esadecimale, complemento a 2, `stdint.h`
- Set, clear, toggle e test di un bit; campi di un frame
- `enum` e macchina a stati con `switch`

---

# Ripasso: lezione 7

**Strutture, memoria dinamica, liste e file**

- `struct`, `typedef`, accesso con `.` e `->`
- `malloc` e `free`: ogni allocazione ha la sua liberazione
- Lista concatenata: nodo, `next`, inserimento in testa, scorrimento
- File: `fopen`, `fclose`, `fgets`, `sscanf`, `fprintf`, controllo degli errori

---

# Come prepararsi al test

- Per le domande su codice: simulare il programma **a mano**, annotando il valore delle variabili a ogni passo
- Rileggere gli esempi della lezione con la domanda "che cosa stampa?"
- Ricontrollare gli errori comuni: indici, `=` contro `==`, `&` contro `&&`, memoria non liberata
