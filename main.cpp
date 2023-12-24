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
    g.acquistaTerreno(c);
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<"Giocatore "<<g.getId()<<": "<<g.getProprietaPossedute()<<endl;
    g.eliminaProprieta();

    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<"Giocatore "<<g.getId()<<": "<<g.getProprietaPossedute()<<endl;*/

    Tabellone t = Tabellone();
    Casella* tab = t.getTabellone();
    Giocatore g = Giocatore(0);
    cout<<t<<endl;
    /*for (int i = 0; i <28 ; ++i) {
        cout<<tab[i];
    }
    cout << endl;*/
    g.acquistaCasella(tab[1]);
    g.acquistaCasa(tab[1]);
    g.muovi(g.tiroDadi());
    cout<<"Posizione "<<g.getPosizione()<<endl;
    g.acquistaCasella(tab[g.getPosizione()]);
    g.acquistaCasa(tab[g.getPosizione()]);
    g.miglioraInAlbergo(tab[g.getPosizione()]);
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t;

    //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nel vector
    t.resetCaselle(g);
    g.eliminaProprieta();
    cout<<"Giocatore "<< g <<": "<<g.getProprietaPossedute()<<endl;
    cout<<t<<endl;

    return 0;
}
