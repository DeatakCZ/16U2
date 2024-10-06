



//MAIN LOOP:

if(counter >= 125)                     //1/s
        {
            counter = 0;
            if(Data == 0)
            {
                PORTC |= 0x80;
                Data++;
            }
            else if(Data == 1)
            {
                PORTC &= 0x7F;
                Data--;
            }
            
            for( uint8_t i = 0 ; i < 4 ; i++ )
            {
                Reading = readMatrix();
                //PORTD = 0x00 | data;

                PORTD &= 0xBF;
                _delay_us(4);
                PORTD |= 0x40;
                _delay_us(4);
            }
        }



   
//IC SETUP:
   
   PORTD |= 0x80;
    for(uint8_t i = 0 ; i < 8 ; i++ )
    {
        PORTD &= 0xF7;
        _delay_us(4);
        PORTD |= 0x04;
        _delay_us(4);
    }
    PORTD &= 0x7F;

 
  
 
 
//FUNCTION:
 
 
 
 uint8_t readMatrix()
{
    uint8_t data = 0x0;
//Load data into register
    PORTD |= 0x10;
    _delay_us(4);
    PORTD &= 0xEF;
//Save data into variable
    for(int i = 0 ; i < 8 ; i++)
    {
        PORTD &= 0xF7;
        _delay_us(4);
        data = ( data << 1 );
        if(PIND5)
        {
            data = data | 0x1;
        }
        PORTD |= 0x04;
        _delay_us(4);
    }
    return data;
}