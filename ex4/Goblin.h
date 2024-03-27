#ifndef UNTITLED27_GOBLIN_H
#define UNTITLED27_GOBLIN_H

#include "Encounter.h"

#define INITIAL_GOBLIN_COMBATPOWER 5
#define INITIAL_GOBLIN_LOOT 2
#define INITIAL_GOBLIN_DAMAGE 10

class Goblin : public Encounter{
public:
    Goblin();
    string getDescription() const override;
};


#endif //UNTITLED27_GOBLIN_H
