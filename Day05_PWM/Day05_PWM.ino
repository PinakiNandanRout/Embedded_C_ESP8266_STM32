/*
 * Day 5: PWM LED Dimming
 * Board: ESP8266 NodeMCU
 * Pin: D2 = GPIO4
 * Logic: Fade LED from 0% to 100% and back
 */

#define LED_PIN D2   // GPIO4 = PWM pin

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Day 5: PWM Dimmer Started");
}

void loop() {
  // Fade IN: 0% to 100%
  for(int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(LED_PIN, brightness);
    Serial.print("Brightness: ");
    Serial.print(map(brightness, 0, 255, 0, 100));
    Serial.println(" %");
    delay(10); // Speed control
  }
  
  delay(500); // Hold at 100%
  
  // Fade OUT: 100% to 0%
  for(int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(LED_PIN, brightness);
    Serial.print("Brightness: ");
    Serial.print(map(brightness, 0, 255, 0, 100));
    Serial.println(" %");
    delay(10);
  }
  
  delay(500); // Hold at 0%
}