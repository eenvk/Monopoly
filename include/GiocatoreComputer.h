#ifndef MONOPOLY_GIOCATORECOMPUTER_H
#define MONOPOLY_GIOCATORECOMPUTER_H
#include "Giocatore.h"

class GiocatoreComputer: public Giocatore{
public:
    GiocatoreComputer();
    void acquistaCasella(Casella& c) override;
    void acquistaCasa(Casella& c) override;
    void miglioraInAlbergo(Casella& c) override;
};

#endif //MONOPOLY_GIOCATORECOMPUTER_H