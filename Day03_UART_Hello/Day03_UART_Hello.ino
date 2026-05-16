// DAY 3: UART COMMUNICATION 🔥
// Goal: ESP8266 se laptop pe message bhejna
// ETC wale ke liye: Ye 8051 ka SBUF + SCON ka upgrade hai

void setup() {
  // UART shuru karo. Baud rate = 115200
  // 8051 me 9600 tha. ESP me tez chahiye
  Serial.begin(115200);  
  delay(2000); // ESP8266 ko 2 sec saans lene de
  
  Serial.println(""); // Khali line
  Serial.println("=== DAY 3 UART START ===");
  Serial.println("ETC 2026 ROCKS 🔥");
  Serial.println("Name: Embedded Ka King");
  Serial.println("Branch: ETC");
  Serial.println("Mission: 6-8 LPA Job");
  Serial.println("=========================");
}

void loop() {
  // Har 3 sec me time print karo
  Serial.print("System ON time: ");
  Serial.print(millis() / 1000);  // millis() = ESP kitni der se chalu
  Serial.println(" seconds");
  
  delay(3000); // 3 sec ruk ja
}