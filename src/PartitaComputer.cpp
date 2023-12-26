#include "../include/PartitaComputer.h"

PartitaComputer::PartitaComputer() {
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(Giocatore(2));
    }
    t.printTabellone(giocatori);
}