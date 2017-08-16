#include "global.h"
#include "checkMotion.h"
#include "rotation.h"

const int BIOMETAL_PIN1 = 5;
const int BIOMETAL_PIN2 = 6;
const int BIOMETAL_PIN3 = 3;

CheckMotion CHECK_MOTION = CheckMotion(BIOMETAL_PIN1, BIOMETAL_PIN2, BIOMETAL_PIN3);
Rotation ROTATION = Rotation(BIOMETAL_PIN1, BIOMETAL_PIN2, BIOMETAL_PIN3);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BIOMETAL_PIN1, OUTPUT);
  pinMode(BIOMETAL_PIN2, OUTPUT);
  pinMode(BIOMETAL_PIN3, OUTPUT);
  analogWrite(BIOMETAL_PIN1, OFF_VALUE);  
  analogWrite(BIOMETAL_PIN2, OFF_VALUE);  
  analogWrite(BIOMETAL_PIN3, OFF_VALUE);  

  delay(50);
  analogWrite(RELAY_PIN, 255);
  delay(100);
}

void updateMain() {
  if (Serial.available() > 0) {
    int recieved_value = inputSerial();
//    CHECK_MOTION.update(recieved_value);
    ROTATION.update(recieved_value);
  }
}

void loop() {
  updateMain();
//  CHECK_MOTION.sequence();
  ROTATION.sequence();
}

