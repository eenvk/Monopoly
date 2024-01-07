#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#include "Tabellone.h"
#include "GiocatoreUmano.h"
#include "GiocatoreComputer.h"
#include <map>
#include <typeinfo>
#include <fstream>
constexpr int MAX_TURNI = 70;

class Partita {
protected:
    Partita();
    void ordinaGiocatori();
    Tabellone t = Tabellone();
    std::vector<Giocatore*> giocatori;
public:
    //Partita(std::string);
    ~Partita();
    void writeLog(const std::string messaggio) const;
    void run();
    void transazione(Giocatore*, Giocatore*, int, Casella&);
    bool handleHumanInteraction(const std::string) const;
    void listaPossedimenti() const;
    void visualizzaBudgetGiocatori() const;
    Giocatore* proprietario(const Casella&) const;
    virtual void printWinner(){}
};

#endif //MONOPOLY_PARTITA_H