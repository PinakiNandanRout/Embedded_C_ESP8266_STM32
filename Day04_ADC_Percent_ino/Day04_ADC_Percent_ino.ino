// DAY 4: ADC - ANALOG TO DIGITAL CONVERTER 🔥
// Goal: Potentiometer ghumao, voltage laptop pe dekho
// ETC 2026: Real sensor ka base

const int potPin = A0;  // A0 = Analog pin

void setup() {
  Serial.begin(115200);  // UART chalu
  delay(1000);
  Serial.println("=== DAY 4 ADC START ===");
  Serial.println("Potentiometer ghumao aur value dekho");
  Serial.println("ESP8266 ADC = 10 bit = 0 to 1023");
}

void loop() {
  // Step 1: Analog value padho - 0 to 1023 aayega
  int adcValue = analogRead(potPin);  
  //int percent = map(adcValue, 0, 1023, 0, 100);// for adc value 0 to 100
  
  // Step 2: Voltage me convert karo - 0 to 3.3V
  float voltage = adcValue * (3.3 / 1023.0); 
  
  // Step 3: Serial Monitor pe bhejo
  Serial.print("ADC Value: ");
  Serial.print(adcValue);
  Serial.print("  |  Voltage: ");
  Serial.print(voltage, 2);  // 2 decimal tak
  Serial.println(" V");
  
  delay(500); // 0.5 sec me ek baar update
}