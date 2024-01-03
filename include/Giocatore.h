#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"
#define BUDGET_INIZIALE 100

class Giocatore{
protected:
    //Giocatore();
    int id;
    std::vector<Casella> proprieta_possedute;
    bool is_alive; //il giocatore è ancora in gioco?
    int budget;
    int posizione;

public:
    class BudgetInsufficiente{};
    int getId() const;
    std::string getProprietaPossedute() const;
    bool isAlive() const;
    int getBudget() const;
    int getPosizione() const;
    std::vector<Casella> proprietaPossedute() const;

    virtual void acquistaCasella(Casella& c){}
    virtual void acquistaCasa(Casella& c){}
    virtual void miglioraInAlbergo(Casella& c){}

    void eliminaProprieta();
    void paga(int); //Il giocatore paga tot soldi
    void incassa(int); //Il giocatore riceve tot soldi
    void setDead();
    int tiroDadi();
    void muovi(int);
};

std::ostream& operator<<(std::ostream&, const Giocatore&);
int callCounter2();

#endif //MONOPOLY_GIOCATORE_H