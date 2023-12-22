#include "../include/Giocatore.h"

Giocatore::Giocatore(int numero_giocatore) {
    this->id_giocatore = numero_giocatore;
    this->conto = 100;
    this->alive = true;
}

void Giocatore::pushProprieta(Casella c) {
    proprieta_possedute.push_back(c);
}

std::vector<Casella> Giocatore::getProprietaPossedute() {
    return proprieta_possedute;
}

int Giocatore::getIdGiocatore() {
    return id_giocatore;
}

void Giocatore::paga(int quantita) {
    conto -= quantita;
}

void Giocatore::riceve(int quantita) {
    conto += quantita;
}

int Giocatore::getConto() {
    return conto;
}

void Giocatore::setDead() {
    alive = false;
}

bool Giocatore::isAlive() {
    return alive;
}

std::ostream& operator<<(std::ostream& os, Giocatore& g) {
    std::vector<Casella> copy = g.getProprietaPossedute();
    for (int i = 0; i < copy.size(); ++i) {
        os << "|" << copy[i] << "|";
    }
    return os;
}