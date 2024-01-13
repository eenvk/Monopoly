cmake_minimum_required(VERSION 3.26)

project(Monopoly)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monopoly
        main.cpp
        src/Casella.cpp
        src/Giocatore.cpp
        src/GiocatoreUmano.cpp
        src/GiocatoreComputer.cpp
        src/Tabellone.cpp
        src/Partita.cpp
)
