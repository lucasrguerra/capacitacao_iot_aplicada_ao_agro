#define PULL_DOWN_PIN				3
#define PULL_UP_PIN					4

void setup(){
	Serial.begin(9600);
}

void loop(){
	bool pull_down_state = digitalRead(PULL_DOWN_PIN);
	bool pull_upn_state = digitalRead(PULL_UP_PIN);

	Serial.print("Pull Down Button: ");
	Serial.print(pull_down_state);
	Serial.print("  /  Pull Up Button: ");
	Serial.println(pull_upn_state);

	delay(50);
}