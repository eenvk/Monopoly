#include "Casella.h"
#include "Giocatore.h"
#include <iostream>
#include <algorithm>
#include <random>
#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H


class Tabellone{
public:
        Tabellone();
        Casella* getTabellone();
        void resetCaselle(Giocatore);

private:
    Casella tabellone[28];
};

std::ostream& operator<<(std::ostream&, Tabellone&);

#endif //MONOPOLY_TABELLONE_H
