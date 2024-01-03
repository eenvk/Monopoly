#ifndef MONOPOLY_GIOCATOREUMANO_H
#define MONOPOLY_GIOCATOREUMANO_H
#include "Giocatore.h"

class GiocatoreUmano: public Giocatore{
public:
    GiocatoreUmano();
    void acquistaCasella(Casella& c) override;
    void acquistaCasa(Casella& c) override;
    void miglioraInAlbergo(Casella& c) override;
};

#endif //MONOPOLY_GIOCATOREUMANO_H