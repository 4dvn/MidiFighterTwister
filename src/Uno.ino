#include <Adafruit_NeoPixel.h>
#define PIN7 7 //You might need to change this depending on what pins your board has. These means you should connect the ring's 'data in' to digital pin 6 on the arduino. 
#define PIN8 8
#define PIN9 9
#define PIN10 10

//Initialize the ring. In the line below I used "24" since you mentioned a ring of 24 LEDs. If not then change it to however many LEDs you have.
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(12, PIN7, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(12, PIN10, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(12, PIN9, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel ring4 = Adafruit_NeoPixel(12, PIN8, NEO_RGBW + NEO_KHZ800);

int numOn; //This is the value you will change based on your potentiometer values once you get that working too.
 // for brightness 

void setup() {
  ring1.begin();
  ring1.show(); // Initialize all pixels to 'off'
  ring2.begin();
  ring2.show(); // Initialize all pixels to 'off'
  ring3.begin();
  ring3.show();
  ring4.begin();
  ring4.show();
  numOn = 0;
  ring1.setBrightness(30);
  ring2.setBrightness(30);
  ring3.setBrightness(30);
  ring4.setBrightness(30);
}

void loop() {

 //Ring 1
  
numOn = (analogRead(A1) * 12 / 1022); 
  //Turn on correct number of LEDs based on numOn
  for (int i = 0; i < 16; i++) {
    if (i < numOn+1) { //the +1 keeps one LED on at all times                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ); //turn on this LED, adjust values to affect colors and brightness of LEDs
      ring1.setPixelColor(i, (-i*22)+255, 0, i*22, 0);}
    else {
      ring1.setPixelColor(i, 0, 0, 0, 0); //turn off this LED
    }
  }

//RING 2
numOn = (analogRead(A4) * 12 / 1022); 
  //Turn on correct number of LEDs based on numOn
  for (int i = 0; i < 16; i++) {
    if (i < numOn+1) { //the +1 keeps one LED on at all times                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ); //turn on this LED, adjust values to affect colors and brightness of LEDs
      ring4.setPixelColor(i, i*22, 255, 255-(i*22), 0);}
    else {
      ring4.setPixelColor(i, 0, 0, 0, 0); //turn off this LED
    }
  }
  //RING 3
numOn = (analogRead(A3) * 12 / 1022); 
  //Turn on correct number of LEDs based on numOn
  for (int i = 0; i < 16; i++) {
    if (i < numOn+1) { //the +1 keeps one LED on at all times                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ); //turn on this LED, adjust values to affect colors and brightness of LEDs
      ring3.setPixelColor(i, 0, i*22, 250, 0);}
    else {
      ring3.setPixelColor(i, 0, 0, 0, 0); //turn off this LED
    }
  }

  //RING 4
numOn = (analogRead(A2) * 12 / 1022); 
  //Turn on correct number of LEDs based on numOn
  for (int i = 0; i < 16; i++) {
    if (i < numOn+1) { //the +1 keeps one LED on at all times                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ); //turn on this LED, adjust values to affect colors and brightness of LEDs
      ring2.setPixelColor(i, i*18+20, 255, 0, 0);}
    else {
      ring2.setPixelColor(i, 0, 0, 0, 0); //turn off this LED
      }
  }
  ring1.show(); //Apply changes to Ring
  ring2.show(); //Apply changes to Ring
  ring3.show(); //Apply changes to Ring
  ring4.show(); //Apply changes to Ring
}

