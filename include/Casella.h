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
    void setCategoria(char); // mi serve per tabellone
    void setGiocatore(int);
    void deleteGiocatore();
    int getTipo() const;
    int getId() const;
    char getGiocatore() const;

private:
    int id;
    char giocatore;
    bool stato; //true = disponibile
    int tipo; //1=terreno, 2=casa, 3=albergo
    char categoria; // 'spazio'-> angolare, P->partenza, E->economica, S->standard, L->lusso
};
std::ostream& operator<<(std::ostream&, const Casella&);

int callCounter();

#endif //MONOPOLY_CASELLA_H
