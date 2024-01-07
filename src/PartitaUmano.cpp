#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    this->giocatori.push_back(new GiocatoreUmano());
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
    for(int i=0;i<giocatori.size();i++){
        if(typeid(*giocatori[i]) == typeid(GiocatoreUmano)){
            std::cout<<giocatori[i]->getId()<<" umano\n";
        }else{
            std::cout<<giocatori[i]->getId()<<" pc\n";
        }
    }
}

void PartitaUmano::printWinner() {
    for (int i=0; i<giocatori.size(); i++) {
        if(giocatori[i]->isAlive()) {
            std::cout << "GIOCATORE " << giocatori[i]->getId() << " HA VINTO LA PARTITA\n";
            writeLog("GIOCATORE " + std::to_string(giocatori[i]->getId()) + " HA VINTO LA PARTITA");
        }
    }
}