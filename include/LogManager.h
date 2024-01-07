#ifndef MONOPOLY_LOGMANAGER_H
#define MONOPOLY_LOGMANAGER_H
#include <iostream>

class LogManager {
public:
    static void log(const std::string messaggio){
        std::ofstream logFile;
        logFile.open("logfile.txt", std::ios_base::app);

        if(!logFile.is_open()) {
            std::cerr << "Failed to open logfile." << std::endl;
            return;
        }

        logFile << messaggio << std::endl;
        logFile.close();
    }
};

/*void Partita::writeLog(const std::string messaggio) const {
    std::ofstream logFile;
    logFile.open("C:\\Users\\elena\\Documents\\uni\\LabProgrammazione\\Monopoly\\log_file.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << messaggio << std::endl;
        logFile.close();
    } else {
        std::cerr << "errore nell'apertura del file" << std::endl;
    }
}*/

#endif //MONOPOLY_LOGMANAGER_H