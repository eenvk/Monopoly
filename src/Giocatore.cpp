//Elena Novkovic

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

Casella& Giocatore::getPosizione() const {
    return *posizione;
}

void Giocatore::eliminaProprieta() {
    for(int j=0;j<proprieta_possedute.size();j++){
        proprieta_possedute[j]->reset();
    }
    proprieta_possedute.clear();
}

void Giocatore::paga(const int quantita) {
    if(quantita>budget){
        throw BudgetInsufficiente();
    }
    budget -= quantita;
}

void Giocatore::incassa(const int quantita) {
    budget += quantita;
}

void Giocatore::setDead() {
    is_alive = false;
}

int Giocatore::tiroDadi() {
    int numero = rand()%11+2; //con 2 dadi il minimo numero che può uscire è 2 e il massimo è 12

    //quando un giocatore tira i dadi viene scritto ciò sul file di log
    LogManager::log("Giocatore " + std::to_string(id) + " ha tirato i dadi ottenendo " + std::to_string(numero));
    std::cout<<"Giocatore "<<id<<" ha tirato i dadi ottenendo "<<numero<<"\n";
    return numero;
}

void Giocatore::setPosizione(Casella* newPosition) {
    if(posizione != nullptr) {
        posizione = newPosition;
    }
}

std::ostream& operator<<(std::ostream& os, const Giocatore& g) {
    std::string is_alive;
    if(g.isAlive()){
        is_alive = "In gioco";
    }
    else{
        is_alive = "Eliminato";
    }
    return os<<"Id: "<<g.getId()<<", "<<is_alive<<", Budget: "<<g.getBudget()<<", Casella posizione: "<<g.getPosizione().getNome();
}

int callCounter2() { //assegna a ogni giocatore il proprio id
    static int count = 1;
    return count++;
}