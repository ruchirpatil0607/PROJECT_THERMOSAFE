
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = 9;
const int ledPin = 8;
const float threshold = 25.0;

OneWire oneWire(sensorPin);
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  lcd.begin(16, 2);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...");
  
  sensors.begin();
  Serial.begin(9600);

  delay(1500);
  lcd.clear();
}

void loop() {
  sensors.requestTemperatures();

  float temperatureC = sensors.getTempCByIndex(0);

  if (temperatureC == DEVICE_DISCONNECTED_C) {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
    lcd.setCursor(0, 1);
    lcd.print("Check DS18B20   ");
    Serial.println("DS18B20 not detected");
    delay(1000);
    return;
  }

  bool highTemperature = temperatureC > threshold;

  digitalWrite(ledPin, highTemperature ? HIGH : LOW);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1);
  lcd.write((uint8_t)223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  if (highTemperature) {
    lcd.print("ALERT: HIGH TEMP");
  } else {
    lcd.print("Status: NORMAL  ");
  }

  Serial.print("Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.println(" C");

  delay(1000);
}
