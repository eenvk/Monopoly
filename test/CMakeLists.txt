cmake_minimum_required(VERSION 3.10)

# Imposta la versione del linguaggio C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Imposta i compilatori C e C++
set(CMAKE_C_COMPILER "cl")
set(CMAKE_CXX_COMPILER "cl")

project(Monopoly)

# Aggiungi le directory degli header
include_directories(include)

# Trova tutti i file sorgente
file(GLOB SOURCES "src/*.cpp")

# Crea una libreria con tutti i file sorgente della directory src
add_library(MonopolyLib ${SOURCES})

# Aggiungi l'eseguibile principale
add_executable(monopoly main.cpp)

# Collega l'eseguibile alla libreria MonopolyLib
target_link_libraries(monopoly PRIVATE MonopolyLib)
