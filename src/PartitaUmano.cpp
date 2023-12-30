#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    giocatori.push_back(Giocatore(UMANO));
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(Giocatore(COMPUTER));
    }
    ordinaGiocatori();
    t.printTabellone(giocatori);
}