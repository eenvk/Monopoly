#include "../include/Tabellone.h"

Tabellone::Tabellone() {
    setCaselleTabellone();
}

void Tabellone::setCaselleTabellone() {

    int max_economiche = 8;
    int max_standard = 10;
    int max_lusso = 6;
    std::vector<int> pos_disponibili;

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
            int valore_rand = rand() % 3;
            if (valore_rand == 0 && max_economiche > 0) {
                tabellone[i] = Casella('E'); // Categoria economica
                max_economiche--;
            } else if (valore_rand == 1 && max_standard > 0) {
                tabellone[i] = Casella('S'); // Categoria standard
                max_standard--;
            } else if (valore_rand == 2 && max_lusso > 0) {
                tabellone[i] = Casella('L'); // Categoria lusso
                max_lusso--;
            } else {
                tabellone[i] = Casella(' ');
                pos_disponibili.push_back(i);
            }
        }
    }

    // Riempie le posizioni mancanti
    std::random_shuffle(pos_disponibili.begin(), pos_disponibili.end()); //E' una funzione di algorithm della lib_std quindi dovrebbe andare bene perchè non saprei come rimischiarle in altri modi, altrimenti non le rimischiamo proprio
    for (int i = 0; i < pos_disponibili.size(); i++) {
        int index = pos_disponibili[i];
        if (max_economiche > 0 ) {
            tabellone[index].setCategoria('E');
            max_economiche--;
        } else if (max_standard > 0) {
            tabellone[index].setCategoria('S');
            max_standard--;
        } else if (max_lusso > 0 ) {
            tabellone[index].setCategoria('L');
            max_lusso--;
        }
    }
}

Casella* Tabellone::getTabellone() {
    return tabellone;
}

void Tabellone::resetCaselle(Giocatore g) {
    std::vector<Casella> copy = g.getVector();
    int j = 0;
    for (int i = 0; i < 28 && j < copy.size(); ++i) {
        if(tabellone[i].getId()==copy[j].getId()){
            tabellone[i].reset();
            j++;
        }
    }
}

std::ostream& operator<<(std::ostream& os, Tabellone& t){
    Casella* copy = t.getTabellone(); //non serve gestire il memory leak dato che l'array non è dinamico
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0) {
                os << "|" << copy[14 + j] << "|" << "  ";
            } else if (i == 7) {
                os << "|" << copy[7 - j] << "|" << "  ";
            } else if (j == 0 && i != 0 && i != 7) {
                if (i == 6) {
                    os << "|" << copy[14 - i] << "|" << "  ";
                } else {
                    os << "|" << copy[14 - i] << "|" << "  ";
                }
            } else if (j == 7 && i != 0 && i != 7) {
                os << "|" << copy[21 + i] << "|";
            } else {
                os << "       ";
            }
        }
        os << std::endl;
    }
    return os;
}

/*int array[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0){
                cout<<array[14+j]<<" ";
            }
            else if(i==7){
                cout<<array[7-j]<<"  ";
            }
            else if(j==0 && i!=0 && i!=7){
                if(i==6){
                    cout<<array[14-i]<<"  ";
                }
                else {
                    cout << array[14 - i] << " ";
                }
            }
            else if(j==7 && i!=0 && i!=7){
                cout<<array[21+i];
            }
            else{
                cout << "   ";
            }
        }
        cout<<endl;
    }*/