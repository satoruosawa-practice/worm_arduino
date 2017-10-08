const int RELAY_PIN = 9;
const int BIOMETAL_PIN1 = 5;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BIOMETAL_PIN1, OUTPUT);

//  TCCR0B &= B11111000;
//  TCCR0B |= B00000010;

  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  int value = 255;
  analogWrite(BIOMETAL_PIN1, 255 - value);
  delay(70);
  value = 25;
  analogWrite(BIOMETAL_PIN1, 255 - value);
  delay(60000);
  value = 0;
  analogWrite(BIOMETAL_PIN1, 255 - value);
  delay(5000);
}


