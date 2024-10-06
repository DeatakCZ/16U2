/* 
 * File:   IC_2024.h
 * Author: PanTalir
 *
 * Created on 02 September 2024, 22:28
 */

#ifndef IC_2024_H
#define	IC_2024_H

#include <inttypes.h>


class IC_2024 {
public:
    IC_2024(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t DataIn, volatile uint8_t Clock, volatile uint8_t Latch, volatile uint8_t OutputEnable);
    ~IC_2024();
    
    void Init();
    void Reset();
    void Write(uint16_t Sequence);
    void TurnOff();
    void Test();
    
    
private:
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;

    volatile uint8_t DataIn;
    volatile uint8_t Clock;
    volatile uint8_t Latch;
    volatile uint8_t Output;
    volatile uint8_t DataIn_NEG;
    volatile uint8_t Clock_NEG;
    volatile uint8_t Latch_NEG;
    volatile uint8_t Output_NEG;
    
};

#endif	/* IC_2024_H */

