#include "../include/GiocatoreUmano.h"

GiocatoreUmano::GiocatoreUmano() {
    this->id = callCounter2();
    this->budget = BUDGET_INIZIALE;
    this->is_alive = true;
    this->posizione = 0;
}

void GiocatoreUmano::acquistaCasella(Casella &c) {
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

void GiocatoreUmano::acquistaCasa(Casella &c) {
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

void GiocatoreUmano::miglioraInAlbergo(Casella &c) {
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
}