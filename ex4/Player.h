//
// Created by user on 3/21/2024.
//

#ifndef UNTITLED27_PLAYER_H
#define UNTITLED27_PLAYER_H


#pragma once

#include <string>
#include <memory>

using std::string;

class Player {
public:
    Player(const string& name,const string& job,const string& behavior,int maxHP=100,int force=5);
    Player(const Player& other)=default;
    virtual ~Player()=default;
    Player& operator=(const Player&)=default;
    virtual int getAttackStrength() const;
    void levelUp();
    void buff(int add_force);
    void heal(int add_hp);
    void damage(int taken_hp);
    bool isKnockedOut() const;
    void addCoins(int add_coins);
    bool pay(int cost);
    int getMaxHealthPoints() const;

    string getBehavior() const;

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

private :
    static const int INITIAL_LEVEL=1;

protected:
    string m_name ;
    string m_job;
    string m_behavior;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};
//FOR SORTING THE LEADERBOARD:
bool playerCompare(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2); //custom '<' operator for the m_leaderboard sorting
typedef bool (*PlayerCompareFunc)(const std::shared_ptr<Player>&, const std::shared_ptr<Player>&);

#endif //UNTITLED27_PLAYER_H
