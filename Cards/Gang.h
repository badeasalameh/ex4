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
    string getDescription() const override;
    void insertGangMember(Encounter* encounter);
    std::vector<Encounter*> m_gangMembers;
 ~Gang() override{
     for (int i = 0; i < m_gangSize; i++) {
         delete  m_gangMembers[i];
     }
 }
};

#endif //EX4_GANG_H
