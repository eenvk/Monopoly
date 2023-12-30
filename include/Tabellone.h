#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H
#include "Casella.h"
#include "Giocatore.h"
#include <random>

class Tabellone{
public:
    Tabellone();
    Casella* getTabellone();
    void resetCaselle(Giocatore);
    void printTabellone(const std::vector<Giocatore> giocatori);
private:
    void setCaselle();
    Casella tabellone[28];
};

#endif //MONOPOLY_TABELLONE_H