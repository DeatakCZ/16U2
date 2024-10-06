/* 
 * File:   Led.h
 * Author: PanTalir
 *
 * Created on 16 August 2024, 21:36
 */

#ifndef LED_H
#define	LED_H

#include "ILed.h"


class Led : public ILed 
{

public:  
    Led(volatile uint8_t* _PORT, volatile uint8_t* _DDR, uint8_t _PIN)
    {
        state = false;
        PORT  = _PORT;
        DDR   = _DDR;
        PIN   = 0x00;
        PIN   |= (1<< _PIN);
        NEG_PIN = 0xFF - PIN;
        
        *PORT &= NEG_PIN;                      //0 1 1 1 1 1 1 1 = 7F
        *DDR  &= PIN;                      //1 0 0 0 0 0 0 0 = 80
        
    }
  
    ~Led(){}    
  
    void on()
    {
        if (!state) 
        {
        // Code to turn the green LED ON (can be specific to hardware or platform)
            *PORT |=  PIN;
            state = true;
        }
    }
  
    void off()
    {
        if (state) 
        {
        // Code to turn the green LED OFF (can be specific to hardware or platform)
            *PORT &=  NEG_PIN;
            state = false;
        }
    }
  
    void toggle()
    {
        if (state) 
        {
            off();
        } else 
        {
            on();
        }
    }
  
    bool getState()
    {
        return state;
    }
  
private:
    bool state; // True if ON, False if OFF
    volatile uint8_t* PORT;
    volatile uint8_t* DDR;
    volatile uint8_t PIN;
    volatile uint8_t NEG_PIN;
};


#endif	/* LED_H */

