//Edoardo Renzi

#include "../include/Tabellone.h"

Tabellone::Tabellone() {
    setCaselle();
    nominaCaselle();
}

void Tabellone::setCaselle(){
    int max_economiche = 8;
    int max_standard = 10;
    int max_lusso = 6;

    //seme sempre diverso per evitare di avere tabelloni sempre uguali
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 28; i++) {
        //Caselle angolari
        if (i == 0) {
            tabellone[i] = Casella(PARTENZA);
        } else if (i % 7 == 0) {
            tabellone[i] = Casella(ANGOLARE);
        } else {
            // Caselle laterali
            while(true){
                int valore_rand = rand() % 3;
                if(valore_rand == 0){
                    if(max_economiche>0){
                        tabellone[i] = Casella(ECONOMICA); // Categoria economica
                        max_economiche--;
                        break;
                    }
                }
                else if(valore_rand == 1){
                    if(max_standard>0){
                        tabellone[i] = Casella(STANDARD); // Categoria standard
                        max_standard--;
                        break;
                    }
                }
                else if(valore_rand == 2){
                    if(max_lusso>0){
                        tabellone[i] = Casella(LUSSO); // Categoria lusso
                        max_lusso--;
                        break;
                    }
                }
            }
        }
    }
}

void Tabellone::printTabellone(const std::vector<Giocatore*> giocatori) const{
    char lettera = 'A';
    for (int i = -1; i < 8; i++) {
        for (int j = -1; j < 8; j++) {
            if(i == -1){
                if(j==-1){
                    std::cout << "      ";
                }
                else{
                    std::cout<<j+1<<"         ";
                }
            }
            else if(i == 0){
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[14+j]){
                        s = s+std::to_string(giocatori[k]->getId());
                    }
                    else{
                        s = s+" ";
                    }
                }
                if(j==-1){
                    std::cout << lettera++ << "  ";
                }
                else {
                    std::cout << "|" << tabellone[14 + j] << s << "|" << "  ";
                }
            }
            else if(i == 7){
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[7-j]){
                        s = s+std::to_string(giocatori[k]->getId());
                    }
                    else{
                        s = s+" ";
                    }
                }
                if(j==-1){
                    std::cout << lettera << "  ";
                }
                else {
                    std::cout << "|" << tabellone[7 - j] << s << "|" << "  ";
                }
            }
            else if(j==-1){
                std::cout << lettera++ << "  ";
            }
            else if(j == 0) {
                if(i==6){
                    std::string s;
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[14-i]){
                            s = s+std::to_string(giocatori[k]->getId());
                        }
                        else{
                            s = s+" ";
                        }
                    }
                    std::cout << "|" << tabellone[14 - i] << s << "|" << "  ";
                }
                else{
                    std::string s;
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[14-i]){
                            s = s+std::to_string(giocatori[k]->getId());
                        }
                        else{
                            s = s+" ";
                        }
                    }
                    std::cout << "|" << tabellone[14 - i] << s << "|" << "  ";
                }
            }
            else if (j == 7) {
                std::string s;
                for (int k = 0; k < giocatori.size(); k++) {
                    if (giocatori[k]->isAlive() && giocatori[k]->getPosizione() == tabellone[21 + i]) {
                        s = s + std::to_string(giocatori[k]->getId());
                    } else {
                        s = s + " ";
                    }
                }
                std::cout << "|" << tabellone[21 + i] << s << "|";
            }
            else{
                std::cout << "          ";
            }
        }
        std::cout << std::endl;
    }
}

void Tabellone::nominaCaselle() {
    for(int j=0;j<NUMERO_CASELLE;j++){
        static char lettera = 72;
        static int numero = 9;
        static int i = 0;
        if(i<BASE){
            i++;
            tabellone[j].setNome(lettera+std::to_string(--numero));
        }
        else if(i<BASE+ALTEZZA-1){
            i++;
            tabellone[j].setNome((--lettera)+std::to_string(numero));
        }
        else if(i<(BASE*2)+ALTEZZA-2){
            i++;
            tabellone[j].setNome(lettera+std::to_string(++numero));
        }
        else {
            i++;
            tabellone[j].setNome((++lettera) + std::to_string(numero));
        }
    }
}

Casella* Tabellone::getTabellone(){
    return tabellone;
}