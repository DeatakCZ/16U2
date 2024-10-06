/* 
 * File:   IC_4094.cpp
 * Author: PanTalir
 * 
 * Created on 02 October 2024, 10:12
 */

#include "IC_4094.h"
#include <util/delay.h>

IC_4094::IC_4094(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Data, volatile uint8_t _Clock, volatile uint8_t _Latch, volatile uint8_t _OutputEnable) 
{
    PORT                = _PORT;
    DDR                 = _DDR;

    Data                = (1<< _Data);
    Clock               = (1<< _Clock);
    Latch               = (1<< _Latch);
    OutputEnable        = (1<< _OutputEnable);
    
    Data_NEG            = 0xFF - Data;
    Clock_NEG           = 0xFF - Clock;
    Latch_NEG           = 0xFF - Latch;
    OutputEnable_NEG    = 0xFF - OutputEnable;
}


IC_4094::~IC_4094() {
}

void IC_4094::Init()
{
    *DDR   |= Data;                     //Data          Output
    *DDR   |= Clock;                    //Clock         Output
    *DDR   |= Latch;                    //Latch         Output
    *DDR   |= OutputEnable;             //OutputEnable  Output
    
    *PORT  &= Data_NEG;                 //Data          OFF
    *PORT  &= Clock_NEG;                //Clock         OFF
    *PORT  &= Latch_NEG;                //Latch         OFF
    *PORT  &= OutputEnable_NEG;         //OutputEnable  OFF
    
    Reset();
}

void IC_4094::Reset()
{
    *PORT  &= Data_NEG;                 //Data          OFF
    *PORT  |= Latch;                    //Latch         ON
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        *PORT |= Clock;                  //Clock        ON
        _delay_us(4);
        *PORT &= Clock_NEG;              //Clock        OFF
        _delay_us(4);
    }
    *PORT  &= Latch_NEG;                //Latch         OFF
}

void IC_4094::Write(uint8_t sequence)
{
    *PORT  |= Latch;                    //Latch         ON
    for(uint8_t i = 7 ; i >= 0 ; i--)
    {
        if((sequence>>i) & 1)
            *PORT  |= Data;             //Data          ON
        else     
            *PORT  &= Data_NEG;         //Data          OFF
        
        *PORT |= Clock;                  //Clock        ON
        _delay_us(4);
        *PORT &= Clock_NEG;              //Clock        OFF
        _delay_us(4);
    }
    *PORT  &= Latch_NEG;                //Latch         OFF
}

