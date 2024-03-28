//
// Created by Mahmoud on 3/20/2024.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"
using std::string;

class Warrior : public Player{
public:
Warrior(const string& name ,const string& behavior,int maxHP=100,int force=5): Player(name,"Warrior",behavior,maxHP,force){};
    Warrior(const Warrior& WarriorPlayer): Player(WarriorPlayer) {};
    Warrior& operator=(const Warrior& Wariorlayer) =default;
     ~Warrior()=default;
  int getAttackStrength() const override;
};


#endif //EX4_WARRIOR_H
