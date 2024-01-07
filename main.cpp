#include "include/PartitaComputer.h"
#include "include/PartitaUmano.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    std::string input; //ciò che leggerò da console

     if (argc > 1) { // controllo se almeno ho inserito un argomento a linea di comando, altrimenti *

        std::cout << "Primo argomento: " << argv[1] << std::endl; //stampo l'argomento scritto

        for (int i = 1; i < argc; ++i) { //leggo la stringa da console che viene inserita nella variabile input
            input += argv[i];
        }

        if(input=="human") { //in questo modo ora posso confrontare se input=human
           PartitaUmano p = PartitaUmano();
           p.run();
           p.printWinner();
       }else{
            if(input=="computer") {
                PartitaComputer p = PartitaComputer();
                p.run();
                p.printWinner();
            }else std::cout << "argomento non valido" << std::endl; //se inserisco qualcosa che non è human o computer
       }

    } else {
       std::cout << "Nessun argomento fornito" << std::endl; //*
    }


    return 0;
}

/*Tabellone t = Tabellone();
 Casella* tab = t.getTabellone();
 vector<Giocatore> giocatori;
 giocatori.push_back(Giocatore(0));
 giocatori.push_back(Giocatore(0));
 t.printTabellone(giocatori);
 int n = giocatori[0].tiroDadi();
 giocatori[0].muovi(n);
 cout<<"Posizione giocatore 1: "<<giocatori[0].getPosizione()<<endl;
 giocatori[0].acquistaCasella(tab[giocatori[0].getPosizione()]);
 giocatori[0].acquistaCasa(tab[giocatori[0].getPosizione()]);
 cout<<endl;
 t.printTabellone(giocatori);
 cout<<endl;
 n = giocatori[1].tiroDadi();
 giocatori[1].muovi(n);
 cout<<"Posizione giocatore 2: "<<giocatori[1].getPosizione()<<endl;
 giocatori[1].acquistaCasella(tab[giocatori[1].getPosizione()]);
 giocatori[1].acquistaCasa(tab[giocatori[1].getPosizione()]);
 giocatori[1].miglioraInAlbergo(tab[giocatori[1].getPosizione()]);
 t.printTabellone(giocatori);

 //supponiamo giocatore eliminato: prima elimino le caselle sul tab poi nel vector
 t.resetCaselle(giocatori[0]);
 giocatori[0].eliminaProprieta();
 giocatori.erase(giocatori.begin());
 t.printTabellone(giocatori);*/