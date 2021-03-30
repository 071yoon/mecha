#ifndef MBED_PLOTTING_H
#define MBED_PLOTTING_H

#include "mbed.h"

class Plotting
{
private:
    float datas[32];
    int dataCount;
public:
    Plotting();
    
    void reset();
    void put(float data, int index);
    void put(int data, int index);
    void put(unsigned int data, int index);
    void send(Serial *port);
};

#endif
