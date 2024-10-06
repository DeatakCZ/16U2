/* 
 * File:   IC_4051.h
 * Author: PanTalir
 *
 * Created on 01 October 2024, 20:46
 */

#ifndef IC_4051_H
#define	IC_4051_H

#include <inttypes.h>

class IC_4051 {
public:
    IC_4051(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t SelectA, volatile uint8_t SelectB, volatile uint8_t SelectC, volatile uint8_t Inhibit);
    ~IC_4051();
    
    void Init();
    void Select(uint8_t channel);
    void InhibitOn();
        
    
private:
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;

    volatile uint8_t SelectA;
    volatile uint8_t SelectB;
    volatile uint8_t SelectC;
    volatile uint8_t Inhibit;
    volatile uint8_t SelectA_NEG;
    volatile uint8_t SelectB_NEG;
    volatile uint8_t SelectC_NEG;
    volatile uint8_t Inhibit_NEG;

};

#endif	/* IC_4051_H */

