#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"


class Giocatore{
public:
    Giocatore(int);
    void pushProprieta(Casella);
    std::vector<Casella> getProprietaPossedute();
    int getIdGiocatore();
    void paga(int); //Il giocatore paga tot soldi
    void riceve(int); //Il giocatore riceve tot soldi
    int getConto();
    void setDead();
    bool isAlive();

    void muovi(); //?


private:
    std::vector<Casella> proprieta_possedute;
    int id_giocatore;
    bool alive; //il giocatore è ancora in gioco?
    int conto;
};

std::ostream& operator<<(std::ostream&, Giocatore&);


#endif //MONOPOLY_GIOCATORE_H
