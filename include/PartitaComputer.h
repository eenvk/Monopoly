#ifndef MONOPOLY_PARTITACOMPUTER_H
#define MONOPOLY_PARTITACOMPUTER_H
#include "Partita.h"

class PartitaComputer: public Partita{
public:
    PartitaComputer();
    void printWinner() override;
};

#endif //MONOPOLY_PARTITACOMPUTER_H