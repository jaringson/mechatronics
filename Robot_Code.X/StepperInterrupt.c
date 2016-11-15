/*
 * File:   StepperInterrupt.c
 * Author: orme23
 *
 * Created on October 25, 2016, 12:41 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void StepperInterrupt(void){
    
      _OC1IF=0; // clear interrupt
    counterStepper=counterStepper+1;
    switch(direction){
        case Forward:
            if(counterStepper>=center){
                //direction=Right;
                direction=Stop;
                counterStepper=0;
                state = Sensing;
            }
            break;
        case Right:
            if(counterStepper>=ten){
                direction=Stop;
                counterStepper=0;
                state=Turret_Turn;
            }
            break;
        case Stop:
            break;
        case Left:
            if(counterStepper>=ten){
                direction=Stop;
                counterStepper=0;
                state=Turret_Turn;
            }
            break;
            break;
        case Back:
            break;
    }
   
    return;
}
