//Edoardo Renzi

#ifndef MONOPOLY_TABELLONE_H
#define MONOPOLY_TABELLONE_H
#include "Casella.h"
#include "Giocatore.h"
#include <ctime>

constexpr int  NUMERO_GIOCATORI = 4;
constexpr int  NUMERO_CASELLE = 28;
constexpr int  BASE = 8;
constexpr int  ALTEZZA = 8;

class Tabellone{
public:
    Tabellone();
    Casella* getTabellone();
    void printTabellone(const std::vector<Giocatore*> giocatori) const;

private:
    void setCaselle();
    void nominaCaselle();
    Casella tabellone[NUMERO_CASELLE];
};

#endif //MONOPOLY_TABELLONE_H