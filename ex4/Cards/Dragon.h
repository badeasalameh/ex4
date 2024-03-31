#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Encounter.h"

#define INITIAL_DRAGON_COMBATPOWER 17
#define INITIAL_DRAGON_LOOT 100
#define INITIAL_DRAGON_DAMAGE 9001

class Dragon : public Encounter {
public:
    Dragon();

    string getDescription() const;
};

#endif //EX4_DRAGON_H
