#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    giocatori.push_back(Giocatore(1));
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(Giocatore(2));
    }
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        std::cout<<giocatori[i]<<"\n";
    }
    t.printTabellone(giocatori);
}