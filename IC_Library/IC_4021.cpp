/* 
 * File:   IC_4021.cpp
 * Author: PanTalir
 * 
 * Created on 20 August 2024, 18:15
 */

#include "IC_4021.h"
#include <inttypes.h>
#include <util/delay.h>

IC_4021::IC_4021(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t* _PIN, volatile uint8_t _Clock, volatile uint8_t _Latch, volatile uint8_t _DataOut) 
{
    PORT          = _PORT;
    PIN           = _PIN;
    DDR           = _DDR;

    Clock         = (1<< _Clock);
    Latch         = (1<< _Latch);
    DataOut       = (1<< _DataOut);
    
    Clock_NEG     = 0xFF - Clock;
    Latch_NEG     = 0xFF - Latch;
    DataOut_NEG   = 0xFF - DataOut;
}

IC_4021::IC_4021(const IC_4021& orig) {
}

IC_4021::~IC_4021() {
}

void IC_4021::Init()
{
    *DDR   |= Clock;                    //Clock     Output
    *DDR   |= Latch;                    //Latch     Output
    *DDR   &= DataOut_NEG;              //DataOut   Input
    
    *PORT  |= Clock;                    //Clock     ON
    *PORT  &= Latch_NEG;                //Latch     OFF
    
    Reset();
}

void IC_4021::Reset()
{
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        *PORT &= Clock_NEG;              //Clock    OFF
        _delay_us(4);
        *PORT |= Clock;                  //Clock    ON
        _delay_us(4);
    }
}

uint8_t IC_4021::Read()
{
    uint8_t data = 0x00;
    
//Capture data in 4021 shift register
    *PORT |= Latch;                     //Latch     ON 
    _delay_us(4);
    *PORT &= Latch_NEG;                 //Latch     OFF
    _delay_us(4);
//Transfer data into MCU memory
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        *PORT &= Clock_NEG;             //Clock     OFF
        //_delay_us(4);
        data = ( data << 1 );           //Shift temp variable to left
        if(*PIN & DataOut)              //and if input is high 
        {                               
            data = data | 0x01;         //write 1 into it        
        }
        else
        {
            asm("nop");                 //otherwise it stays 0
            asm("nop");                 
        }
        *PORT |= Clock;                 //Clock     ON
        _delay_us(4);
    }
    return data;
}
