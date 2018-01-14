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
      setBioFreq(0, 659l, 30 - value);
      if (now > 1000l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBioFreq(0, 500l, 0);
      if (now > 2000l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 2900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 3000l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBioFreq(0, 500l, 0);
      if (now > 4000l) { sequence_no_[0]++; }
      break;
    } case 4: {
      long t = constrain(now - 4900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 5000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 5900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 6000l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 7900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 7: {
      setBioFreq(0, 500l, 0);
      if (now > 10000l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 10900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 11000l) { sequence_no_[0]++; }
      break;
    } case 9: {
      setBioFreq(0, 500l, 0);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 10: {
      long t = constrain(now - 13400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 13500l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 13900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 14000l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 14900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 277l, 30 - value);
      if (now > 15000l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 16900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 17000l) { sequence_no_[0]++; }
      break;
    } case 14: {
      setBioFreq(0, 500l, 0);
      if (now > 18000l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 18900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 19000l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 19900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 208l, 30 - value);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 20400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 20500l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 21900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 22000l) { sequence_no_[0]++; }
      break;
    } case 19: {
      long t = constrain(now - 23400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 23500l) { sequence_no_[0]++; }
      break;
    } case 20: {
      setBioFreq(0, 659l, 30);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 24400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 24500l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 24900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 25000l) { sequence_no_[0]++; }
      break;
    } case 23: {
      setBioFreq(0, 500l, 0);
      if (now > 26000l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 26150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 26250l) { sequence_no_[0]++; }
      break;
    } case 25: {
      long t = constrain(now - 26900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 277l, 30 - value);
      if (now > 27000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      setBioFreq(0, 500l, 0);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    } case 27: {
      long t = constrain(now - 28150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 28250l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 28900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 29000l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 29900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 30000l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 30400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 30500l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 30900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 31000l) { sequence_no_[0]++; }
      break;
    } case 32: {
      long t = constrain(now - 33900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 220l, 30 - value);
      if (now > 34000l) { sequence_no_[0]++; }
      break;
    } case 33: {
      setBioFreq(0, 500l, 0);
      if (now > 35000l) { sequence_no_[0]++; }
      break;
    } case 34: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 36567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 36667l) { sequence_no_[0]++; }
      break;
    } case 36: {
      long t = constrain(now - 37233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 37333l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 37900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 38000l) { sequence_no_[0]++; }
      break;
    } case 38: {
      long t = constrain(now - 38233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 38333l) { sequence_no_[0]++; }
      break;
    } case 39: {
      long t = constrain(now - 38567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 38667l) { sequence_no_[0]++; }
      break;
    } case 40: {
      long t = constrain(now - 38900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 39000l) { sequence_no_[0]++; }
      break;
    } case 41: {
      long t = constrain(now - 39233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 39333l) { sequence_no_[0]++; }
      break;
    } case 42: {
      long t = constrain(now - 39567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 39667l) { sequence_no_[0]++; }
      break;
    } case 43: {
      long t = constrain(now - 39900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1760l, 30 - value);
      if (now > 40000l) { sequence_no_[0]++; }
      break;
    } case 44: {
      setBioFreq(0, 500l, 0);
      if (now > 40500l) { sequence_no_[0]++; }
      break;
    } case 45: {
      long t = constrain(now - 41900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 42000l) { sequence_no_[0]++; }
      break;
    } case 46: {
      long t = constrain(now - 42233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 208l, 30 - value);
      if (now > 42333l) { sequence_no_[0]++; }
      break;
    } case 47: {
      long t = constrain(now - 42567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 42667l) { sequence_no_[0]++; }
      break;
    } case 48: {
      long t = constrain(now - 42900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 43000l) { sequence_no_[0]++; }
      break;
    } case 49: {
      long t = constrain(now - 43400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 43500l) { sequence_no_[0]++; }
      break;
    } case 50: {
      setBioFreq(0, 500l, 0);
      if (now > 44000l) { sequence_no_[0]++; }
      break;
    } case 51: {
      long t = constrain(now - 44067l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 44167l) { sequence_no_[0]++; }
      break;
    } case 52: {
      long t = constrain(now - 44233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 44333l) { sequence_no_[0]++; }
      break;
    } case 53: {
      long t = constrain(now - 44400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1245l, 30 - value);
      if (now > 44500l) { sequence_no_[0]++; }
      break;
    } case 54: {
      long t = constrain(now - 44567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 44667l) { sequence_no_[0]++; }
      break;
    } case 55: {
      long t = constrain(now - 44733l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 44833l) { sequence_no_[0]++; }
      break;
    } case 56: {
      long t = constrain(now - 44900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 45000l) { sequence_no_[0]++; }
      break;
    } case 57: {
      long t = constrain(now - 45400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 45500l) { sequence_no_[0]++; }
      break;
    } case 58: {
      long t = constrain(now - 45900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 46000l) { sequence_no_[0]++; }
      break;
    } case 59: {
      long t = constrain(now - 46400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 277l, 30 - value);
      if (now > 46500l) { sequence_no_[0]++; }
      break;
    } case 60: {
      long t = constrain(now - 47900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 220l, 30 - value);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    } case 61: {
      long t = constrain(now - 48567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 48667l) { sequence_no_[0]++; }
      break;
    } case 62: {
      long t = constrain(now - 49233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 49333l) { sequence_no_[0]++; }
      break;
    } case 63: {
      long t = constrain(now - 49900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 50000l) { sequence_no_[0]++; }
      break;
    } case 64: {
      long t = constrain(now - 50233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 50333l) { sequence_no_[0]++; }
      break;
    } case 65: {
      long t = constrain(now - 50567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1760l, 30 - value);
      if (now > 50667l) { sequence_no_[0]++; }
      break;
    } case 66: {
      setBioFreq(0, 500l, 0);
      if (now > 51000l) { sequence_no_[0]++; }
      break;
    } case 67: {
      setBioFreq(0, 500l, 0);
      if (now > 52500l) { sequence_no_[0]++; }
      break;
    } case 68: {
      long t = constrain(now - 52567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 52667l) { sequence_no_[0]++; }
      break;
    } case 69: {
      long t = constrain(now - 52733l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 52833l) { sequence_no_[0]++; }
      break;
    } case 70: {
      long t = constrain(now - 52900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1245l, 30 - value);
      if (now > 53000l) { sequence_no_[0]++; }
      break;
    } case 71: {
      long t = constrain(now - 53067l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 53167l) { sequence_no_[0]++; }
      break;
    } case 72: {
      long t = constrain(now - 53233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 53333l) { sequence_no_[0]++; }
      break;
    } case 73: {
      setBioFreq(0, 500l, 0);
      if (now > 53500l) { sequence_no_[0]++; }
      break;
    } case 74: {
      setBioFreq(0, 500l, 0);
      if (now > 54000l) { sequence_no_[0]++; }
      break;
    } case 75: {
      setBioFreq(0, 500l, 0);
      if (now > 55000l) { sequence_no_[0]++; }
      break;
    } case 76: {
      long t = constrain(now - 55400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 55500l) { sequence_no_[0]++; }
      break;
    } case 77: {
      long t = constrain(now - 55900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 56000l) { sequence_no_[0]++; }
      break;
    } case 78: {
      long t = constrain(now - 56900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1245l, 30 - value);
      if (now > 57000l) { sequence_no_[0]++; }
      break;
    } case 79: {
      long t = constrain(now - 57900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 58000l) { sequence_no_[0]++; }
      break;
    } case 80: {
      long t = constrain(now - 59900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 220l, 30 - value);
      if (now > 60000l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }
     // 1
     switch (sequence_no_[1]) {
       case 0: {
         setBioFreq(1, 500l, 0);
         if (now > 6000l) { sequence_no_[1]++; }
         break;
       } case 1: {
         setBioFreq(1, 500l, 0);
         if (now > 7000l) { sequence_no_[1]++; }
         break;
       } case 2: {
         long t = constrain(now - 8900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 9000l) { sequence_no_[1]++; }
         break;
       } case 3: {
         long t = constrain(now - 9900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 659l, 30 - value);
         if (now > 10000l) { sequence_no_[1]++; }
         break;
       } case 4: {
         setBioFreq(1, 500l, 0);
         if (now > 11000l) { sequence_no_[1]++; }
         break;
       } case 5: {
         long t = constrain(now - 11900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 12000l) { sequence_no_[1]++; }
         break;
       } case 6: {
         long t = constrain(now - 12900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 880l, 30 - value);
         if (now > 13000l) { sequence_no_[1]++; }
         break;
       } case 7: {
         long t = constrain(now - 14900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1245l, 30 - value);
         if (now > 15000l) { sequence_no_[1]++; }
         break;
       } case 8: {
         long t = constrain(now - 15900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 16000l) { sequence_no_[1]++; }
         break;
       } case 9: {
         setBioFreq(1, 330l, 30);
         if (now > 17000l) { sequence_no_[1]++; }
         break;
       } case 10: {
         long t = constrain(now - 17900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 330l, 30 - value);
         if (now > 18000l) { sequence_no_[1]++; }
         break;
       } case 11: {
         long t = constrain(now - 18900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 330l, 30 - value);
         if (now > 19000l) { sequence_no_[1]++; }
         break;
       } case 12: {
         long t = constrain(now - 19900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 415l, 30 - value);
         if (now > 20000l) { sequence_no_[1]++; }
         break;
       } case 13: {
         long t = constrain(now - 20900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 440l, 30 - value);
         if (now > 21000l) { sequence_no_[1]++; }
         break;
       } case 14: {
         long t = constrain(now - 21400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 21500l) { sequence_no_[1]++; }
         break;
       } case 15: {
         long t = constrain(now - 22400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 22500l) { sequence_no_[1]++; }
         break;
       } case 16: {
         long t = constrain(now - 23400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1319l, 30 - value);
         if (now > 23500l) { sequence_no_[1]++; }
         break;
       } case 17: {
         long t = constrain(now - 23900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 24000l) { sequence_no_[1]++; }
         break;
       } case 18: {
         long t = constrain(now - 24400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 880l, 30 - value);
         if (now > 24500l) { sequence_no_[1]++; }
         break;
       } case 19: {
         long t = constrain(now - 24900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 25000l) { sequence_no_[1]++; }
         break;
       } case 20: {
         setBioFreq(1, 500l, 0);
         if (now > 26000l) { sequence_no_[1]++; }
         break;
       } case 21: {
         setBioFreq(1, 500l, 0);
         if (now > 26250l) { sequence_no_[1]++; }
         break;
       } case 22: {
         long t = constrain(now - 26400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 26500l) { sequence_no_[1]++; }
         break;
       } case 23: {
         long t = constrain(now - 26900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 330l, 30 - value);
         if (now > 27000l) { sequence_no_[1]++; }
         break;
       } case 24: {
         setBioFreq(1, 500l, 0);
         if (now > 27250l) { sequence_no_[1]++; }
         break;
       } case 25: {
         long t = constrain(now - 27400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 415l, 30 - value);
         if (now > 27500l) { sequence_no_[1]++; }
         break;
       } case 26: {
         long t = constrain(now - 27900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 880l, 30 - value);
         if (now > 28000l) { sequence_no_[1]++; }
         break;
       } case 27: {
         long t = constrain(now - 29900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 30000l) { sequence_no_[1]++; }
         break;
       } case 28: {
         long t = constrain(now - 30150l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 988l, 30 - value);
         if (now > 30250l) { sequence_no_[1]++; }
         break;
       } case 29: {
         long t = constrain(now - 30400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 659l, 30 - value);
         if (now > 30500l) { sequence_no_[1]++; }
         break;
       } case 30: {
         long t = constrain(now - 30650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 415l, 30 - value);
         if (now > 30750l) { sequence_no_[1]++; }
         break;
       } case 31: {
         long t = constrain(now - 30900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 220l, 30 - value);
         if (now > 31000l) { sequence_no_[1]++; }
         break;
       } case 32: {
         long t = constrain(now - 31567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 311l, 30 - value);
         if (now > 31667l) { sequence_no_[1]++; }
         break;
       } case 33: {
         long t = constrain(now - 32233l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 247l, 30 - value);
         if (now > 32333l) { sequence_no_[1]++; }
         break;
       } case 34: {
         long t = constrain(now - 32900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 330l, 30 - value);
         if (now > 33000l) { sequence_no_[1]++; }
         break;
       } case 35: {
         long t = constrain(now - 33233l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 415l, 30 - value);
         if (now > 33333l) { sequence_no_[1]++; }
         break;
       } case 36: {
         long t = constrain(now - 33567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 440l, 30 - value);
         if (now > 33667l) { sequence_no_[1]++; }
         break;
       } case 37: {
         long t = constrain(now - 33900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 34000l) { sequence_no_[1]++; }
         break;
       } case 38: {
         long t = constrain(now - 34567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 988l, 30 - value);
         if (now > 34667l) { sequence_no_[1]++; }
         break;
       } case 39: {
         setBioFreq(1, 659l, 30);
         if (now > 35333l) { sequence_no_[1]++; }
         break;
       } case 40: {
         long t = constrain(now - 35900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 659l, 30 - value);
         if (now > 36000l) { sequence_no_[1]++; }
         break;
       } case 41: {
         long t = constrain(now - 36567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 36667l) { sequence_no_[1]++; }
         break;
       } case 42: {
         setBioFreq(1, 440l, 30);
         if (now > 37333l) { sequence_no_[1]++; }
         break;
       } case 43: {
         long t = constrain(now - 37900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 440l, 30 - value);
         if (now > 38000l) { sequence_no_[1]++; }
         break;
       } case 44: {
         long t = constrain(now - 39900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 311l, 30 - value);
         if (now > 40000l) { sequence_no_[1]++; }
         break;
       } case 45: {
         setBioFreq(1, 500l, 0);
         if (now > 40500l) { sequence_no_[1]++; }
         break;
       } case 46: {
         long t = constrain(now - 41900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 42000l) { sequence_no_[1]++; }
         break;
       } case 47: {
         setBioFreq(1, 500l, 0);
         if (now > 43500l) { sequence_no_[1]++; }
         break;
       } case 48: {
         long t = constrain(now - 44900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1319l, 30 - value);
         if (now > 45000l) { sequence_no_[1]++; }
         break;
       } case 49: {
         long t = constrain(now - 46400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 415l, 30 - value);
         if (now > 46500l) { sequence_no_[1]++; }
         break;
       } case 50: {
         setBioFreq(1, 500l, 0);
         if (now > 48000l) { sequence_no_[1]++; }
         break;
       } case 51: {
         long t = constrain(now - 49400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 440l, 30 - value);
         if (now > 49500l) { sequence_no_[1]++; }
         break;
       } case 52: {
         long t = constrain(now - 49567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 49667l) { sequence_no_[1]++; }
         break;
       } case 53: {
         long t = constrain(now - 49733l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 494l, 30 - value);
         if (now > 49833l) { sequence_no_[1]++; }
         break;
       } case 54: {
         long t = constrain(now - 49900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 659l, 30 - value);
         if (now > 50000l) { sequence_no_[1]++; }
         break;
       } case 55: {
         long t = constrain(now - 50067l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 50167l) { sequence_no_[1]++; }
         break;
       } case 56: {
         long t = constrain(now - 50233l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 440l, 30 - value);
         if (now > 50333l) { sequence_no_[1]++; }
         break;
       } case 57: {
         long t = constrain(now - 50400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 622l, 30 - value);
         if (now > 50500l) { sequence_no_[1]++; }
         break;
       } case 58: {
         long t = constrain(now - 50567l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 988l, 30 - value);
         if (now > 50667l) { sequence_no_[1]++; }
         break;
       } case 59: {
         long t = constrain(now - 50733l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 659l, 30 - value);
         if (now > 50833l) { sequence_no_[1]++; }
         break;
       } case 60: {
         setBioFreq(1, 831l, 30);
         if (now > 51000l) { sequence_no_[1]++; }
         break;
       } case 61: {
         long t = constrain(now - 51900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 52000l) { sequence_no_[1]++; }
         break;
       } case 62: {
         long t = constrain(now - 52900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 880l, 30 - value);
         if (now > 53000l) { sequence_no_[1]++; }
         break;
       } case 63: {
         long t = constrain(now - 53900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1245l, 30 - value);
         if (now > 54000l) { sequence_no_[1]++; }
         break;
       } case 64: {
         setBioFreq(1, 500l, 0);
         if (now > 55000l) { sequence_no_[1]++; }
         break;
       } case 65: {
         long t = constrain(now - 55900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 988l, 30 - value);
         if (now > 56000l) { sequence_no_[1]++; }
         break;
       } case 66: {
         long t = constrain(now - 56400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1319l, 30 - value);
         if (now > 56500l) { sequence_no_[1]++; }
         break;
       } case 67: {
         long t = constrain(now - 56900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 831l, 30 - value);
         if (now > 57000l) { sequence_no_[1]++; }
         break;
       } case 68: {
         long t = constrain(now - 57900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 1760l, 30 - value);
         if (now > 58000l) { sequence_no_[1]++; }
         break;
       } case 69: {
         long t = constrain(now - 59900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 30, 100l);
         setBioFreq(1, 2489l, 30 - value);
         if (now > 60000l) { sequence_no_[1]++; }
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
