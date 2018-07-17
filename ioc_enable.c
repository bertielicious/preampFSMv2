/*
 * File:   ioc_enable.c
 * Author: philip
 *
 * Created on 16 April 2018, 19:43
 */


#include <xc.h>

void ioc_enable(void) 
{
    INTCONbits.GIE = 1;         // enable global interrupts
    UCONbits.USBEN = 0;         // disable USB module     
    INTCONbits.IOCIE = 1;       // set interrupt on change to be enabled
    IOCANbits.IOCAN1 = 1;       // enable negative falling edge trigger on external interrupt on PORTAbits.RA1 pin 18
    IOCAFbits.IOCAF1 = 0;       // interrupt flag for RA1 interrupt on change
    INTCONbits.IOCIF = 0;       // clear IOC interrupt flag to allow any future interrupts
    
}
