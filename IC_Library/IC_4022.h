/* 
 * File:   IC_4022.h
 * Author: PanTalir
 *
 * Created on 22 August 2024, 19:08
 */

#ifndef IC_4022_H
#define	IC_4022_H

#include <inttypes.h>

class IC_4022 {
public:
    IC_4022(volatile uint8_t* DDR, volatile uint8_t* PORT, uint8_t Clock, uint8_t Reset);
    //IC_4022(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t* PIN, uint8_t Clock, uint8_t Reset, uint8_t CarryOut);
    ~IC_4022();
    
    void Init();
    void Reset();
    void Increment();       //could be defined as bool to return the carry
    
    uint8_t getState();
    //void setState(uint8_t);
    
private:    
    uint8_t state;
    volatile uint8_t *PORT;
    //volatile uint8_t *PIN;
    volatile uint8_t *DDR;
    
    volatile uint8_t PinClock;
    volatile uint8_t PinClock_NEG;
    volatile uint8_t PinReset;
    volatile uint8_t PinReset_NEG;
    //volatile uint8_t CarryOut;
    //volatile uint8_t CarryOut_NEG;
};

#endif	/* IC_4022_H */