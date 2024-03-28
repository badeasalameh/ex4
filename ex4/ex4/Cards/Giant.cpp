//
// Created by Mahmoud on 3/20/2024.
//

#include "Giant.h"
Giant :: Giant() : Encounter(INITIAL_GIANT_COMBATPOWER , INITIAL_GIANT_LOOT , INITIAL_GIANT_DAMAGE){}
string Giant ::getDescription() const
{
    return "Giant (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}

