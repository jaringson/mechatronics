/*
 * File:   MAIN.c
 * Author: Andrew
 * MAIN Robot File
 * Created on October 18, 2016, 5:08 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"
#include "FUNCTIONS.h"
#pragma config OSCIOFNC = OFF // Enables Pin 8
#pragma config SOSCSRC = DIG // Enables Pin 9 10
#pragma config FNOSC=FRC // 8MHz Oscillator

// Define global variables
extern enum dir direction=Stop;
extern int counterStepper=0;
int balls;
//Interrupt service routines
void __attribute__((interrupt, no_auto_psv)) _OC1Interrupt(void){
    StepperInterrupt();
}

int main(void) {
    config_pins();
    config_stepperPWM();
    counterStepper=0;
    config_ONEStimer();
    direction=Forward;
    balls=0;
    while(1){
        // drive();
        if (balls<=6)
        {
            PitchWheel=on;
//            if(balls==0){
//                ONES_Timer=0;
//              while(ONES_Timer<=one_second)
//   {
//   }  
//            }
        feedball();
        balls=balls+1;
                    }
        else{
            PitchWheel=off;
        }
    }
    return 0;
}
