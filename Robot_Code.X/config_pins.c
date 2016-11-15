/*
 * File:   config_pins.c
 * Author: orme23
 * Configures pins for Analog/digital  Input/Output
 * Created on October 25, 2016, 12:20 PM
 */


#include "xc.h"

void config_pins(void) {
        ANSA=0x00;  //Set all analog off
        ANSB=0xE000; //Sets pins 16,17,18 to analog, rest to digital
        TRISA=0x00;  //Sets all pins to output
        TRISB=0xE000; //Sets pins 16,17,18 to input
    return;
}
