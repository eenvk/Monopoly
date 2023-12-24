#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#define NUMERO_GIOCATORI
#include "Tabellone.h"
#include "map"

class Partita {
public:
    Partita();
public:
    Tabellone t;
    std::vector<Giocatore> giocatori;
};

#endif //MONOPOLY_PARTITA_H