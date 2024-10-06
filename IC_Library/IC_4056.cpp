/* 
 * File:   IC_4056.cpp
 * Author: PanTalir
 * 
 * Created on 23 August 2024, 16:41
 */

#include "IC_4056.h"
#include <util/delay.h>

IC_4056::IC_4056(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4) 
{
    PORT           = _PORT;
    DDR            = _DDR;
    
    Input1         = (1<< _Input1);
    Input2         = (1<< _Input2);
    Input3         = (1<< _Input3);
    Input4         = (1<< _Input4);
    
    Input1_NEG     = 0xFF - Input1;
    Input2_NEG     = 0xFF - Input2;
    Input3_NEG     = 0xFF - Input3;
    Input4_NEG     = 0xFF - Input4;
    
    Latch          = 255;
}

IC_4056::IC_4056(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4, volatile uint8_t _Latch) 
{
    PORT           = _PORT;
    DDR            = _DDR;
    
    Input1         = (1<< _Input1);
    Input2         = (1<< _Input2);
    Input3         = (1<< _Input3);
    Input4         = (1<< _Input4);
    Latch          = (1<< _Latch);
    
    Input1_NEG     = 0xFF - Input1;
    Input2_NEG     = 0xFF - Input2;
    Input3_NEG     = 0xFF - Input3;
    Input4_NEG     = 0xFF - Input4;
    Latch_NEG      = 0xFF - Latch;
}

IC_4056::~IC_4056() {
}
    
void IC_4056::Init()
{
    *DDR    |= Latch;                       //Latch      Output
    *DDR    |= Input1;                      //Input1     Output
    *DDR    |= Input2;                      //Input2     Output
    *DDR    |= Input3;                      //Input3     Output
    *DDR    |= Input4;                      //Input4     Output
    
    Display(15);
}

//void IC_4056::Clear()
//{
//    *PORT   |= Input1;                    //Input1     ON
//    *PORT   |= Input2;                    //Input2     ON
//    *PORT   |= Input3;                    //Input3     ON
//    *PORT   |= Input4;                    //Input4     ON    
//}

void IC_4056::Display(uint8_t character)
{//4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321, 4321
// 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
//    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    L,    H,    P,    A,    -, Blank
    state = character;
    switch(character)
    {
        case 0:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;
        case 1:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;
        case 2:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  |= Input2;                       //Input2    ON
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break; 
        case 3:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  |= Input2;                       //Input2    ON
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;  
        case 4:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  |= Input3;                       //Input3    ON
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;
        case 5:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  |= Input3;                       //Input3    ON
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;
        case 6:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  |= Input2;                       //Input2    ON
            *PORT  |= Input3;                       //Input3    ON
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break; 
        case 7:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  |= Input2;                       //Input2    ON
            *PORT  |= Input3;                       //Input3    ON
            *PORT  &= Input4_NEG;                   //Input4    OFF
            break;      
        case 8:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  |= Input4;                       //Input4    ON    
            break;
        case 9:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  |= Input4;                       //Input4    ON 
            break;
        case 10:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  |= Input2;                       //Input2    ON
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  |= Input4;                       //Input4    ON 
            break; 
        case 11:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  |= Input2;                       //Input2    ON
            *PORT  &= Input3_NEG;                   //Input3    OFF
            *PORT  |= Input4;                       //Input4    ON 
            break;  
        case 12:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  |= Input3;                       //Input3    ON
            *PORT  |= Input4;                       //Input4    ON 
            break;
        case 13:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  &= Input2_NEG;                   //Input2    OFF
            *PORT  |= Input3;                       //Input3    ON
            *PORT  |= Input4;                       //Input4    ON 
            break;
        case 14:
            *PORT  &= Input1_NEG;                   //Input1    OFF
            *PORT  |= Input2;                       //Input2    ON
            *PORT  |= Input3;                       //Input3    ON
            *PORT  |= Input4;                       //Input4    ON 
            break; 
        case 15:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  |= Input2;                       //Input2    ON
            *PORT  |= Input3;                       //Input3    ON
            *PORT  |= Input4;                       //Input4    ON 
            break;    
        default:
            *PORT  |= Input1;                       //Input1    ON
            *PORT  |= Input2;                       //Input2    ON
            *PORT  |= Input3;                       //Input3    ON
            *PORT  |= Input4;                       //Input4    ON
            state = 16;                             //Invalid state
            break; 
    }
    if(Latch != 255)
    {
    *PORT  |= Latch;                                //Latch     ON
    _delay_us(1);
    *PORT  &= Latch_NEG;                            //Latch     OFF
    }
}