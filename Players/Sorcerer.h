//
// Created by Mahmoud on 3/20/2024.
//

#ifndef EX4_SORCERER_H
#define EX4_SORCERER_H

#include "Player.h"

class Sorcerer : public Player{
public:
    Sorcerer(const string& name ,const string& behavior,int maxHP=100,int force=5): Player(name,"Sorcerer",behavior,maxHP,force){}
    Sorcerer(const Sorcerer& sorcerer): Player(sorcerer)  {}
    Sorcerer& operator=(const Sorcerer& sorcerer) =default;
    ~Sorcerer()override=default;
    int getAttackStrength() const override;
};

#endif //EX4_SORCERER_H
