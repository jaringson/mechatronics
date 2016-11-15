/*
 * File:   turret_turn.c
 * Author: orme23
 * Drives the robot
 * Created on October 25, 2016, 12:50 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void turret_turn(){
    if(tur_dir == Turret_Left){
        OC3R = 150; //found 150
    }
    if(tur_dir == Turret_Right){
        OC3R = 35; //found 35
    }
    if(tur_dir == Turret_Center){
        OC3R = 185/2; //found 185/2
    }
    state=Sensing;
}
