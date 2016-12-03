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

//For Ball Release
#define release 1
#define lock 0

//Pin Shortcuts
#define Stepper_DirectionL _LATB2 //Dir 2
#define Stepper_DirectionR _LATA2 //Dir 1
#define BallFeed _LATB4
#define PitchWheel _LATA3
#define LeftBump _RB12  // Touch 1
#define RightBump _RA6 // Touch 2

// Timer one values
#define ONES_Timer TMR1
#define one_second 15600
#define half_second 7812
#define fourth_second 3906
#define eigth_second 1953

// Drive Directions
#define ccw 1 //SET
#define cw 0 //SET

//Drive Distances
#define ten 50*4 
#define ninety 100*4 //steps per degrees
#define one80 160*4
#define three60 260*4
#define center 2.3*three60
#define slow 32000
#define fast 8000

// Analog Pins
#define left_goal ADC1BUF11 //photodiode 3
#define center_goal ADC1BUF10 //photodiode 2
#define right_goal ADC1BUF9 //photodiode 1
#define ACTIVE 1242

//State Definitions
enum states {Stationary, Sensing, Shooting, Turret_Turn, Drive, Test, Turning, Turning_Right};
extern enum states state;

// DEFINE (Do not initialize) global variables
extern int counterStepper; // To measure distance of steppers
extern int gametime; // Measures overall game time
enum dir {Forward, Back, Left, Right, Stop, RightC}; //Drive Directions
extern enum dir direction;

enum turret_dir {Turret_Center, Turret_Left, Turret_Right}; //Turret Directions
extern enum turret_dir tur_dir; // Desired Turret Position
extern enum turret_dir tur_prev; // Previous/actual Turret Position

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

