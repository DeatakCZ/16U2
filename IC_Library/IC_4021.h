/* 
 * File:   IC_4021.h
 * Author: PanTalir
 *
 * Created on 20 August 2024, 18:15
 */

#ifndef IC_4021_H
#define	IC_4021_H

#include <inttypes.h>


class IC_4021 {
public:
    IC_4021(volatile uint8_t* DDR, volatile uint8_t* PORT, volatile uint8_t* PIN, uint8_t Clock, uint8_t Latch, uint8_t DataOut);
    IC_4021(const IC_4021& orig);
    ~IC_4021();
    
    void Init();
    void Reset();
    uint8_t Read();
    
private:    
    volatile uint8_t *PORT;
    volatile uint8_t *PIN;
    volatile uint8_t *DDR;
    
    volatile uint8_t Clock;
    volatile uint8_t Clock_NEG;
    volatile uint8_t Latch;
    volatile uint8_t Latch_NEG;
    volatile uint8_t DataOut;
    volatile uint8_t DataOut_NEG;
    
};

#endif	/* IC_4021_H */

