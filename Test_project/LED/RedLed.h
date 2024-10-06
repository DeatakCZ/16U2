/* 
 * File:   RedLed.h
 * Author: PanTalir
 *
 * Created on 16 August 2024, 22:13
 */

#ifndef REDLED_H
#define	REDLED_H

#include "LED.h"


class LedRed : public ILed 
{
private:
    bool state; // True if ON, False if OFF
public:
    LedRed()
    {
        PORTD = PORTD | 0xBF;               //1 0 1 1 1 1 1 1 = BF
        DDRD  = DDRD  & 0x40;               //0 1 0 0 0 0 0 0 = 40
        state = false;
    }

    ~LedRed(){}
    
    void on()
    {
        if (!state)
        {
        // Code to turn the green LED ON (can be specific to hardware or platform)
            PORTD = PORTD | 0x40;
            state = true;
        }
    }
    
    void off(){
        if (state)
        {
        // Code to turn the green LED OFF (can be specific to hardware or platform)
            PORTD = PORTD & 0xBF;
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
        return this->state;
    }
};

#endif	/* REDLED_H */

