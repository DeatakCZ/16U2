/* 
 * File:   Switch.h
 * Author: PanTalir
 *
 * Created on 07 September 2024, 22:44
 */

#ifndef ISWITCH_H
#define	ISWITCH_H


#include <inttypes.h>

class ISwitch {
public:
  enum SwitchState_t{
    OFF = 0,
    ON = 1
  };
  // Constructors and Destructors
  
   ~ISwitch() {};
  // Class methods

  //SwitchState_t getState() const;
protected:
  SwitchState_t state;
  volatile uint8_t *PIN;
  volatile uint8_t *DDR;
  volatile uint8_t Pin;
private:


};
#endif	/* ISWITCH_H */

