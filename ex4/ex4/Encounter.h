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

    int getCombatPower() const;
    int getLoot() const;
    int getDamage() const;
};
#endif //UNTITLED27_ENCOUNTER_H
