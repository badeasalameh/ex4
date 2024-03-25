#ifndef UNTITLED27_SOLARECLIPSE_H
#define UNTITLED27_SOLARECLIPSE_H

#include "Event.h"

class SolarEclipse : public Event{
public:
    SolarEclipse();
    string getDescription() const override;
};


#endif //UNTITLED27_SOLARECLIPSE_H
