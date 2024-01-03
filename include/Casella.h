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
#define PERNOTTAMENTO_CASA_ECO 2
#define PERNOTTAMENTO_ALBERGO_ECO 4
#define PERNOTTAMENTO_CASA_STANDARD 4
#define PERNOTTAMENTO_ALBERGO_STANDARD 8
#define PERNOTTAMENTO_CASA_LUSSO 7
#define PERNOTTAMENTO_ALBERGO_LUSSO 14
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
    //void setProprietario(int);
    void reset();

    char getCategoria() const;
    char getTipo() const;
    int getId() const;
    bool getStato() const;
    std::string getNome()const;

private:
    int id;
    std::string nome;
    //int proprietario;
    bool stato; //true = disponibile
    char tipo; // ' '=terreno, '*'=casa, '^'=albergo
    char categoria; // ' '-> angolare, P->partenza, E->economica, S->standard, L->lusso
};
std::ostream& operator<<(std::ostream&, const Casella&);

int callCounter();
std::string setNome();

#endif //MONOPOLY_CASELLA_H