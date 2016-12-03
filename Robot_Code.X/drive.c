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
            OC3R=10000/2;
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=cw;
            break;
        case Back:
            OC3R=10000/2;  // Slow to catch balls?
            Stepper_DirectionL=cw;
            Stepper_DirectionR=ccw;
            break;
        case Left:
            OC3R=10000/2;
            OC3RS=9999;
            Stepper_DirectionL=cw;
            Stepper_DirectionR=cw;
            break;
        case Right:
            OC3R=10000/2;
            OC3RS=9999;
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=ccw;
            break;
        case Stop:
            OC3R=0;
            OC3RS=fast;
            break;
        case RightC:
            OC3R=10000/2;
            Stepper_DirectionL=ccw;
            Stepper_DirectionR=ccw;
            break;
    }
    return;
}
