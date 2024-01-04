#ifndef MONOPOLY_PARTITA_H
#define MONOPOLY_PARTITA_H
#include "Tabellone.h"
#include "GiocatoreUmano.h"
#include "GiocatoreComputer.h"
#include <map>
#include <memory>

class Partita {
protected:
    Partita();
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