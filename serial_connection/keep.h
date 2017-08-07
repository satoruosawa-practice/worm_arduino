#pragma once

#include "Arduino.h"
#include "global.h"

class Keep {
 public:
  Keep(int pin);
  void update(int recieved_value);
  void sequence();

 private:
  int biometal_pin_;
  int on_time_;
  int keep_time_;
  int keep_value_;
  int span_time_;

};

Keep::Keep(int pin) {
  biometal_pin_ = pin;
  on_time_ = 30;
  keep_time_ = 0;
  keep_value_ = 240;
  span_time_ = 2000;
}

void Keep::update(int recieved_value) {
 keep_time_ = map(recieved_value, 0, 9, 0, 1000);
}

void Keep::sequence() {
  analogWrite(biometal_pin_, ON_VALUE);
  delay(on_time_);
  analogWrite(biometal_pin_, keep_value_);
  delay(keep_time_);
  analogWrite(biometal_pin_, OFF_VALUE);
  delay(span_time_);
}
