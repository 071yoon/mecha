#ifndef MBED_DISTANCESENSOR_H
#define MBED_DISTANCESENSOR_H

#include "mbed.h"

class DistanceSensor
{
public:
    DistanceSensor(PinName a);
    float getDistance_cm();

protected:
    float m_distance;
    AnalogIn  m_analogIn;
    
};

#endif //MBED_DISTANCESENSOR_H