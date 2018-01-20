#pragma once
#include "Arduino.h"
#include "global.h"
#include "biometal.h"

class SoundBiometalUno : public Biometal {
 public:
  SoundBiometalUno(int pin) : Biometal(pin) {
  }
  void setDeg(int deg_target, long delta);
  void setFreq(long freq);
  void setPwm(int value, long delta);
};

void SoundBiometalUno::setDeg(int deg_target, long delta) {
  int deg = int(heat_param_ / (1000l * 255l));
  int deg_delta = deg_target - deg;
  int pwm = map(deg_delta, 5, 70, pwm_keep_, 550);
  pwm = constrain(pwm, 0, 255);
  setPwm(pwm, delta);
}

void SoundBiometalUno::setPwm(int value, long delta) {
  long estimate_heat_param = heat_param_ + long(value - pwm_keep_) * delta;
  if (estimate_heat_param > heat_param_limit_) {
    pwm_ = pwm_keep_;
  } else {
    pwm_ = value;
  }
  if (pin_ == 3) {
    unsigned int max_value = OCR2A;
    unsigned int out = max_value - (unsigned int)((float)max_value * (float)pwm_ / 255.0f);
    analogWrite(pin_, out);
  } else if (pin_ == 10) {
    unsigned int max_value = OCR1A;
    unsigned int out = max_value - (unsigned int)((float)max_value * (float)pwm_ / 255.0f);
    analogWrite(pin_, out);
  } 
}

void SoundBiometalUno::setFreq(long freq) {
  if (pin_ == 3) {
    long value = 8000000l / freq;
    if(value < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000001;
      OCR2A = (unsigned int)(value);
    } else if (value / 8l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000010;
      OCR2A = (unsigned int)(value / 8l);
    } else if (value / 32l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000011;
      OCR2A = (unsigned int)(value / 32l);
    } else if (value / 64l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000100;
      OCR2A = (unsigned int)(value / 64l);
    } else if (value / 128l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000101;
      OCR2A = (unsigned int)(value / 128l);
    } else if (value / 256l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000110;
      OCR2A = (unsigned int)(value / 256l);
    } else if (value / 1024l < 256l) {
      TCCR2B &= B11111000;
      TCCR2B |= B00000111;
      OCR2A = (unsigned int)(value / 1024l);
    }
  } else if (pin_ == 10) {
    long value = 8000000l / freq;
    if(value < 65535l) {
      TCCR1B &= B11111000;
      TCCR1B |= B00000001;
      OCR1A = (unsigned int)(value);
    } else if (value / 8l < 65535l) {
      TCCR1B &= B11111000;
      TCCR1B |= B00000010;
      OCR1A = (unsigned int)(value / 8l);
    } else if (value / 64l < 65535l) {
      TCCR1B &= B11111000;
      TCCR1B |= B00000011;
      OCR1A = (unsigned int)(value / 64l);
    } else if (value / 256l < 65535l) {
      TCCR1B &= B11111000;
      TCCR1B |= B00000100;
      OCR1A = (unsigned int)(value / 256l);
    } else if (value / 1024l < 65535l) {
      TCCR1B &= B11111000;
      TCCR1B |= B00000101;
      OCR1A = (unsigned int)(value / 1024l);
    }
  }
}
