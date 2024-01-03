#ifndef MONOPOLY_PARTITACOMPUTER_H
#define MONOPOLY_PARTITACOMPUTER_H
#define MAX_TURNI 100
#include "Partita.h"

class PartitaComputer: public Partita{
public:
    PartitaComputer();
    void run() override;
};


#endif //MONOPOLY_PARTITACOMPUTER_H