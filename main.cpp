#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
#include "include/Tabellone.h"
#include "include/Partita.h"
using namespace std;

int main(){

    Tabellone t = Tabellone();
    Casella* tab = t.getTabellone();
    Giocatore g = Giocatore(0);

    tab[0].setGiocatore(g.getId());
    cout<<t<<endl;
    tab[0].deleteGiocatore();
    g.muovi(1);
    cout<<"Posizione "<<g.getPosizione()<<endl;
    tab[g.getPosizione()].setGiocatore(g.getId());
    cout<<t<<endl;
    g.acquistaCasella(tab[1]);
    g.acquistaCasa(tab[1]);
    cout<<t<<endl;
    tab[1].deleteGiocatore();
    g.muovi(g.tiroDadi());
    tab[g.getPosizione()].setGiocatore(g.getId());
    cout<<"Posizione "<<g.getPosizione()<<endl;
    cout<<t<<endl;
    g.acquistaCasella(tab[g.getPosizione()]);
    g.acquistaCasa(tab[g.getPosizione()]);
    g.miglioraInAlbergo(tab[g.getPosizione()]);
    cout<<t<<endl;
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<"Budget = "<<g.getBudget()<<endl;

    //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nel vector
    t.resetCaselle(g);
    g.eliminaProprieta();
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t<<endl;

    return 0;
}