#include "../include/Partita.h"
Partita::Partita() {

}
void Partita::ordinaGiocatori() {
    std::multimap<int,int,std::greater<int>>ordine;
    for(int i=0;i<4;i++){
        ordine.insert(std::make_pair(giocatori[i].tiroDadi(), giocatori[i].getId()));
    }
    std::cout<<"I giocatori tirano i dadi per decidere l'rdine di gioco"<<"\n";
    for (const auto& coppia : ordine) {
        std::cout << "Numero uscito: " << coppia.first << ", Id giocatore: " << coppia.second<< std::endl;
    }
    std::vector<Giocatore> temp;
    for (const auto& coppia : ordine) {
        temp.push_back(giocatori[coppia.second - 1]);
    }
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        giocatori[i] = temp[i];
    }
}

std::vector<Giocatore> Partita::getGiocatori() {
    return giocatori;
}
