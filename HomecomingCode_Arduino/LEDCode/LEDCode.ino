#include <FastLED.h>

#define NUM_LEDS 480*4
#define DATA_PIN 7
#define BRIGHTNESS 60
#define VOLTS 5
#define MAX_AMPS 500  //in mA

CRGB leds[NUM_LEDS];
int r = 0, g = 0, b = 0;
int i = 0, h = 0, randVal = 0, oneTime = 0, functionRandVal = 0;

void setup() {

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  randomSeed(2);
}

void loop() {
  FastLED.clear();
    //ElectricTrail(1);
    for (i = 0; i < NUM_LEDS; i++) {
        FastLED.setBrightness(random(BRIGHTNESS));
        randVal = random(3);
        if (randVal == 0) {
          leds[i] = CRGB::Yellow;
        } else if (randVal == 1) {
          leds[i] = CRGB(240, 234, 43);
        } else if (randVal == 2) {
          leds[i] = CRGB::Blue;
        }
        i = i+10; 
        FastLED.show();
      }
    
}

  void ElectricTrail(int trailType) {
    //ledOffset is the trail length
    int upperBound = 0, lowerBound = 0, ledOffset = 15;
    if (trailType == 1) {
      for (i = 0; i < ledOffset; i++) {
        FastLED.setBrightness(random(BRIGHTNESS));
        randVal = random(3);
        if (randVal == 0) {
          leds[i] = CRGB::Yellow;
        } else if (randVal == 1) {
          leds[i] = CRGB(240, 234, 43);
        } else if (randVal == 2) {
          leds[i] = CRGB::Blue;
        }
        FastLED.show();
      }
      upperBound = ledOffset * 2, lowerBound = ledOffset;
      for (int d = 0; d < 124; d++) {
        for (i = lowerBound; i < upperBound; i++) {
          FastLED.setBrightness(random(BRIGHTNESS));
          randVal = random(3);
          if (randVal == 0) {
            leds[i] = CRGB::Yellow;
          } else if (randVal == 1) {
            leds[i] = CRGB(240, 234, 43);
          } else if (randVal == 2) {
            leds[i] = CRGB::Blue;
          }
          //leds[i] = CRGB::Blue;
          leds[i - ledOffset] = CRGB(0, 0, 0);
          FastLED.show();
          //i = i +3;
        }
        lowerBound = lowerBound + ledOffset;
        upperBound = upperBound + ledOffset;
      }
    }
  }

