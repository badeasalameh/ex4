#include "Goblin.h"
Goblin :: Goblin() : Encounter(INITIAL_GOBLIN_COMBATPOWER , INITIAL_GOBLIN_LOOT , INITIAL_GOBLIN_DAMAGE){}
string Goblin :: getDescription() const
{
    return "Goblin (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}