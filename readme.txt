
# MONOPOLY

Lo metto qui così per compilarlo fate prima se non usate CMake:

```
g++ -o monopoly src/Casella.cpp src/Giocatore.cpp src/GiocatoreComputer.cpp src/GiocatoreUmano.cpp src/Partita.cpp src/PartitaComputer.cpp src/PartitaUmano.cpp src/Tabellone.cpp main.cpp

```

## Struttura del codice

Il codice è organizzato nelle seguenti directory:

📦 monopoly
┣📂 include
┃ ┣ 📜 Casella.h
┃ ┣ 📜 Giocatore.h
┃ ┣ 📜 GiocatoreComputer.h
┃ ┣ 📜 GiocatoreUmano.h
┃ ┣ 📜 Partita.h
┃ ┣ 📜 PartitaComputer.h
┃ ┣ 📜 PartitaUmano.h
┃ ┣ 📜 Tabellone.h
┣📂 src
┃ ┣ 📜 Casella.cpp
┃ ┣ 📜 Giocatore.cpp
┃ ┣ 📜 GiocatoreComputer.cpp
┃ ┣ 📜 GiocatoreUmano.cpp
┃ ┣ 📜 Partita.cpp
┃ ┣ 📜 PartitaComputer.cpp
┃ ┣ 📜 PartitaUmano.cpp
┃ ┣ 📜 Tabellone.cpp
┃ ┣ 📜 main.cpp
┣📜 CMakeLists.txt
┣📜 README.md
┣📜 README.txt

dove

1. **`include`**: Contiene i file header.


2. **`src`**: Contiene i file sorgente.

    - `main.cpp`: Un file sorgente di esempio che illustra come utilizzare le classi nel tuo progetto.

3. `CMakeLists.txt`: Gestisce i file nella compilazione del programma

## Scelte progettuali


## Esempio d'utilizzo del codice

```cpp


```