#define SENSOR_PIN                  A0
#define SENSOR_OFFSET               360
#define SENSOR_MV_PER_DEGREES       9.5

#define LED_RED_PIN                 3
#define LED_GREEN_PIN               4
#define LED_BLUE_PIN                5

#define ADC_RESOLUTION              1024
#define MAX_MILIVOLTS               5000

const float VALUE_TO_MV = MAX_MILIVOLTS / ADC_RESOLUTION;

void setup(){
    Serial.begin(9600);
}

void loop(){
    int analog_value = analogRead(SENSOR_PIN);
    int value_in_mv = analog_value * VALUE_TO_MV;
    int temperature_celsius = (value_in_mv - SENSOR_OFFSET) / SENSOR_MV_PER_DEGREES;

    if (temperature_celsius < 18){
        digitalWrite(LED_BLUE_PIN, HIGH);
        digitalWrite(LED_GREEN_PIN, LOW);
        digitalWrite(LED_RED_PIN, LOW);
    } else if (temperature_celsius >= 18 && temperature_celsius < 30){
        digitalWrite(LED_BLUE_PIN, LOW);
        digitalWrite(LED_GREEN_PIN, HIGH);
        digitalWrite(LED_RED_PIN, LOW);
    } else {
        digitalWrite(LED_BLUE_PIN, LOW);
        digitalWrite(LED_GREEN_PIN, LOW);
        digitalWrite(LED_RED_PIN, HIGH);
    }

    Serial.print("Temperature in Celsius: ");
    Serial.println(temperature_celsius);

    delay(5000);
}