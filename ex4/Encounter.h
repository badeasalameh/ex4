#ifndef UNTITLED27_ENCOUNTER_H
#define UNTITLED27_ENCOUNTER_H
#include "Card.h"

class Encounter {
protected:
    int m_combatPower;
    int m_loot;
    int m_damage;
public:
    Encounter(int combatPower , int loot , int damage);

     virtual int getCombatPower() const;
     virtual int getLoot() const;
     virtual int getDamage() const;

    void setCombatPower(int combatPower);
    void setLoot(int loot);
    void setDamage(int damage);
};
#endif //UNTITLED27_ENCOUNTER_H
