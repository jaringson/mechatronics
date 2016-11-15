/*
 * File:   config_servoPWM.c
 * Author: orme23
 * Configures PWM for the Stepper Motors
 * Created on October 25, 2016, 12:30 PM
 */


#include "xc.h"

void config_servoPWM(void){
        
    // Configure PWM
    OC3R=0;
    OC3RS=1249; //Period for PWM frequency of 1000Hz
    OC3CON1bits.OCTSEL= 0b000; // Selects timer 2
    OC3CON1bits.OCM= 0b110; // Selects Edge aligned // STAYS
    OC3CON2bits.SYNCSEL=0x1F; // Selects current OC3 as the sync source  //STAYS
    OC3CON2bits.OCTRIG=0; // Trigger set up  //STAYS
    return;
}

