#ifndef MONOPOLY_GIOCATOREUMANO_H
#define MONOPOLY_GIOCATOREUMANO_H
#include "Giocatore.h"

class GiocatoreUmano: public Giocatore{
public:
    GiocatoreUmano();
    void acquistaCasella(Casella&) override;
    void acquistaCasa(Casella&) override;
    void miglioraInAlbergo(Casella&) override;
};

#endif //MONOPOLY_GIOCATOREUMANO_H