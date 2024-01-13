cmake_minimum_required(VERSION 3.26)
project(Monopoly)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monopoly
        main.cpp
        include/Casella.h
        src/Casella.cpp
        include/Giocatore.h
        src/Giocatore.cpp
        include/Tabellone.h
        src/Tabellone.cpp
        include/Partita.h
        src/Partita.cpp
        include/GiocatoreUmano.h
        src/GiocatoreUmano.cpp
        include/GiocatoreComputer.h
        src/GiocatoreComputer.cpp
        include/LogManager.h
)
