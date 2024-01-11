//Edoardo Renzi

#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H
#include "Casella.h"
#include "Giocatore.h"
#include <ctime>

constexpr int  NUMERO_GIOCATORI = 4;

class Tabellone{
public:
    Tabellone();
    Casella* getTabellone();
    void printTabellone(const std::vector<Giocatore*> giocatori) const;
private:
    void setCaselle();
    Casella tabellone[28];
};

#endif //MONOPOLY_TABELLONE_H