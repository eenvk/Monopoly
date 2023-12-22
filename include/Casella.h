#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H

struct Coordinate{
    char row;
    char column;
};

class Casella{
public:
    Casella(char categoria, char abitazione, int giocatore, char colonna, char riga){
        categoria_casella = categoria;
        tipo_abitazione = abitazione;
        n_giocatore = giocatore;
        co.row = riga;
        co.column = colonna;
    }

    void acquista();
    void print() const;

private:
    bool comprato; //E' stata comprata la casella?
    char categoria_casella; // 'spazio'-> angolare, P->partenza, E->economica, S->standard, L->lusso
    char tipo_abitazione; // *-> casa, ^->albergo
    int n_giocatore; // 1,2,3,4
    Coordinate co;
};

#endif //MONOPOLY_CASELLA_H
