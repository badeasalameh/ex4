//
// Created by Mahmoud on 3/24/2024.
//

#ifndef EX4_SOLARECLIPSE_H
#define EX4_SOLARECLIPSE_H


#include "Event.h"

#define FORCE_TO_ADD 1
#define FORCE_TO_DEDUCT 1

class SolarEclipse : public Event{
public:
    SolarEclipse();
    string getDescription() const override;
};


#endif //EX4_SOLARECLIPSE_H
