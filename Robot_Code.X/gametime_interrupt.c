/*
 * File:   gametime_interrupt.c
 * Author: danielbf
 *
 * Created on November 15, 2016, 9:18 AM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void gametime_interrupt(void) {
    _T3IF = 0;
    gametime++;
    if (gametime >= 115) {
        state = Stationary;
    }
            
}