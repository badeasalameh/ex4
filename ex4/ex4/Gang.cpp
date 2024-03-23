#include "Gang.h"
int Gang :: getTotalCombatPower()
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getCombatPower();
    }
    return tot;
}
int Gang :: getTotalLoot()
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getLoot();
    }
    return tot;
}
int Gang :: getTotalDamage()
{
    int tot = 0;
    for(auto& gangMember : m_gangMembers)
    {
        tot += gangMember -> getDamage();
    }
    return tot;
}

Gang :: Gang() : Encounter(0 , 0 , 0)
{
    setCombatPower(getCombatPower());
    setLoot(getLoot());
    setDamage(getDamage());

    int count = 0;
    for(auto& gangMember : m_gangMembers)
    {
        count++;
    }
    m_gangSize = count;
}

string Gang :: getDescription() const
{
    return "Gang of " + to_string(m_gangSize) + "members (power " + to_string(m_combatPower) + ", loot " + to_string(m_loot) + ", damage " + to_string(m_damage) + ")";
}

int Gang :: getCombatPower() const
{
    return m_combatPower;
}
int Gang :: getLoot() const
{
    return m_loot;
}
int Gang :: getDamage() const
{
    return m_damage;
}


