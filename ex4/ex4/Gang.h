#ifndef UNTITLED27_GANG_H
#define UNTITLED27_GANG_H

#include <vector>
#include "Encounter.h"

class Gang : public Encounter {
private:
    std::vector<Encounter*> m_gangMembers;
    int m_gangSize;
public:
    int getTotalCombatPower();
    int getTotalLoot();
    int getTotalDamage();
    Gang();
    string getDescription() const;
     int getCombatPower() const override;
     int getLoot() const override;
     int getDamage() const override;
};


#endif //UNTITLED27_GANG_H
