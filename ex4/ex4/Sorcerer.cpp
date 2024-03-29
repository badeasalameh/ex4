//
// Created by Mahmoud on 3/20/2024.
//

#include "Sorcerer.h"
Sorcerer :: Sorcerer(const string& name ,const string& behavior,int maxHP,int force): Player(name,"Sorcerer",behavior,maxHP,force){}
int Sorcerer::getAttackStrength() const  {
    return m_force+m_level;
}