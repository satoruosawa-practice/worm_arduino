#pragma once

#include "Arduino.h"
#include "global.h"

class Rotation {
 public:
  Rotation(int pin1, int pin2, int pin3);
  void update(int recieved_value);
  void sequence();

 private:
  int biometal_pin1_;
  int biometal_pin2_;
  int biometal_pin3_;
  int on_value_;
  int on_time_;
  int span_time_;
};

Rotation::Rotation(int pin1, int pin2, int pin3) {
  biometal_pin1_ = pin1;
  biometal_pin2_ = pin2;
  biometal_pin3_ = pin3;
  on_value_ = 255 - 25;
  on_time_ = 1500;
  span_time_ = 100;
}

void Rotation::update(int recieved_value) {
// on_value_ = 255 - map(recieved_value, 0, 9, 20, 150);
 span_time_ = map(recieved_value, 0, 9, 0, 1000);
}

void Rotation::sequence() {
  analogWrite(biometal_pin1_, on_value_);
  delay(on_time_);
  analogWrite(biometal_pin1_, OFF_VALUE);
  delay(span_time_);
  analogWrite(biometal_pin2_, on_value_);
  delay(on_time_);
  analogWrite(biometal_pin2_, OFF_VALUE);
  delay(span_time_);
  analogWrite(biometal_pin3_, on_value_);
  delay(on_time_);
  analogWrite(biometal_pin3_, OFF_VALUE);
  delay(span_time_);
}
