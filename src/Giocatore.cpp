#include "../include/Giocatore.h"

Giocatore::Giocatore() {
    this->id_giocatore = call_counter();
    this->budget = 100;
    this->is_alive = true;
}

void Giocatore::aggiungiProprieta(Casella c) {
    proprieta_possedute.push_back(c);
}

std::vector<Casella> Giocatore::getProprietaPossedute() {
    return proprieta_possedute;
}

int Giocatore::getIdGiocatore() {
    return id_giocatore;
}

void Giocatore::paga(int quantita) {
    budget -= quantita;
}

void Giocatore::riceve(int quantita) {
    budget += quantita;
}

int Giocatore::getConto() {
    return budget;
}

void Giocatore::setDead() {
    is_alive = false;
}

bool Giocatore::isAlive() {
    return is_alive;
}

std::ostream& operator<<(std::ostream& os, Giocatore& g) {
    std::vector<Casella> copy = g.getProprietaPossedute();
    for (int i = 0; i < copy.size(); ++i) {
        os << "|" << copy[i] << "|";
    }
    return os;
}

int call_counter() {
    static int count = 1;
    return count++;
}