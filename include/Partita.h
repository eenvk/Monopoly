#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#include "Tabellone.h"
#include "GiocatoreUmano.h"
#include "GiocatoreComputer.h"
#include <map>
constexpr int MAX_TURNI = 500;

class Partita {
protected:
    Partita();
    ~Partita();
    void ordinaGiocatori();
    Tabellone t = Tabellone();
    std::vector<Giocatore*> giocatori;
public:
    virtual void run(){}
    std::vector<Giocatore*> getGiocatori() const;
    void listaPossedimenti() const;
    int whose(const Casella&) const;
};

#endif //MONOPOLY_PARTITA_H