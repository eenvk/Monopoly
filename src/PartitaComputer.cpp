#include "../include/PartitaComputer.h"

PartitaComputer::PartitaComputer() {
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(Giocatore(COMPUTER));
    }
    ordinaGiocatori();
    t.printTabellone(giocatori);
    Casella* caselle = t.getTabellone();
    for(int i=0;i<20;i++){
        for(int j=0;j<giocatori.size();j++){
            int n = giocatori[i].tiroDadi();
            giocatori[i].muovi(n);
            if(caselle[giocatori[i].getPosizione()].getCategoria()!=ANGOLARE || caselle[giocatori[i].getPosizione()].getCategoria()!=PARTENZA){
                /*int possibilita = rand()%4+1;
                if(possibilita==1){
                    giocatori[i].acquistaCasella(caselle[giocatori[i].getPosizione()]);
                }*/
            }
        }
    }
}