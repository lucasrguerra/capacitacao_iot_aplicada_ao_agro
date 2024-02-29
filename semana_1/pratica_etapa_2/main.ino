#include <Adafruit_NeoPixel.h>


#define SWITCH_PIN			13
#define LED_COLUMN_0_PIN	9
#define LED_COLUMN_1_PIN	8
#define LED_COLUMN_2_PIN	7
#define LED_COLUMN_3_PIN	6
#define LED_COLUMN_4_PIN	5
#define LED_COLUMN_5_PIN	4
#define LED_COLUMN_6_PIN	3
#define LED_COLUMN_7_PIN	2
#define LEDS_PER_COLUMN		8
#define NUMBER_OF_COLUMNS	8


typedef struct RGB_LED_t {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} RGB_LED;


Adafruit_NeoPixel column_0 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_0_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_1 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_2 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_3 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_3_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_4 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_4_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_5 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_5_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_6 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_6_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel column_7 = Adafruit_NeoPixel(LEDS_PER_COLUMN, LED_COLUMN_7_PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel led_panel[NUMBER_OF_COLUMNS] = {
  column_0,
  column_1,
  column_2,
  column_3,
  column_4,
  column_5,
  column_6,
  column_7
};


void setPixel2D(uint8_t x, uint8_t y, RGB_LED color);
void drawLadder(RGB_LED color);


void setup() {
  for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++) {
    led_panel[i].begin();
  }
}


void loop() {
  bool switch_state = digitalRead(SWITCH_PIN);
  if (switch_state) {
    drawLadder({0, 255, 0});
  } else {
    drawLadder({255, 0, 0});
  }
  delay(100);
}


void setPixel2D(uint8_t x, uint8_t y, RGB_LED color) {
  if (x < NUMBER_OF_COLUMNS && y < LEDS_PER_COLUMN) {
    led_panel[x].setPixelColor(y, color.red, color.green, color.blue);
    led_panel[x].show();
  }
}


void drawLadder(RGB_LED color) {
  for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++) {
    for (uint8_t j = 0; j <= i; j++) {
      setPixel2D(i, j, color);
    }
  }
}
