#include "../include/Tabellone.h"

Tabellone::Tabellone() {
    setCaselle();
}

void Tabellone::setCaselle(){
    int max_economiche = 8;
    int max_standard = 10;
    int max_lusso = 6;

    // seme sempre diverso per evitare di avere tabelloni sempre uguali, altrimenti basta commentarlo così il tabellone è sempre lo stesso
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 28; i++) {
        //Caselle angolari
        if (i == 0) {
            tabellone[i] = Casella('P');
        } else if (i % 7 == 0) {
            tabellone[i] = Casella(' ');
        } else {
            // Caselle laterali
            while(true){
                int valore_rand = rand() % 3;
                if(valore_rand == 0){
                    if(max_economiche>0){
                        tabellone[i] = Casella('E'); // Categoria economica
                        max_economiche--;
                        break;
                    }
                }
                else if(valore_rand == 1){
                    if(max_standard>0){
                        tabellone[i] = Casella('S'); // Categoria standard
                        max_standard--;
                        break;
                    }
                }
                else if(valore_rand == 2){
                    if(max_lusso>0){
                        tabellone[i] = Casella('L'); // Categoria lusso
                        max_lusso--;
                        break;
                    }
                }
            }
        }
    }
}

Casella* Tabellone::getTabellone() {
    return tabellone;
}

void Tabellone::resetCaselle(Giocatore g) {
    std::vector<Casella> proprietà_possedute = g.proprietaPossedute();
    int j = 0;
    for (int i = 0; i < 28 && j < proprietà_possedute.size(); ++i) {
        if(tabellone[i].getId() == proprietà_possedute[j].getId()){
            tabellone[i].reset();
            j++;
        }
    }
}

void Tabellone::printTabellone(std::vector<Giocatore> giocatori) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0) {
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k].getPosizione()==tabellone[14+j].getId()){
                        s = s + std::to_string(giocatori[k].getId());
                    }
                    else{
                        s = " ";
                    }
                }
                std::cout << "|" << tabellone[14 + j].toString() + s << "|" << "  ";
            } else if (i == 7) {
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k].getPosizione()==tabellone[7-j].getId()){
                        s = s + std::to_string(giocatori[k].getId());
                    }
                    else{
                        s = " ";
                    }
                }
                std::cout << "|" << tabellone[7 - j].toString() + s << "|" << "  ";
            } else if (j == 0 && i != 0 && i != 7) {
                if(i==6){
                    std::string s;
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k].getPosizione()==tabellone[14-i].getId()){
                            s = s + std::to_string(giocatori[k].getId());
                        }
                        else{
                            s = " ";
                        }
                    }
                    std::cout << "|" << tabellone[14 - i].toString() + s << "|" << "  ";
                }
                else{
                    std::string s;
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k].getPosizione()==tabellone[14-i].getId()){
                            s = s + std::to_string(giocatori[k].getId());
                        }
                        else{
                            s = " ";
                        }
                    }
                    std::cout << "|" << tabellone[14 - i].toString() + s << "|" << "  ";
                }
            } else if (j == 7 && i != 0 && i != 7) {
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k].getPosizione()==tabellone[21+i].getId()){
                        s = s + std::to_string(giocatori[k].getId());
                    }
                    else{
                        s = " ";
                    }
                }
                std::cout << "|" << tabellone[21 + i].toString() + s << "|";
            } else {
                std::cout << "       ";
            }
        }
        std::cout << std::endl;
    }
}