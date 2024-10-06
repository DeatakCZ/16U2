/* 
 * File:   Led.cpp
 * Author: PanTalir
 * 
 * Created on 22 August 2024, 19:02
 */

#include "Led.h"



    Led::Led( volatile uint8_t* _DDR, volatile uint8_t* _PORT, uint8_t _Pin)
    {
        state = false;
        PORT  = _PORT;
        DDR   = _DDR;
        Pin   = 0x00;
        Pin   |= (1 << _Pin);
        Pin_NEG = 0xFF - Pin;
        
        *PORT &= Pin_NEG;                       //PORT  OFF
        *DDR  |= Pin;                           //DDR   ON Output
    }
  
    Led::~Led(){}    
  
    void Led::on()
    {
        if (!state) 
        {
        // Code to turn the green LED ON (can be specific to hardware or platform)
            *PORT |=  Pin;                      //PORT  ON
            state = true;
        }
    }
  
    void Led::off()
    {
        if (state) 
        {
        // Code to turn the green LED OFF (can be specific to hardware or platform)
            *PORT &=  Pin_NEG;                  //PORT  OFF
            state = false;
        }
    }
  
    void Led::toggle()
    {
        if (state) 
        {
            off();
        } else 
        {
            on();
        }
    }
  
    bool Led::getState()
    {
        return state;
    }
 
