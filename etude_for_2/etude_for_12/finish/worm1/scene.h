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
  // 0
  switch (sequence_no_[0]) {
    case 0: {
      setBioFreq(0, 500l, 0);
      if (now > 200l) { sequence_no_[0]++; }
      break;
    } case 1: {
      long t = constrain(now - 1300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 1400l) { sequence_no_[0]++; }
      break;
    } case 2: {
      setBioFreq(0, 500l, 0);
      if (now > 3800l) { sequence_no_[0]++; }
      break;
    } case 3: {
      long t = constrain(now - 4300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 4400l) { sequence_no_[0]++; }
      break;
    } case 4: {
      setBioFreq(0, 500l, 0);
      if (now > 5000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 5500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 5600l) { sequence_no_[0]++; }
      break;
    } case 6: {
      setBioFreq(0, 500l, 0);
      if (now > 6800l) { sequence_no_[0]++; }
      break;
    } case 7: {
      long t = constrain(now - 7300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 7400l) { sequence_no_[0]++; }
      break;
    } case 8: {
      setBioFreq(0, 500l, 0);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 9700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 9800l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBioFreq(0, 500l, 0);
      if (now > 11600l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 12100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1397l, 30 - value);
      if (now > 12200l) { sequence_no_[0]++; }
      break;
    } case 12: {
      setBioFreq(0, 500l, 0);
      if (now > 15200l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 16300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1661l, 30 - value);
      if (now > 16400l) { sequence_no_[0]++; }
      break;
    } case 14: {
      setBioFreq(0, 500l, 0);
      if (now > 17600l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 19300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 19400l) { sequence_no_[0]++; }
      break;
    } case 16: {
      setBioFreq(0, 500l, 0);
      if (now > 19700l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 19900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      setBioFreq(0, 500l, 0);
      if (now > 20300l) { sequence_no_[0]++; }
      break;
    } case 19: {
      long t = constrain(now - 20500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 20600l) { sequence_no_[0]++; }
      break;
    } case 20: {
      setBioFreq(0, 500l, 0);
      if (now > 22400l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 24100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 24200l) { sequence_no_[0]++; }
      break;
    } case 22: {
      setBioFreq(0, 500l, 0);
      if (now > 24800l) { sequence_no_[0]++; }
      break;
    } case 23: {
      long t = constrain(now - 25300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 25400l) { sequence_no_[0]++; }
      break;
    } case 24: {
      setBioFreq(0, 500l, 0);
      if (now > 26600l) { sequence_no_[0]++; }
      break;
    } case 25: {
      long t = constrain(now - 27100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 27200l) { sequence_no_[0]++; }
      break;
    } case 26: {
      setBioFreq(0, 500l, 0);
      if (now > 27800l) { sequence_no_[0]++; }
      break;
    } case 27: {
      long t = constrain(now - 28900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 29000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      setBioFreq(0, 500l, 0);
      if (now > 29600l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 31300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 31400l) { sequence_no_[0]++; }
      break;
    } case 30: {
      setBioFreq(0, 500l, 0);
      if (now > 33200l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 33700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 33800l) { sequence_no_[0]++; }
      break;
    } case 32: {
      setBioFreq(0, 500l, 0);
      if (now > 34400l) { sequence_no_[0]++; }
      break;
    } case 33: {
      long t = constrain(now - 36100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 36200l) { sequence_no_[0]++; }
      break;
    } case 34: {
      setBioFreq(0, 500l, 0);
      if (now > 38000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 38500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 38600l) { sequence_no_[0]++; }
      break;
    } case 36: {
      setBioFreq(0, 500l, 0);
      if (now > 39200l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 39700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 39800l) { sequence_no_[0]++; }
      break;
    } case 38: {
      setBioFreq(0, 500l, 0);
      if (now > 40400l) { sequence_no_[0]++; }
      break;
    } case 39: {
      long t = constrain(now - 42100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 42200l) { sequence_no_[0]++; }
      break;
    } case 40: {
      setBioFreq(0, 500l, 0);
      if (now > 42500l) { sequence_no_[0]++; }
      break;
    } case 41: {
      long t = constrain(now - 42700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 42800l) { sequence_no_[0]++; }
      break;
    } case 42: {
      setBioFreq(0, 500l, 0);
      if (now > 44000l) { sequence_no_[0]++; }
      break;
    } case 43: {
      long t = constrain(now - 45100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 45200l) { sequence_no_[0]++; }
      break;
    } case 44: {
      setBioFreq(0, 500l, 0);
      if (now > 45800l) { sequence_no_[0]++; }
      break;
    } case 45: {
      long t = constrain(now - 46300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 46400l) { sequence_no_[0]++; }
      break;
    } case 46: {
      setBioFreq(0, 500l, 0);
      if (now > 47000l) { sequence_no_[0]++; }
      break;
    } case 47: {
      long t = constrain(now - 47500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 47600l) { sequence_no_[0]++; }
      break;
    } case 48: {
      setBioFreq(0, 500l, 0);
      if (now > 49400l) { sequence_no_[0]++; }
      break;
    } case 49: {
      long t = constrain(now - 51100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 208l, 30 - value);
      if (now > 51200l) { sequence_no_[0]++; }
      break;
    } case 50: {
      setBioFreq(0, 500l, 0);
      if (now > 51800l) { sequence_no_[0]++; }
      break;
    } case 51: {
      long t = constrain(now - 52300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 220l, 30 - value);
      if (now > 52400l) { sequence_no_[0]++; }
      break;
    } case 52: {
      setBioFreq(0, 500l, 0);
      if (now > 53600l) { sequence_no_[0]++; }
      break;
    } case 53: {
      long t = constrain(now - 54100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 262l, 30 - value);
      if (now > 54200l) { sequence_no_[0]++; }
      break;
    } case 54: {
      setBioFreq(0, 500l, 0);
      if (now > 54800l) { sequence_no_[0]++; }
      break;
    } case 55: {
      long t = constrain(now - 55900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 56000l) { sequence_no_[0]++; }
      break;
    } case 56: {
      setBioFreq(0, 500l, 0);
      if (now > 56600l) { sequence_no_[0]++; }
      break;
    } case 57: {
      long t = constrain(now - 57700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 57800l) { sequence_no_[0]++; }
      break;
    } case 58: {
      setBioFreq(0, 500l, 0);
      if (now > 58400l) { sequence_no_[0]++; }
      break;
    } case 59: {
      long t = constrain(now - 59500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 59600l) { sequence_no_[0]++; }
      break;
    } case 60: {
      setBioFreq(0, 500l, 0);
      if (now > 61400l) { sequence_no_[0]++; }
      break;
    } case 61: {
      long t = constrain(now - 61750l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 61850l) { sequence_no_[0]++; }
      break;
    } case 62: {
      setBioFreq(0, 500l, 0);
      if (now > 62300l) { sequence_no_[0]++; }
      break;
    } case 63: {
      long t = constrain(now - 62650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 62750l) { sequence_no_[0]++; }
      break;
    } case 64: {
      setBioFreq(0, 500l, 0);
      if (now > 63050l) { sequence_no_[0]++; }
      break;
    } case 65: {
      long t = constrain(now - 63400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 63500l) { sequence_no_[0]++; }
      break;
    } case 66: {
      setBioFreq(0, 500l, 0);
      if (now > 63800l) { sequence_no_[0]++; }
      break;
    } case 67: {
      long t = constrain(now - 64000l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 233l, 30 - value);
      if (now > 64100l) { sequence_no_[0]++; }
      break;
    } case 68: {
      setBioFreq(0, 500l, 0);
      if (now > 64400l) { sequence_no_[0]++; }
      break;
    } case 69: {
      long t = constrain(now - 64600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 64700l) { sequence_no_[0]++; }
      break;
    } case 70: {
      setBioFreq(0, 500l, 0);
      if (now > 65000l) { sequence_no_[0]++; }
      break;
    } case 71: {
      long t = constrain(now - 65200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1397l, 30 - value);
      if (now > 65300l) { sequence_no_[0]++; }
      break;
    } case 72: {
      setBioFreq(0, 500l, 0);
      if (now > 68900l) { sequence_no_[0]++; }
      break;
    } case 73: {
      long t = constrain(now - 72400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 72500l) { sequence_no_[0]++; }
      break;
    } case 74: {
      long t = constrain(now - 72700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 72800l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }

  // 1
  switch (sequence_no_[1]) {
    case 0: {
      long t = constrain(now - 700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 698l, 30 - value);
      if (now > 800l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBioFreq(1, 500l, 0);
      if (now > 2600l) { sequence_no_[1]++; }
      break;
    } case 2: {
      long t = constrain(now - 4300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 4400l) { sequence_no_[1]++; }
      break;
    } case 3: {
      setBioFreq(1, 500l, 0);
      if (now > 6200l) { sequence_no_[1]++; }
      break;
    } case 4: {
      long t = constrain(now - 6400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 6500l) { sequence_no_[1]++; }
      break;
    } case 5: {
      setBioFreq(1, 500l, 0);
      if (now > 6800l) { sequence_no_[1]++; }
      break;
    } case 6: {
      long t = constrain(now - 7900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 8000l) { sequence_no_[1]++; }
      break;
    } case 7: {
      setBioFreq(1, 500l, 0);
      if (now > 9200l) { sequence_no_[1]++; }
      break;
    } case 8: {
      long t = constrain(now - 10300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 294l, 30 - value);
      if (now > 10400l) { sequence_no_[1]++; }
      break;
    } case 9: {
      setBioFreq(1, 500l, 0);
      if (now > 11600l) { sequence_no_[1]++; }
      break;
    } case 10: {
      long t = constrain(now - 12700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 12800l) { sequence_no_[1]++; }
      break;
    } case 11: {
      setBioFreq(1, 500l, 0);
      if (now > 26600l) { sequence_no_[1]++; }
      break;
    } case 12: {
      long t = constrain(now - 27700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 27800l) { sequence_no_[1]++; }
      break;
    } case 13: {
      setBioFreq(1, 500l, 0);
      if (now > 29000l) { sequence_no_[1]++; }
      break;
    } case 14: {
      long t = constrain(now - 29500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 740l, 30 - value);
      if (now > 29600l) { sequence_no_[1]++; }
      break;
    } case 15: {
      setBioFreq(1, 500l, 0);
      if (now > 30800l) { sequence_no_[1]++; }
      break;
    } case 16: {
      long t = constrain(now - 31300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 831l, 30 - value);
      if (now > 31400l) { sequence_no_[1]++; }
      break;
    } case 17: {
      setBioFreq(1, 500l, 0);
      if (now > 32000l) { sequence_no_[1]++; }
      break;
    } case 18: {
      long t = constrain(now - 33100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 33200l) { sequence_no_[1]++; }
      break;
    } case 19: {
      setBioFreq(1, 500l, 0);
      if (now > 34400l) { sequence_no_[1]++; }
      break;
    } case 20: {
      long t = constrain(now - 36700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 36800l) { sequence_no_[1]++; }
      break;
    } case 21: {
      setBioFreq(1, 500l, 0);
      if (now > 38600l) { sequence_no_[1]++; }
      break;
    } case 22: {
      long t = constrain(now - 40300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 277l, 30 - value);
      if (now > 40400l) { sequence_no_[1]++; }
      break;
    } case 23: {
      setBioFreq(1, 500l, 0);
      if (now > 41000l) { sequence_no_[1]++; }
      break;
    } case 24: {
      long t = constrain(now - 41500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 41600l) { sequence_no_[1]++; }
      break;
    } case 25: {
      setBioFreq(1, 500l, 0);
      if (now > 42800l) { sequence_no_[1]++; }
      break;
    } case 26: {
      long t = constrain(now - 43900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 44000l) { sequence_no_[1]++; }
      break;
    } case 27: {
      setBioFreq(1, 500l, 0);
      if (now > 44600l) { sequence_no_[1]++; }
      break;
    } case 28: {
      long t = constrain(now - 45100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 45200l) { sequence_no_[1]++; }
      break;
    } case 29: {
      setBioFreq(1, 500l, 0);
      if (now > 45800l) { sequence_no_[1]++; }
      break;
    } case 30: {
      long t = constrain(now - 46900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 47000l) { sequence_no_[1]++; }
      break;
    } case 31: {
      setBioFreq(1, 500l, 0);
      if (now > 48200l) { sequence_no_[1]++; }
      break;
    } case 32: {
      long t = constrain(now - 48400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 48500l) { sequence_no_[1]++; }
      break;
    } case 33: {
      setBioFreq(1, 500l, 0);
      if (now > 48800l) { sequence_no_[1]++; }
      break;
    } case 34: {
      long t = constrain(now - 49000l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 49100l) { sequence_no_[1]++; }
      break;
    } case 35: {
      setBioFreq(1, 500l, 0);
      if (now > 50600l) { sequence_no_[1]++; }
      break;
    } case 36: {
      long t = constrain(now - 51100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 698l, 30 - value);
      if (now > 51200l) { sequence_no_[1]++; }
      break;
    } case 37: {
      setBioFreq(1, 500l, 0);
      if (now > 52100l) { sequence_no_[1]++; }
      break;
    } case 38: {
      long t = constrain(now - 52900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 740l, 30 - value);
      if (now > 53000l) { sequence_no_[1]++; }
      break;
    } case 39: {
      setBioFreq(1, 500l, 0);
      if (now > 53900l) { sequence_no_[1]++; }
      break;
    } case 40: {
      long t = constrain(now - 55000l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 831l, 30 - value);
      if (now > 55100l) { sequence_no_[1]++; }
      break;
    } case 41: {
      setBioFreq(1, 500l, 0);
      if (now > 56300l) { sequence_no_[1]++; }
      break;
    } case 42: {
      long t = constrain(now - 57100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 57200l) { sequence_no_[1]++; }
      break;
    } case 43: {
      setBioFreq(1, 500l, 0);
      if (now > 58100l) { sequence_no_[1]++; }
      break;
    } case 44: {
      long t = constrain(now - 58900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 59000l) { sequence_no_[1]++; }
      break;
    } case 45: {
      setBioFreq(1, 500l, 0);
      if (now > 59900l) { sequence_no_[1]++; }
      break;
    } case 46: {
      long t = constrain(now - 61600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 61700l) { sequence_no_[1]++; }
      break;
    } case 47: {
      setBioFreq(1, 880l, 30);
      if (now > 65300l) { sequence_no_[1]++; }
      break;
    } case 48: {
      long t = constrain(now - 68800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 68900l) { sequence_no_[1]++; }
      break;
    } case 49: {
      long t = constrain(now - 72400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 72500l) { sequence_no_[1]++; }
      break;
    } case 50: {
      long t = constrain(now - 72700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 72800l) { sequence_no_[1]++; }
      break;
    } default:
      setBioFreq(1, 500l, 0);
      break;
  }
}
