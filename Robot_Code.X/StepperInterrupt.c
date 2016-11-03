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
    counter=counter+1;
    switch(direction){
        case Forward:
            if(counter>=three60){
                direction=Right;
                counter=0;
            }
            break;
        case Right:
            if(counter>=one80){
                direction=Forward;
                counter=0;
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
