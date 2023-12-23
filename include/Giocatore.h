#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"

class Giocatore{
public:
    Giocatore(int);
    std::vector<Casella> getProprietaPossedute();
    int getId() const;
    bool isAlive() const;
    int getBudget() const;
    int getTipo() const;
    int getPosizione() const;
    void aggiornaPosizione(int);

    void aggiungiProprieta(Casella);
    void paga(int); //Il giocatore paga tot soldi
    void incassa(int); //Il giocatore riceve tot soldi
    void setDead();
    int tiroDadi();
    void muovi(); //?


private:
    int id_giocatore;
    std::vector<Casella> proprieta_possedute;
    bool is_alive; //il giocatore è ancora in gioco?
    int budget;
    int tipo; //1=umano 2=computer
    int posizione;
};

std::ostream& operator<<(std::ostream&, Giocatore&);
int callCounter2();

#endif //MONOPOLY_GIOCATORE_H