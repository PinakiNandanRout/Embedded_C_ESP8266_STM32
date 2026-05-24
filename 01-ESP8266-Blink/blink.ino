
void setup() {
  pinMode(2, OUTPUT);  // ESP8266 ka onboard LED pin 2 pe hai
  Serial.begin(115200); // Serial monitor chalu
}

void loop() {
  digitalWrite(2, LOW);   // LED ON - Pin 2 LOW pe on hota
  Serial.println("LED ON");
  delay(1000);            // 1 sec ruko
  
  digitalWrite(2, HIGH);  // LED OFF
  Serial.println("LED OFF");
  delay(1000);            // 1 sec ruko
}
