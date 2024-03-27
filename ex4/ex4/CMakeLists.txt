cmake_minimum_required(VERSION 3.27)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        main.cpp
        Mtmchkin.cpp
        Mtmchkin.h
        utilities.cpp
        utilities.h
        Dragon.h
        Encounter.cpp
        Event.cpp
        Gang.cpp
        Dragon.cpp
        Giant.cpp
        Player.h
        Player.cpp
        Card.cpp
        Goblin.cpp
        PotionMerchant.cpp
        SolarEclipse.cpp
        Warrior.cpp
        Warrior.h
        Sorcerer.cpp
        Sorcerer.h
        InvalidCardsFile.h
        InvalidPlayersFile.h
)
