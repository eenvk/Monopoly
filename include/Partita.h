#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#define NUMERO_GIOCATORI 4
#include "Tabellone.h"
#include <map>

class Partita {
protected:
    Partita();
    Tabellone t = Tabellone();
    std::vector<Giocatore> giocatori;
};

#endif //MONOPOLY_PARTITA_H