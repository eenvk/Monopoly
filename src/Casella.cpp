#include "../include/Casella.h"

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->categoria = categoria;
    this->id = call_counter();
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

int call_counter() {
    static int count = 0;
    return count++;
}