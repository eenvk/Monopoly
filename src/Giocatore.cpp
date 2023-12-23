#include "../include/Giocatore.h"

Giocatore::Giocatore(int tipo) {
    this->id_giocatore = callCounter2();
    this->budget = 100;
    this->is_alive = true;
    this->tipo = tipo; //1=human, 2=computer
    this->posizione = 0;
}

int Giocatore::getId() const{
    return id_giocatore;
}

std::vector<Casella> Giocatore::getProprietaPossedute() {
    return proprieta_possedute;
}

int Giocatore::getBudget() const{
    return budget;
}

void Giocatore::aggiungiProprieta(Casella c) {
    proprieta_possedute.push_back(c);
}

bool Giocatore::isAlive() const{
    return is_alive;
}

int Giocatore::getTipo() const {
    return tipo;
}

int Giocatore::getPosizione() const {
    return posizione;
}

void Giocatore::aggiornaPosizione(int spostamento) {
    if((posizione + spostamento) > 27){
        posizione = spostamento - (27 - posizione) - 1;
    }else{
        posizione += spostamento;
    }
}

void Giocatore::paga(int quantita) {
    budget -= quantita;
}

void Giocatore::incassa(int quantita) {
    budget += quantita;
}

void Giocatore::setDead() {
    is_alive = false;
}

int Giocatore::tiroDadi() {
    int numero = rand()%12+2; //con 2 dadi il minimo numero che può uscire è 2 e il massimo è 12
    return numero;
}


std::ostream& operator<<(std::ostream& os, Giocatore& g) {
    std::vector<Casella> copy = g.getProprietaPossedute();
    for (int i = 0; i < copy.size(); ++i) {
        os << "|" << copy[i] << "|";
    }
    return os;
}

int callCounter2() {
    static int count = 1;
    return count++;
}