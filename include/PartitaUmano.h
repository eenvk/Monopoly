#ifndef MONOPOLY_PARTITAUMANO_H
#define MONOPOLY_PARTITAUMANO_H
#include "Partita.h"

class PartitaUmano : public Partita{
public:
    PartitaUmano();
    void run() override;
};
#endif //MONOPOLY_PARTITAUMANO_H