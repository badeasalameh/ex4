
#pragma once

#include "../Players/Player.h"
#include <sstream>

#include <sstream>
using namespace std;

class Card {
protected:
    std::string m_cardType;
public:
    /**
     * Gets the description of the card
     *
     * @return - the description of the card
    */
    virtual string getDescription() const = 0;
    virtual ~Card() = default;
    explicit Card(const string& cardType);
};
