//Edoardo Renzi

#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H
#include <iostream>

constexpr int PREZZO_ECO_TERRENO = 6;
constexpr int PREZZO_ECO_CASA = 3;
constexpr int PREZZO_ECO_ALBERGO = 3;
constexpr int PREZZO_STANDARD_TERRENO = 10;
constexpr int PREZZO_STANDARD_CASA = 5;
constexpr int PREZZO_STANDARD_ALBERGO = 5;
constexpr int PREZZO_LUSSO_TERRENO = 20;
constexpr int PREZZO_LUSSO_CASA = 10;
constexpr int PREZZO_LUSSO_ALBERGO = 10;
constexpr int PERNOTTAMENTO_CASA_ECO = 2;
constexpr int PERNOTTAMENTO_ALBERGO_ECO = 4;
constexpr int PERNOTTAMENTO_CASA_STANDARD = 4;
constexpr int PERNOTTAMENTO_ALBERGO_STANDARD = 8;
constexpr int PERNOTTAMENTO_CASA_LUSSO = 7;
constexpr int PERNOTTAMENTO_ALBERGO_LUSSO = 14;
constexpr char TERRENO = ' ';
constexpr char CASA = '*';
constexpr char ALBERGO = '^';
constexpr char ECONOMICA = 'E';
constexpr char STANDARD = 'S';
constexpr char LUSSO = 'L';
constexpr char PARTENZA = 'P';
constexpr char ANGOLARE = ' ';

class Casella{
public:
    class TerrenoNonAcquistabile{};
    class CasaNonAcquistabile{};
    class CasaNonMigliorabileInAlbergo{};

    Casella();
    Casella(const char);
    void acquistaTerreno();
    void acquistaCasa();
    void miglioraInAlbergo();
    void reset();

    char getCategoria() const;
    char getTipo() const;
    int getId() const;
    bool getStato() const;
    std::string getNome()const;
    void setNome(const std::string);
    bool operator==(const Casella&) const;

private:
    int id;
    std::string nome; //coordinata all'interno del tabellone
    bool stato; //true = disponibile
    char tipo; // ' '=terreno, '*'=casa, '^'=albergo
    char categoria; // ' '-> angolare, P->partenza, E->economica, S->standard, L->lusso
};
std::ostream& operator<<(std::ostream&, const Casella&);

int callCounter();

#endif //MONOPOLY_CASELLA_H