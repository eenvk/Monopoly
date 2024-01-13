cmake_minimum_required(VERSION 3.10)

# Imposta il nome e la versione del software
project(Monopoly VERSION 1.0)

# Imposta la versione del linguaggio C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggiunge la directory degli header
include_directories(include)

# Aggiunge i file sorgente files, con main.cpp la radice
set(SOURCE_FILES
        src/Casella.cpp
        src/Giocatore.cpp
        src/GiocatoreComputer.cpp
        src/GiocatoreUmano.cpp
        src/Partita.cpp
        src/Tabellone.cpp
)

# Collego la raccolta dei file sorgente a quello principale
add_executable(Monopoly main.cpp ${SOURCE_FILES})