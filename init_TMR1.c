/*
 * File:   init_TMR1.c
 * Author: philip
 *
 * Created on 30 March 2018, 19:26
 */
#include <xc.h>
#include"init_TMR1.h"
void init_TMR1(void) 
{
    TMR1H = 0x00;
    TMR1L = 0x00;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    T1CONbits.TMR1CS = 0;       // fosc/4 is the clock source
    T1CONbits.T1CKPS1 = 0;      // 11 = 1:8, 10 = 1:4, 01 = 1:2, 00 = 1:1
    T1CONbits.T1CKPS0 = 0;
    PIE1bits.TMR1IE = 1;
    T1CONbits.TMR1ON = 0;
    PIR1bits.TMR1IF = 0;
}
