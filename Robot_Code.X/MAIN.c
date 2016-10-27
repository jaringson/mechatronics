/*
 * File:   MAIN.c
 * Author: Andrew
 * MAIN Robot File
 * Created on October 18, 2016, 5:08 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"
#include "FUNCTIONS.h"
#pragma config FNOSC=FRC // 8MHz Oscillator

// Define global variables
extern enum dir direction=Stop;
extern int counter=0;

//Interrupt service routines
void __attribute__((interrupt, no_auto_psv)) _OC1Interrupt(void){
    StepperInterrupt();
}

int main(void) {
    config_pins();
    config_stepperPWM();
    counter=0;
    direction=Forward;
    
    while(1){
        drive();
    }
    return 0;
}
