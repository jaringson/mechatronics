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
#pragma config ICS = PGx2


// Define global variables
extern enum dir direction=Stop;
extern int counterStepper=0;
extern enum states state = Stationary;
extern enum turret_dir tur_dir = Turret_Left;
int balls;
extern int gametime = 0;
//Interrupt service routines
void __attribute__((interrupt, no_auto_psv)) _OC1Interrupt(void){
    StepperInterrupt();
}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void){
    gametime_interrupt();
    //I made a separate function, but its so few lines of code should we just 
    //put it here?
}

int main(void) {
    config_pins();
    config_stepperPWM();
    counterStepper=0;
    config_ONEStimer();
    config_ad();
    config_servoTimer();
    config_servoPWM();
    config_gameTimer();
    direction=Forward;
    tur_dir = Turret_Left;
    gametime = 0;
    balls=0;
    state = Sensing;
    while(1){
        
//        tur_dir = Turret_Left;
        switch(state)
        {
            case Stationary:
                break;
                
            case Sensing:
                sense();
                break;
                
            case Shooting:
                break;
                
            case Turret_Turn:
                turret_turn();
                break;
                
            case Drive:
                drive();
                break;
                
            case Loading:
                break;
                
            case Turning:
                drive();
                break;
                
            default :
                state = Stationary;
                
        }
         //drive();
//        sense();
//        if (balls<=6)
//        {
//            PitchWheel=on;
////            if(balls==0){
////                ONES_Timer=0;
////              while(ONES_Timer<=one_second)
////   {
////   }  
////            }
//        feedball();
//        balls=balls+1;
//                    }
//        else{
//            PitchWheel=off;
//        }
    }
    return 0;
}
