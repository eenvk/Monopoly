#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H

#include <iostream>

class Casella{
public:
    Casella(char);
    void acquistaCasella();
    void acquistaCasa();
    void miglioraInAlbergo();

    char getCategoria() const;
    int getTipo() const;
    int getId() const;

private:
    bool stato; //true = disponibile
    int tipo; //1=terreno, 2=casa, 3=albergo
    char categoria; // 'spazio'-> angolare, P->partenza, E->economica, S->standard, L->lusso
    int id;
};
std::ostream& operator<<(std::ostream&, const Casella&);

int call_counter();

#endif //MONOPOLY_CASELLA_H
