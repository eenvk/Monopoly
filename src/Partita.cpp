#include "../include/Partita.h"
Partita::Partita() {

}

void Partita::ordinaGiocatori() {
    std::multimap<int,int,std::greater<int>> ordine;
    std::cout<<"I giocatori tirano i dadi per decidere l'ordine di gioco"<<"\n";
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        ordine.insert(std::make_pair(giocatori[i]->tiroDadi(), giocatori[i]->getId()));
    }
    std::vector<Giocatore*> temp;
    while(!ordine.empty()){
        int valore = ordine.begin()->first;
        int count = ordine.count(valore);
        while(count>=2){
            for(int i=0;i<count;i++){
                int id_giocatore = ordine.find(valore)->second;
                ordine.erase(ordine.find(valore));
                ordine.insert(std::make_pair(giocatori[id_giocatore-1]->tiroDadi(), id_giocatore));
            }
            valore = ordine.begin()->first;
            count = ordine.count(valore);
        }
        temp.push_back(giocatori[ordine.begin()->second - 1]);
        ordine.erase(ordine.begin());
    }
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        giocatori[i] = temp[i];
    }
    std::cout<<"L'ordine dei giocatori e' ";
    for (int i=0;i<NUMERO_GIOCATORI;i++){
        std::cout<<giocatori[i]->getId()<<" ";
    }
    std::cout<<"\n";
}

std::vector<Giocatore*> Partita::getGiocatori() const{
    return giocatori;
}

void Partita::listaPossedimenti() const{
    for(int i=0;i<giocatori.size();i++){
        std::cout<<"Giocatore "<<giocatori[i]->getId()<<": "<<giocatori[i]->getProprietaPossedute()<<"\n";
    }
}

int Partita::whose(const Casella& c) const{
    for(int i=0;i<giocatori.size();i++){
        for(int j=0;j<giocatori[i]->proprietaPossedute().size();j++){
            if(giocatori[i]->proprietaPossedute()[j].getId() == c.getId()){
                return giocatori[i]->getId();
            }
        }
    }
    return 0;//non è di nessuno
}