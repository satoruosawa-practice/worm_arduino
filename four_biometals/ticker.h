#pragma once
#include "Arduino.h"

class Ticker {
 public:
  Ticker();
  void setupTicker();
  void updateTicker();
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

void Ticker::setupTicker() {
  start_micros_ = micros();
}

void Ticker::updateTicker() {
  was_micros_ = is_micros_;
  is_micros_ = micros();
}
