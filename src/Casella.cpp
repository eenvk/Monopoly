#include "../include/Casella.h"

Casella::Casella() {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->id = callCounter();
}

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->categoria = categoria;
    this->id = callCounter();
}

void Casella::acquistaCasella() {
    if(stato){
        stato = false;
    }
}

void Casella::acquistaCasa() {
    if(!stato && tipo == 1){
        tipo = 2;
    }
}

void Casella::miglioraInAlbergo() {
    if(!stato && tipo == 2){
        tipo = 3;
    }
}

char Casella::getCategoria() const{
    return categoria;
}

int Casella::getTipo() const {
    return tipo;
}

int Casella::getId() const {
    return id;
}

void Casella::reset() {
    tipo = 1;
    stato = true;
}

std::ostream& operator<<(std::ostream& os, const Casella& c) {
    char tipo;
    switch (c.getTipo()) {
        case 1:
            tipo = ' ';
            break;
        case 2:
            tipo = '*';
            break;
        case 3:
            tipo = '^';
            break;
        default: tipo = ' ';
        break;
    }
    return os<<c.getCategoria()<<" "<<tipo;
}

int callCounter() {
    static int count = 0;
    return count++;
}
