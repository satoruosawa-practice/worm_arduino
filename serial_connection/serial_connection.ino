#include "quick.h"
#include "global.h"

const int BIOMETAL_PIN  = 5;

Quick QUICK = Quick(BIOMETAL_PIN);

void setup() {
  // シリアル通信開始
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BIOMETAL_PIN, OUTPUT);

  analogWrite(BIOMETAL_PIN, OFF_VALUE);  
  delay(50);
  analogWrite(RELAY_PIN, 255);
  delay(100);
}

void updateMain() {
  if (Serial.available() > 0) {
    int recieved_value = inputSerial();
    QUICK.update(recieved_value);
  }
}

void loop() {
  updateMain();
//  if (Serial.available() > 0) {
//    int recieved_value = inputSerial();
//    keep(recieved_value);
//  }
  QUICK.sequence();
}


