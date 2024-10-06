/*
 * File:   main.c
 * Author: PanTalir
 *
 * Created on 01 July 2024, 19:14
 */

//---DEFINITIONS----------------------------------------------------------------
#define __AVR_ATmega16U2__
#define F_CPU 8000000UL
//---LIBRARIES------------------------------------------------------------------
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include <util/delay.h>
//---FILES----------------------------------------------------------------------
#include "config.h"
//------------------------------------------------------------------------------


//---GLOBAL_SET-UP--------------------------------------------------------------
uint32_t counter = 0;
//------------------------------------------------------------------------------
//---INTERRUPT_SERVICE_ROUTINE--------------------------------------------------
ISR(TIMER0_COMPA_vect)                          
{  
    counter++;
}
//------------------------------------------------------------------------------
//---TIMER_INIT-----------------------------------------------------------------
void Timer0_Init()
{                                                              //7 6 5 4 3 2 1 0
//    TCCR0A = 0x00;
//    TCCR0B = 0x00;
//    OCR0A =  0x00;
//    TIMSK0 = 0x00;
    
    TCCR0A = ( 0x02 );                                         //0 0 0 0 0 0 1 0
    TCCR0B = ( 0x04 );                                         //0 0 0 0 0 1 0 0 
    
//    TCCR0A = ( 0<<COM0A1 | 0<<COM0A0 | 0<<COM0B1 | 0<<COM0B0 | 1<<WGM01 | 0<<WGM00 );
//    TCCR0B = ( 0<<WGM02  | 1<<CS02   | 0<<CS01   | 0<<CS00   );
    OCR0A =  0x7C ;             // 7C = 124 // C7 = 199
    TIMSK0 = 0x02;          //1<<OCIE0A
    _delay_us(4);
    
    _delay_ms(50);
    PORTC &= 0x7F;
    _delay_ms(200);
    PORTC |= 0x80;
    _delay_ms(50);
}
//------------------------------------------------------------------------------
//---I/O_INIT-------------------------------------------------------------------
void IO_Init()
{
//---PORTD 4021 => 3 clock, 4 latch, 5 Data-out | 4022 => 6Clock, 7Reset    
//---------4021 =>    out       out       in    | 4022 =>   out     out
//PORTD - BUTTON MATRIX CONTROL                                //7 6 5 4 3 2 1 0         
    DDRD = 0xD8;                                               //1 1 0 1 1 0 0 0
    PORTD = 0x08;                                              //0 0 0 0 1 0 0 0
//PORTC - DEBUG LED
    DDRC = 0xC0;                                               //1 1 0 0 0 0 0 0                                        
    PORTC = 0x80;                                              //1 0 0 0 0 0 0 0
//PORTB - 7 SEGMENT DISPLAY 
    DDRB = 0xF0;                                               //1 1 1 1 0 0 0 0
    PORTB = 0xE0;                                              //1 1 1 1 0 0 0 0
    _delay_us(4);
    
    _delay_ms(50);
    PORTC &= 0x7F;
    _delay_ms(200);
    PORTC |= 0x80;
    _delay_ms(50);
}
//------------------------------------------------------------------------------
//---MATRIX_INIT----------------------------------------------------------------
void Matrix_Init()
{
    PORTD |= 0x80;                      //PD7 ON    Reset
    for(uint8_t i = 0 ; i < 8 ; i++ )
    {
        PORTD &= 0xF7;                  //PD3 OFF   Clock
        _delay_us(4);
        PORTD |= 0x08;                  //PD3 ON    Clock
        _delay_us(4);
    }
    PORTD &= 0x7F;                      //PD7 OFF   Reset
    _delay_us(4);
}
//------------------------------------------------------------------------------
//---READ-MATRIX----------------------------------------------------------------
uint8_t Matrix_Read()
{
    uint8_t data = 0x00;
//Load data into register
    PORTD |= 0x10;              //PD4 ON    Latch
    _delay_us(4);
    PORTD &= 0xEF;              //PD4 OFF   Latch
//Save data into variable
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        PORTD &= 0xF7;          //PD3 OFF   Clock
        _delay_us(4);
        data = ( data << 1 );
        if(PIND & 0x20)
        {
            data = data | 0x01;
            Flare();
        }
        PORTD |= 0x08;          //PD3 ON    Clock
        _delay_us(4);
    }
    return data;
}
//------------------------------------------------------------------------------
//---7_SEGMENT_OUTPUT-----------------------------------------------------------
void Display_Write(uint8_t character)
{
//uint8_t Symbols8[16] = 
//{ 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};
    PORTB = 0x00;
    if(character & 0x01)
    {
        PORTB |= 0x10;                  // 1
    }
    if(character & 0x02)                 // 2
    {
        PORTB |= 0x20;
    }            
    if(character & 0x04)                 // 4
    {
        PORTB |= 0x30;
    }            
    if(character & 0x08)                 // 8
    {
        PORTB |= 0x40;
    }
    _delay_us(4);
}
//------------------------------------------------------------------------------
//---HEARTBEAT------------------------------------------------------------------test manually if it works
void Heartbeat()
{
    PINC |= 0x80;
    _delay_us(4);
    PINC &= 0x7F;
    _delay_us(4);
}
void Flare()
{
    PINC |= 0x40;
    _delay_us(1);
    PINC &= 0xBF;
    _delay_us(1);
    _delay_us(10);
    PINC |= 0x40;
    _delay_us(1);
    PINC &= 0xBF;
    _delay_us(1);
}
//------------------------------------------------------------------------------
//---MAIN_FUNCTION--------------------------------------------------------------
int main(void) 
{ 
//---SET-UP---------------------------------------------------------------------
    IO_Init();
    Matrix_Init();
    Timer0_Init();

    uint8_t Input8[4] = {0x00, 0x00, 0x00, 0x00};
   _delay_us(4);
   
   _delay_ms(50);
    PORTC &= 0x7F;
    _delay_ms(200);
    PORTC |= 0x80;
    _delay_ms(50);
//------------------------------------------------------------------------------    
//---MAIN_LOOP------------------------------------------------------------------
//  uint8_t Data8 = 0;
    sei();
    while(1)
    {
        //printf(counter);
        if(counter >= 250)                     //1/s
        { 
            counter = 0;
            Heartbeat();
           
            for( uint8_t i = 0 ; i < 4 ; i++ )
            {
                Input8[i] = Matrix_Read();
                for(uint8_t o = 0 ; o < 8 ; o++)
                {
                    if(Input8[i] & (0x01 << o))
                    {
                        Heartbeat();
                        _delay_us(1);
                        Heartbeat();
                    }
                    _delay_us(10);
                }
                PORTD |= 0x40;          //PD6 OFF Clock
                _delay_us(4);
                PORTD &= 0xBF;          //PD6 ON Clock
                _delay_us(4);
            }
            
            Matrix_Init();
            for( uint8_t i = 4 ; i > 0 ; i-- )
            {
                Display_Write(Input8[i]);
                _delay_ms(200); 
            }    
        }
             
         

        _delay_ms(10);
    }
     return 0;
}
//------------------------------------------------------------------------------

//    while(1)
//    {
//        if(PIND5)
//        {
//            PORTC |= 0x80;
//        }
//        else
//        {
//            PORTC &= 0x7F;
//        }
//        _delay_ms(100);
//        
//        
//        
//    }
    


