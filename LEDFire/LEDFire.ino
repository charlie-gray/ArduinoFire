/* LED Strip Fire (2020)
 * Made with <3 by charguyy :)
 * 
 * REQUIREMENTS:
 * Make sure that the FastLED lib is installed
 * 
 * NOTE:
 * Make sure that you don't run too many LEDs off 
 * of the Arduino 5v internal power pin. Use a power
 * supply in that case instead. 
 * 
 * Also remember to uncomment the strip that you are 
 * using below.
 */

#include <FastLED.h>

//LED and Clock Pin Digital IO Ports
#define LED_PIN     11
#define CLOCK_PIN   13

//Number of LEDs in strip (See note)
#define NUM_LEDS    30 

//if your colors look incorrect, change the color order here
#define COLOR_ORDER BGR  

//Create vars
float brightMod = 1.0;
int g;

//Create an array for all of the LEDs
CRGB leds[NUM_LEDS];

//Setup
void setup() {,

    //Declare LED strip
    /*
     * NOTE:
     * Be sure to uncomment the RGB LED strip that you are using.
     */

     
    FastLED.addLeds<DOTSTAR, LED_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    //FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    
}
//Loop
void loop() {
  //Loop through all LEDs
    for (int i = 0; i <= NUM_LEDS; i++) {
      
      //Choose random brightness multiplier
      brightMod=random(70)+30;
      brightMod/=100;

      //Choose random green value
      g = random(20)+random(40);

      //Send RGB value to strip
      leds[i] = CRGB (230*brightMod, g*brightMod, 0);

      
    }
    //Show light
    FastLED.show();

    //Delay
    delay(random(100));
}
