#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#include "Tabellone.h"
#include "map"

class Partita {
protected:
    Partita();
private:
    Tabellone t;
    std::map<int, Giocatore> giocatori;
public:

};


#endif //MONOPOLY_PARTITA_H