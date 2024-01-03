#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    this->giocatori.push_back(new GiocatoreUmano());
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
    t.printTabellone(giocatori);
}

void PartitaUmano::run() {
    t.printTabellone(giocatori);
    Casella* caselle = t.getTabellone();
    for(int i=0;i<1;i++){
        for(int j=0;j<giocatori.size();j++){
            int n = giocatori[j]->tiroDadi();
            giocatori[j]->muovi(n);
            Casella& pos = caselle[giocatori[j]->getPosizione()];
            if(pos.getCategoria()==ANGOLARE || pos.getCategoria()==PARTENZA){
                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha finito il turno"<<"\n";
            }
            else{
                giocatori[j]->acquistaCasella(pos);
                //std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha acquistato "<<pos.getNome()<<"\n";
            }
        }
        t.printTabellone(giocatori);
    }
    std::cout<<"\n";
    listaPossedimenti();
}
