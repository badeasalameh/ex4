#include "Dragon.h"
Dragon ::Dragon() : Encounter(INITIAL_DRAGON_COMBATPOWER , INITIAL_DRAGON_LOOT , INITIAL_DRAGON_DAMAGE)
{}
string Dragon ::getDescription() const
{
    return "Dragon (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}
int Dragon :: getCombatPower() const
{
    return m_combatPower;
}
int Dragon :: getLoot() const
{
    return m_loot;
}
int Dragon :: getDamage() const
{
    return m_damage;
}