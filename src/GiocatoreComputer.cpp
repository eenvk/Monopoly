//Giada Zago

#include "../include/GiocatoreComputer.h"

GiocatoreComputer::GiocatoreComputer(Casella* c) {
    this->id = callCounter2();
    this->budget = BUDGET_INIZIALE;
    this->is_alive = true;
    if(c != nullptr){
        this->posizione = c;
    }
}

void GiocatoreComputer::acquistaCasella(Casella &c){
    int probabilita = rand()%4+1;
    //il fatto che esca 1 su 4 rappresenta la probabilita del 25%
    if(probabilita == 1){
        if(c.getCategoria()==ECONOMICA){
            if(budget>=PREZZO_ECO_TERRENO){
                c.acquistaTerreno();
                proprieta_possedute.push_back(&c);
                paga(PREZZO_ECO_TERRENO);
            }
            else{
                throw BudgetInsufficiente();
            }
        }
        if(c.getCategoria()==STANDARD){
            if(budget>=PREZZO_STANDARD_TERRENO){
                c.acquistaTerreno();
                proprieta_possedute.push_back(&c);
                paga(PREZZO_STANDARD_TERRENO);
            }
            else{
                throw BudgetInsufficiente();
            }
        }
        if(c.getCategoria()==LUSSO){
            if(budget>=PREZZO_LUSSO_TERRENO){
                c.acquistaTerreno();
                proprieta_possedute.push_back(&c);
                paga(PREZZO_LUSSO_TERRENO);
            }
            else{
                throw BudgetInsufficiente();
            }
        }
        LogManager::log("Giocatore " + std::to_string(id) + " ha acquistato il terreno " + c.getNome());
        std::cout<<"Giocatore "<<id<<" ha acquistato il terreno "<<c.getNome()<<"\n";
    }
    //else vuol dire che non l'ha acquistato che e' diverso dal non poterla acquistare (cioe che non si hanno abbastanza soldi)
}

void GiocatoreComputer::acquistaCasa(Casella &c) {
    int probabilita = rand()%4+1;
    //il fatto che esca 1 su 4 rappresenta la probabilita del 25%
    if(probabilita == 1){
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
        LogManager::log("Giocatore " + std::to_string(id) + " ha costruito una casa sul terreno " + c.getNome());
        std::cout<<"Giocatore "<<id<<" ha costruito una casa sul terreno "<<c.getNome()<<"\n";
    }
}

void GiocatoreComputer::miglioraInAlbergo(Casella &c) {
    int probabilita = rand()%4+1;
    //il fatto che esca 1 su 4 rappresenta la probabilita del 25%
    if(probabilita == 1){
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
        LogManager::log("Giocatore " + std::to_string(id) + " ha migliorato una casa in albergo sul terreno " + c.getNome());
        std::cout<<"Giocatore "<<id<<" ha migliorato una casa in albergo sul terreno "<<c.getNome()<<"\n";
    }
}