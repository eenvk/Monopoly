#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
#include "include/Tabellone.h"
using namespace std;

int main(){

    Tabellone t = Tabellone();
    Casella* tab = t.getTabellone();
    Giocatore g = Giocatore(0);
    cout<<t<<endl;

    g.acquistaCasella(tab[1]);
    g.acquistaCasa(tab[1]);
    g.muovi(g.tiroDadi());
    cout<<"Posizione "<<g.getPosizione()<<endl;
    g.acquistaCasella(tab[g.getPosizione()]);
    g.acquistaCasa(tab[g.getPosizione()]);
    g.miglioraInAlbergo(tab[g.getPosizione()]);
    cout<<t<<endl;
    cout<<g.getProprietaPossedute()<<endl;
    cout<<g.getBudget()<<endl;

    //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nel vector
    t.resetCaselle(g);
    g.eliminaProprieta();
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t<<endl;

    return 0;
}