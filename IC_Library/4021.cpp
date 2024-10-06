#ifndef __4021_CPP__
#define	__4021_CPP__

//---LIBRARIES------------------------------------------------------------------
#include <inttypes.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>


//volatile uint8_t *my_variable;
//my_variable = &PORTB;
//*my_variable |= 1<<0;


class IC4021
{
protected:
    uint8_t *PORT;
    uint8_t *PIN;
    uint8_t *DDR;
    
    uint8_t Clock;
    uint8_t Clock_NEG;
    uint8_t Latch;
    uint8_t Latch_NEG;
    uint8_t DataOut;
    uint8_t DataOut_NEG;
    
public:
    IC4021( uint8_t DDR, uint8_t PORT, uint8_t PIN, uint8_t Clock, uint8_t Latch, uint8_t DataOut);
    ~IC4021();
    
    void Init();
    void Reset();
    uint8_t Read();
};

IC4021::IC4021( uint8_t _DDR,  uint8_t _PORT,  uint8_t _PIN, uint8_t _Clock, uint8_t _Latch, uint8_t _DataOut)
{
    this->PORT          = &_PORT;
    this->PIN           = &_PIN;
    this->DDR           = &_DDR;
    
    this->Clock         = _Clock;
    this->Latch         = _Latch;
    this->DataOut       = _DataOut; 
    
    this->Clock_NEG     = 0xF - _Clock;
    this->Latch_NEG     = 0xF - _Latch;
    this->DataOut_NEG   = 0xF - _DataOut;
}

IC4021::~IC4021()
{
}

void IC4021::Init()
{
    *DDR   |= this->Clock;
    *DDR   |= this->Latch;
    *DDR   &= this->DataOut_NEG;
    *PORT  |= this->Clock;
    Reset();
}

void IC4021::Reset()
{
        *PORT &= this->Clock_NEG;              //PD3 OFF   Clock
        _delay_us(4);
        *PORT |= this->Clock;                  //PD3 ON    Clock
        _delay_us(4); 
}
/*
uint8_t IC4021::Read()
{
    uint8_t data = 0x0;
    
//Capture data in 4021 shift register
    this->PORT |= this->Latch;                  //PD4 ON    Latch
    _delay_us(4);
    this->PORT &= this->Latch_NEG;              //PD4 OFF   Latch
    _delay_us(4);
//Transfer data into MCU memory
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        this->PORT &= this->Clock_NEG;          //PD3 OFF   Clock
        _delay_us(4);
        data = ( data << 1 );                   //Shift temp variable to left
        if(this->PIN & this->DataOut)           //and if input is high 
        {                                       //write 1 into it
            data = data | 0x01;                 //otherwise it stays 0
        }
        this->PORT |= this->Clock;              //PD3 ON    Clock
        _delay_us(4);
    }
    
    return data;
}
*/


/*
void 4021_Init(uint8_t PORT, char Clock, char Latch, char DataOut );
uint8_t 4021_Read();

//---PORTD 4021 => 3 clock, 4 latch, 5 Data-out | 4022 => 6Clock, 7Reset    
//---------4021 =>    out       out       in    | 4022 =>   out     out
//PORTD - BUTTON MATRIX CONTROL                                //7 6 5 4 3 2 1 0         
    DDRD = 0xD8;                                               //1 1 0 1 1 0 0 0
    PORTD = 0x08;                                              //0 0 0 0 1 0 0 0




//---MATRIX_INIT----------------------------------------------------------------
void 4021_Init()
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
uint8_t 4021_Read()
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
//---4022?----------------------------------------------------------------------

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
//------------------------------------------------------------------------------

*/

#endif /* __4021_CPP__ */