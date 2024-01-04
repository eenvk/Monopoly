#ifndef MONOPOLY_PARTITAUMANO_H
#define MONOPOLY_PARTITAUMANO_H
#include "Partita.h"
#include <typeinfo>
class PartitaUmano : public Partita{
public:
    PartitaUmano();
    void run() override;
    void HandleHumanCase(int&, int&, bool&, Casella*);
    void HandleComputerCase(int&, int&, bool&, Casella*);
};

#endif //MONOPOLY_PARTITAUMANO_H