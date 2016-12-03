/*
 * File:   MAIN.c
 * Author: Andrew
 * MAIN Robot File
 * Created on October 18, 2016, 5:08 PM
 */


#include "xc.h"
#include "DEFINTIONS.h"
#include "FUNCTIONS.h"
#pragma config OSCIOFNC = OFF // Enables Pin 8
#pragma config SOSCSRC = DIG // Enables Pin 9 10
#pragma config FNOSC=FRC // 8MHz Oscillator
#pragma config ICS = PGx2


// Define global variables
extern enum dir direction=Stop;
extern int counterStepper=0;
extern enum states state = Stationary;
extern enum turret_dir tur_dir = Turret_Left;
int balls;
extern int gametime = 0;
extern enum turret_dir tur_prev= Turret_Center;

//Interrupt service routines
void __attribute__((interrupt, no_auto_psv)) _OC3Interrupt(void){
    StepperInterrupt();
}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void){
    gametime_interrupt();
    //I made a separate function, but its so few lines of code should we just 
    //put it here?
}

int main(void) {
    config_pins(); // Update when PCB is done //
    config_stepperPWM();  // Driving PWM
    counterStepper=0;  // Resets Distance for Steppers
    config_ONEStimer();  // Generic One Second Timer
    config_ad();  // IR analog to digital conversion
    config_servoTimer(); // PWM Source for servo
    config_servoPWM();  // PWM for Servo
    config_gameTimer();  // Global Game Timer
    
    // Initial Conditions
    direction=RightC;
    gametime = 0;
    balls=0;
    //state = Test;
    state=Turning_Right;
    while(1){
        switch(state)
        {
            case Stationary:  // End of Game State, All actions disabled
                direction=Stop;
                drive();
                PitchWheel=off;
                tur_dir=Turret_Center;
                turret_turn();
                break;
                
            case Turning_Right:  // Sensing for garage off of front IR sensor.  When found, turn 180 Degrees more and enter driving back slowly
                direction=RightC;
                drive();
                break;
                
            case Drive:  // If backward, PWM is slow, continue until both touch sensors active
                         // If forward, PWM is fast, drive to center (set distance)
                drive();
                break;
                
            case Sensing:  // Detects active goals, reading from IR Sensors
                if(balls==0){
                    PitchWheel=on;
                }
                sense();
                break;
                
            case Shooting:  // Shoots one Ping Pong ball and returns to sensing, sends to garage if 6 balls have been shot
                if (balls<6){
                    feedball();
                    balls=balls+1;
                    state=Sensing;
                }
                if(balls>=6){
                    PitchWheel=off;
//                    balls=0;
                    
                    if(tur_dir==Turret_Center){
                        balls=0;
                        state=Drive;
                        direction=Back;
                    }
                    else{
                        state=Turret_Turn;
                        tur_dir = Turret_Center;
                    }
                    
//                    if(tur_prev==Turret_Left){
//                        direction=Right;
//                        tur_prev= Turret_Center;
//                        drive();
//                    }
//                    if(tur_prev==Turret_Right){
//                        direction=Left;
//                        tur_prev= Turret_Center;
//                        drive();
//                    }
//                    if(tur_prev==Turret_Center){
//                        state=Drive;
//                        direction=Back;
//                    }
                }
                break;
                
            case Turret_Turn:  // Rotates the turret towards the active goal (both driving and servo)
                if(tur_prev==tur_dir){
                    direction=Stop;
                    drive(); //To Stop the motors
                    state=Shooting;
                }
                else{
                    
                    if(tur_prev==Turret_Right) {
                        if(tur_dir==Turret_Left){
                            direction=Left;
                            turret_turn();
                            drive();
                        }
                        if(tur_dir==Turret_Center){
                            direction=Left; 
                            turret_turn();
                            drive();
                        }
                    }
                    if(tur_prev==Turret_Left){
                        if(tur_dir==Turret_Right){
                            direction=Right;
                            turret_turn();
                            drive();
                        }
                        if(tur_dir==Turret_Center){
                            direction=Right;
                            turret_turn();
                            drive();                            
                        }
                    }
                    if(tur_prev==Turret_Center){
                        if(tur_dir==Turret_Left){
                            direction=Left;
                            turret_turn();
                            drive();
                        }
                        if(tur_dir==Turret_Right){
                            direction=Right;
                            turret_turn();
                            drive();
                        }
                    }
                    
                    
                   
                }
                break;
                     
            case Test:  // Not needed?
                BallFeed=release;
                break;
                
            case Turning: //Not Needed?
                break;
                
            default :
                state = Stationary;
                
        }
    }
    return 0;
}
