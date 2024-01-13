//Elena Novkovic

#ifndef MONOPOLY_GIOCATORE_H
#define MONOPOLY_GIOCATORE_H
#include <iostream>
#include <vector>
#include "LogManager.h"
#include "Casella.h"

constexpr int BUDGET_INIZIALE = 100;
constexpr int INCREMENTO_BUDGET = 20;

class Giocatore{
protected:
    int id;
    std::vector<Casella*> proprieta_possedute; //vector di proprieta
    bool is_alive; //true se il giocatore è vivo
    int budget; //visto che non ci sono i centesimi non serve float
    Casella* posizione;

public:
    class BudgetInsufficiente{};

    //getter
    int getId() const;
    std::vector<Casella*> proprietaPossedute() const;
    std::string getProprietaPossedute() const; //restituisce l'elenco dei nomi delle caselle possedute sotto forma di stringa
    bool isAlive() const;
    int getBudget() const;
    Casella& getPosizione() const;

    //questi 3 metodi sono diversi per giocatore umano e giocatore pc dunque si adotta l'ereditarieta
    virtual void acquistaCasella(Casella& c){}
    virtual void acquistaCasa(Casella& c){}
    virtual void miglioraInAlbergo(Casella& c){}

    void eliminaProprieta();
    void paga(const int); //Il giocatore paga tot soldi
    void incassa(const int); //Il giocatore riceve tot soldi
    void setDead(); //quando il giocatore viene eliminato
    int tiroDadi();
    void setPosizione(Casella*);
};

std::ostream& operator<<(std::ostream&, const Giocatore&);
int callCounter2();

#endif //MONOPOLY_GIOCATORE_H