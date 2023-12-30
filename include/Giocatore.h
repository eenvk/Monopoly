#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"
#define UMANO 'U'
#define COMPUTER 'C'
#define BUDGET_INIZIALE 100

class Giocatore{
public:
    class BudgetInsufficiente{};
    Giocatore(char);
    int getId() const;
    std::string getProprietaPossedute() const;
    bool isAlive() const;
    int getBudget() const;
    char getTipo() const;
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
    char tipo; //U=umano C=computer
    int posizione;
};

std::ostream& operator<<(std::ostream&, Giocatore&);
int callCounter2();

#endif //MONOPOLY_GIOCATORE_H