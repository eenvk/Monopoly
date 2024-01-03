#include "../include/PartitaComputer.h"

PartitaComputer::PartitaComputer() {
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
}

void PartitaComputer::run() {
    t.printTabellone(giocatori);
    Casella* caselle = t.getTabellone();
    for(int i=0;i<200;i++){
        for(int j=0;j<giocatori.size();j++){
            int n = giocatori[j]->tiroDadi();
            giocatori[j]->muovi(n);
            Casella& pos = caselle[giocatori[j]->getPosizione()];
            if(pos.getCategoria()==ANGOLARE || pos.getCategoria()==PARTENZA){
                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha finito il turno"<<"\n";
            }
            else{
                try {
                    //giocatori[j]->acquistaCasella(pos);
                    int whose = Partita::whose(pos);
                    if(whose == 0){
                        giocatori[j]->acquistaCasella(pos);
                    }
                    else{
                        if(whose == giocatori[j]->getId()){
                            if(pos.getTipo() == TERRENO){
                                giocatori[j]->acquistaCasa(pos);
                            }
                            if(pos.getTipo() == CASA){
                                giocatori[j]->miglioraInAlbergo(pos);
                            }
                        }
                    }
                }
                catch(Casella::TerrenoNonAcquistabile){
                    std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non puo acquistare il terreno perche non e' disponibile\n";
                }
            }
            if(typeid(giocatori[j]) == typeid(GiocatoreUmano)){

            }
        }
        t.printTabellone(giocatori);
    }
    std::cout<<"\n";
    listaPossedimenti();
}
