
//
// Created by Mahmoud on 3/19/2024.
//
#include "Player.h"
#include <iostream>




Player::Player(const std::string name, const std::string job, const std::string behavior,int maxHP, int force) {
    m_name=name;
    m_behavior=behavior;
    m_job=job;
    m_HP=maxHP;
    m_force=5;
    m_coins=10;
    m_level=1;
    m_maxHP=maxHP;
}
string Player::getDescription() const {
    return (m_name +", " + m_job + " with " + m_behavior +
            " behavior (level " + std::to_string(m_level) + ", force " + std::to_string(m_force) + ")" );
}
string Player::getName() const{
    return this->m_name;
}

int Player::getLevel() const {
    return this->m_level;
}

int Player::getForce() const{
    return this->m_force;
}

int Player::getHealthPoints() const {
    return this->m_HP;
}
int Player::getCoins() const {
    return this->m_coins;
}
void Player::levelUp() {
    if (this->m_level >= 1 && this->m_level < 10) {
        this->m_level++;
    }
}
void Player::buff(int add_force)
{
    this->m_force += add_force;
}

void Player::heal(int add_hp) {
    if(add_hp > 0) {
        if (this->m_HP + add_hp > m_maxHP) {
            this->m_HP = m_maxHP;
        } else {
            this->m_HP += add_hp;
        }
    }
}

void Player::damage(int taken_hp) {
    if (taken_hp >= 0)
    {
        if(m_HP >= taken_hp)
        {
            m_HP -= taken_hp;
        }
        else{
            m_HP=0;
        }
    }
}

bool Player::isKnockedOut() const {
    if(this->m_HP==0) {
        return true;
    }
    return false;
}

void Player::addCoins(int add_coins) {
    if (add_coins > 0) {
        m_coins += add_coins;
    }
}
bool Player::pay(int cost) {
    if (cost < 0){
        return false;
    }
    if(m_coins>=cost)
    {
        m_coins -= cost;
        return true;
    }
    return false;
}

string Player :: getBehavior() const
{
    return m_behavior;
}

int Player :: getMaxHealthPoints() const
{
    return m_maxHP
}