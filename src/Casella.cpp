#include "../include/Casella.h"

Casella::Casella() {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->categoria = ' ';
}

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->categoria = categoria;
    this->id = callCounter();
}

void Casella::acquistaTerreno() {
    if(stato && categoria != ' ' && categoria != 'P'){
        stato = false;
    }
    else{
        throw TerrenoNonAcquistabile();
    }
}

void Casella::acquistaCasa() {
    if(!stato && tipo == 1){
        tipo = 2;
    }
    else{
        throw CasaNonAcquistabile();
    }
}

void Casella::miglioraInAlbergo() {
    if(!stato && tipo == 2){
        tipo = 3;
    }
    else{
        throw CasaNonMigliorabileInAlbergo();
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

std::string Casella::toString() const {
    std::string t;
    switch (tipo) {
        case 1:
            t = " ";
            break;
        case 2:
            t = "*";
            break;
        case 3:
            t = "^";
            break;
        default: t = " ";
            break;
    }
    return (categoria + t);
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