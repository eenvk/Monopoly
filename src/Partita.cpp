#include "../include/Partita.h"
/*Partita::Partita(std::string arg) {
    if(arg=="human"){
        this->giocatori.push_back(new GiocatoreUmano());
        for(int i=1;i<NUMERO_GIOCATORI;i++){
            this->giocatori.push_back(new GiocatoreComputer());
        }
    }
    else{
        for(int i=0;i<NUMERO_GIOCATORI;i++){
            this->giocatori.push_back(new GiocatoreComputer());
        }
    }
    ordinaGiocatori();
}*/

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

void Partita::listaPossedimenti() const{
    for(int i=0;i<giocatori.size();i++){
        if(!giocatori[i]->isAlive())
            std::cout<<"Giocatore "<<giocatori[i]->getId()<<": "<<"eliminato\n";
        else
            std::cout<<"Giocatore "<<giocatori[i]->getId()<<": "<<giocatori[i]->getProprietaPossedute()<<"\n";
    }
}

void Partita::visualizzaBudgetGiocatori() const {
    for(int i=0;i<giocatori.size();i++){
        std::cout<<"Giocatore "<<giocatori[i]->getId()<<" ha "<<giocatori[i]->getBudget()<<" fiorini\n";
    }
}

Giocatore* Partita::proprietario(const Casella& c) const{
    for(int i=0;i<giocatori.size();i++){
        for(int j=0;j<giocatori[i]->proprietaPossedute().size();j++){
            if(giocatori[i]->proprietaPossedute()[j]->getId() == c.getId()){
                return giocatori[i];
            }
        }
    }
    return nullptr;//non è di nessuno
}

void Partita::run() {
    t.printTabellone(giocatori);
    Casella* caselle = t.getTabellone();

    bool is_running = true;
    int n_giocatori = giocatori.size();

    for(int i=0; is_running && i < MAX_TURNI; i++){ //altrimenti max turni 500 && is_running

        std::cout << "Turno: " << i+1 <<"\n";

        for(int j=0;j<giocatori.size();j++){

            if(giocatori[j]->isAlive()){

                int n = giocatori[j]->tiroDadi();
                giocatori[j]->muovi(n);
                Casella& pos = caselle[giocatori[j]->getPosizione()];
                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" e' arrivato alla casella "<<pos.getNome()<<"\n";
                if(pos.getCategoria()==ANGOLARE || pos.getCategoria()==PARTENZA){
                    std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha finito il turno"<<"\n";
                }
                else{
                    Giocatore* proprietario = Partita::proprietario(pos);
                    if(proprietario == nullptr){
                        try {
                            if(typeid(*giocatori[j]) == typeid(GiocatoreUmano)){
                                if(handleHumanInteraction("Vuoi acquistare la casella " + pos.getNome() + "?")){
                                    giocatori[j]->acquistaCasella(pos);
                                }
                            }else{
                                giocatori[j]->acquistaCasella(pos);
                            }
                        }catch (Giocatore::BudgetInsufficiente){
                            std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non ha abbastanza soldi per comprare il terreno "<<pos.getNome()<<"\n";
                        }
                    }
                    else{
                        if(proprietario == giocatori[j]){
                            if(pos.getTipo() == TERRENO){
                                try{
                                    if(typeid(*giocatori[j]) == typeid(GiocatoreUmano)){
                                        if(handleHumanInteraction("Vuoi costruire una casa sulla casella " + pos.getNome() + "?")){
                                            giocatori[j]->acquistaCasa(pos);
                                        }
                                    }else{
                                        giocatori[j]->acquistaCasa(pos);
                                    }
                                }
                                catch (Giocatore::BudgetInsufficiente){
                                    std::cout<<"Giocatore "<<giocatori[j]->getId()<<" non ha abbastanza soldi per costruire una casa sul terreno "<<pos.getNome()<<"\n";
                                }
                            }
                            else if(pos.getTipo() == CASA){
                                try{
                                    if(typeid(*giocatori[j]) == typeid(GiocatoreUmano)){
                                        if(handleHumanInteraction("Vuoi migliorare la casa in albergo sulla casella " + pos.getNome() + "?")){
                                            giocatori[j]->miglioraInAlbergo(pos);
                                        }
                                    }else{
                                        giocatori[j]->miglioraInAlbergo(pos);
                                    }
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
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_CASA_ECO, pos);
                                    }
                                    else if(pos.getTipo() == ALBERGO){
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_ALBERGO_ECO, pos);
                                    }
                                }
                                if(pos.getCategoria() == STANDARD){
                                    if(pos.getTipo() == CASA){
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_CASA_STANDARD, pos);
                                    }
                                    else if(pos.getTipo() == ALBERGO){
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_ALBERGO_STANDARD, pos);
                                    }
                                }
                                if(pos.getCategoria() == LUSSO){
                                    if(pos.getTipo() == CASA){
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_CASA_LUSSO, pos);
                                    }
                                    else if(pos.getTipo() == ALBERGO){
                                        transazione(giocatori[j], proprietario, PERNOTTAMENTO_ALBERGO_LUSSO, pos);
                                    }
                                }
                            }
                            catch(Giocatore::BudgetInsufficiente){
                                int id = giocatori[j]->getId();
                                std::cout<<"\033[31mGicoatore "<<id<<" e' stato eliminato\033[0m\n";
                                giocatori[j]->eliminaProprieta();
                                giocatori[j]->setDead();
                                n_giocatori--;
                                if(n_giocatori==1) {
                                    is_running = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        t.printTabellone(giocatori);
        listaPossedimenti();
        std::cout<<"\n";
    }
}

void Partita::transazione(Giocatore* g, Giocatore* proprietario, int prezzo, Casella& pos) {
    g->paga(prezzo);
    proprietario->incassa(prezzo);
    std::cout<<"Giocatore "<<g->getId()<<" ha pagato "<<prezzo<<" fiorini a giocatore "<<proprietario->getId()<<" per pernottamento nella casella "<<pos.getNome()<<"\n";
}

bool Partita::handleHumanInteraction(std::string messaggio){
    std::string risposta;

    while(true){
        std::cout << messaggio << " [rispondi 'S' per si o 'S' per no]\n";
        std::cin >> risposta;
        if(risposta=="S" || risposta=="s"){
            return true;
        }
        else if(risposta=="N" || risposta=="n"){
            return false;
        }
        else if(risposta=="show"){
            t.printTabellone(giocatori);
            std::cout<<"-----------\n";
            listaPossedimenti();
            std::cout<<"-----------\n";
            visualizzaBudgetGiocatori();
        }
    }
}

Partita::~Partita() {
    for (Giocatore* giocatore : giocatori) {
        delete giocatore;
    }
    giocatori.clear();
}