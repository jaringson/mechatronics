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

void config_ONEStimer(void);  // Configures a timer that runs for 1 second
void config_ad(void);  // Sets up analog to digital conversion
void config_pins(void);  // Sets up pins
void config_stepperPWM(void);  // Sets up drive PWM
void drive(void);  //  Executes drive 
void feedball(void); // Feeds one ball 
void sense(void); // Reads sensors and returns desired turret position
void turret_turn(void);  // Rotates turret to desired position
void config_servoTimer(void); // Configures timer for Servo
void config_servoPWM(void);  // Configures PWM for servo
void config_gameTimer(void);  // Configures overall game timer

//Interrupt Routines
void StepperInterrupt(void);
void gametime_interrupt(void);

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

