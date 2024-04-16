
#include "OLEDModule.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initializeOLED() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Initialize with the I2C addr 0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);  // Don't proceed, loop forever
  }
  display.display();
  delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0,0);     // Start at top-left corner
}

void displaySensorData(float temperature, float dissolvedOxygen) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(F("Sensor Readings:"));
  display.print(F("Temp: "));
  display.print(temperature);
  display.println(F(" C"));
  display.print(F("DO: "));
  display.print(dissolvedOxygen);
  display.println(F(" mg/L"));
  display.display();  // Actually display all of the above
}
