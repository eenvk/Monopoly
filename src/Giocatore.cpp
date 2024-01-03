#include "../include/Giocatore.h"

Giocatore::Giocatore() {

}

int Giocatore::getId() const{
    return id;
}

std::string Giocatore::getProprietaPossedute() const{
    std::string s = "";
    for(int i=0;i<proprieta_possedute.size();i++){
        s = s + (proprieta_possedute[i].getNome()) + " ";
    }
    return s;
}

std::vector<Casella> Giocatore::proprietaPossedute() {
    return proprieta_possedute;
}

int Giocatore::getBudget() const{
    return budget;
}

bool Giocatore::isAlive() const{
    return is_alive;
}

int Giocatore::getPosizione() const {
    return posizione;
}

/*void Giocatore::acquistaCasella(Casella &c) {
    if(c.getCategoria()==ECONOMICA){
        if(budget>=PREZZO_ECO_TERRENO){
            c.acquistaTerreno();
            proprieta_possedute.push_back(c);
            paga(PREZZO_ECO_TERRENO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==STANDARD){
        if(budget>=PREZZO_STANDARD_TERRENO){
            c.acquistaTerreno();
            proprieta_possedute.push_back(c);
            paga(PREZZO_STANDARD_TERRENO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==LUSSO){
        if(budget>=PREZZO_LUSSO_TERRENO){
            c.acquistaTerreno();
            proprieta_possedute.push_back(c);
            paga(PREZZO_LUSSO_TERRENO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
}

void Giocatore::acquistaCasa(Casella &c) {
    if(c.getCategoria()==ECONOMICA){
        if(budget>=PREZZO_ECO_CASA){
            c.acquistaCasa();
            paga(PREZZO_ECO_CASA);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==STANDARD){
        if(budget>=PREZZO_STANDARD_CASA){
            c.acquistaCasa();
            paga(PREZZO_STANDARD_CASA);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==LUSSO){
        if(budget>=PREZZO_LUSSO_CASA){
            c.acquistaCasa();
            paga(PREZZO_LUSSO_CASA);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
}

void Giocatore::miglioraInAlbergo(Casella &c) {
    if(c.getCategoria()==ECONOMICA){
        if(budget>=PREZZO_ECO_ALBERGO){
            c.miglioraInAlbergo();
            paga(PREZZO_ECO_ALBERGO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==STANDARD){
        if(budget>=PREZZO_STANDARD_ALBERGO){
            c.miglioraInAlbergo();
            paga(PREZZO_STANDARD_ALBERGO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
    if(c.getCategoria()==LUSSO){
        if(budget>=PREZZO_LUSSO_ALBERGO){
            c.miglioraInAlbergo();
            paga(PREZZO_LUSSO_ALBERGO);
        }
        else{
            throw BudgetInsufficiente();
        }
    }
}*/

void Giocatore::eliminaProprieta() {
    proprieta_possedute.clear();
}

void Giocatore::paga(int quantita) {
    budget -= quantita;
}

void Giocatore::incassa(int quantita) {
    budget += quantita;
}

void Giocatore::setDead() {
    is_alive = false;
}

int Giocatore::tiroDadi() {
    int numero = rand()%11+2; //con 2 dadi il minimo numero che può uscire è 2 e il massimo è 12
    std::cout<<"Giocatore "<<id<<" ha tirato i dadi ottenendo "<<numero<<"\n";
    return numero;
}

void Giocatore::muovi(int spostamento) {
    if(posizione + spostamento > 27){
        int diff = 28-posizione;
        posizione = spostamento-diff;
        incassa(20);
        std::cout<<"Giocatore "<<id<<" e' passato dal via e ha ritirato 20 fiorini"<<"\n";
    }
    else{
        posizione += spostamento;
    }
}

std::ostream& operator<<(std::ostream& os, const Giocatore& g) {
    return os<<"Id: "<<g.getId()<<", Budget: "<<g.getBudget()<<", Pos: "<<g.getPosizione();
}

int callCounter2() {
    static int count = 1;
    return count++;
}