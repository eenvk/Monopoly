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
    cout<<t;


    return 0;
}
