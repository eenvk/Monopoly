#include "../include/Casella.h"

Casella::Casella() {
    this->stato = true; //di default una casella è disponibile
    this->tipo = TERRENO; //è un terreno di default
    this->categoria = ' ';
}

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = TERRENO; //è un terreno di default
    this->categoria = categoria;
    this->id = callCounter();
}

void Casella::acquistaTerreno() {
    if(stato && categoria != ANGOLARE && categoria != PARTENZA){
        stato = false;
    }
    else{
        throw TerrenoNonAcquistabile();
    }
}

void Casella::acquistaCasa() {
    if(!stato && tipo == TERRENO){
        tipo = CASA;
    }
    else{
        throw CasaNonAcquistabile();
    }
}

void Casella::miglioraInAlbergo() {
    if(!stato && tipo == CASA){
        tipo = ALBERGO;
    }
    else{
        throw CasaNonMigliorabileInAlbergo();
    }
}

char Casella::getCategoria() const{
    return categoria;
}

char Casella::getTipo() const {
    return tipo;
}

int Casella::getId() const {
    return id;
}

bool Casella::getStato() const {
    return stato;
}

void Casella::reset() {
    tipo = 1;
    stato = true;
}

std::ostream& operator<<(std::ostream& os, const Casella& c) {
    /*char tipo;
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
    }*/
    return os<<c.getCategoria()<<c.getTipo();
}

int callCounter() {
    static int count = 0;
    return count++;
}