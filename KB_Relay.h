#ifndef __KB_LERAY_H
#define __KB_LERAY_H



#if ARDUINO >= 100
#include "Arduino.h"
#define I2CWRITE(x) Wire.write(x)
#define I2CREAD() Wire.read()
#else
#include "WProgram.h"
#define I2CWRITE(x) Wire.send(x)
#define I2CREAD() Wire.receive()
#define INPUT_PULLUP 2
#endif


/**
   @brief KB_RELAY Arduino class
*/
class KB_RELAY {
  public:
    /**
       Create a new KB_RELAY instance
    */
    KB_RELAY();

    /**
       Start the I2C controller and store the KB_RELAY_Module address
    */
    void begin(uint8_t address);

    void digitalWrite(uint8_t ch, uint8_t logic);

  private:
    volatile uint8_t _ch;
    volatile uint8_t _logic;
    uint8_t _address;
};
#endif
