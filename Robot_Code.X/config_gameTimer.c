/*
 * File:   config_gameTimer.c
 * Author: danielbf
 *
 * Created on November 15, 2016, 8:32 AM
 */

#include "xc.h"
#include "DEFINTIONS.h"

// Game timer, counts 1 second

void config_gameTimer(void) {
    T3CONbits.TON=1;
    T3CONbits.TCS = 0;
    T3CONbits.TCKPS = 0b10; //1:64 prescale
    PR3 = 62500; //15625
    TMR3 = 0;
 
    _T3IE = 1;
    _T3IP = 3;
    return;
}