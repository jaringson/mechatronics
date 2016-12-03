/*
 * File:   StepperInterrupt.c
 * Author: orme23
 *
 * Created on October 25, 2016, 12:41 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void StepperInterrupt(void){
    
      _OC3IF=0; // clear interrupt
    counterStepper=counterStepper+1;
    switch(direction){
        case Forward:
            if(counterStepper<250){
                OC3RS=slow;
            }
            else{
                OC3RS=9999; 
   
            if(counterStepper>=center){
                //direction=Right;
                direction=Stop;
                counterStepper=0;
                state = Sensing;
            }
            }
            break;
        case Right:
            if(counterStepper>=ten){
                if(tur_prev==Turret_Left){
                    tur_prev=Turret_Center;
                }
                else if(tur_prev==Turret_Center){
                    tur_prev=Turret_Right;
                }

                direction=Stop;
                counterStepper=0;
                if(PitchWheel==on){
                state=Sensing;
                }
            }
            break;
        case Stop:
            counterStepper=0;
            break;
        case Left:
            if(counterStepper>=ten){
                if(tur_prev==Turret_Right){
                    tur_prev=Turret_Center;
                }
                else if(tur_prev==Turret_Center){
                    tur_prev=Turret_Left;
                }
                direction=Stop;
                counterStepper=0;
                if(PitchWheel==on){
                state=Sensing;
                }
            }
            break;
        case RightC:
            if(center_goal>=ACTIVE){
                tur_dir=Turret_Center;
                counterStepper=0;
            }
            if(tur_dir==Turret_Center){
                if(counterStepper>=1200){
                    direction=Back;
                    counterStepper=0;
                    state=Drive;
                }
            }
            break;
        case Back:
            if(counterStepper<=2000){
                OC3RS=fast;  // Slow to catch balls?
            }
            else{
                OC3RS=slow;
                if(LeftBump==on&&RightBump==on){
                    direction=Forward;
                    counterStepper=0;
                    state=Drive;
            }
            }
            break;
    }
   
    return;
}
