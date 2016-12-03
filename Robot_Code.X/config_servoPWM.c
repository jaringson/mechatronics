/*
 * File:   config_servoPWM.c
 * Author: orme23
 * Configures PWM for the Stepper Motors
 * Created on October 25, 2016, 12:30 PM
 */


#include "xc.h"

void config_servoPWM(void){
        
    // Configure PWM
    OC2R=185/2;
    OC2RS=1249; //Period for PWM frequency of 1000Hz
    OC2CON1bits.OCTSEL= 0b000; // Selects timer 2
    OC2CON1bits.OCM= 0b110; // Selects Edge aligned // STAYS
    OC2CON2bits.SYNCSEL=0x1F; // Selects current OC3 as the sync source  //STAYS
    OC2CON2bits.OCTRIG=0; // Trigger set up  //STAYS
    return;
}

