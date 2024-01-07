#include "../include/Giocatore.h"

int Giocatore::getId() const{
    return id;
}

std::string Giocatore::getProprietaPossedute() const{
    std::string s = "";
    for(int i=0;i<proprieta_possedute.size();i++){
        s = s + (proprieta_possedute[i]->getNome()) + " ";
    }
    return s;
}

std::vector<Casella*> Giocatore::proprietaPossedute() const{
    return proprieta_possedute;
}

int Giocatore::getBudget() const{
    return budget;
}

bool Giocatore::isAlive() const{
    return is_alive;
}

int Giocatore::getPosizione() const {
    return posizione;
}

void Giocatore::eliminaProprieta() {
    for(int j=0;j<proprieta_possedute.size();j++){
        proprieta_possedute[j]->reset();
    }
    proprieta_possedute.clear();
}

void Giocatore::paga(int quantita) {
    if(quantita>budget){
        throw BudgetInsufficiente();
    }
    budget -= quantita;
}

void Giocatore::incassa(int quantita) {
    budget += quantita;
}

void Giocatore::setDead() {
    is_alive = false;
}

int Giocatore::tiroDadi() {
    int numero = rand()%11+2; //con 2 dadi il minimo numero che può uscire è 2 e il massimo è 12
    std::cout<<"Giocatore "<<id<<" ha tirato i dadi ottenendo "<<numero<<"\n";
    return numero;
}

void Giocatore::muovi(int spostamento) {
    if(posizione + spostamento > 27){
        int diff = 28-posizione;
        posizione = spostamento-diff;
        incassa(20);
        LogManager::log("Giocatore " + std::to_string(id) + " e' passato dal via e ha ritirato 20 fiorini\n");
        std::cout<<"Giocatore "<<id<<" e' passato dal via e ha ritirato 20 fiorini"<<"\n";
    }
    else{
        posizione += spostamento;
    }
}

std::ostream& operator<<(std::ostream& os, const Giocatore& g) {
    return os<<"Id: "<<g.getId()<<", Budget: "<<g.getBudget()<<", Pos: "<<g.getPosizione();
}

int callCounter2() {
    static int count = 1;
    return count++;
}