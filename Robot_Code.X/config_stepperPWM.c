/*
 * File:   config_stepperPWM.c
 * Author: orme23
 * Configures PWM for the Stepper Motors
 * Created on October 25, 2016, 12:30 PM
 */


#include "xc.h"

void config_stepperPWM(void){
    // Output Compare Interrupt     
        _OC1IP = 4;          // Select Output Compare 1 interrupt priority pin 14
        _OC1IE = 1;          // Enable OC1 interrupt (1=enabled)
        _OC1IF = 0;         // Set Flag to 0
        
    // Configure PWM
        OC1R=0; // Duty Cycle of 50%
        OC1RS=9999 ; //Period for PWM frequency of 240Hz
        OC1CON1bits.OCTSEL= 0b111; // Selects system clock
        OC1CON1bits.OCM= 0b110; // Selects Edge aligned // STAYS
        OC1CON2bits.SYNCSEL=0x1F; // Selects current OC1 as the sync source  //STAYS
        OC1CON2bits.OCTRIG=0; // Trigger set up  //STAYS
    return;
}
