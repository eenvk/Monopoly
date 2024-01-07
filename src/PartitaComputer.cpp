#include "../include/PartitaComputer.h"

PartitaComputer::PartitaComputer() {
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
}

void PartitaComputer::printWinner() {
    int max_budget = 0;
    int budget = 0;
    for (int i=0; i<giocatori.size(); i++) {
        if(giocatori[i]->isAlive()) {
            budget = giocatori[i]->getBudget();
            if(budget >= max_budget){
                max_budget = budget;
            }
        }
    }
    for(int i=0;i<giocatori.size();i++){
        if(giocatori[i]->isAlive() && giocatori[i]->getBudget() >= max_budget){
            std::cout << "GIOCATORE " << giocatori[i]->getId() << " HA VINTO LA PARTITA\n";
            LogManager::log("GIOCATORE " + std::to_string(giocatori[i]->getId()) + " HA VINTO LA PARTITA");
        }
    }
}