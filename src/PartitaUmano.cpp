#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    giocatori.push_back(GiocatoreUmano());
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(GiocatoreComputer());
    }
    ordinaGiocatori();
    t.printTabellone(giocatori);
}