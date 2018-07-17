/*
 * File:   interrupt isr.c
 * Author: philip
 *
 * Created on 30 March 2018, 20:08
 */
#include <xc.h>
#include "config.h"
#include <stdio.h>
#include "debounce.h"
#include "fsm.h"
#include "bar_graph.h"
#include "update_PGA2311.h"
#include "interrupt isr.h"


void interrupt isr(void) 
{
    if(PIR1bits.TMR1IF == 1)
    {
        TMR1H = 0x00;                       // 85ms interrupt
        TMR1L = 0x00;
        time_out++;                         // at least 85ms has expired
        //printf(" time_out = %d\n", time_out);
        //DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;    //diagnostic led  pin 13 GREEN LED
    }
    PIR1bits.TMR1IF = 0;
    /************************************************************************/
  
    if(INTCONbits.TMR0IF == 1)
    { 
        fsm(kurrent_state); // FSM for rotary encoder detecting de-bounced CW and ACW rotations to provide volume control functionality
        
        if(CW_Flag)       // clockwise movement of the knob
        { 
            count++;
            up_down = HI;
            CW_Flag == LO;   
        }
        else if (ACW_Flag) // anti-clockwise movement of the knob
        {
            count--;
            up_down = LO;
            ACW_Flag == LO;     
        }
        TMR0 = 0xE0;
        INTCONbits.TMR0IF = 0;
    } 
}