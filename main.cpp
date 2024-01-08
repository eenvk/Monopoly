#include "include/Partita.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]){

     std::string input; //ciò che leggerò da console

     if(argc == 2) { // controllo se almeno ho inserito un argomento a linea di comando, altrimenti *

         std::cout << "Primo argomento: " << argv[1] << std::endl; //stampo l'argomento scritto

         for (int i = 1; i < argc; i++) { //leggo la stringa da console che viene inserita nella variabile input
            input += argv[i];
         }

         if(input != "human" && input != "computer"){
             std::cout << "L'argomento fornito non e' valido" << std::endl; //se inserisco qualcosa che non è human o computer
         }

     } else {
       std::cout << "Il numero di argomenti forniti non e' corretto" << std::endl; //*
     }
     Partita p = Partita(input);
     p.run();
     p.printWinner();
     return 0;
}