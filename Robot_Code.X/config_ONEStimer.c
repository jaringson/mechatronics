/*
 * File:   config_cTimer.c
 * Author: Andrew
 *
 * Created on November 3, 2016, 11:43 AM
 */


#include <xc.h>
#include "DEFINTIONS.h"

// One second timer, increment up to 120s

void config_ONEStimer(void) {
    T1CONbits.TON=1;
    T1CONbits.TCS=0;
    T1CONbits.TCKPS=0b11; //256 Prescaler
    PR1=15625; // Timer set to 1 second
    return;
}
