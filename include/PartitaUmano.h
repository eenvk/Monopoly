#ifndef MONOPOLY_PARTITAUMANO_H
#define MONOPOLY_PARTITAUMANO_H
#include "Partita.h"
class PartitaUmano:public Partita{
public:
    //PartitaUmano();
private:
    Tabellone t;
    std::vector<Giocatore> giocatori;
};
#endif //MONOPOLY_PARTITAUMANO_H