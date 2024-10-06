/* 
 * File:   IC_4022.cpp
 * Author: PanTalir
 * 
 * Created on 22 August 2024, 19:08
 */

#include "IC_4022.h"

#include <inttypes.h>
#include <util/delay.h>

IC_4022::IC_4022(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _PinClock, volatile uint8_t _PinReset)
{
    PORT          = _PORT;
    DDR           = _DDR;
    
    PinClock         = (1<< _PinClock);
    PinReset         = (1<< _PinReset);
    
    PinClock_NEG     = 0xFF - PinClock;
    PinReset_NEG     = 0xFF - PinReset;
}
    
    //IC_4022::IC_4022(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t* PIN, uint8_t Clock, uint8_t Reset, uint8_t CarryOut);
    
IC_4022::~IC_4022()
{}
    
void IC_4022::Init()
{
    *DDR   |= PinClock;                    //Clock     Output
    *DDR   |= PinReset;                    //Reset     Output

    *PORT  &= PinClock_NEG;                //Clock     OFF
    *PORT  &= PinReset_NEG;                //Reset     OFF

    Reset();
}
    
void IC_4022::Reset()
{
    *PORT |= PinReset;                  //Reset    ON
    _delay_us(1);
    *PORT &= PinReset_NEG;              //Reset    OFF
    _delay_us(1);
    state = 0;
}

void IC_4022::Increment()
{
    *PORT |= PinClock;                  //Clock    ON
    _delay_us(1);
    *PORT &= PinClock_NEG;              //Clock    OFF
    _delay_us(1);
    
    state++;
    if(state == 8)
    {
        state = 0;
    }
}

uint8_t IC_4022::getState()
{
    return state;
}