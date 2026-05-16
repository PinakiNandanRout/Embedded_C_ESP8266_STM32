/*
 * Day 4 + 5 Combo: Potentiometer se LED Brightness Control
 * Board: ESP8266 NodeMCU
 * Logic: Pot ghumao = ADC read = PWM write = LED dim/bright
 */

#define POT_PIN A0    // Day 4: ADC Input pin
#define LED_PIN D2    // Day 5: PWM Output pin

void setup() {
  pinMode(LED_PIN, OUTPUT);   // LED pin ko OUTPUT banao
  Serial.begin(115200);       // Serial Monitor chalu karo
  Serial.println("Day 4+5 Combo: Pot + PWM Ready!");
}

void loop() {
  // STEP 1: DAY 4 KA KAAM - Pot se value padho
  int potValue = analogRead(POT_PIN);   // 0 se 1023 tak value aayegi
  
  // STEP 2: CONVERSION - ADC ko PWM me badlo
  // map(value, fromLow, fromHigh, toLow, toHigh)
  int brightness = map(potValue, 0, 1023, 0, 255);  // 1023→255 convert // map use for convert one unit to another
  
  // STEP 3: DAY 5 KA KAAM - LED pe brightness likho
  analogWrite(LED_PIN, brightness);     // 0=OFF, 255=Full ON
  
  // STEP 4: DEBUGGING - Serial pe print karo
  int potPercent = map(potValue, 0, 1023, 0, 100);      // Pot kitna %
  int ledPercent = map(brightness, 0, 255, 0, 100);     // LED kitna %
  
  Serial.print("Pot: ");
  Serial.print(potPercent);
  Serial.print("%  |  LED: ");
  Serial.print(ledPercent);
  Serial.println("%");
  
  delay(50);  // 50ms ka gap, nahi to Serial spam ho jayega
}