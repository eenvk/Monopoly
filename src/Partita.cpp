#include "../include/Partita.h"
Partita::Partita() {

}
void Partita::ordineGiocatoriNelTiroDadi() {
    std::multimap<int,int,std::greater<int>>ordine;
    for(int i=0;i<4;i++){
        ordine.insert(std::make_pair(giocatori[i].tiroDadi(), giocatori[i].getId()));
    }
    std::cout<<"I giocatori tirano i dadi per decidere l'rdine di gioco"<<"\n";
    for (const auto& coppia : ordine) {
        std::cout << "Numero uscito: " << coppia.first << ", Id giocatore: " << coppia.second<< std::endl;
    }
    std::vector<Giocatore> temp;
    while(ordine.size()>0){
        int max = ordine.begin()->second;
        max--;
        temp.push_back(giocatori[max]);
        ordine.erase(ordine.begin());
    }
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        giocatori[i] = temp[i];
    }
}

std::vector<Giocatore> Partita::getGiocatori() {
    return giocatori;
}
