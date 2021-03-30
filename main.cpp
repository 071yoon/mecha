#include "mbed.h"
#include "DistanceSensor.h"
#include "Plotting.h"
#include "Motor.h"
#include "LaneSensor.h"
#include "Servo.h"

//To plot with usb, set as below.
Serial pc(USBTX,USBRX); // Tx, Rx Pin
Plotting plot;
Servo servo (p10);
//Set each gpio to see the output of the hall sensor as a led
LaneSensor laneSensor(p11,p12,p13,p14,p15,p16,p17);
//Set each gpio to see the output of the psd sensor as a led
DigitalOut myled1(LED1);
DistanceSensor pir (p20);
Motor motor (p23, p24, p25, p26);

//Interrupt is generated every 1ms and degree is increased by 1
unsigned int uiFlag_50ms = 0;
unsigned int uiFlag_1ms = 0;

float prev = 0;
void counter_1ms ()
{
    uiFlag_1ms++;
    uiFlag_50ms++;
}

float speed_percent;
float myabs(float a)
{
    if(a<0.0) {
        a*=-1.0;
    }
    return a;
}


// Plot distance sensor
int main()
{   
    //servo.h teraterm max,mid값 조절
    servo.update (0.0);

    
    wait(1);

    //Set the 1ms thicker.
    Ticker ticker_1ms;
    ticker_1ms.attach(&counter_1ms,0.001);

    Timer time;
    time.start();
    

    while(1) {

        // Every 1 ms,
        if(uiFlag_1ms>=1) {
            uiFlag_1ms=0;
            float error = laneSensor.getError();        
            // error + : left , error - : right
            
            float angle = error/0.38;
            servo.update(angle);

            if(pir.getDistance_cm() <= 30 && pir.getDistance_cm() >= 0){
                speed_percent = 10.0;
                motor.setSpeed_percent(speed_percent, BRAKE);
                }

            else{
                if(angle >= 35 || angle <= -35){
                    speed_percent = 17.0 ;
                }
                else if((angle >= 25 && angle <= 35) || (angle >= -35 && angle <= -25)){
                    speed_percent = 16.0;
                }
                else{
                speed_percent=22.0;
                }
                motor.setSpeed_percent(speed_percent,BACKWARD);
                }
            
        }
        // Every 50 ms,
        if(uiFlag_50ms>=50) {
            uiFlag_50ms=0;
            
            // clear plotting buffer
            plot.reset();
            
            // put data to buffer
            plot.put(pir.getDistance_cm(),0);
            
            // send buffer
            plot.send(&pc);
        }
    }
}