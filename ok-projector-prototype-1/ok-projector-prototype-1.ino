// This file is released under the CC0 1.0 Universal

#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include "RGBmatrixPanel2.h"
RGBmatrixPanel2 matrix(A0, A1, A2, 30, A3, 31, true); // For Arduino Mega 2560

#include <Wii.h>
#include <usbhub.h>
#include <SPI.h>
USB Usb;
BTD Btd(&Usb);
WII Wii(&Btd, PAIR);

void setup() {
  matrix.begin();
  Usb.Init();
}

void loop() {
  Usb.Task();
  if (Wii.wiimoteConnected) {
    if (Wii.getButtonClick(HOME)) {
      Wii.disconnect();
    } else {
      if (Wii.getButtonPress(LEFT)) {
        // After you
        matrix.fillScreen(0b0000011111100000);
        matrix.swapBuffers(true);
      } else if (Wii.getButtonPress(RIGHT)) {
        // Thank you
        matrix.fillScreen(0b1111111111100000);
        matrix.swapBuffers(true);
      } else {
        matrix.fillScreen(0b0000000000000000);
        matrix.swapBuffers(true);
      }
    }
  }
}

