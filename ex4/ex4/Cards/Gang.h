//
// Created by Mahmoud on 3/20/2024.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H


#include <vector>
#include "Encounter.h"

class Gang : public Encounter {
private:
    int m_gangSize;
public:
    Gang();
    string getDescription() const ;
    void insertGangMember(Encounter* encounter);
    std::vector<Encounter*> m_gangMembers;
};

#endif //EX4_GANG_H
