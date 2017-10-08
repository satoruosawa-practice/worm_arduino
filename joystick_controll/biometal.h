#include "Arduino.h"
#pragma once

class Biometal {
 public:
  Biometal();
  void setupBio();
  void updateBio(long diff);
  void set(int value, long last_diff);
  long heatParam() {
    return heat_param_;
  }
  int pwm() {
    return pwm_;
  }
 
 private:
  long heat_param_;
  long heat_param_limit_;
  int pwm_;
  int pwm_keep_;
};

Biometal::Biometal() {
  heat_param_ = 0l;
  heat_param_limit_ = 70l * 1000l * 255l;
  pwm_keep_ = 20;
  pwm_ = 0;
}

void Biometal::setupBio() {
  
}


void Biometal::updateBio(long diff) {
  heat_param_ += long(pwm_ - pwm_keep_) * diff;
  if(heat_param_ < 0) {
    heat_param_ = 0;
  }
}

void Biometal::set(int value, long last_diff) {
  long estimate_heat_param = heat_param_ + long(value - pwm_keep_) * last_diff;
  if(estimate_heat_param > heat_param_limit_) {
    pwm_ = pwm_keep_;
  } else {
    pwm_ = value;
  }
}

