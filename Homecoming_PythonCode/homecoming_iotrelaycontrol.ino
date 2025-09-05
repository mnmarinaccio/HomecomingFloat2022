// C++ code
//
#include <FastLED.h>

#define IOTRELAY 4
//#define BUTTONPIN 8
//#define POTPIN A0
#define BUZZER 10

#define NUM_LEDS 480 * 4
#define DATA_PIN 7
#define BRIGHTNESS 60
#define VOLTS 5
#define MAX_AMPS 500  //in mA

CRGB leds[NUM_LEDS];
int r = 0, g = 0, b = 0;
int i = 0, h = 0, randVal = 0, oneTime = 0, functionRandVal = 0;

int delaySpeed = 5000;
uint8_t randFunction = 0;
//int test = 1;

void setup() {
  pinMode(IOTRELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  //pinMode(BUTTONPIN, INPUT_PULLUP);
  //pinMode(POTPIN, INPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  //randomSeed(2);
}

void loop() {
  tone(BUZZER, 1000);  // Send 1KHz sound signal...
  delay(1000);         // ...for 1 sec
  noTone(BUZZER);      // Stop sound...
  delay(1000);         // ...for 1sec

  randFunction = random(2);
  FastLED.clear();
  if (randFunction == 0) {
    ElectricScatter();
  } else if (randFunction == 1) {
  ElectricSpark();
}
  //} else if (randFunction == 2) {
  //ElectricTrail(1);
  //} else {randFunction == 0;}
  FastLED.clear();
  delay(1000);

  TurnOnMotors();
  /*
  if (digitalRead(BUTTONPIN) == LOW) {
    while (test == 1) {
      if (analogRead(POTPIN) >= 500) {
        test = 0;
      }
    }
  }*/

  //test = 1;
}

void TurnOnMotors() {
  digitalWrite(IOTRELAY, HIGH);
  delay(delaySpeed);
  digitalWrite(IOTRELAY, LOW);
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
      }
      lowerBound = lowerBound + ledOffset;
      upperBound = upperBound + ledOffset;
    }
  }
}

void ElectricSpark() {
  int upperBound = 20;
  int lowerBound = 0;
  int randVal = 0;
  while (upperBound <= NUM_LEDS) {
    for (int y = lowerBound; y < upperBound; y++) {
      FastLED.setBrightness(random(BRIGHTNESS));
      randVal = random(3);
      if (randVal == 0) {
        leds[y] = CRGB::Yellow;
      } else if (randVal == 1) {
        leds[y] = CRGB(240, 234, 43);
      } else if (randVal == 2) {
        leds[y] = CRGB::Blue;
      }
    }
    upperBound = upperBound + 40;
    lowerBound = lowerBound + 40;
    FastLED.show();
  }
}

void ElectricScatter() {
  for (i = 0; i < NUM_LEDS; i++) {
    FastLED.setBrightness(random(BRIGHTNESS));
    randVal = random(3);
    if (randVal == 0) {
      leds[i] = CRGB::Yellow;
      leds[i + 1] = CRGB::Yellow;
    } else if (randVal == 1) {
      leds[i] = CRGB(240, 234, 43);
      leds[i + 1] = CRGB(240, 234, 43);
    } else if (randVal == 2) {
      leds[i] = CRGB::Blue;
      leds[i + 1] = CRGB::Blue;
    }
    i = i + 19;
    FastLED.show();
  }
}