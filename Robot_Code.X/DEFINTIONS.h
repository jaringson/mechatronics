/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

//Header name definitions  
#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "FUNCTIONS.h"

// ALL Definitions should go here
#define on 1
#define off 0
#define Stepper_DirectionL _LATB8
#define Stepper_DirectionR _LATB9
#define Stepper_Step _RA6
#define ccw 1 //May Change
#define cw 0 //May Change
#define ninety 100*4 //steps per degrees
#define one80 160*4
#define three60 260*4

// DEFINE (Do not initialize) global variables
extern int counter;
enum dir {Forward, Back, Left, Right, Stop};
extern enum dir direction;

// DONT Mess with the rest of this stuff
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

