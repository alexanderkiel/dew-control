int podiPin = A0;
int heaterPin = 3;
int podiValue = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  podiValue = analogRead(podiPin);
  analogWrite(heaterPin, podiValue / 4);
  if (podiValue < 512) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  delay(100);
}
