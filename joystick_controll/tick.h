#include "Arduino.h"
#pragma once

class Tick {
 public:
  Tick();
  void setupTick();
  void updateTick();
  long diffMicros() {
    return is_micros_ - was_micros_;
  }
  long ellapsedMicros() {
    return is_micros_ - start_micros_;
  }

 private:
  long start_micros_;
  long was_micros_;
  long is_micros_;
};

Tick::Tick() {
  start_micros_ = 0l;
  was_micros_ = 0l;
  is_micros_ = 0l;
}

void Tick::setupTick() {
    start_micros_ = micros();
}

void Tick::updateTick() {
  was_micros_ = is_micros_;
  is_micros_ = micros();
}
