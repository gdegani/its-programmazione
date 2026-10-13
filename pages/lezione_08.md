---
layout: cover
transition:
coverDate:

---

# 8 - Verifica finale e discussione

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
- Prima il test, poi la discussione con la classe

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

# Come affrontare le domande su codice

- Simulare il programma **a mano**, annotando il valore delle variabili a ogni passo
- Controllare i casi limite: primo e ultimo indice, condizioni con `=` o `==`, `&` o `&&`
- Non fidarsi della prima impressione: leggere tutte le risposte prima di scegliere

---

# Dopo il test: discussione

- Correzione delle domande, una alla volta
- Gli errori più frequenti e le loro cause
- Domande e dubbi sugli argomenti del corso
- Commenti della classe sul corso: che cosa ha funzionato e che cosa cambiare

---

# Che cosa viene dopo

Il corso prosegue con il modulo **"Programmazione assistita dall'AI"** (16 ore, 4 lezioni).

- Si lavora sul codice C scritto in questo corso: il progetto diventa il caso di studio
- Prima dell'inizio: richiedere la licenza gratuita di GitHub Education per Copilot, perché la verifica dello stato di studente può richiedere alcuni giorni
