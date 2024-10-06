/* 
 * File:   Switch.h
 * Author: PanTalir
 *
 * Created on 07 September 2024, 22:46
 */

#ifndef SWITCH_H
#define	SWITCH_H

#include <inttypes.h>

class Switch
{
public:  
    Switch( uint8_t volatile* _DDR, uint8_t volatile* _PIN, uint8_t volatile* _PORT, uint8_t volatile _Pin);
    ~Switch();

    uint8_t getState();
    void readStatus();
    
private:
    uint8_t volatile state; // True if ON, False if OFF
    
    uint8_t volatile tempPIN;
    uint8_t volatile* PORT;
    uint8_t volatile* DDR;
    uint8_t volatile* PIN;
    uint8_t volatile Pin;
    uint8_t volatile Pin_NEG;
};

#endif	/* SWITCH_H */

