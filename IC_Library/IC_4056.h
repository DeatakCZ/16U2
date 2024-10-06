/* 
 * File:   IC_4056.h
 * Author: PanTalir
 *
 * Created on 23 August 2024, 16:41
 */

#ifndef IC_4056_H
#define	IC_4056_H

#include <inttypes.h>

class IC_4056 {
public:
    IC_4056( volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4);
    IC_4056( volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _Input1, volatile uint8_t _Input2, volatile uint8_t _Input3, volatile uint8_t _Input4, volatile uint8_t _Latch);
    ~IC_4056();
    
    void Init();
    void Clear();
    void Display(uint8_t character);
    
private:
    uint8_t state;
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;

    volatile uint8_t Latch;         //Strobe
    volatile uint8_t Latch_NEG;
    volatile uint8_t Input1;
    volatile uint8_t Input1_NEG;
    volatile uint8_t Input2;
    volatile uint8_t Input2_NEG;
    volatile uint8_t Input3;
    volatile uint8_t Input3_NEG;
    volatile uint8_t Input4;
    volatile uint8_t Input4_NEG;    
    
//    volatile uint8_t Strobe;
//    volatile uint8_t Strobe_NEG;


};

#endif	/* IC_4056_H */

