
#define F_CPU 8000000
//#define __AVR_ATmega16U2__

#include "config.h"
#include "../IC_Library/IC_4056.h"
#include "../IC_Library/IC_2024.h"
#include "../IC_Library/Led.h"
#include "../IC_Library/Switch.h"

#include <util/delay.h>

/*    
    Empty   _
    Reset   R   1x          Reset
    ISP_Com C   3x          MOSI, MISO, SCK 
    4056 A  6+A 5+ => 6x    10
    4056 B  6+B +1 => 6x    01
    2024    4   4x          LEDBar
    DHT111  D   1x          Sensor
    LED     L   1x          LED
    Switch  S   1x          Switch
     
     PORTB - 7 6 5 4 3 2 1 0
             4 4 4 4 C C C D
     
     
     PORTC - 7 6 5 4   2 1 0
             L L S _   _ R _
     
     
     PORTD - 7 6 5 4 3 2 1 0
             6 6 6 6 A B _ _
     */

int main()
{
//IC_4056( volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4, volatile uint8_t _Latch);
//IC_2024( volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t DataIn, volatile uint8_t Clock, volatile uint8_t Latch, volatile uint8_t OutputEnable);    
//Led( volatile uint8_t* _DDR, volatile uint8_t* _PORT, uint8_t _Pin);
//Switch( volatile uint8_t* _DDR, volatile uint8_t* _PIN, uint8_t _Pin);    
    
    
    IC_4056 Display_A( &DDRD, &PORTD, 7, 6, 5, 4, 3 );
    IC_4056 Display_B( &DDRD, &PORTD, 7, 6, 5, 4, 2 );
    IC_2024 LEDBar( &DDRB, &PORTB, 7, 6, 5, 4 );
    Led RedLED(&DDRC, &PORTC, 6 );
    Led BlueLED(&DDRC, &PORTC, 7 );
    //Switch Switch(&DDRC, &PINC, 5);
    
    BlueLED.on();
    Display_A.Init();
    Display_B.Init();
    LEDBar.Init();
    BlueLED.off();
    RedLED.on();
    _delay_ms(500);
    RedLED.off();
    
    volatile uint8_t CharA = 0;
    volatile uint8_t CharB = 0;
    volatile uint8_t Char  = 187;        // = 0b 1011 1011
    uint16_t BarString = 65535; //=> 0b 1100 1111 1100 1111 
    
    LEDBar.Write(BarString);
    Display_A.Display(CharA);
    Display_B.Display(CharB);
    
    volatile uint8_t  temp1 = 0;
    volatile uint16_t temp2 = 0;
    volatile uint8_t  temp3 = 0;
    volatile uint8_t  temp4 = 0;
    
/*    
    while(1)
    {
//Calculate 8bit value into 16bit value, doubling bits
        for(uint8_t i = 8 ; i > 0 ; i--)        
        {
            temp1 = Char >> (i-1);
            temp1 = temp1 & 1;
            temp2 = temp2 << 2;
            if(temp1)
            {
                temp2 = temp2 | 0b11;
            }
        }
        LEDBar.Write(temp2);
//separate 8bit value into 2 4bit values used for 7Segment
        Display_A.Display(Char);
        Display_B.Display(Char >> 4);
    }
*/    
      
/*    
//Count to 99 on 2x 7Seg displays    
    while(1)
    {

        for(CharA = 0; CharA < 10 ; CharA++ )
        {
            for(CharB = 0; CharB < 10 ; CharB++ )
            {
                
                Display_B.Display(CharB);
                _delay_ms(200);
            }
            Display_A.Display(CharA);
        }
        
        
        
    }
*/    
  
    
    //Count to 99 on 2x 7Seg displays    
    while(1)
    {
        
        for(CharA = 0; CharA < 10 ; CharA++ )
        {
            for(CharB = 0; CharB < 10 ; CharB++ )
            {
                /*
                while(Switch.getState() == 1)
                {
                    _delay_ms(10);
                }
                */
                Char = CharA << 4;
                Char = Char | CharB;
                //Calculate 8bit value into 16bit value, doubling bits
                for(uint8_t i = 8 ; i > 0 ; i--)        
                {
                    temp1 = Char >> (i-1);
                    temp1 = temp1 & 1;
                    temp2 = temp2 << 2;
                    if(temp1)
                    {
                        temp2 = temp2 | 0b11;
                    }
                }
                LEDBar.Write(temp2);
                //separate 8bit value into 2 4bit values used for 7Segment
                temp3 = Char & 0xF;
                temp4 = Char >> 4;
                
                Display_A.Display(Char >> 4);
                Display_B.Display(Char & 0xF);
                _delay_ms(300);
            }
        }
        
        
        
    }
    
}
    
    
    
