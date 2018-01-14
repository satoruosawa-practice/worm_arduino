#pragma once
#include "Arduino.h"

class Ticker {
 public:
  Ticker();
  void reset();
  void update();
  long deltaMicros() {
    return is_micros_ - was_micros_;
  }
  long ellapsedMicros() {
    return is_micros_ - start_micros_;
  }
  long ellapsedMillis() {
    return (is_micros_ - start_micros_) / 1000l;
  }

 private:
  long start_micros_;
  long was_micros_;
  long is_micros_;
};

Ticker::Ticker() {
  start_micros_ = 0l;
  was_micros_ = 0l;
  is_micros_ = 0l;
}

void Ticker::reset() {
  start_micros_ = micros();
}

void Ticker::update() {
  was_micros_ = is_micros_;
  is_micros_ = micros();
}
