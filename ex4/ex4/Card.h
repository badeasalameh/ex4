#ifndef UNTITLED27_CARD_H
#define UNTITLED27_CARD_H
#pragma once

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
    explicit Card(const string& cardType);
};
#endif //UNTITLED27_CARD_H
