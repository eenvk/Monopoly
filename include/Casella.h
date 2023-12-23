#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H

#include <iostream>

class Casella{
public:
    Casella();
    Casella(char);
    void acquistaCasella();
    void acquistaCasa();
    void miglioraInAlbergo();
    void reset();

    char getCategoria() const;
    void setCategoria(char c); // mi serve per tabellone
    int getTipo() const;
    int getId() const;

private:
    int id;
    bool stato; //true = disponibile
    int tipo; //1=terreno, 2=casa, 3=albergo
    char categoria; // 'spazio'-> angolare, P->partenza, E->economica, S->standard, L->lusso
};
std::ostream& operator<<(std::ostream&, const Casella&);

int callCounter();

#endif //MONOPOLY_CASELLA_H
