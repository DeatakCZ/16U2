/* 
 * File:   ILed.h
 * Author: PanTalir
 *
 * Created on 16 August 2024, 21:09
 */

#ifndef ILED_H
#define	ILED_H




/*
class Led {
public:
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void toggle() = 0;
};
*/

#include <inttypes.h>

class ILed {
public:
  enum LedState_t{
    OFF = 0,
    ON = 1
  };
  // Constructors and Destructors
  
   ~ILed() {};
  // Class methods
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void toggle() = 0;
  LedState_t getState() const;
protected:
  LedState_t state;
  volatile uint8_t *PORT;
  volatile uint8_t *DDR;
  volatile uint8_t Pin;
private:
// Delete the copy constructor and assignment operator.
// This prevents the compiler from generating them.
// We don't want to allow copying of Led objects.
//  ILed(const ILed &other) = delete;
//  ILed& operator=(const ILed&) = delete;
// Delete the move constructor and assignment operator.
// This prevents the compiler from generating them.
// We don't want to allow moving of Led objects.
//  ILed(ILed &&other) = delete;
//  ILed &operator=(ILed &&other) = delete;
};

#endif	/* ILED_H */

