// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      11

int starting = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  if (0 == starting) {
    for (int j = 0; j < 5; j++) {
      for (int shift = 0; shift < NUMPIXELS; shift++) {
        for (int i = 0; i < NUMPIXELS; i++) {
          if (i == shift) {
            pixels.setPixelColor(i, pixels.Color(0, 255, 0));
          } else {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
          }
        }
        pixels.show();
        delay(50);
      }

      for (int shift = NUMPIXELS - 1; shift > 0; shift--) {
        for (int i = 0; i < NUMPIXELS; i++) {
          if (i == shift) {
            pixels.setPixelColor(i, pixels.Color(0, 255, 0));
          } else {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
          }
        }
        pixels.show();
        delay(50);
      }
    }
  }
  
  starting = 1;

  // For a set of NeoPixels the first NeoPixel is 0, second is 1,
  // all the way up to the count of pixels minus one.

  for(int j = 0; j < 255; j=j+8) {

    // pixels takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(0, pixels.Color(255 - j, 0, j));
    pixels.setPixelColor(1, pixels.Color(j,255 - j, 0));
    pixels.setPixelColor(2, pixels.Color(0, j, 255 - j));
    pixels.setPixelColor(3, pixels.Color(255 -j, j/2, 255 - j));
    pixels.setPixelColor(4, pixels.Color(j/2, j/2, 255 - j));
    pixels.setPixelColor(5, pixels.Color(j/2, 255-j, j/2));

    pixels.setPixelColor(6, pixels.Color(255 - j, 0, j));
    pixels.setPixelColor(7, pixels.Color(j,255 - j, 0));
    pixels.setPixelColor(8, pixels.Color(0, j, 255 - j));
    pixels.setPixelColor(9, pixels.Color(255 -j, j/2, 255 - j));
    pixels.setPixelColor(10, pixels.Color(j/2, j/2, 255 - j));

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
  }

  for(int j = 255; j > 0; j=j-8) {

    pixels.setPixelColor(0, pixels.Color(255 - j, 0, j));
    pixels.setPixelColor(1, pixels.Color(j,255 - j, 0));
    pixels.setPixelColor(2, pixels.Color(0, j, 255 - j));
    pixels.setPixelColor(3, pixels.Color(255 -j, j/2, 255 - j));
    pixels.setPixelColor(4, pixels.Color(j/2, j/2, 255 - j));
    pixels.setPixelColor(5, pixels.Color(j/2, 255-j, j/2));


    pixels.setPixelColor(6, pixels.Color(255 - j, 0, j));
    pixels.setPixelColor(7, pixels.Color(j,255 - j, 0));
    pixels.setPixelColor(8, pixels.Color(0, j, 255 - j));
    pixels.setPixelColor(9, pixels.Color(255 -j, j/2, 255 - j));
    pixels.setPixelColor(10, pixels.Color(j/2, j/2, 255 - j));

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}
