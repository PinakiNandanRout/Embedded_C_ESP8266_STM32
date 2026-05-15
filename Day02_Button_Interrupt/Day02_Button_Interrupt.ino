/*
 * Day 2: ESP8266 Button Interrupt + Debounce
 * Board: NodeMCU ESP8266
 * Button: FLASH button = GPIO0, Active LOW
 * LED: Onboard LED = GPIO2, Active LOW
 * Concept: External Interrupt + Software Debounce
 */

#define LED_PIN 2 // GPIO2 = Onboard LED
#define BUTTON_PIN 0 // GPIO0 = FLASH button

// volatile = ISR aur loop dono use karte, compiler optimize na kare
volatile bool ledState = HIGH; // LED OFF initially, Active Low
volatile unsigned long lastInterruptTime = 0; // Debounce ke liye

// IRAM_ATTR = ISR ko RAM me rakho, Flash se slow nahi chalega
void IRAM_ATTR handleButtonPress() {
  unsigned long interruptTime = millis();

  // Debounce: 200ms ke andar dubara interrupt ignore karo
  if (interruptTime - lastInterruptTime > 200) {
    ledState =!ledState; // LED toggle
    lastInterruptTime = interruptTime;
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("\nDay 2 Start: Button Interrupt 🔥");

  // LED Output setup
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);

  // Button Input setup - PULLUP kyunki button GND se connect hota
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Interrupt attach karo: Button pin, ISR function, FALLING edge
  // FALLING = HIGH se LOW jane pe trigger, button dabate hi
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);

  Serial.println("Setup Done: FLASH button dabao, LED toggle hoga");
  Serial.println("B.Tech ECE: 8051 INT0 ka ESP8266 version 💪");
}

void loop() {
  // Loop me kuch nahi karna. Sab kaam Interrupt karega
  // Bas LED ki state update karte raho
  digitalWrite(LED_PIN, ledState);

  // Debug ke liye 1 sec me print
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    Serial.print("Loop chal raha... LED State: ");
    Serial.println(ledState == LOW? "ON" : "OFF");
    lastPrint = millis();
  }
}