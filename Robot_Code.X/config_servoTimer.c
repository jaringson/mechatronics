/*
 * File:   config_servoTimer.c
 * Author: Daniel
 *
 * Created on November 3, 2016, 11:43 AM
 */


#include <xc.h>
#include "DEFINTIONS.h"

// Timer for servo pwm

void config_servoTimer(void) {
    T2CONbits.TON=1;
    T2CONbits.T32 = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TCKPS = 0b10; //1:64 prescale
    TMR2 = 0;
 
    return;
}

