#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
#include "include/Tabellone.h"
using namespace std;

int main(){
    /*
    Casella a = Casella('P');
    Casella b = Casella('L');
    Casella c = Casella('E');
    cout<<a<<" "<<b<<" "<<c<<endl;
    Giocatore g = Giocatore(0);
    g.acquistaCasella(a);
    g.acquistaCasa(a);
    g.acquistaCasella(c);
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<"Giocatore "<<g.getId()<<": "<<g.getProprietaPossedute()<<endl;
    g.eliminaProprieta();

    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<"Giocatore "<<g.getId()<<": "<<g.getProprietaPossedute()<<endl;*/

    Tabellone t = Tabellone();
    Casella* tab = t.getTabellone();
    Giocatore g = Giocatore(0);

    for (int i = 0; i <28 ; ++i) {
        cout<<tab[i];
    }
    cout << endl;
    g.acquistaCasella(tab[1]);
    g.acquistaCasa(tab[1]);
    g.muovi(g.tiroDadi());
    g.acquistaCasella(tab[g.getPosizione()]);
    g.acquistaCasa(tab[g.getPosizione()]);
    g.miglioraInAlbergo(tab[g.getPosizione()]);
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t;


    cout<<tab[1]<<" "<<tab[9]<<" "<< tab[15] <<endl;
    //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nell'array
    t.resetCaselle(g);
    g.eliminaProprieta();
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t;


    return 0;
}
