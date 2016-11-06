/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// Header Name  
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "DEFINTIONS.h"
// ALL function prototypes should go here

void config_ONEStimer(void);
void config_ad(void);
void config_pins(void);
void config_stepperPWM(void);
void drive(void);
void feedball(void);


//Interrupt Routines
void StepperInterrupt(void);


//DONT Mess with the rest of this stuff
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

