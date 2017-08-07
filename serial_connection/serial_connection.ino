#include "global.h"
#include "quick.h"
#include "keep.h"

const int BIOMETAL_PIN  = 5;

Quick QUICK = Quick(BIOMETAL_PIN);
Keep KEEP = Keep(BIOMETAL_PIN);

void setup() {
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
//    KEEP.update(recieved_value);
  }
}

void loop() {
  updateMain();
  QUICK.sequence();
//  KEEP.sequence();
}

