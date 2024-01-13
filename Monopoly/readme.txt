
MONOPOLY
Scelte di programmazione

Per giocatore abbiamo adottato l'ereditarietà in quanto ci sono due tipi di giocatori che hanno due comportamenti diversi in alcune funzionalità
(acquisto di terreni/case/alberghi).

Qualsiasi partita venga giocata essa ha la stessa struttura indipendentemente dal numero/varietà di giocatori,
semplicemente quando viene incontrato un giocatore che è umano si interagisce con quest'ultimo facendogli la domanda appropriata.
Quindi l'unica cosa che differenzia le partite è il vector di giocatori:
1. vector con un GiocatoreUmano e tre GiocoatoreComputer;
2. vector con quattro GiocatoreComputer;

Note
Tenendo "20 fiorini" come quantità che ogni giocatore riceve ogni volta che passa per la partenza, nessun giocatore riesce a essere eliminato,
affinché succeda ciò servirebbe un numero davvero molto elevato di turni.
Dunque conviene abbassare la quantità di fiorini da 20 a 1 o 2 così che almeno un giocatore riesca a essere eliminato tenendo un numero ragionevole di turni.

Struttura del progetto

Il codice è organizzato nelle seguenti directory:

📦 monopoly
┣📂 include
┃ ┣ 📜 Casella.h
┃ ┣ 📜 Giocatore.h
┃ ┣ 📜 GiocatoreComputer.h
┃ ┣ 📜 GiocatoreUmano.h
┃ ┣ 📜 LogManager.h
┃ ┣ 📜 Partita.h
┃ ┣ 📜 Tabellone.h
┣📂 src
┃ ┣ 📜 Casella.cpp
┃ ┣ 📜 Giocatore.cpp
┃ ┣ 📜 GiocatoreComputer.cpp
┃ ┣ 📜 GiocatoreUmano.cpp
┃ ┣ 📜 Partita.cpp
┃ ┣ 📜 Tabellone.cpp
┣📜 main.cpp
┣📜 CMakeLists.txt
┣📜 README.md
┣📜 README.txt
