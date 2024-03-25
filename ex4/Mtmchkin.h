
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

#include "Encounter.h"
#include "Dragon.h"
#include "Giant.h"
#include "Goblin.h"
#include "Gang.h"

#include "Event.h"
#include "SolarEclipse.h"
#include "PotionMerchant.h"

#include "Warrior.h"
#include "Sorcerer.h"

#define POTION_COST 5
#define POTION_HEAL 10
#define SOLARECLIPSE_WARRIOR -1
#define SOLARECLIPSE_SORCERER 1
#define MAX_LEVEL 10

using std::string;
using std::shared_ptr;
using std::vector;
using std::queue;
using std::map;
using std::set;

class Mtmchkin{
private:
    int m_turnIndex;
    int m_numOfWinners;
    int m_numOfLosers;

    map<int , shared_ptr<Player>> m_players;
    queue<shared_ptr<Card>> m_cards;
    vector<shared_ptr<Player>> m_finished;
    set<shared_ptr<Player> , PlayerCompareFunc> m_leaderboard;

    /**
     * Plays a single turn for a player
     * 
     * @param player - the player to play the turn for
     * 
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     * 
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     * 
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    /**
     * Constructor of Mtmchkin class
     * 
     * @param deckPath - path to the deck file
     * @param playersPath - path to the players file
     * 
     * @return - Mtmchkin object with the given deck and players
     *
    */
    Mtmchkin(const string& deckPath, const string& playersPath);

    /**
     * Plays the entire game
     * 
     * @return - void
    */
    void play();
};
