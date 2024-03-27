#include "Encounter.h"

Encounter :: Encounter(int combatPower, int loot, int damage) : Card("Encounter") , m_combatPower(combatPower) , m_loot(loot) , m_damage(damage)
{}

int Encounter ::getCombatPower() const
{
    return m_combatPower;
}
int Encounter ::getLoot() const
{
    return m_loot;
}
int Encounter ::getDamage() const
{
    return m_damage;
}

