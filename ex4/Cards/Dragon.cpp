#include "Dragon.h"
using std::string;

Dragon ::Dragon() : Encounter(INITIAL_DRAGON_COMBATPOWER , INITIAL_DRAGON_LOOT , INITIAL_DRAGON_DAMAGE)
{}
string Dragon ::getDescription() const
{
    return "Dragon (power " + std::to_string(m_combatPower) + ", loot " + std::to_string(m_loot) + ", damage " + std::to_string(m_damage) + ")";
}
