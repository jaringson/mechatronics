/*
 * File:   sense.c
 * Author: danielbf
 * Senses which goal is active
 * Created on November 12, 2016
 */

#include "xc.h"
#include "DEFINTIONS.h"

void sense(void) {  // add 15 second check??
    if(left_goal > ACTIVE) {
        tur_dir = Turret_Left;
        state = Turret_Turn;
    }
    else if(right_goal > ACTIVE){
        tur_dir = Turret_Right;
        state = Turret_Turn;
    }
    else{
        tur_dir = Turret_Center;
        state = Turret_Turn;
    }  
    return;
}