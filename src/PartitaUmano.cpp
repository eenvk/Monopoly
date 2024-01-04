#include "../include/PartitaUmano.h"

PartitaUmano::PartitaUmano() {
    this->giocatori.push_back(new GiocatoreUmano());
    for(int i=1;i<NUMERO_GIOCATORI;i++){
        this->giocatori.push_back(new GiocatoreComputer());
    }
    ordinaGiocatori();
}

void PartitaUmano::run() {
    t.printTabellone(giocatori);
    Casella* caselle = t.getTabellone();

    bool is_run_alive = true;
    int n_giocatori = giocatori.size();

    for(int i=0; is_run_alive; i++){ //altrimenti max turni 500 && is_run_alive

        std::cout << "Turno: " << i+1 <<"!\n";

        for(int j=0;j<giocatori.size();j++){

            if(typeid(*giocatori[j]) == typeid(GiocatoreUmano)){
                std::cout << "E' umano \n";
                giocatori[j]->setDead(); //intanto cosi per vedere che funziona
                if(n_giocatori>3) //solo perchè se no si ripete da, eliminare ovviamente
                    n_giocatori--;
            }else{
                HandleComputerCase(j, n_giocatori, is_run_alive, caselle);
            }

        }
        t.printTabellone(giocatori);
        listaPossedimenti();
    }
    //winner
    for (int i=0; i<giocatori.size(); i++) {
        if(giocatori[i]->getProprietaPossedute().size()!=0)
            std::cout <<"\n\x1b[38;5;46mGIOCATORE "<< giocatori[i]->getId() << " HA VINTO LA PARTITA\x1b[0m\n";
    }
    std::cout<<"\n";
}


void PartitaUmano::HandleComputerCase(int& j, int& n_giocatori, bool& is_run_alive, Casella* caselle) {
    if(giocatori[j]->isAlive()){

        int n = giocatori[j]->tiroDadi();
        giocatori[j]->muovi(n);
        Casella& pos = caselle[giocatori[j]->getPosizione()];

        if(pos.getCategoria()==ANGOLARE || pos.getCategoria()==PARTENZA){
            std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha finito il turno"<<"\n";
        }
        else{
            int whose = Partita::whose(pos);
            if(whose == 0){
                try {
                    giocatori[j]->acquistaCasella(pos);
                }catch (Giocatore::BudgetInsufficiente){
                    std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non ha abbastanza soldi per comprare il terreno "<<pos.getNome()<<"\n";
                }
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
                    else if(pos.getTipo() == CASA){
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
                            else if(pos.getTipo() == ALBERGO){
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
                            else if(pos.getTipo() == ALBERGO){
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
                            else if(pos.getTipo() == ALBERGO){
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
                        std::cout<<"\033[31mGicoatore "<<id<<" e' stato eliminato\033[0m\n";
                        //t.resetCaselle(giocatori[j]);
                        giocatori[j]->eliminaProprieta();
                        giocatori[j]->setDead();
                        n_giocatori--;
                        if( n_giocatori==1 )
                            is_run_alive = false;
                    }
                }
            }
        }
    }
}
