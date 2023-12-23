#include "../include/Giocatore.h"

Giocatore::Giocatore(int tipo) {
    this->id = callCounter2();
    this->budget = 100;
    this->is_alive = true;
    this->tipo = tipo; //1=human, 2=computer
    this->posizione = 0;
}

int Giocatore::getId() const{
    return id;
}

std::string Giocatore::getProprietaPossedute() const{
    std::string s = "";
    for(int i=0;i<proprieta_possedute.size();i++){
        s = s + std::to_string(proprieta_possedute[i].getId()) + " ";
    }
    return s;
}

int Giocatore::getBudget() const{
    return budget;
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

void Giocatore::acquistaCasella(Casella &c) {
    proprieta_possedute.push_back(c);
    c.acquistaCasella();
}

void Giocatore::acquistaCasa(Casella &c) {
    c.acquistaCasa();
}

void Giocatore::miglioraInAlbergo(Casella &c) {
    c.miglioraInAlbergo();
}

void Giocatore::eliminaProprieta() {
    proprieta_possedute.clear();
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
    return os<<g.getId();
}

int callCounter2() {
    static int count = 1;
    return count++;
}
