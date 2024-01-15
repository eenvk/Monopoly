//Edoardo Renzi

#include "../include/Casella.h"

Casella::Casella() {
    //serve a tabellone quando si dichiara Casella tabellone[28];
    //ma non dovrebbe essere usato come metodo per la creazione di oggetti casella
}

Casella::Casella(const char categoria) {
    this->tipo = TERRENO; //all'inizio è un terreno
    this->categoria = categoria;
    this->id = callCounter();
    this->nome = "";
    if(categoria==ANGOLARE || categoria==PARTENZA){ //queste non sono disponibili per l'acquisto
        this->stato = false;
    }
    else{
        this->stato = true;
    }
}

void Casella::acquistaTerreno() {
    if(stato){
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

void Casella::reset() {
    tipo = TERRENO;
    stato = true;
}

void Casella::setNome(const std::string nome) {
    this->nome = nome;
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

std::string Casella::getNome()const{
    return nome;
}

bool Casella::getStato() const {
    return stato;
}

bool Casella::operator==(const Casella &c) const {
    return this->id == c.getId();
}

std::ostream& operator<<(std::ostream& os, const Casella& c) {
    return os<<c.getCategoria()<<c.getTipo();
}

int callCounter() { //assegna a ogni casella il proprio id
    static int count = 0;
    return count++;
}