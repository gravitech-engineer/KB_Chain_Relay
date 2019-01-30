/* Dependencies */
#include <Wire.h>
#include "KB_Relay.h"

KB_RELAY::KB_RELAY()
{

}
// _ch(0), _logic(0), _address(0);

void KB_RELAY::begin(uint8_t address) {

  /* Store the I2C address and init the Wire library */
  _address = address;
  Wire.begin(4, 5); // join another i2c bus edit KB_Relay.h default for i2c KidBright32
}

void KB_RELAY::digitalWrite(uint8_t ch, uint8_t logic) {
  /* Start communication */
  byte value;
  _ch = ch;
  _logic = logic;

  if (_ch == 0) {
    switch (_logic)
    {
      case 0:
        value = 0xA0;
        break;
      case 1:
        value = 0xA1;
        break;
      default:
        break;
    }
  }
  else if (_ch == 1)
  {
    switch (_logic)
    {
      case 0:
        value = 0xB0;
        break;
      case 1:
        value = 0xB1;
        break;
      default:
        break;
    }
  } else {
    printf("CH NOT FOUND\n");
  }
  // Serial.println(value, HEX);
  Wire.beginTransmission(_address);
  Wire.write(value);
  // Serial.print(_address);
  Wire.endTransmission();
  value = 0;
}
