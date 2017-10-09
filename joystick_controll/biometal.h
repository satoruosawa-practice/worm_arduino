#include "Arduino.h"
#include "global.h"
#pragma once

class Biometal {
 public:
  Biometal(int pin);
  void setupBio();
  void updateBio(long diff);
  void setPwm(int value, long last_diff);
  void setDeg(int deg_target, long last_diff);
  long heatParam() {
    return heat_param_;
  }
  int pwm() {
    return pwm_;
  }

 private:
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
  heat_param_limit_ = 70l * 1000l * long(255 - pwm_keep_);
  pwm_ = 0;
}

void Biometal::setupBio() {
  pinMode(pin_, OUTPUT);
  analogWrite(pin_, OFF_VALUE);
}

void Biometal::updateBio(long diff) {
  heat_param_ += long(pwm_ - pwm_keep_) * diff;
  if (heat_param_ < 0) {
    heat_param_ = 0;
  }
}

void Biometal::setPwm(int value, long last_diff) {
  long estimate_heat_param = heat_param_ + long(value - pwm_keep_) * last_diff;
  if (estimate_heat_param > heat_param_limit_) {
    pwm_ = pwm_keep_;
  } else {
    pwm_ = value;
  }
  analogWrite(pin_, 255 - pwm_);
}

void Biometal::setDeg(int deg_target, long last_diff) {
  int deg = int(heat_param_ / (1000l * 255l));
  int deg_diff = deg_target - deg;
  int pwm = map(deg_diff, 5, 70, pwm_keep_, 550);
  pwm = constrain(int(pwm), 0, 255);
  setPwm(pwm, last_diff);
}



