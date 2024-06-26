#include "Gang.h"

Gang :: Gang() : Encounter(0 , 0 , 0) , m_gangSize(0)
{}

string Gang :: getDescription() const
{
    return "Gang of " + to_string(m_gangSize) + " members (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}




void Gang :: insertGangMember(Encounter *encounter)
{
    m_gangMembers.push_back(encounter);
    m_combatPower += encounter -> getCombatPower();
    m_loot += encounter -> getLoot();
    m_damage += encounter -> getDamage();
    m_gangSize++;
}

