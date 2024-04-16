#include "main.h"

unsigned long previousMillis = 0;
const long interval = 1000;  // Interval to read sensor data in milliseconds

void setup() {
  Serial.begin(9600);
  initializeSystem();
}


void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // SensorData data = readSensorData();
    // DateTime now = getCurrentDateTime();
    
    // saveDataToSDCard(data, now);
    // sendDataToThingSpeak(data);
    float dissolvedOxygen = random(0, 10);
    float temperature = random(0, 10);
    displaySensorData(temperature, dissolvedOxygen);
  }
}

void initializeSystem() {
  initializeOLED();
}
