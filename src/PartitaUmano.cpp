#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    giocatori.push_back(Giocatore(1));
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(Giocatore(2));
    }
    t.printTabellone(giocatori);
}