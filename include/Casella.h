#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H

#include <iostream>

class Casella{
public:
    Casella(char);
    void acquistaCasella();
    void acquistaCasa();
    void miglioraInAlbergo();

private:
    bool stato; //true = disponibile
    int tipo; //1=terreno, 2=casa, 3=albergo
    char categoria; // 'spazio'-> angolare, P->partenza, E->economica, S->standard, L->lusso
    //char tipo_abitazione; // *-> casa, ^->albergo
    //int n_giocatore; // 1,2,3,4
};


#endif //MONOPOLY_CASELLA_H
