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
public:
    void ordineGiocatoriNelTiroDadi();
    std::vector<Giocatore> getGiocatori();
};

#endif //MONOPOLY_PARTITA_H