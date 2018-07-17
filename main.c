/*
 * File:   main.c
 * Author: Phil
 *
 * Created on 04 May 2018, 21:28
 */


#include <xc.h>
#include "config.h"
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "init_ports.h"
#include "config_osc.h"
#include "write_command.h"
#include "config_oled.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "clear_oled.h"
#include "putch.h"
#include "set_usart.h"
#include "ioc_enable.h"
#include "init_TMR1.h"
#include "init_TMR0.h"
#include "get_digit.h"
#include "write_character.h"
#include "splash_screen.h"
#include "setup_vol_scrn.h"
#include "bar_graph.h"
#include "split_digits.h"
#include "update_PGA2311.h"
#include "state_of_machine.h"
#include "fsm.h"
#include "vol.h"

void main(void) 
{
    count = 0;          // clear count so volume is at minimum at reset/ power on
    init_ports();       // set port directions and SPI setup
    config_osc();       // set osccon bits to generate a 4MHz internal clock
    set_usart();        // setup USART for serial comms with the PC terminal
    init_TMR0();
    init_TMR1();
    config_oled();      // oled now talking to PIC, but with garbage pixels illuminated on oled
    clear_oled();
    splash_screen();
    __delay_ms(1000);
    clear_oled();
    setup_vol_scrn();
    printf ("\n");
    printf (" Hello world!\n");
    //int current_state = VOL;
    
    count = 1;          // initial volume set to -94dB
    while(1)
    {   
       
        state_of_machine(&current_state);   // FSM for Preamp functions of VOL, MUTE, INPUT, IP_SELECT 
       
        
       if(count != count)                   // terminal display of volume for debugging
        {
            printf("count = %d\n", count);
            //printf ("vol = %d\n", count - 95);
        }
    }   
}    

