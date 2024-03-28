//
// Created by Mahmoud on 3/24/2024.
//

#ifndef EX4_POTIONMERCHANT_H
#define EX4_POTIONMERCHANT_H

#include "Event.h"
 class PotionMerchant : public Event {
 public:
    PotionMerchant();
   string getDescription() const override;
};


#endif //EX4_POTIONMERCHANT_H
