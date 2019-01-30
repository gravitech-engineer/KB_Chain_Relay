//////////////////////////////////////////////////////////////////////
// Name: Example_KB_Relay_Module
// Device: KidBrigth32 V1.3
// Create: 18/10/30
// By: Nattkarn.P
/////////////////////////////////////////////////////////////////////
// select adress with pad select adress on module
//
//     **                                   **
//   ******                               ******
//  ********                             ********
//     **    --->   addr = 0x1A                   --->   addr = 0x1B
//  ********                             ********
//   ******                               ******
//     **                                   **
//
//  chanel = 0 ---> relay chanel 0 control
//  chanel = 1 ---> relay chanel 1 control
//  digitalWrite(chanel,state)  
//////////////////////////////////////////////////////////////////////


#include <Wire.h>
#include "KB_Relay.h"

KB_RELAY i2c_relay; 


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
//  Wire.begin(4, 5); // join another i2c bus edit KB_Relay.h default for i2c KidBright32
  i2c_relay.begin(0x1A); // Start the I2C controller and store the KB_RELAY_Module address
}


void loop() {
  i2c_relay.digitalWrite(0, HIGH);
  digitalWrite(LED_BUILTIN , HIGH);
  delay(500);
  i2c_relay.digitalWrite(0, LOW);
  digitalWrite(LED_BUILTIN , LOW);
  delay(500);
  i2c_relay.digitalWrite(1, HIGH);
  digitalWrite(LED_BUILTIN , HIGH);
  delay(500);
  i2c_relay.digitalWrite(1, LOW);
  digitalWrite(LED_BUILTIN , LOW);
  delay(500);
}
