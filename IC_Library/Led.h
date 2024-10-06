/* 
 * File:   Led.h
 * Author: PanTalir
 *
 * Created on 22 August 2024, 19:02
 */

#ifndef LED_H
#define	LED_H 

#include "ILed.h"


class Led : public ILed 
{
public:  
    Led( volatile uint8_t* _DDR, volatile uint8_t* _PORT, uint8_t _Pin);
    ~Led();
    
    void on();
    void off();
    void toggle();
    
    bool getState();
    
private:
    bool state; // True if ON, False if OFF
    volatile uint8_t* PORT;
    volatile uint8_t* DDR;
    volatile uint8_t Pin;
    volatile uint8_t Pin_NEG;
};


#endif	/* LED_H */

