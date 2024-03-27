#ifndef UNTITLED27_GANG_H
#define UNTITLED27_GANG_H

#include <vector>
#include "Encounter.h"

class Gang : public Encounter {
private:
    int m_gangSize;
    std::vector<Encounter*> m_gangMembers;
public:
    Gang();
    string getDescription() const override;
     void insertGangMember(Encounter* encounter);

};



#endif //UNTITLED27_GANG_H
