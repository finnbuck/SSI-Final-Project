/*
  Library for the MMA8452Q
  By: Jim Lindblom and Andrea DeVore
  SparkFun Electronics

  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/14587

  This sketch uses the SparkFun_MMA8452Q library to initialize
  the accelerometer and print a message each time it is tapped.

  Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

  The MMA8452Q is a 3.3V max sensor, so you'll need to do some
  level-shifting between the Arduino and the breakout. Series
  resistors on the SDA and SCL lines should do the trick.

  License: This code is public domain, but if you see me
  (or any other SparkFun employee) at the local, and you've
  found our code helpful, please buy us a round (Beerware
  license).

  Distributed as is; no warrenty given.
*/

#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    // Click here to get the library: http://librarymanager/All#SparkFun_MMA8452Q

MMA8452Q accel;                 // create instance of the MMA8452 class

void setup() {
  Serial.begin(9600);
  // Serial.println("MMA8452Q Read Tap Code!");
  Wire.begin();

  if (accel.begin() == false) {
    // Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }

  accel.setScale(SCALE_8G);
}

void loop() {
  if (Serial.available()) {
    // Serial.print(Serial.read());
    Serial.write(Serial.read());
  }
  if (accel.available()) {      // Wait for new data from accelerometer
    // Prints "Tap" each time accelerometer detects a tap
    if (accel.readTap() > 0) {
      // Serial.print(2);
      Serial.write(2);
    }
  }
}