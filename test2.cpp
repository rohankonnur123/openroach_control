#include "mbed.h"
#include <string>
#define SPEED_PWM 0.25

AnalogIn north(p16);
AnalogIn east(p19);
AnalogIn south(p18);
AnalogIn west(p17);
// Motors -- As labelled on the Zumy mbed board
PwmOut m1_fwd(p21);
PwmOut m1_back(p22);

PwmOut m2_fwd(p23);
PwmOut m2_back(p24);

Serial pc(USBTX, USBRX);

int readBeacon() {
    
    if(east.read() < 0.5f) {
        return 2;
        }
    if(west.read() < 0.5f){
        return 3;
        }
    if(south.read() < 0.5f){
        return 0;
        }
    if(north.read() < 0.5f){
        return 1;
        }
}

int main() {
    //en able = 1;
    int prev_dir = 1;
    int direction;
    while(1) {
        direction = readBeacon();
        if(direction == 1) { 
            direction = prev_dir;
        }
        if (direction == 0) {
            m2_fwd.write(SPEED_PWM);
            m2_back.write(0);
            m1_fwd.write(SPEED_PWM);
            m1_back.write(0);
        } else if(direction == 2) {
            m2_fwd.write(0);
            m2_back.write(0);
            m1_fwd.write(SPEED_PWM);
            m1_back.write(0);
        } else if(direction == 3) {
            m2_fwd.write(SPEED_PWM);
            m2_back.write(0);
            m1_fwd.write(0);
            m1_back.write(0);
        }
        prev_dir = direction;
        //wait(0.2);
    }
}

