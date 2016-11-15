/*
 * File:   sense.c
 * Author: danielbf
 * Senses which goal is active
 * Created on November 12, 2016
 */

#include "xc.h"
#include "DEFINTIONS.h"

void sense(void) {
 
    if(left_goal > 1242) {
        // Change turret turning state to turn left
        //left_on = 1;
        //Then in turning state, we check if right_on =1. if so, then we 
        //turn accordingly. If not and center_on = 0, then we stay
        //where we are and go to shooting state.
        state = Turning;
        tur_dir = Turret_Left;
        direction=Left;
    }
    else if(right_goal > 1242){
        //right_on = 1;
        state = Turning;
        tur_dir = Turret_Right;
        direction=Right;
    }
    else{
        //center_on = 1;
        state = Turret_Turn;
        tur_dir = Turret_Center;
       
    }
//      {
//        _LATA2 = 1;
//    }
//    
    return;
}