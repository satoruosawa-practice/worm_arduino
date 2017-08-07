#pragma once

#include "Arduino.h"
#include "global.h"

class Quick {
 public:
  Quick(int pin);
  void update(int recieved_value);
  void sequence();

 private:
  int biometal_pin_;
  int on_time_;
  int span_time_;
};

Quick::Quick(int pin) {
  biometal_pin_ = pin;
  on_time_ = 0;
  span_time_ = 10;
}

void Quick::update(int recieved_value) {
  on_time_ = map(recieved_value, 0, 9, 0, 40);
  span_time_ = map(recieved_value, 0, 9, 10, 1000);
}

void Quick::sequence() {
  analogWrite(biometal_pin_, ON_VALUE);
  delay(on_time_);
  analogWrite(biometal_pin_, OFF_VALUE);
  delay(span_time_);
}

