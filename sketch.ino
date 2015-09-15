int podiPin = A0;
int podiValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  podiValue = analogRead(podiPin);
  Serial.println(podiValue);
  delay(100);
}
