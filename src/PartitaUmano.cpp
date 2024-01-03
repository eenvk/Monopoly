#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    this->giocatori.push_back(new GiocatoreUmano());
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
    t.printTabellone(giocatori);
}