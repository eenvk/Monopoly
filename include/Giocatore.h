#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "../include/Casella.h"


class Giocatore{


    void getProprietaPossedute();

private:
    int name;
    std::vector<Casella> proprieta_possedute;
    bool vivo; //il giocatore è ancora in gioco?
    int conto;
    Casella ;

};

std::ostream& operator<<(std::ostream&, const Giocatore&);


#endif //MONOPOLY_GIOCATORE_H
