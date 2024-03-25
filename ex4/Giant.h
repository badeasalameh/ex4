#ifndef UNTITLED27_GIANT_H
#define UNTITLED27_GIANT_H

#include "Encounter.h"

#define INITIAL_GIANT_COMBATPOWER 12
#define INITIAL_GIANT_LOOT 5
#define INITIAL_GIANT_DAMAGE 25

class Giant : public Encounter {
public:
    Giant();
    std::string getDescription() const override;
     int getCombatPower() const override;
     int getLoot() const override;
     int getDamage() const override;

};

#endif //UNTITLED27_GIANT_H
