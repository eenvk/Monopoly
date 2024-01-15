//Edoardo Renzi

#ifndef MONOPOLY_LOGMANAGER_H
#define MONOPOLY_LOGMANAGER_H
#include <iostream>
#include <fstream>

class LogManager {
public:
    static void log(const std::string messaggio){
        static bool first_time = true;
        std::ofstream logFile;
        if(first_time){ //ad ogni nuova esecuzione del programma il file sovrascrive le cose che erano scritte nell'esecuzione precedente (con std::ios_base::out)
            logFile.open("log_file.txt", std::ios_base::out);
            first_time = false;
        }
        else{
            logFile.open("log_file.txt", std::ios_base::app);
        }

        if (logFile.is_open()) {
            logFile << messaggio << std::endl;
            logFile.close();
        } else {
            std::cerr << "errore nell'apertura del file" << std::endl;
        }
    }
};

#endif //MONOPOLY_LOGMANAGER_H