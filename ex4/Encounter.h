#ifndef UNTITLED27_ENCOUNTER_H
#define UNTITLED27_ENCOUNTER_H
#include "Card.h"

class Encounter : public Card {
protected:
    int m_combatPower;
    int m_loot;
    int m_damage;
public:
    Encounter(int combatPower , int loot , int damage);

     virtual int getCombatPower() const = 0;
     virtual int getLoot() const = 0;
     virtual int getDamage() const = 0;

    void setCombatPower(int combatPower);
    void setLoot(int loot);
    void setDamage(int damage);
};
#endif //UNTITLED27_ENCOUNTER_H
