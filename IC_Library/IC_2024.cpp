/* 
 * File:   IC_2024.cpp
 * Author: PanTalir
 * 
 * Created on 02 September 2024, 22:28
 */

#include "IC_2024.h"
#include <inttypes.h>
#include <util/delay.h>

IC_2024::IC_2024(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _DataIn, volatile uint8_t _Clock, volatile uint8_t _Latch, volatile uint8_t _Output)
{
    PORT            = _PORT;
    DDR             = _DDR;

    DataIn          = (1<< _DataIn);
    Clock           = (1<< _Clock);
    Latch           = (1<< _Latch);    
    Output          = (1<< _Output);
    
    DataIn_NEG      = 0xFF - DataIn;
    Clock_NEG       = 0xFF - Clock;
    Latch_NEG       = 0xFF - Latch;
    Output_NEG      = 0xFF - Output;
}

IC_2024::~IC_2024()
{ 
}   

void IC_2024::Init()
{
    *DDR    |= DataIn;                  //DataIn   Output
    *DDR    |= Clock;                   //Clock    Output
    *DDR    |= Latch;                   //Latch    Output
    *DDR    |= Output;                  //Output   Output
    
    *PORT   &= DataIn_NEG;              //DataIn  OFF
    *PORT   &= Clock_NEG;                //Clock   OFF
    *PORT   &= Latch_NEG;               //Latch   OFF
    *PORT   |= Output;                  //Output  ON
    
    Reset();
}

void IC_2024::Reset()
{
    *PORT   &= DataIn_NEG;              //DataIn  OFF
    for(uint8_t i = 0 ; i < 16 ; i++)
    {
        *PORT |= Clock;                 //Clock    ON
        _delay_us(4);
        *PORT &= Clock_NEG;             //Clock    OFF
        _delay_us(4);
    }
    *PORT |= Latch;                     //Latch    ON
    _delay_us(4);
    *PORT &= Latch_NEG;                 //Latch    OFF
    _delay_us(4);
    
    TurnOff();
}

void IC_2024::Write(uint16_t Sequence)
{
    for(uint8_t i = 0 ; i < 16 ; i++)
    {
        if((Sequence >> i) & 1 )
            *PORT |= DataIn;            //DataIn    ON
        else
            *PORT &= DataIn_NEG;        //DataIn    OFF
        
        *PORT |= Clock;                 //Clock     ON
        _delay_us(4);
        *PORT &= Clock_NEG;             //Clock     OFF
        _delay_us(4);
    }
    *PORT &= DataIn_NEG;        //DataIn    OFF
    
    *PORT |= Latch;                     //Latch     ON
    _delay_us(4);
    *PORT &= Latch_NEG;                 //Latch     OFF
    _delay_us(4);
    
    *PORT &= Output_NEG;                //Output    OFF
    _delay_us(4);
}

void IC_2024::TurnOff()
{
    *PORT |= Output;                    //Output    ON
    _delay_us(4);    
}

void IC_2024::Test()
{
    *PORT |= DataIn;            //DataIn    ON
    for(uint8_t i = 0 ; i < 16 ; i++)
    {
        *PORT |= Clock;                 //Clock     ON
        _delay_us(4);
        *PORT &= Clock_NEG;             //Clock     OFF
        _delay_us(4);
    }
    *PORT &= DataIn_NEG;                //DataIn    OFF
    
    *PORT |= Latch;                     //Latch     ON
    _delay_us(4);
    *PORT &= Latch_NEG;                 //Latch     OFF
    _delay_us(4);
    
    *PORT &= Output_NEG;                //Output    OFF
    _delay_us(4);
}