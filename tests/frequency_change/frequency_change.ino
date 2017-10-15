const int RELAY_PIN = 9;
const int BIOMETAL_PIN1 = 3;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BIOMETAL_PIN1, OUTPUT);
  Serial.begin(115200);

  Serial.println("defult:");
  Serial.println(TCCR2A, BIN);
  Serial.println(TCCR2B, BIN);
  Serial.println(OCR2A, BIN);
  Serial.println(OCR2B, BIN);

  TCCR2B &= B11110111;
  TCCR2B |= B00001000;  // WGM22, 21, 20 = 101
  analogWrite(BIOMETAL_PIN1, 255);

  delay(1000);
  digitalWrite(RELAY_PIN, HIGH);
}

int span = 500;

void loop() {
  float value;
  span /= 2;
  value = 0.1;
  setFrequency2(262l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(277l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(294l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(311l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(330l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(349l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(370l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(392l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(415l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(440l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(466l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(494l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);
  setFrequency2(523l);
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(span);

  value = 0.0;
  analogWrite(BIOMETAL_PIN1, getPWM2(value));
  delay(5000);
}

