#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
#include "include/Tabellone.h"
#include "include/Partita.h"
using namespace std;

int main(){

    Tabellone t = Tabellone();
    Casella* tab = t.getTabellone();
    vector<Giocatore> giocatori;
    giocatori.push_back(Giocatore(0));
    cout<<endl;
    t.printTabellone(giocatori);
    int n = giocatori[0].tiroDadi();
    giocatori[0].muovi(n);
    giocatori[0].acquistaCasella(tab[n]);
    giocatori[0].acquistaCasa(tab[n]);
    giocatori[0].miglioraInAlbergo(tab[n]);
    cout<<"Posizione "<<giocatori[0].getPosizione()<<endl;
    t.printTabellone(giocatori);

    //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nel vector
    t.resetCaselle(giocatori[0]);
    giocatori[0].eliminaProprieta();
    giocatori.clear();
    cout << "Giocatore " << giocatori[0] << ": " << giocatori[0].getProprietaPossedute() << endl;
    t.printTabellone(giocatori);
    return 0;
}