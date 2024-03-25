#ifndef UNTITLED27_SOLARECLIPSE_H
#define UNTITLED27_SOLARECLIPSE_H

#include "Event.h"

#define FORCE_TO_ADD 1
#define FORCE_TO_DEDUCT 1

class SolarEclipse : public Event{
public:
    SolarEclipse();
    string getDescription() const override;
};


#endif //UNTITLED27_SOLARECLIPSE_H
