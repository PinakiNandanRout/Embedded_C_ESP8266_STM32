// DAY 4: ADC to Percent using map() 🔥
// Goal: 0-1023 ko 0-100% me badlo
// ETC 2026: Real sensor data ban gaya

const int potPin = A0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("DAY 4: ADC Percent Mode ON");
  Serial.println("Pot ghumao = 0% se 100%");
}

void loop() {
  int adcValue = analogRead(potPin);  // 0 se 1023 aayega
  
  // YAHI HAI WO LINE JO TU CHAHTA THA 👇
  int percent = map(adcValue, 0, 1023, 0, 100);  // 0-1023 ko 0-100 me
  
  float voltage = adcValue * (3.3 / 1023.0);  // Voltage bhi nikal le
  
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print("  |  Volt: ");
  Serial.print(voltage, 2);
  Serial.print("V  |  Level: ");
  Serial.print(percent);
  Serial.println("%");
  
  delay(300);
}