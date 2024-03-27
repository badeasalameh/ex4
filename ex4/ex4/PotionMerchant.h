//
// Created by user on 3/20/2024.
//
#include "Event.h"

#ifndef UNTITLED27_POTIONMERCHANT_H
#define UNTITLED27_POTIONMERCHANT_H


class PotionMerchant : public Event {
public:
    PotionMerchant();
    string getDescription() const override;
};


#endif //UNTITLED27_POTIONMERCHANT_H
