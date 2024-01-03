#ifndef MONOPOLY_GIOCATORECOMPUTER_H
#define MONOPOLY_GIOCATORECOMPUTER_H
#include "Giocatore.h"

class GiocatoreComputer: public Giocatore{
public:
    GiocatoreComputer();
    void acquistaCasella(Casella& c) ;
    void acquistaCasa(Casella& c) ;
    void miglioraInAlbergo(Casella& c) ;
};

#endif //MONOPOLY_GIOCATORECOMPUTER_H