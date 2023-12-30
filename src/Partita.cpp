#include "../include/Partita.h"
Partita::Partita() {

}

void Partita::ordinaGiocatori() {
    std::multimap<int,int,std::greater<int>>ordine;
    std::cout<<"I giocatori tirano i dadi per decidere l'ordine di gioco"<<"\n";
    for(int i=0;i<4;i++){
        ordine.insert(std::make_pair(giocatori[i].tiroDadi(), giocatori[i].getId()));
    }
    std::cout<<"L'ordine dei giocatori e' ";
    for (const auto& coppia : ordine) {
        std::cout << coppia.second<<" ";
    }
    std::cout<<"\n";
    std::vector<Giocatore> temp;
    for (const auto& coppia : ordine) {
        temp.push_back(giocatori[coppia.second - 1]);
    }
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        giocatori[i] = temp[i];
    }
}

std::vector<Giocatore> Partita::getGiocatori() const{
    return giocatori;
}

void Partita::listaPossedimenti() const{
    for(int i=0;i<giocatori.size();i++){
        std::cout<<"Giocatore "<<giocatori[i].getId()<<": "<<giocatori[i].getProprietaPossedute()<<"\n";
    }
}