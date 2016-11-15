/*
 * File:   drive.c
 * Author: orme23
 * Drives the robot
 * Created on October 25, 2016, 12:50 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void drive(void) {
    switch(direction){
        case Forward:
            OC1R=10000/2;  // slow to catch balls
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=cw;
            break;
        case Back:
            OC1R=10000/2;  // Slow to catch balls
            Stepper_DirectionL=cw;
            Stepper_DirectionR=ccw;
            break;
        case Left:
            OC1R=10000/2;
            Stepper_DirectionL=cw;
            Stepper_DirectionR=cw;
            break;
        case Right:
            OC1R=10000/2;
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=ccw;
            break;
        case Stop:
            OC1R=0;
            break;
        case RightC:
            OC1R=10000/2;
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=ccw;
            break;
    }
    return;
}
