#define LED_PIN D4    
#define LDR_PIN A0

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP8266 Night Lamp Started");
}

void loop() {
  int ldrValue = analogRead(A0);  // 0-1023 aayega
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  if(ldrValue > 300) {   // ESP32 me 500 , ESP8266 me 300
    digitalWrite(LED_PIN, HIGH); 
    Serial.println("Andhera! LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Roshni! LED OFF");
  }
  delay(100);
}
