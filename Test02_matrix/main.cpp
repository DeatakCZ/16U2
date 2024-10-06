#define F_CPU 8000000UL

#include <stdio.h>
#include <stdlib.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
//#include <avr/cpufunc.h>

#include "../IC_Library/IC_4094.h"
#include "../IC_Library/IC_4051.h"
#include "../IC_Library/IC_2024.h"
#include "../IC_Library/Led.h"
#include "config.h"



//long counter = 0;


int main(void) 
{
 
    Led BlueLed(&DDRC, &PORTC, 5);
    Led RedLed(&DDRC, &PORTC, 4);
    
IC_2024 IC2024( &DDRB, &PORTB, 6, 5, 4, 7);

IC_4051 IC4051( &DDRD, &PORTD, 0, 1, 2, 3);
IC_4094 IC4094( &DDRD, &PORTD, 4, 5, 6, 7);

BlueLed.on();
IC2024.Init();
IC4051.Init();
IC4094.Init();

_delay_ms(500);

IC2024.Test();
IC4094.Write(0xAA);
BlueLed.off();
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
//    PORTD = 0x00;               //0 0 0 0 0 0 0 0 = 00
//    DDRD  = 0xC0;               //1 1 0 0 0 0 0 0 = C0
//    _delay_ms(500);
//    PORTD = 0xC0;
//    _delay_ms(500);
//    PORTD = 0x00;
//-------------------------------------------
//---SET-UP_MISC-----------------------------
/*
    uint16_t bTimer1 = 0;
    uint16_t bTimer2 = 0;
    uint16_t Timer = 0;
    //TCCR0B = ( 1<<CS00 | 1<<CS02);        //Start timer
    sei();                      //global interrupts enable        
*/
    uint16_t sequence1 = 0;
    uint8_t channel = 0;
    
    while(1)
    {
//        IC2024.Write(sequence1);
//        sequence1++;
        
//        RedLed.on();
//        IC2024.Write(0xFFFF);
//        _delay_ms(500);
//        
//        RedLed.off();
//        IC2024.Write(0x0000);
//        BlueLed.on();
//        
//        _delay_ms(500);
//        
//        BlueLed.off();
//        IC2024.TurnOff();
//        _delay_ms(500);
        
        IC4051.Select(channel);
        if(channel <= 7)
            channel++;
        else
            channel = 0;
        
        IC2024.Write(sequence1);
        if(sequence1 != 0xFFFF)
            sequence1++;
        else
            sequence1 = 0;
        _delay_ms(500);
        
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