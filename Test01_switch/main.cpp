#include "config.h"
#include <util/delay.h>
#include "../IC_Library/Switch.h"
#include "../IC_Library/Led.h"

int main()
{
    Led Led_1(&DDRC, &PORTC, 4);
    Led Led_2(&DDRC, &PORTC, 5);
    Switch Switch01(&DDRC, &PINC, &PORTC, 7);
    _delay_us(1);
    _delay_ms(1000);
    
    while(1)
    {
        Switch01.getState();
        if(Switch01.getState() != 0)
        {
            Led_1.on();
            _delay_us(1);
            _delay_ms(1000);
            Led_1.off();
        }
        else
        {
            Led_2.on();
            _delay_us(1);
            _delay_ms(1000);
            Led_2.off();            
        }
        _delay_us(2);
        _delay_ms(2000);
    }
}
