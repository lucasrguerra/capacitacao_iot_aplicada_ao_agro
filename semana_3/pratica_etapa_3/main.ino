#define LED_PIN						4
#define BUTTON_PIN					3

volatile bool led_state = false;
volatile int change_counter = 0;

void button_pressed();

void setup() {
	Serial.begin(9600);
	pinMode(BUTTON_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_pressed, RISING);
}

void loop() {
	Serial.println(change_counter);

	delay(5000);
}

void button_pressed() {
	led_state = !led_state;
	change_counter++;

	digitalWrite(LED_PIN, led_state);
}