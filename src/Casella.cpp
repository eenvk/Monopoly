#include "../include/Casella.h"

Casella::Casella() {
    this->stato = true; //di default una casella è disponibile
    this->tipo = TERRENO; //è un terreno di default
    this->categoria = ' ';
    //this->proprietario = 0;
}

Casella::Casella(char categoria) {
    this->stato = true; //di default una casella è disponibile
    this->tipo = TERRENO; //è un terreno di default
    this->categoria = categoria;
    this->id = callCounter();
    this->nome = setNome();
    //this->proprietario = 0; //0 vuol dire di nessuno
}

void Casella::acquistaTerreno() {
    if(stato && (categoria != ANGOLARE && categoria != PARTENZA)){
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

/*void Casella::setProprietario(int id_giocatore) {
    this->proprietario = id_giocatore;
}*/

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

void Casella::reset() {
    tipo = TERRENO;
    stato = true;
}

std::ostream& operator<<(std::ostream& os, const Casella& c) {
    return os<<c.getCategoria()<<c.getTipo();
}

int callCounter() {
    static int count = 0;
    return count++;
}

std::string setNome(){
    static char lettera = 72;
    static int numero = 9;
    static int i = 0;
    if(i<8){
        i++;
        return lettera+std::to_string(--numero);
    }
    if(i<15){
        i++;
        return (--lettera)+std::to_string(numero);
    }
    if(i<22){
        i++;
        return lettera+std::to_string(++numero);
    }
    i++;
    return (++lettera)+std::to_string(numero);
}