#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H
#include "Casella.h"
#include "Giocatore.h"
#include <random>

class Tabellone{
public:
        Tabellone();
        void setCaselle();
        Casella* getTabellone();
        void resetCaselle(Giocatore);
        void printTabellone(std::vector<Giocatore> giocatori);

private:
    Casella tabellone[28];
};

#endif //MONOPOLY_TABELLONE_H