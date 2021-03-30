#include "Plotting.h"

Plotting::Plotting()
{
    for(int i=0; i<32; i++) {
        datas[i]=0;
    }
    dataCount=0;
}

void Plotting::reset()
{
    for(int i=0; i<32; i++) {
        datas[i]=0;
    }
    dataCount=0;
}

void Plotting::put(float data, int index)
{
    datas[index]=data;
    dataCount++;
}

void Plotting::put(int data, int index)
{
    datas[index]=(float)data;
    dataCount++;
}

void Plotting::put(unsigned int data, int index)
{
    datas[index]=(float)data;
    dataCount++;
}

void Plotting::send(Serial *port)
{
    port->putc(0xAA);
    port->putc(0xBB);
    port->putc(0xCC);
    port->putc((char)(dataCount*4));
    for(int i=0; i<dataCount; i++) {
        char *bytePtr = (char *)&(datas[i]);
        port->putc(*bytePtr);      // reverse the order of these lines if you have endian issues
        port->putc(*(bytePtr+1));
        port->putc(*(bytePtr+2));
        port->putc(*(bytePtr+3));
    }
}
