#include "Encounter.h"

Encounter :: Encounter(int combatPower, int loot, int damage) : Card("Encounter") , m_combatPower(combatPower) , m_loot(loot) , m_damage(damage)
{}
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