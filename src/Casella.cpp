#include "../include/Casella.h"

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = 1; //è un terreno di default
    this->categoria = categoria;
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