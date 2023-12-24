#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#define NUMERO_GIOCATORI 4
#include "Tabellone.h"

class Partita {
protected:
    Partita();
public:
    Tabellone t;
    std::vector<Giocatore> giocatori;
};

#endif //MONOPOLY_PARTITA_H