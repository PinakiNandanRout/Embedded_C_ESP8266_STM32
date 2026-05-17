// ===== PIN DEFINE KIYA - HARDWARE KAHAN LAGA HAI =====
#define LED_PIN D4 // LED ka + pin D4 me laga hai
#define LDR_PIN A0 // LDR ka signal A0 me aa raha hai

void setup() {
  // ===== SETUP - EK BAAR CHALTA HAI =====
  Serial.begin(115200); // Serial Monitor ON karo, 115200 speed pe
  pinMode(LED_PIN, OUTPUT); // D4 ko LED chalane ke liye OUTPUT banaya

  Serial.println("Day 7: Auto Night Lamp Started"); // Startup message
  Serial.println("LED brightness will change with room light"); // User ko instruction
}

void loop() {
  // ===== LOOP - BAAR BAAR CHALTA HAI =====

  // ===== LDR SE ROSHNI NAPO =====
  int ldrValue = analogRead(A0); // LDR se roshni napo. 0-1023 value milegi
                                          // Andhera = low value ~100, Roshni = high value ~900

  // ===== LDR KI VALUE KO LED KI BRIGHTNESS ME BADLO =====
  // Jab andhera ho [100] to LED full tez [255]
  // Jab roshni ho [900] to LED band [0]
  int brightness = map(ldrValue, 100, 900, 255, 0);

  // ===== SAFETY CHECK =====
  brightness = constrain(brightness, 0, 255); // 0 se kam ya 255 se zyada nahi hone dena

  // ===== LED CHALAO =====
  analogWrite(LED_PIN, brightness); // LED ko us brightness pe chala do

  // ===== SERIAL MONITOR PE VALUES DIKHAO =====
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  delay(100); // 100ms ruk ja. CPU ko thoda rest aur LDR ko stable hone ka time
}