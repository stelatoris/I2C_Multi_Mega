#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>
#include<TM1637.h>

// Define the SDA and SCL pins of the TCA9548A multiplexer
const byte tca_sda_pin = 20;
const byte tca_scl_pin = 21;

// Define the I2C address of the TM1637 display
const byte tm1637_address = 0x27;

TM1637Display display(tca_sda_pin, tca_scl_pin, tm1637_address);

// Initialize the I2C bus and the TCA9548A multiplexer
void setup() {
  Wire.begin(); // Initialize I2C bus
  //Wire.setClock(400000); // Set I2C clock speed to 400kHz

  // Initialize the TCA9548A multiplexer
  Wire.beginTransmission(0x70); // Start transmission to TCA9548A
  Wire.write(1 << 0); // Select channel 0
  Wire.endTransmission();
}

// Initialize the TM1637Display object and display some numbers
void loop() {
  // Initialize the TM1637Display object for channel 0 of the TCA9548A
  

  // Display the number 1234
  display.showNumberDec(1234);

  // Wait for some time before displaying another number
  delay(1000);
}
