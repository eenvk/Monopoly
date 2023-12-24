#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H
#include "Casella.h"
#include "Giocatore.h"
#include <algorithm>
#include <random>

class Tabellone{
public:
        Tabellone();
        void setCaselle();
        Casella* getTabellone();
        void resetCaselle(Giocatore);

private:
    Casella tabellone[28];
};

std::ostream& operator<<(std::ostream&, Tabellone&);

#endif //MONOPOLY_TABELLONE_H
