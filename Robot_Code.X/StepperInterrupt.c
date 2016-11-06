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
            if(counterStepper>=three60){
                direction=Right;
                counterStepper=0;
            }
            break;
        case Right:
            if(counterStepper>=one80){
                direction=Forward;
                counterStepper=0;
            }
            break;
        case Stop:
            break;
        case Left:
            break;
        case Back:
            break;
    }
   
    return;
}
