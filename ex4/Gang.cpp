#include "Gang.h"

Gang :: Gang() : Encounter(0 , 0 , 0) , m_gangSize(0)
{}

string Gang :: getDescription() const
{
    return "Gang of " + to_string(m_gangSize) + "members (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}

int Gang :: getCombatPower() const
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getCombatPower();
    }
    return tot;
}
int Gang :: getLoot() const
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getLoot();
    }
    return tot;
}
int Gang :: getDamage() const
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getDamage();
    }
    return tot;
}

void Gang :: insertGangMember(Encounter *encounter)
{
    m_gangMembers.push_back(encounter);
    m_gangSize++;
}


