#define LDR_PIN                     A0
#define LED_1_PIN                   3
#define LED_2_PIN                   4
#define LED_3_PIN                   5
#define LED_4_PIN                   6
#define LED_5_PIN                   7

void setup() {
    Serial.begin(9600);
}

void loop() {
    int ldrValue = analogRead(LDR_PIN);

    if (ldrValue < 100) {
        digitalWrite(LED_1_PIN, HIGH);
        digitalWrite(LED_2_PIN, HIGH);
        digitalWrite(LED_3_PIN, HIGH);
        digitalWrite(LED_4_PIN, HIGH);
        digitalWrite(LED_5_PIN, HIGH);
    } else if (ldrValue < 150) {
        digitalWrite(LED_1_PIN, HIGH);
        digitalWrite(LED_2_PIN, HIGH);
        digitalWrite(LED_3_PIN, HIGH);
        digitalWrite(LED_4_PIN, HIGH);
        digitalWrite(LED_5_PIN, LOW);
    } else if (ldrValue < 250) {
        digitalWrite(LED_1_PIN, HIGH);
        digitalWrite(LED_2_PIN, HIGH);
        digitalWrite(LED_3_PIN, HIGH);
        digitalWrite(LED_4_PIN, LOW);
        digitalWrite(LED_5_PIN, LOW);
    } else if (ldrValue < 350) {
        digitalWrite(LED_1_PIN, HIGH);
        digitalWrite(LED_2_PIN, HIGH);
        digitalWrite(LED_3_PIN, LOW);
        digitalWrite(LED_4_PIN, LOW);
        digitalWrite(LED_5_PIN, LOW);
    } else if (ldrValue < 450) {
        digitalWrite(LED_1_PIN, HIGH);
        digitalWrite(LED_2_PIN, LOW);
        digitalWrite(LED_3_PIN, LOW);
        digitalWrite(LED_4_PIN, LOW);
        digitalWrite(LED_5_PIN, LOW);
    } else {
        digitalWrite(LED_1_PIN, LOW);
        digitalWrite(LED_2_PIN, LOW);
        digitalWrite(LED_3_PIN, LOW);
        digitalWrite(LED_4_PIN, LOW);
        digitalWrite(LED_5_PIN, LOW);
    }

    Serial.println("LDR Value: " + String(ldrValue));

    delay(100);
}