#pragma once
#include "Arduino.h"
#include "global.h"

class Biometal {
 public:
  Biometal(int pin);
  void setup();
  void update(long delta);
  void setPwm(int value, long delta);
  void setDeg(int deg_target, long delta);
  long heatParam() { return heat_param_; }
  int pwm() { return pwm_; }

 protected:
  int pin_;
  long heat_param_;
  long heat_param_limit_;
  int pwm_;
  int pwm_keep_;
};

Biometal::Biometal(int pin) {
  pin_ = pin;
  heat_param_ = 0l;
  pwm_keep_ = 20;
  heat_param_limit_ = 70l * 1000l * long(255 - pwm_keep_);  // 70ms * max
  pwm_ = 0;
}

void Biometal::setup() {
  pinMode(pin_, OUTPUT);
  analogWrite(pin_, OFF_VALUE);
}

void Biometal::update(long delta) {
  heat_param_ += long(pwm_ - pwm_keep_) * delta;
  if (heat_param_ < 0) {
    heat_param_ = 0;
  }
}

void Biometal::setPwm(int value, long delta) {
  long estimate_heat_param = heat_param_ + long(value - pwm_keep_) * delta;
  if (estimate_heat_param > heat_param_limit_) {
    pwm_ = pwm_keep_;
  } else {
    pwm_ = value;
  }
  analogWrite(pin_, 255 - pwm_);
}

void Biometal::setDeg(int deg_target, long delta) {
  int deg = int(heat_param_ / (1000l * 255l));
  int deg_delta = deg_target - deg;
  int pwm = map(deg_delta, 5, 70, pwm_keep_, 550);
  pwm = constrain(pwm, 0, 255);
  setPwm(pwm, delta);
}
