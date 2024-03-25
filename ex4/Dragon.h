#ifndef UNTITLED27_DRAGON_H
#define UNTITLED27_DRAGON_H
#include "Encounter.h"

#define INITIAL_DRAGON_COMBATPOWER 17
#define INITIAL_DRAGON_LOOT 100
#define INITIAL_DRAGON_DAMAGE 9001

class Dragon : public Encounter{
public:
    Dragon();
    string getDescription() const override;
     int getCombatPower() const override;
     int getLoot() const override;
     int getDamage() const override;
};
#endif //UNTITLED27_DRAGON_H
