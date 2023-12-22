#include "../include/Casella.h"

Casella::Casella(char categoria, char abitazione, int giocatore, char colonna, char riga){
    categoria_casella = categoria;
    tipo_abitazione = abitazione;
    n_giocatore = giocatore;
    co.row = riga;
    co.column = colonna;
    comprato = false;
}

void Casella::acquista(){
    if(!comprato)
        comprato=true;
}

void Casella::print() const{
    std::cout << "|" << categoria_casella << tipo_abitazione << n_giocatore << "|";
}