/*
 * File:   config_ad.c
 * Author: Andrew
 * Configures AD - no scanning
 * Created on October 18, 2016, 5:14 PM
 */


#include "xc.h"

void config_ad(void){
    _ADON = 0;    // AD1CON1<15> -- Turn off A/D during config

    // AD1CON1 register
    _ADSIDL = 0;  // AD1CON1<13> -- A/D continues in idle mode
    _MODE12 = 1;  // AD1CON1<10> -- 12-bit A/D operation
    _FORM = 0;    // AD1CON1<9:8> -- Unsigned integer output
    _SSRC = 7;    // AD1CON1<7:4> -- Auto conversion (internal counter)
    _ASAM = 1;    // AD1CON1<2> -- Auto sampling

    // AD1CON2 register
    _PVCFG = 0;   // AD1CON2<15:14> -- Use VDD as positive
                  // ref voltage
    _NVCFG = 0;   // AD1CON2<13> -- Use VSS as negative
                  // ref voltage
    _BUFREGEN = 1;// AD1CON2<11> -- Result appears in buffer
                  // location corresponding to channel
    _CSCNA = 0;   // AD1CON2<10> -- Does not scan inputs
                  // specified in AD1CSSx registers (instead
                  // uses channels specified by CH0SA bits in
                  // AD1CHS register) -- Selecting '0' here
                  // probably makes writing to the AD1CSSL
                  // register unnecessary.
    _SMPI = 0;    // AD1CON2<6:2> -- Each conversion sent to 
                  // buffer
    _ALTS = 0;    // AD1CON2<0> -- Sample MUXA only

    // AD1CON3 register
    _ADRC = 0;    // AD1CON3<15> -- Use system clock
    _SAMC = 1;    // AD1CON3<12:8> -- Auto sample every A/D
                  // period TAD
    _ADCS = 0x3F; // AD1CON3<7:0> -- A/D period TAD = 64*TCY

    // AD1CHS register
    _CH0NA = 0;   // AD1CHS<7:5> -- Use VDD as negative input
    _CH0SA = 0b00011; // AD1CHS<4:0> -- Use ANx as positive input

    // AD1CSSL register
    AD1CSSL = 0;  // AD1CSSL<15:0> -- Skip all channels on 
                  // input scan -- see the CSCNA bits in
                  // AD1CON2

    _ADON = 1;    // AD1CON1<15> -- Turn on A/D
    return;
}