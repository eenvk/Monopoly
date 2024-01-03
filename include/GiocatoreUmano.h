#ifndef MONOPOLY_GIOCATOREUMANO_H
#define MONOPOLY_GIOCATOREUMANO_H
#include "Giocatore.h"

class GiocatoreUmano: public Giocatore{
public:
    GiocatoreUmano();
    void acquistaCasella(Casella& c);
    void acquistaCasa(Casella& c);
    void miglioraInAlbergo(Casella& c);
};

#endif //MONOPOLY_GIOCATOREUMANO_H