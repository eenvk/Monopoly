//Elena Novkovic

#include "../include/Partita.h"

Partita::Partita(std::string arg) {
    if(arg=="human"){
        this->giocatori.push_back(new GiocatoreUmano(&t.getTabellone()[0]));
        for(int i=1;i<NUMERO_GIOCATORI;i++){
            this->giocatori.push_back(new GiocatoreComputer(&t.getTabellone()[0]));
        }
    }
    else{
        for(int i=0;i<NUMERO_GIOCATORI;i++){
            this->giocatori.push_back(new GiocatoreComputer(&t.getTabellone()[0]));
        }
    }
    ordinaGiocatori(); //ordino il vector di giocatori in modo che siano disposti in ordine decrescente in base al numero uscito nel tiro dei dadi
}

//se il numero più alto che e' uscito nei tiri e' uno solo (cioe non ci sono 2 o piu giocatori che hanno avuto lo stesso esito nel lancio) questo viene pushato nel vector,
//se no quelli che hanno avuto lo stesso esito ritirano i dadi finche di nuovo non si riesce a stabilire un unico massimo nella multimappa che deve essere pushato nel vector
void Partita::ordinaGiocatori() {
    std::multimap<int,int,std::greater<int>> ordine; //multimappa che mette in ordine decrescente rispetto al numero uscito nei lanci
    std::cout<<"I giocatori tirano i dadi per decidere l'ordine di gioco"<<"\n";
    for(int i=0;i<NUMERO_GIOCATORI;i++){
        int n = giocatori[i]->tiroDadi();
        ordine.insert(std::make_pair(n, giocatori[i]->getId()));
    }
    std::vector<Giocatore*> temp;
    while(!ordine.empty()){
        int valore = ordine.begin()->first; //lancio con il valore piu alto
        int count = ordine.count(valore); //conto il numero di tiri che hanno avuto lo stesso esito
        while(count>=2){
            for(int i=0;i<count;i++){
                int id_giocatore = ordine.find(valore)->second;
                ordine.erase(ordine.find(valore));
                int n = giocatori[id_giocatore-1]->tiroDadi(); //faccio ritirare i dadi al giocatore che ha avuto il numero uguale a quello di un altro giocatore
                ordine.insert(std::make_pair(n, id_giocatore));
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

void Partita::visualizzaBudgetGiocatori() const{
    for(int i=0;i<giocatori.size();i++){
        std::cout<<"Giocatore "<<giocatori[i]->getId()<<" ha "<<giocatori[i]->getBudget()<<" fiorini\n";
    }
}

Giocatore* Partita::getProprietario(const Casella& c) const{
    for(int i=0;i<giocatori.size();i++){
        for(int j=0;j<giocatori[i]->proprietaPossedute().size();j++){
            if(*giocatori[i]->proprietaPossedute()[j] == c){
                return giocatori[i];
            }
        }
    }
    return nullptr;//c non è di nessuno
}

void Partita::run() {
    //t.printTabellone(giocatori);

    bool is_running = true;
    int n_giocatori = giocatori.size();

    for(int i=0; is_running && i < MAX_TURNI; i++){

        std::cout << "Turno: " << i+1 <<"\n";

        for(int j=0;j<giocatori.size();j++){

            if(giocatori[j]->isAlive()){

                int spostamento = giocatori[j]->tiroDadi();
                muoviGiocatore(giocatori[j],spostamento);
                Casella& pos = giocatori[j]->getPosizione();

                std::cout<<"Giocatore "<<giocatori[j]->getId()<<" e' arrivato alla casella "<<pos.getNome()<<"\n";
                LogManager::log("Giocatore " + std::to_string(giocatori[j]->getId()) + " e' arrivato alla casella " + pos.getNome());

                if(pos.getCategoria()==ANGOLARE || pos.getCategoria()==PARTENZA){
                    std::cout<<"Giocatore "<<giocatori[j]->getId()<<" ha finito il turno\n";
                    LogManager::log("Giocatore " + std::to_string(giocatori[j]->getId()) + " ha finito il turno");
                }
                else{
                    Giocatore* proprietario = Partita::getProprietario(pos);
                    if(proprietario == nullptr){ //la casella non è di nessuno
                        try {
                            if(typeid(*giocatori[j]) == typeid(GiocatoreUmano)){
                                if(handleHumanInteraction("Vuoi acquistare il terreno " + pos.getNome() + "?")){
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
                                giocatori[j]->eliminaProprieta();
                                giocatori[j]->setDead();
                                std::cout<<"Gicoatore "<<id<<" e' stato eliminato\n";
                                LogManager::log("Giocatore " + std::to_string(id) + " e' stato eliminato");
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
        /*t.printTabellone(giocatori);
        std::cout<<"Possedimenti di\n";
        listaPossedimenti();*/
        std::cout<<"\n";
    }
}

void Partita::muoviGiocatore(Giocatore *g, const int spostamento) {
    Casella* caselle = t.getTabellone();
    int current = g->getPosizione().getId();
    int newPos = spostamento + current;
    g->setPosizione(&caselle[newPos % NUMERO_CASELLE]);
    if(newPos>NUMERO_CASELLE-1){ //e' passato per la partenza
        g->incassa(INCREMENTO_BUDGET);
        LogManager::log("Giocatore " + std::to_string(g->getId()) + " e' passato dal via e ha ritirato " + std::to_string(INCREMENTO_BUDGET) + " fiorini");
        std::cout<<"Giocatore "<<g->getId()<<" e' passato dal via e ha ritirato "<<INCREMENTO_BUDGET<<" fiorini"<<"\n";
    }
}

void Partita::transazione(Giocatore* g, Giocatore* proprietario, const int prezzo, const Casella& pos) {
    g->paga(prezzo);
    proprietario->incassa(prezzo);
    std::cout<<"Giocatore "<<g->getId()<<" ha pagato "<<prezzo<<" fiorini a giocatore "<<proprietario->getId()<<" per pernottamento nella casella "<<pos.getNome()<<"\n";
    LogManager::log("Giocatore " + std::to_string(g->getId()) + " ha pagato " + std::to_string(prezzo) + " fiorini a giocatore " + std::to_string(proprietario->getId()) + " per pernottamento nella casella " + pos.getNome());
}

bool Partita::handleHumanInteraction(const std::string messaggio) const{
    std::string risposta;

    while(true){
        std::cout << messaggio << " [rispondi 'S' per si, 'N' per no, 'show' per visualizzare lo stato della partita]\n";
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
            std::cout<<"Possedimenti di\n";
            listaPossedimenti();
            std::cout<<"-----------\n";
            visualizzaBudgetGiocatori();
        }
    }
}

void Partita::printWinner() const{
    int max_budget = 0;
    int budget = 0;

    for (int i=0; i<giocatori.size(); i++) {
        if(giocatori[i]->isAlive()) {
            budget = giocatori[i]->getBudget();
            if(budget >= max_budget){
                max_budget = budget;
            }
        }
    }
    for(int i=0;i<giocatori.size();i++){
        if(giocatori[i]->isAlive() && giocatori[i]->getBudget() >= max_budget){
            std::cout << "GIOCATORE " << giocatori[i]->getId() << " HA VINTO LA PARTITA\n";
            LogManager::log("GIOCATORE " + std::to_string(giocatori[i]->getId()) + " HA VINTO LA PARTITA");
        }
    }
}

Partita::~Partita() {
    for (Giocatore* giocatore : giocatori) {
        delete giocatore;
    }
    giocatori.clear();
}
