#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C  // I2C address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1); // SDA=D2, SCL=D1 for ESP8266
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("OLED fail");
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15,10);
  display.println("Hello");
  display.setCursor(5,35);
  display.println("Honeywell");
  display.display();
  delay(3000);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("D9: I2C Protocol");
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);
  display.setCursor(0,15);
  display.println("SDA: GPIO4 / D2");
  display.setCursor(0,25);
  display.println("SCL: GPIO5 / D1");
  display.setCursor(0,50);
  display.print("Pinaki Nandan Rout");
  display.display();
  delay(2000);
}