cmake_minimum_required(VERSION 3.27)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Cards)
include_directories(Players)

add_executable(ex4
        Cards/Card.h
        Players/Player.h
        main.cpp
        Mtmchkin.cpp
        Mtmchkin.h
        utilities.cpp
        utilities.h
        Players/Player.cpp
        Cards/Card.cpp
        Cards/Encounter.h
        Cards/Encounter.h
        Cards/Encounter.cpp
        Cards/Gang.h
        Cards/Gang.cpp
        Cards/Dragon.h
        Cards/Dragon.cpp
        Cards/Giant.h
        Cards/Goblin.h
        Cards/Giant.cpp
        Cards/Goblin.cpp
        Players/Warrior.h
        Players/Warrior.cpp
        Players/Sorcerer.h
        Players/Sorcerer.cpp
        Cards/Event.cpp
        Cards/PotionMerchant.cpp
        Cards/SolarEclipse.h
        Cards/SolarEclipse.h
        Cards/SolarEclipse.cpp
        Players/InvalidPlayersFile.h
        Cards/InvalidCardsFile.h
        testMain.cpp)
