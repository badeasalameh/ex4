//
// Created by Mahmoud on 3/20/2024.
//

#include "Goblin.h"

#define INITIAL_GOBLIN_COMBATPOWER 5
#define INITIAL_GOBLIN_LOOT 2
#define INITIAL_GOBLIN_DAMAGE 10

Goblin :: Goblin() : Encounter(INITIAL_GOBLIN_COMBATPOWER , INITIAL_GOBLIN_LOOT , INITIAL_GOBLIN_DAMAGE){}
    string Goblin :: getDescription() const
    {
        return "Goblin (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
    }
