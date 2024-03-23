#include "Encounter.h"

Encounter :: Encounter(int combatPower, int loot, int damage) : m_combatPower(combatPower) , m_loot(loot) , m_damage(damage)
{}
/*
int Encounter :: getCombatPower() const
{
    return m_combatPower;
}
int Encounter :: getLoot() const
{
    return m_loot;
}
int Encounter :: getDamage() const
{
    return m_damage;
}
*/
void Encounter :: setCombatPower(int combatPower)
{
    m_combatPower = combatPower;
}
void Encounter ::setLoot(int loot)
{
    m_loot = loot;
}
void Encounter ::setDamage(int damage)
{
    m_damage = damage;
}