#include "DistanceSensor.h"

#define MAX_DISTANCE (-1.0)

DistanceSensor::DistanceSensor(PinName a): m_analogIn(a)
{
    m_distance = MAX_DISTANCE;
}

float DistanceSensor::getDistance_cm()
{
    float scaled_analog = 3.3*m_analogIn;
    
    if (scaled_analog >= 3.0){
        m_distance = 5.0;
    }
    else if (scaled_analog < 3.0 && scaled_analog >= 2.5){
        m_distance = 10.0;
    }
    else if (scaled_analog < 2.5 && scaled_analog >= 2.2){
        m_distance = 11.2;
    }
    else if (scaled_analog < 2.2 && scaled_analog >= 1.9){
        m_distance = 12.0;
    }
    else if (scaled_analog < 1.9 && scaled_analog >= 1.5){
        m_distance = 14.9;
    }
    else if (scaled_analog < 1.5 && scaled_analog >= 1.1){
        m_distance = 20.2;
    }
    else if (scaled_analog < 1.1 && scaled_analog >= 0.9){
        m_distance = 26.6;
    }
    else if (scaled_analog < 0.9 && scaled_analog >= 0.8){
        m_distance = 33.2;
    }
    else if (scaled_analog < 0.8 && scaled_analog >= 0.7){
        m_distance = 37.9;
    }
    else if (scaled_analog < 0.7 && scaled_analog >= 0.6){
        m_distance = 46.2;
    }
    else if (scaled_analog < 0.6 && scaled_analog >= 0.5){
        m_distance = 55.6;
    }
    else if (scaled_analog < 0.5 && scaled_analog >= 0.40){
        m_distance = 69.9;
    }
    else{
        m_distance = MAX_DISTANCE;
    }
    
    return m_distance;
}