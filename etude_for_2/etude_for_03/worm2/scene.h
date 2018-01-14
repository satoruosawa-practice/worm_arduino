#pragma once
#include "Arduino.h"
#include "global.h"
#include "ticker.h"
#include "biometal.h"
#include "biometalContainer.h"

class Scene {
 public:
  Scene(Ticker &ticker, BiometalContainer &biometals);
  void sequence();
  void reset();

 private:
  void setBio(int index, int value) {
    biometals_->get(index)->setDeg(value, ticker_->deltaMicros());
  }
  void setBioFreq(int index, long freq, int value) {
    Biometal * bio = biometals_->get(index);
    ((SoundBiometalUno *)(bio))->setFreq(freq);
    ((SoundBiometalUno *)(bio))->setDeg(value, ticker_->deltaMicros());
  }
  BiometalContainer * biometals_;
  Ticker * ticker_;
  int * sequence_no_;
};

Scene::Scene(Ticker &ticker, BiometalContainer &biometals) {
  ticker_ = &ticker;
  biometals_ = &biometals;
  sequence_no_ = new int[biometals_->size()];
  this->reset();
}

void Scene::reset() {
  for (int i = 0; i < biometals_->size(); i++) {
    sequence_no_ [i] = 0;
  }
}

void Scene::sequence() {
  long now = ticker_->ellapsedMillis();
  // tempo 75 = 800ms
  // 5/4 = 4000ms


  //     long t = constrain(now - 11200l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //      setBioFreq(0, 370l, value);
  //      if (now > 12000l) { sequence_no_[0]++; }
  //      break;

  // 0
  switch (sequence_no_[0]) {
    case 0: {
      long t = constrain(now - 900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 1000l) { sequence_no_[0]++; }
      break;
    } case 1: {
      long t = constrain(now - 1900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 2000l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 3400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 3500l) { sequence_no_[0]++; }
      break;
    } case 3: {
      long t = constrain(now - 3900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 4000l) { sequence_no_[0]++; }
      break;
    } case 4: {
      long t = constrain(now - 5900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 6000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 6400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 6500l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 6900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 7000l) { sequence_no_[0]++; }
      break;
    } case 7: {
      long t = constrain(now - 7900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 9400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 9500l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 10900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 11000l) { sequence_no_[0]++; }
      break;
    } case 10: {
      long t = constrain(now - 11900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 12067l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 12167l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 12233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 262l, 30 - value);
      if (now > 12333l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 12400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 208l, 30 - value);
      if (now > 12500l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 13900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 14000l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 14400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 14500l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 15900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 16000l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 16400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 16500l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 17900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 18000l) { sequence_no_[0]++; }
      break;
    } case 19: {
      long t = constrain(now - 18150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 18250l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 18400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 18500l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 18650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 262l, 30 - value);
      if (now > 18750l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 18900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 19000l) { sequence_no_[0]++; }
      break;
    } case 23: {
      long t = constrain(now - 19150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 19250l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 19400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 19500l) { sequence_no_[0]++; }
      break;
    } case 25: {
      long t = constrain(now - 19900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 20900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 21000l) { sequence_no_[0]++; }
      break;
    } case 27: {
      long t = constrain(now - 21900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 22000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 22900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 23000l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 23900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 24400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 262l, 30 - value);
      if (now > 24500l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 24900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 25000l) { sequence_no_[0]++; }
      break;
    } case 32: {
      long t = constrain(now - 25150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 25250l) { sequence_no_[0]++; }
      break;
    } case 33: {
      long t = constrain(now - 25400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 25500l) { sequence_no_[0]++; }
      break;
    } case 34: {
      long t = constrain(now - 26400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 26500l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 27900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1397l, 30 - value);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    } case 36: {
      long t = constrain(now - 28900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 29000l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 29233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 29333l) { sequence_no_[0]++; }
      break;
    } case 38: {
      long t = constrain(now - 29567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 29667l) { sequence_no_[0]++; }
      break;
    } case 39: {
      long t = constrain(now - 29900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 30000l) { sequence_no_[0]++; }
      break;
    } case 40: {
      long t = constrain(now - 30900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 31000l) { sequence_no_[0]++; }
      break;
    } case 41: {
      long t = constrain(now - 31400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 31500l) { sequence_no_[0]++; }
      break;
    } case 42: {
      long t = constrain(now - 31567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 31667l) { sequence_no_[0]++; }
      break;
    } case 43: {
      long t = constrain(now - 31733l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 31833l) { sequence_no_[0]++; }
      break;
    } case 44: {
      long t = constrain(now - 31900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 32000l) { sequence_no_[0]++; }
      break;
    } case 45: {
      long t = constrain(now - 33900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 34000l) { sequence_no_[0]++; }
      break;
    } case 46: {
      long t = constrain(now - 34400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 34500l) { sequence_no_[0]++; }
      break;
    } case 47: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }
     // 1
     switch (sequence_no_[1]) {
       case 0: {
         long t = constrain(now - 400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 185l, 30 - value);
         if (now > 500l) { sequence_no_[1]++; }
         break;
       } case 1: {
         long t = constrain(now - 900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 233l, 30 - value);
         if (now > 1000l) { sequence_no_[1]++; }
         break;
       } case 2: {
         long t = constrain(now - 1400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 277l, 30 - value);
         if (now > 1500l) { sequence_no_[1]++; }
         break;
       } case 3: {
         long t = constrain(now - 1900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 370l, 30 - value);
         if (now > 2000l) { sequence_no_[1]++; }
         break;
       } case 4: {
         long t = constrain(now - 2400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 466l, 30 - value);
         if (now > 2500l) { sequence_no_[1]++; }
         break;
       } case 5: {
         long t = constrain(now - 3900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 4000l) { sequence_no_[1]++; }
         break;
       } case 6: {
         long t = constrain(now - 4900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 5000l) { sequence_no_[1]++; }
         break;
       } case 7: {
         long t = constrain(now - 5900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 932l, 30 - value);
         if (now > 6000l) { sequence_no_[1]++; }
         break;
       } case 8: {
         long t = constrain(now - 6650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1109l, 30 - value);
         if (now > 6750l) { sequence_no_[1]++; }
         break;
       } case 9: {
         long t = constrain(now - 6900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 7000l) { sequence_no_[1]++; }
         break;
       } case 10: {
         long t = constrain(now - 7400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 466l, 30 - value);
         if (now > 7500l) { sequence_no_[1]++; }
         break;
       } case 11: {
         long t = constrain(now - 7650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 7750l) { sequence_no_[1]++; }
         break;
       } case 12: {
         long t = constrain(now - 7900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 370l, 30 - value);
         if (now > 8000l) { sequence_no_[1]++; }
         break;
       } case 13: {
         long t = constrain(now - 8150l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 233l, 30 - value);
         if (now > 8250l) { sequence_no_[1]++; }
         break;
       } case 14: {
         long t = constrain(now - 8650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 277l, 30 - value);
         if (now > 8750l) { sequence_no_[1]++; }
         break;
       } case 15: {
         long t = constrain(now - 8900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 370l, 30 - value);
         if (now > 9000l) { sequence_no_[1]++; }
         break;
       } case 16: {
         long t = constrain(now - 9900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 466l, 30 - value);
         if (now > 10000l) { sequence_no_[1]++; }
         break;
       } case 17: {
         long t = constrain(now - 10900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 11000l) { sequence_no_[1]++; }
         break;
       } case 18: {
         setBioFreq(1, 740l, 30);
         if (now > 12000l) { sequence_no_[1]++; }
         break;
       } case 19: {
         long t = constrain(now - 12900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 13000l) { sequence_no_[1]++; }
         break;
       } case 20: {
         long t = constrain(now - 13900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 466l, 30 - value);
         if (now > 14000l) { sequence_no_[1]++; }
         break;
       } case 21: {
         long t = constrain(now - 14900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 15000l) { sequence_no_[1]++; }
         break;
       } case 22: {
         long t = constrain(now - 15900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 16000l) { sequence_no_[1]++; }
         break;
       } case 23: {
         long t = constrain(now - 17400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 932l, 30 - value);
         if (now > 17500l) { sequence_no_[1]++; }
         break;
       } case 24: {
         long t = constrain(now - 18400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 18500l) { sequence_no_[1]++; }
         break;
       } case 25: {
         long t = constrain(now - 19900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 20000l) { sequence_no_[1]++; }
         break;
       } case 26: {
         long t = constrain(now - 20650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 466l, 30 - value);
         if (now > 20750l) { sequence_no_[1]++; }
         break;
       } case 27: {
         long t = constrain(now - 21400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 277l, 30 - value);
         if (now > 21500l) { sequence_no_[1]++; }
         break;
       } case 28: {
         long t = constrain(now - 22150l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 370l, 30 - value);
         if (now > 22250l) { sequence_no_[1]++; }
         break;
       } case 29: {
         long t = constrain(now - 22900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 932l, 30 - value);
         if (now > 23000l) { sequence_no_[1]++; }
         break;
       } case 30: {
         long t = constrain(now - 23650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 23750l) { sequence_no_[1]++; }
         break;
       } case 31: {
         long t = constrain(now - 23900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 24000l) { sequence_no_[1]++; }
         break;
       } case 32: {
         long t = constrain(now - 24900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 932l, 30 - value);
         if (now > 25000l) { sequence_no_[1]++; }
         break;
       } case 33: {
         long t = constrain(now - 25900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1109l, 30 - value);
         if (now > 26000l) { sequence_no_[1]++; }
         break;
       } case 34: {
         long t = constrain(now - 26900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 740l, 30 - value);
         if (now > 27000l) { sequence_no_[1]++; }
         break;
       } case 35: {
         long t = constrain(now - 27900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 932l, 30 - value);
         if (now > 28000l) { sequence_no_[1]++; }
         break;
       } case 36: {
         long t = constrain(now - 29900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 554l, 30 - value);
         if (now > 30000l) { sequence_no_[1]++; }
         break;
       } case 37: {
         long t = constrain(now - 31900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 370l, 30 - value);
         if (now > 32000l) { sequence_no_[1]++; }
         break;
       } case 38: {
         long t = constrain(now - 33900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 233l, 30 - value);
         if (now > 34000l) { sequence_no_[1]++; }
         break;
       } case 39: {
         long t = constrain(now - 35900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 139l, 30 - value);
         if (now > 36000l) { sequence_no_[1]++; }
         break;
       } default:
         setBioFreq(1, 500l, 0);
         break;
     }
        // 2
  switch (sequence_no_[2]) {
    default:
      setBio(2, 0);
      break;
  }

  // 3
  switch (sequence_no_[3]) {
    default:
      setBio(3, 0);
      break;
  }
}
