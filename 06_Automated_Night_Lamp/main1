#define LED_PIN D4    
#define LDR_PIN A0

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Day 7: PWM Night Lamp Started");
}

void loop() {
  int ldrValue = analogRead(A0);  // 0-1023 aata hai
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  
  // LDR Value ko Brightness me convert karo
  // Andhera = LDR value kam = LED tez jalao
  // Roshni = LDR value zyada = LED dheemi
  
  int brightness = map(ldrValue, 100, 900, 255, 0);
  // 100-900 LDR range ko 255-0 brightness me badlo
  
  brightness = constrain(brightness, 0, 255); // 0-255 ke bahar na jaye
  
  analogWrite(LED_PIN, brightness); // PWM se LED chalao
  
  Serial.print(" | Brightness: ");
  Serial.println(brightness);
  
  delay(100);
}
