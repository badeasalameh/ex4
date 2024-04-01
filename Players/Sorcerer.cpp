//
// Created by Mahmoud on 3/20/2024.
//

#include "Sorcerer.h"

int Sorcerer::getAttackStrength() const  {
    return m_force+m_level;
}