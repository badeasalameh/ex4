    //
// Created by Mahmoud on 3/20/2024.
//

#include "Warrior.h"
Warrior :: Warrior(const string& name ,const string& behavior,int maxHP,int force): Player(name,"Warrior",behavior,maxHP,force){}
int Warrior::getAttackStrength() const {
    return (m_force*2 +m_level);
}

