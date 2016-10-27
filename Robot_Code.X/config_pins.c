/*
 * File:   config_pins.c
 * Author: orme23
 * Configures pins for Analog/digital  Input/Output
 * Created on October 25, 2016, 12:20 PM
 */


#include "xc.h"

void config_pins(void) {
        ANSA=0x00;  //Set all analog off
        ANSB=0x0000; 
        TRISA=0x00;  //Sets all pins to output
        TRISB=0x0000;
    return;
}
