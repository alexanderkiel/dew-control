#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
 
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

int podiPin = A0;
int heaterPin = 3;
int podiValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  sensors.begin();

  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");
  
  Serial.print("Temperature for Device 1 is: ");
  Serial.println(sensors.getTempCByIndex(0));
  Serial.print("Temperature for Device 2 is: ");
  Serial.println(sensors.getTempCByIndex(1));
  Serial.println();
  
  podiValue = analogRead(podiPin);
  analogWrite(heaterPin, podiValue / 4);
  if (podiValue < 512) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  delay(100);
}
