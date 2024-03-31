#ifndef EX4_GIANT_H
#define EX4_GIANT_H

#include "Encounter.h"

#define INITIAL_GIANT_COMBATPOWER 12
#define INITIAL_GIANT_LOOT 5
#define INITIAL_GIANT_DAMAGE 25

class Giant : public Encounter {
public:
    Giant();
    std::string getDescription() const;

};

#endif //EX4_GIANT_H
