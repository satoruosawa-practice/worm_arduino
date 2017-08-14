#pragma once

#include "Arduino.h"
#include "global.h"

class onTimeOnce {
 public:
  onTimeOnce(int pin);
  void update(int recieved_value);
  void sequence();

 private:
  int biometal_pin_;
  int on_time_;
  int span_time_;
  bool onFlag_;
};

onTimeOnce::onTimeOnce(int pin) {
  biometal_pin_ = pin;
  on_time_ = 0;
  span_time_ = 2000;
  onFlag_ = false;
}

void onTimeOnce::update(int recieved_value) {
 onFlag_ = true;
 on_time_ = map(recieved_value, 0, 9, 0, 100);
}

void onTimeOnce::sequence() {
  if(onFlag_) {
    analogWrite(biometal_pin_, ON_VALUE);
    delay(on_time_);
    analogWrite(biometal_pin_, OFF_VALUE);
    delay(span_time_);
    onFlag_ = false;
  }
}
