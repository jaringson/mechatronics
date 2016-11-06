/*
 * File:   feedball.c
 * Author: Andrew
 *
 * Created on November 3, 2016, 11:40 AM
 */


#include "xc.h"
#include "DEFINTIONS.h"

void feedball(void) {
   ONES_Timer=0;
   BallFeed=release;
   while(ONES_Timer<=eigth_second)
   {
   }
   ONES_Timer=0;
   BallFeed=lock;
   while(ONES_Timer<=one_second)
   {
   }
   return;
}
