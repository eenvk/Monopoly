#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"

class Giocatore{
public:
    class BudgetInsufficiente{};
    Giocatore(int);
    int getId() const;
    std::string getProprietaPossedute() const;
    bool isAlive() const;
    int getBudget() const;
    int getTipo() const;
    int getPosizione() const;
    std::vector<Casella> proprietaPossedute();

    void acquistaCasella(Casella& c);
    void acquistaCasa(Casella& c);
    void miglioraInAlbergo(Casella& c);

    void eliminaProprieta();
    void paga(int); //Il giocatore paga tot soldi
    void incassa(int); //Il giocatore riceve tot soldi
    void setDead();
    int tiroDadi();
    void muovi(int);

private:
    int id;
    std::vector<Casella> proprieta_possedute;
    bool is_alive; //il giocatore è ancora in gioco?
    int budget;
    int tipo; //1=umano 2=computer
    int posizione;
};

std::ostream& operator<<(std::ostream&, Giocatore&);
int callCounter2();

#endif //MONOPOLY_GIOCATORE_H