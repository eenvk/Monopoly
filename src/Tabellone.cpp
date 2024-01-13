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

    for (int i = 0; i < NUMERO_CASELLE; i++) {
        //Caselle angolari
        if (i == 0) {
            tabellone[i] = Casella(PARTENZA);
        } else if (i % (BASE-1) == 0) {
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
    for (int i = -1; i < ALTEZZA; i++) {
        for (int j = -1; j < BASE; j++) {
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
                if(j==-1){
                    std::cout << lettera++ << "  ";
                }
                else {
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[(BASE+ALTEZZA-2)+j]){
                            s = s+std::to_string(giocatori[k]->getId());
                        }
                        else{
                            s = s+" ";
                        }
                    }
                    std::cout << "|" << tabellone[(BASE+ALTEZZA-2)+j] << s << "|" << "  ";
                }
            }
            else if(i == ALTEZZA-1){
                std::string s;
                if(j==-1){
                    std::cout << lettera << "  ";
                }
                else {
                    for(int k=0; k<giocatori.size(); k++){
                        if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[(BASE-1)-j]){
                            s = s+std::to_string(giocatori[k]->getId());
                        }
                        else{
                            s = s+" ";
                        }
                    }
                    std::cout << "|" << tabellone[(BASE-1)-j] << s << "|" << "  ";
                }
            }
            else if(j==-1){
                std::cout << lettera++ << "  ";
            }
            else if(j == 0) {
                std::string s;
                for(int k=0; k<giocatori.size(); k++){
                    if(giocatori[k]->isAlive() && giocatori[k]->getPosizione()==tabellone[BASE+ALTEZZA-2 - i]){
                        s = s+std::to_string(giocatori[k]->getId());
                    }
                    else{
                        s = s+" ";
                    }
                }
                std::cout << "|" << tabellone[BASE+ALTEZZA-2 - i] << s << "|" << "  ";
            }
            else if (j == BASE-1) {
                std::string s;
                for (int k = 0; k < giocatori.size(); k++) {
                    if (giocatori[k]->isAlive() && giocatori[k]->getPosizione() == tabellone[((BASE*2)+ALTEZZA-3) + i]) {
                        s = s + std::to_string(giocatori[k]->getId());
                    } else {
                        s = s + " ";
                    }
                }
                std::cout << "|" << tabellone[((BASE*2)+ALTEZZA-3) + i] << s << "|";
            }
            else{
                std::cout << "          ";
            }
        }
        std::cout << std::endl;
    }
}

void Tabellone::nominaCaselle() {
    char lettera = 72;
    int numero = 9;
    int i = 0;
    for(int j=0;j<NUMERO_CASELLE;j++){
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