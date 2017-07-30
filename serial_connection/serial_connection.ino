const int LED_PIN  = 11;

int INTENSITY = 01;

void setup() {
  // シリアル通信開始
  Serial.begin(9600);
  // ピンモード
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int recieved_value = 0;

  if (Serial.available() > 0) {
    inputSerial(recieved_value);
    INTENSITY = map(recieved_value, 0, 9, 0, 255);
    
  }

  analogWrite(LED_PIN, INTENSITY);
}

