
#define F_CPU 8000000
//#define __AVR_ATmega16U2__

#include "config.h"
#include "../IC_Library/Led.h"
#include "../IC_Library/IC_4021.h"
#include "../IC_Library/IC_4022.h"
#include "../IC_Library/IC_4056.h"


#include <util/delay.h>



int main()
{
//---SET-UP_I/O---------------------------------------
//---PORTD--Pin6=PD0,Pin7=PD1,...Pin13=PD7------------
                                //7 6 5 4 3 2 1 0
                                //0 0 1 1 1 1 1 1 = 3F
    //PORTD = 0x00;               //0 0 0 0 0 0 0 0 = 00
    //DDRD  = 0xC0;               //1 1 0 0 0 0 0 0 = C0
    
    /*
     R -Reset
     C - Com ISP6 header
     1 - 4021 - Reader
     2 - 4022 - Counter
     6 - 4056 - 7Seg driver
     L - Leds 
     
    
     
     PORTB - 7 6 5 4 3 2 1 0
             _ 1 1 1 C C C _
     
     
     PORTC - 7 6 5 4   2 1 0
             6 6 6 6   _ R _
     
     
     PORTD - 7 6 5 4 3 2 1 0
             L L L 2 2 _ _ _
     */
    
    
    Led Heartbeat(&PORTD, &DDRD, 5);
    Led Flare(&PORTD, &DDRD, 6);
    //Led YellowLed(&PORTD, &DDRD, 5);
    
    //(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t* PIN, uint8_t Clock, uint8_t Latch, uint8_t DataOut)
    IC_4021 IC4021( &DDRD, &PORTD, &PIND, 0, 1, 2 );
    //(volatile uint8_t* DDR, volatile uint8_t* PORT, uint8_t Clock, uint8_t Reset)
    IC_4022 IC4022( &DDRD, &PORTD, 3, 4 );
    //(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4)
    IC_4056 IC4056( &DDRC, &PORTC, 4, 5, 6, 7 );
    
    
    _delay_ms(1000);
    
    /*
    for( uint8_t i=0; i<10 ; i++ )
    {
        Led1.toggle();
        if(Led1.getState())
        {
            Led2.toggle();
            _delay_ms(200);
        }
        _delay_ms(200);
    }
    */
            
            
    Heartbeat.on();
    Flare.on();
    _delay_ms(2000);
    
    Heartbeat.off();
    Flare.off();
    
    _delay_ms(2000);
    
    
    IC4021.Init();
    IC4022.Init();
    IC4056.Init();
    
    uint8_t ReadOut = 0x00;
    uint8_t DisplayChar = 0;
    
    //ReadOut = 0b11110000;
    while(1)
    {
        for( uint8_t o = 0 ; o < 4 ; o++ )
        {
            ReadOut = IC4021.Read();
            IC4056.Display(IC4022.getState());
            for( uint8_t i = 0 ; i < 8 ; i++ )
            {
                /*

                */ 

                if((ReadOut >> i) & 1 )
                {
                    Heartbeat.on();
                    _delay_ms(100);
                    Heartbeat.off();
                    _delay_ms(100);
                }else
                {
                    Flare.on();
                    _delay_ms(100);
                    Flare.off();
                    _delay_ms(100);
                }   
            }
            IC4022.Increment();
            _delay_ms(200);
        }
      
        Flare.on();
        Heartbeat.on();
        
        IC4022.Reset();
        IC4056.Display(DisplayChar);
        if(DisplayChar < 15)
            DisplayChar++;
        else
            DisplayChar = 0;
        _delay_ms(500);
        
        
        Flare.off();
        Heartbeat.off();
        _delay_ms(200);
    }
    return 0;
}

