// ===== PIN DEFINE KIYA - HARDWARE KAHAN LAGA HAI =====
#define LED_PIN D4      // LED ka + pin D4 me laga hai
#define LDR_PIN A0      // LDR ka signal A0 me aa raha hai  
#define BUTTON_PIN D2   // Button ka ek pair D2 me, dusra GND me

// ===== LAMP KA DIMAAG - STATE VARIABLES =====
bool manualMode = false;        // false = Auto mode, true = Manual mode. Shuru me Auto
bool lastButtonState = HIGH;    // Button ka purana state yaad rakhne ke liye. Pullup hai to HIGH
int manualBrightness = 255;     // Manual mode me LED kitni tez jalegi. 255 = full tez

void setup() {
  // ===== SETUP - EK BAAR CHALTA HAI =====
  Serial.begin(115200);           // Serial Monitor ON karo, 115200 speed pe
  pinMode(LED_PIN, OUTPUT);       // D4 ko LED chalane ke liye OUTPUT banaya
  pinMode(BUTTON_PIN, INPUT_PULLUP); // D2 ko button padhne ke liye INPUT banaya + andar hi resistor ON kar diya
  
  Serial.println("Day 8: Auto + Manual Night Lamp Started"); // Startup message
  Serial.println("Press button to toggle Auto/Manual mode"); // User ko instruction
}

void loop() {
  // ===== LOOP - BAAR BAAR CHALTA HAI =====
  
  // ===== PART 1: BUTTON CHECK KARO AUR MODE BADLO =====
  bool buttonState = digitalRead(BUTTON_PIN); // Button abhi dabaya ya nahi? LOW = dabaya, HIGH = nahi
  
  // Check: Button "abhi" dabaya aur "pehle" nahi dabaya tha = Naya press
  if (buttonState == LOW && lastButtonState == HIGH) { 
    manualMode = !manualMode;     // Mode ko palat do. Auto tha to Manual, Manual tha to Auto
    delay(200);                   // 200ms ruk ja. Button ka jhatka/chatter ignore karne ke liye
    
    // User ko batana ki mode badal gaya
    if (manualMode) {
      Serial.println("MANUAL MODE ON - LED Full Bright"); // Manual mode me aa gaye
    } else {
      Serial.println("AUTO MODE ON - LDR Control");       // Wapas Auto me aa gaye
    }
  }
  lastButtonState = buttonState;  // Aaj ka state kal ke liye "last" bana do
  
  // ===== PART 2: MODE KE HISAB SE LED CHALAO =====
  if (manualMode) {
    // MANUAL MODE KA CODE: LDR ko ignore karo, LED full chalao
    analogWrite(LED_PIN, manualBrightness); // LED ko 255 pe chala do = full bright
    
  } else {
    // AUTO MODE KA CODE: Day 7 wala LDR ka logic
    int ldrValue = analogRead(A0);          // LDR se roshni napo. 0-1023 value milegi
    
    // LDR ki value ko LED ki brightness me badlo. Andhera=100=255, Roshni=900=0
    int brightness = map(ldrValue, 100, 900, 255, 0); 
    
    brightness = constrain(brightness, 0, 255); // Safety: 0 se kam ya 255 se zyada nahi hone dena
    analogWrite(LED_PIN, brightness);           // LED ko us brightness pe chala do
    
    // Serial Monitor pe values dikhao debug ke liye
    Serial.print("LDR: ");
    Serial.print(ldrValue);
    Serial.print(" | Auto Brightness: ");
    Serial.println(brightness);
  }
  
  delay(100); // 100ms ruk ja. CPU ko thoda rest aur LDR ko stable hone ka time
}