#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"

class Giocatore{
public:
    Giocatore();
    void aggiungiProprieta(Casella);
    std::vector<Casella> getProprietaPossedute();
    int getId();
    void paga(int); //Il giocatore paga tot soldi
    void riceve(int); //Il giocatore riceve tot soldi
    int getBudget();
    void setDead();
    bool isAlive();

    void muovi(); //?


private:
    int id_giocatore;
    std::vector<Casella> proprieta_possedute;
    bool is_alive; //il giocatore è ancora in gioco?
    int budget;
};

std::ostream& operator<<(std::ostream&, Giocatore&);
int callCounter2();


#endif //MONOPOLY_GIOCATORE_H