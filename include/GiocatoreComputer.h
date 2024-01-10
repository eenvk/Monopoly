//Giada Zago

#ifndef MONOPOLY_GIOCATORECOMPUTER_H
#define MONOPOLY_GIOCATORECOMPUTER_H
#include "Giocatore.h"

class GiocatoreComputer: public Giocatore{
public:
    GiocatoreComputer();
    void acquistaCasella(Casella&) override;
    void acquistaCasa(Casella&) override;
    void miglioraInAlbergo(Casella&) override;
};

#endif //MONOPOLY_GIOCATORECOMPUTER_H