//
// Created by Mahmoud on 3/20/2024.
//

#ifndef EX4_ENCOUNTER_H
#define EX4_ENCOUNTER_H
#include "Card.h"

class Encounter : public Card{
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
#endif //EX4_ENCOUNTER_H
