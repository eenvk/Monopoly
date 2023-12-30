#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H
#define PREZZO_ECO_TERRENO 6
#define PREZZO_ECO_CASA 3
#define PREZZO_ECO_ALBERGO 3
#define PREZZO_STANDARD_TERRENO 10
#define PREZZO_STANDARD_CASA 5
#define PREZZO_STANDARD_ALBERGO 5
#define PREZZO_LUSSO_TERRENO 20
#define PREZZO_LUSSO_CASA 10
#define PREZZO_LUSSO_ALBERGO 10
#define TERRENO ' '
#define CASA '*'
#define ALBERGO '^'
#define ECONOMICA 'E'
#define STANDARD 'S'
#define LUSSO 'L'
#define PARTENZA 'P'
#define ANGOLARE ' '

#include <iostream>

class Casella{
public:
    class TerrenoNonAcquistabile{};
    class CasaNonAcquistabile{};
    class CasaNonMigliorabileInAlbergo{};

    Casella();
    Casella(char);
    void acquistaTerreno();
    void acquistaCasa();
    void miglioraInAlbergo();
    void reset();

    char getCategoria() const;
    char getTipo() const;
    int getId() const;
    bool getStato() const;

private:
    int id;
    //char giocatore;
    bool stato; //true = disponibile
    char tipo; // ' '=terreno, '*'=casa, '^'=albergo
    char categoria; // ' '-> angolare, P->partenza, E->economica, S->standard, L->lusso
};
std::ostream& operator<<(std::ostream&, const Casella&);

int callCounter();

#endif //MONOPOLY_CASELLA_H