/* 
 * File:   main.c
 * Author: PanTalir
 *
 * Created on 02 July 2024, 17:18
 */
#define F_CPU 8000000UL

#include <stdio.h>
#include <stdlib.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
//#include <avr/cpufunc.h>

#include "config.h"



long counter = 0;


int main(void) 
{

    
//---SET-UP TIMER----------------------------
/*    
    TCCR0A = ( 0<<COM0A1 | 0<<COM0A0 | 0<<COM0B1 | 0<<COM0B0 | 1<<WGM01 | 0<<WGM00 );
    TCCR0B = ( 0<<WGM02  | 0<<CS02   | 0<<CS01   | 1<<CS00   );
    OCR0A =  ( 0xC7 );      //  199
    
    TIMSK0 = ( 1<<OCIE0A );
*/ 
//-------------------------------------------
//---SET-UP_I/O------------------------------
//---PORTD--Pin6=PD0,Pin7=PD1,...Pin13=PD7---
                                //7 6 5 4 3 2 1 0
    PORTD = 0x00;               //0 0 0 0 0 0 0 0 = 00
    DDRD  = 0xC0;               //1 1 0 0 0 0 0 0 = C0
    _delay_ms(500);
    PORTD = 0xC0;
    _delay_ms(500);
    PORTD = 0x00;
//-------------------------------------------
//---SET-UP_MISC-----------------------------
/*
    uint16_t bTimer1 = 0;
    uint16_t bTimer2 = 0;
    uint16_t Timer = 0;
    //TCCR0B = ( 1<<CS00 | 1<<CS02);        //Start timer
    sei();                      //global interrupts enable        
*/
    
    while(1)
    {
        
    }
    return 0;
}
        /*
        if(counter >= 1000)                     //20Hz
        {
            Timer++;
            counter = 0;
        }
        
        //Yellow
        if((Timer>=40) && (bTimer1 == 1))       //0.5Hz
        {
            PORTB = PORTB | 0x40;
            Timer = 0;
            bTimer1 = 0;
        }
        
        else if((Timer>=40) && (bTimer1 == 0))
        {
            PORTB = PORTB & 0xBF;
            Timer = 0;
            bTimer1 = 1;
        }
        
        
        
        //Red
        if(((Timer%20)==0 ) && (bTimer2 == 1))   //1Hz
        {
            PORTB = PORTB | 0x10;
            bTimer2 = 0;

        }
        
        else if(((Timer%20)==0 ) && (bTimer2 == 0))
        {
            PORTB = PORTB & 0xEF;
            bTimer2 = 1;

        }
       
    }
    return 0;
}


ISR(TIMER0_COMPA_vect)                          //F = 20.000Hz = 20.000/s
{  
    counter++;
}
         */