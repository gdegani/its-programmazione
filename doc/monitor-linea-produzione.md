# Progetto: monitor di linea di produzione

Il monitor di linea di produzione è un simulatore didattico di supervisione di
una macchina produttiva.

Non deve comandare realmente motori o sensori: deve comportarsi come un piccolo
pannello che riceve dati, li interpreta e informa l'operatore.

## Scenario

La macchina simulata è, per esempio, una pressa industriale. Il programma riceve
dati come:

```text
Temperatura: 72.5 °C
Vibrazione: 3.2 mm/s
Velocità: 120 pezzi/ora
Pezzi prodotti: 458
```

Per ogni valore il programma conosce anche un limite:

```text
Temperatura massima: 80.0 °C
Vibrazione massima: 5.0 mm/s
Velocità minima: 100 pezzi/ora
```

Il programma confronta le misure con questi limiti e determina lo stato della
macchina.

## Funzionamento principale

A ogni ciclo il monitor dovrebbe:

1. leggere una misura;
   - inizialmente da tastiera;
   - successivamente da dati simulati;
   - infine da un file CSV;
2. identificare il sensore, per esempio `TEMP-01`, `VIB-01` o `SPEED-01`;
3. memorizzare il valore e l'unità di misura;
4. confrontare il valore con le soglie;
5. determinare lo stato della misura o della macchina;
6. visualizzare un messaggio per l'operatore;
7. conservare la misura per analizzarla insieme alle successive.

Gli stati possibili possono essere:

```text
NORMAL
WARNING
ALARM
```

## Esempio senza allarme

```text
=== LINE MONITOR ===
Machine: Press 01
Sensor: TEMP-01
Value: 72.5 C
Limit: 80.0 C
Machine state: RUNNING
Alarm: NONE
```

## Esempio con allarme

```text
=== LINE MONITOR ===
Machine: Press 01
Sensor: TEMP-01
Value: 86.2 C
Limit: 80.0 C
Machine state: ALARM
Alarm: HIGH TEMPERATURE
Action: STOP AND INSPECT
```

Il programma non arresta realmente la pressa: visualizza l'azione che, in un
sistema reale, dovrebbe essere intrapresa.

## Versione finale prevista

Nella versione finale il programma potrebbe leggere un file CSV:

```csv
time,sensor_id,value,unit
08:00,TEMP-01,72.5,C
08:05,TEMP-01,74.1,C
08:10,VIB-01,3.2,mm/s
08:15,TEMP-01,86.2,C
```

E potrebbe produrre un report:

```text
=== PRODUCTION LINE REPORT ===
Machine: Press 01
Measurements: 4
Temperature average: 77.6 C
Maximum temperature: 86.2 C
Alarms: 1
Final state: ALARM
```

## Evoluzione durante il corso

- **Lezione 2:** lettura e stampa di una misura;
- **Lezione 3:** confronto con una soglia e segnalazione dell'allarme;
- **Lezione 4:** memorizzazione di molte misure in un vettore;
- **Lezione 5:** suddivisione del programma in funzioni e moduli;
- **Lezione 6:** gestione degli stati della macchina e dei bit di allarme;
- **Lezione 7:** lettura da CSV, lista concatenata e report finale.

## Obiettivo didattico

Il progetto trasforma progressivamente un semplice programma che stampa un
valore in un piccolo sistema di monitoraggio simulato, capace di raccogliere
dati, rilevare anomalie e riassumere il comportamento della linea.

Il progetto è previsto nel piano del corso, ma la sua realizzazione completa
nelle slide e negli snippet è ancora da sviluppare.
