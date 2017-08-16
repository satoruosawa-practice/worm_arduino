#pragma once

#include "Arduino.h"
#include "global.h"

class CheckMotion {
 public:
  CheckMotion(int pin1, int pin2, int pin3);
  void update(int recieved_value);
  void sequence();

 private:
  int biometal_pin1_;
  int biometal_pin2_;
  int biometal_pin3_;
  int on_value_;
  int on_time_;
  int keep_time_;
  int keep_value_;
  int span_time_;

};

CheckMotion::CheckMotion(int pin1, int pin2, int pin3) {
  biometal_pin1_ = pin1;
  biometal_pin2_ = pin2;
  biometal_pin3_ = pin3;
  on_value_ = 255 - 10;
  on_time_ = 100;
//  keep_value_ = 235;
//  keep_time_ = 500;
  span_time_ = 2000;
}

void CheckMotion::update(int recieved_value) {
// on_value_ = 255 - map(recieved_value, 0, 9, 20, 150);
 on_time_ = map(recieved_value, 0, 9, 0, 10000);
}

void CheckMotion::sequence() {
  analogWrite(biometal_pin1_, on_value_);
  delay(on_time_);
//  analogWrite(biometal_pin1_, keep_value_);
//  delay(keep_time_);
  analogWrite(biometal_pin1_, OFF_VALUE);
  delay(span_time_);
}
