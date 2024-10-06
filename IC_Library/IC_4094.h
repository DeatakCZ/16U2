/* 
 * File:   IC_4094.h
 * Author: PanTalir
 *
 * Created on 02 October 2024, 10:12
 */

#ifndef IC_4094_H
#define	IC_4094_H

#include <inttypes.h>
class IC_4094 {
public:
    IC_4094(volatile uint8_t* DDR, volatile uint8_t* PORT, uint8_t Data, uint8_t Clock, uint8_t Latch, uint8_t OutputEnable);
    ~IC_4094();
    
    void Init();
    void Reset();
    void Write(uint8_t sequence);
    
private:    
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    
    volatile uint8_t Clock;
    volatile uint8_t Clock_NEG;
    volatile uint8_t Latch;                 //Strobe
    volatile uint8_t Latch_NEG;
    volatile uint8_t Data;
    volatile uint8_t Data_NEG;
    volatile uint8_t OutputEnable;
    volatile uint8_t OutputEnable_NEG;
    
    

};

#endif	/* IC_4094_H */

