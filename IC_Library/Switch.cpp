#include "Switch.h"
#include <inttypes.h>

Switch::Switch( uint8_t volatile* _DDR, uint8_t volatile* _PIN, uint8_t volatile* _PORT, uint8_t volatile _Pin)
{
    DDR   = _DDR;
    PIN   = _PIN;
    PORT  = _PORT;
    
    Pin   = 0x00;
    Pin   |= (1 << _Pin);
    Pin_NEG = 0xFF - Pin;

    //*PORT |= Pin;                          //PORT       ON  PullUp ON    
    *DDR  &= Pin_NEG;                      //DDR        OFF Input    
    readStatus();
}

Switch::~Switch()
    {
    }
    
void Switch::readStatus()
{
    tempPIN = *PIN;
    if((tempPIN & Pin) > 0)
    {
        state = 1;
    }else
    {
        state = 0;
    } 
}
uint8_t Switch::getState()
{
    readStatus();
    return state;
}


/*
    #   7 6 5 4 3 2 1 0
 Pin    0 0 0 1 0 0 0 0
 *PIN   1 0 1 1 1 0 1 0 
 &      0 0 0 1 0 0 0 0
 
 
 */