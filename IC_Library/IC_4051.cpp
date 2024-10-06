/* 
 * File:   IC_4051.cpp
 * Author: PanTalir
 * 
 * Created on 01 October 2024, 20:46
 */

#include "IC_4051.h"
#include <inttypes.h>

IC_4051::IC_4051(volatile uint8_t* _DDR, volatile uint8_t* _PORT, volatile uint8_t _SelectA, volatile uint8_t _SelectB, volatile uint8_t _SelectC, volatile uint8_t _Inhibit)
{
    PORT            = _PORT;
    DDR             = _DDR;

    SelectA          = (1<< _SelectA);
    SelectB          = (1<< _SelectB);
    SelectC          = (1<< _SelectC);    
    Inhibit          = (1<< _Inhibit);
    
    SelectA_NEG      = 0xFF - SelectA;
    SelectB_NEG       = 0xFF - SelectB;
    SelectC_NEG       = 0xFF - SelectC;
    Inhibit_NEG      = 0xFF - Inhibit;
}

IC_4051::~IC_4051()
{ 
}   

void IC_4051::Init()
{
    *DDR    |= SelectA;                  //SelectA    Output
    *DDR    |= SelectB;                  //SelectB    Output
    *DDR    |= SelectC;                  //SelectC    Output
    *DDR    |= Inhibit;                  //Inhibit    Output
    
    *PORT   &= SelectA_NEG;              //SelectA   OFF
    *PORT   &= SelectB_NEG;              //SelectB   OFF
    *PORT   &= SelectC_NEG;              //SelectC   OFF
    *PORT   |= Inhibit;                  //Inhibit   ON
}


void IC_4051::Select(uint8_t channel){
    
    *PORT   &= SelectA_NEG;              //SelectA   OFF
    *PORT   &= SelectB_NEG;              //SelectB   OFF
    *PORT   &= SelectC_NEG;              //SelectC   OFF
    

    if((channel >> 2) & 1)
    {   
        *PORT   |= SelectC;              //SelectC   ON
    }
    if((channel >> 1) & 1)
    {
        *PORT   |= SelectB;             //SelectB   ON
    }
    if(channel & 1)
    {
        *PORT   |= SelectA;             //SelectA   ON
    }
    
    *PORT   &= Inhibit_NEG;              //Inhibit   OFF
}


void IC_4051::InhibitOn(){
    *PORT   |= Inhibit;                 //Inhibit   ON
}