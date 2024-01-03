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
                int whose = Partita::whose(pos);
                if(whose == 0){
                    giocatori[j]->acquistaCasella(pos);
                }
                else{
                    if(whose == giocatori[j]->getId()){
                        if(pos.getTipo() == TERRENO){
                            try{
                                giocatori[j]->acquistaCasa(pos);
                            }
                            catch (Giocatore::BudgetInsufficiente){
                                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non ha abbastanza soldi per costruire una casa sul terreno "<<pos.getNome()<<"\n";
                            }
                        }
                        if(pos.getTipo() == CASA){
                            try{
                                giocatori[j]->miglioraInAlbergo(pos);
                            }
                            catch (Giocatore::BudgetInsufficiente){
                                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non ha abbastanza soldi per migliorare una casa in albergo sul terreno "<<pos.getNome()<<"\n";
                            }
                        }
                    }
                    else{
                        try{
                            if(pos.getCategoria() == ECONOMICA){
                                if(pos.getTipo() == CASA){
                                    giocatori[j]->paga(PERNOTTAMENTO_CASA_ECO);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_CASA_ECO);
                                            break;
                                        }
                                    }
                                }
                                if(pos.getTipo() == ALBERGO){
                                    giocatori[j]->paga(PERNOTTAMENTO_ALBERGO_ECO);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_ALBERGO_ECO);
                                            break;
                                        }
                                    }
                                }
                            }
                            if(pos.getCategoria() == STANDARD){
                                if(pos.getTipo() == CASA){
                                    giocatori[j]->paga(PERNOTTAMENTO_CASA_STANDARD);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_CASA_STANDARD);
                                            break;
                                        }
                                    }
                                }
                                if(pos.getTipo() == ALBERGO){
                                    giocatori[j]->paga(PERNOTTAMENTO_ALBERGO_STANDARD);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_ALBERGO_STANDARD);
                                            break;
                                        }
                                    }
                                }
                            }
                            if(pos.getCategoria() == LUSSO){
                                if(pos.getTipo() == CASA){
                                    giocatori[j]->paga(PERNOTTAMENTO_CASA_LUSSO);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_CASA_LUSSO);
                                            break;
                                        }
                                    }
                                }
                                if(pos.getTipo() == ALBERGO){
                                    giocatori[j]->paga(PERNOTTAMENTO_ALBERGO_LUSSO);
                                    for(int k=0;k<giocatori.size();k++){
                                        if(giocatori[k]->getId() == whose){
                                            giocatori[k]->incassa(PERNOTTAMENTO_ALBERGO_LUSSO);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        catch(Giocatore::BudgetInsufficiente){
                            int id = giocatori[j]->getId();
                            t.resetCaselle(giocatori[j]);
                            giocatori[j]->eliminaProprieta();
                            giocatori.erase(giocatori.begin()+j);
                            std::cout<<"Gicoatore "<<id<<" e' stato eliminato\n";
                        }
                    }
                }
            }
        }
        t.printTabellone(giocatori);
    }
    std::cout<<"\n";
    listaPossedimenti();
}
