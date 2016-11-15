/*
 * File:   sense.c
 * Author: danielbf
 * Senses which goal is active
 * Created on November 12, 2016
 */

#include "xc.h"
#include "DEFINTIONS.h"

void sense(void) {
    if(left_goal > ACTIVE) {
        state = Turret_Turn;
        tur_dir = Turret_Left;
        direction=Left;
    }
    else if(right_goal > ACTIVE){
        state = Turret_Turn;
        tur_dir = Turret_Right;
        direction=Right;
    }
    else{
        state = Turret_Turn;
        tur_dir = Turret_Center;
        if(tur_prev==Turret_Right){
            direction=Left;
        }
        else{
            direction=Right;
        }
    }  
    return;
}