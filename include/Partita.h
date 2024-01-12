//Elena Novkovic

#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#include "Tabellone.h"
#include "GiocatoreUmano.h"
#include "GiocatoreComputer.h"
#include "LogManager.h"
#include <map>
#include <typeinfo>

constexpr int MAX_TURNI = 250;

class Partita {
private:
    void ordinaGiocatori();
    Tabellone t = Tabellone();
    std::vector<Giocatore*> giocatori;
public:
    Partita(std::string);
    ~Partita();
    void run();
    void transazione(Giocatore*, Giocatore*, const int, const Casella&);
    void muoviGiocatore(Giocatore*, const int);
    bool handleHumanInteraction(const std::string) const;
    void listaPossedimenti() const;
    void visualizzaBudgetGiocatori() const;
    Giocatore* proprietario(const Casella&) const;
    void printWinner() const;
};

#endif //MONOPOLY_PARTITA_H