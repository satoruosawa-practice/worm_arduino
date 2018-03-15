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
      setBioFreq(0, 500l, 0);
      if (now > 1200l) { sequence_no_[0]++; }
      break;
    } case 1: {
      long t = constrain(now - 1700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 1800l) { sequence_no_[0]++; }
      break;
    } case 2: {
      setBioFreq(0, 500l, 0);
      if (now > 3600l) { sequence_no_[0]++; }
      break;
    } case 3: {
      long t = constrain(now - 4700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 4800l) { sequence_no_[0]++; }
      break;
    } case 4: {
      setBioFreq(0, 500l, 0);
      if (now > 5400l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 6500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 6600l) { sequence_no_[0]++; }
      break;
    } case 6: {
      setBioFreq(0, 500l, 0);
      if (now > 7200l) { sequence_no_[0]++; }
      break;
    } case 7: {
      long t = constrain(now - 8300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 8400l) { sequence_no_[0]++; }
      break;
    } case 8: {
      setBioFreq(0, 500l, 0);
      if (now > 9600l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 10100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 10200l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBioFreq(0, 500l, 0);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 13700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 13800l) { sequence_no_[0]++; }
      break;
    } case 12: {
      setBioFreq(0, 500l, 0);
      if (now > 31200l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 32300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 32400l) { sequence_no_[0]++; }
      break;
    } case 14: {
      setBioFreq(0, 500l, 0);
      if (now > 34200l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } case 16: {
      setBioFreq(0, 500l, 0);
      if (now > 37200l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 38900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 39000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      setBioFreq(0, 500l, 0);
      if (now > 39600l) { sequence_no_[0]++; }
      break;
    } case 19: {
      long t = constrain(now - 40100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 40200l) { sequence_no_[0]++; }
      break;
    } case 20: {
      setBioFreq(0, 500l, 0);
      if (now > 42000l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 43700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 294l, 30 - value);
      if (now > 43800l) { sequence_no_[0]++; }
      break;
    } case 22: {
      setBioFreq(0, 500l, 0);
      if (now > 44400l) { sequence_no_[0]++; }
      break;
    } case 23: {
      long t = constrain(now - 46700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 46800l) { sequence_no_[0]++; }
      break;
    } case 24: {
      setBioFreq(0, 500l, 0);
      if (now > 47400l) { sequence_no_[0]++; }
      break;
    } case 25: {
      long t = constrain(now - 47900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 247l, 30 - value);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      setBioFreq(0, 500l, 0);
      if (now > 49800l) { sequence_no_[0]++; }
      break;
    } case 27: {
      long t = constrain(now - 50900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 51000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      setBioFreq(0, 500l, 0);
      if (now > 52200l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 53300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 53400l) { sequence_no_[0]++; }
      break;
    } case 30: {
      setBioFreq(0, 500l, 0);
      if (now > 54000l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 54500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 54600l) { sequence_no_[0]++; }
      break;
    } case 32: {
      setBioFreq(0, 500l, 0);
      if (now > 55200l) { sequence_no_[0]++; }
      break;
    } case 33: {
      long t = constrain(now - 56300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 294l, 30 - value);
      if (now > 56400l) { sequence_no_[0]++; }
      break;
    } case 34: {
      setBioFreq(0, 500l, 0);
      if (now > 57000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 57500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 57600l) { sequence_no_[0]++; }
      break;
    } case 36: {
      setBioFreq(0, 500l, 0);
      if (now > 58200l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 59300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 59400l) { sequence_no_[0]++; }
      break;
    } case 38: {
      setBioFreq(0, 500l, 0);
      if (now > 60000l) { sequence_no_[0]++; }
      break;
    } case 39: {
      long t = constrain(now - 60500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 60600l) { sequence_no_[0]++; }
      break;
    } case 40: {
      setBioFreq(0, 500l, 0);
      if (now > 61200l) { sequence_no_[0]++; }
      break;
    } case 41: {
      long t = constrain(now - 62300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 62400l) { sequence_no_[0]++; }
      break;
    } case 42: {
      setBioFreq(0, 500l, 0);
      if (now > 63600l) { sequence_no_[0]++; }
      break;
    } case 43: {
      long t = constrain(now - 64100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 64200l) { sequence_no_[0]++; }
      break;
    } case 44: {
      setBioFreq(0, 500l, 0);
      if (now > 64800l) { sequence_no_[0]++; }
      break;
    } case 45: {
      long t = constrain(now - 65900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 66000l) { sequence_no_[0]++; }
      break;
    } case 46: {
      setBioFreq(0, 500l, 0);
      if (now > 67200l) { sequence_no_[0]++; }
      break;
    } case 47: {
      long t = constrain(now - 68300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 68400l) { sequence_no_[0]++; }
      break;
    } case 48: {
      setBioFreq(0, 500l, 0);
      if (now > 69600l) { sequence_no_[0]++; }
      break;
    } case 49: {
      long t = constrain(now - 70100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 70200l) { sequence_no_[0]++; }
      break;
    } case 50: {
      setBioFreq(0, 500l, 0);
      if (now > 71400l) { sequence_no_[0]++; }
      break;
    } case 51: {
      long t = constrain(now - 72500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 72600l) { sequence_no_[0]++; }
      break;
    } case 52: {
      setBioFreq(0, 500l, 0);
      if (now > 73200l) { sequence_no_[0]++; }
      break;
    } case 53: {
      long t = constrain(now - 73700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 73800l) { sequence_no_[0]++; }
      break;
    } case 54: {
      setBioFreq(0, 500l, 0);
      if (now > 75600l) { sequence_no_[0]++; }
      break;
    } case 55: {
      long t = constrain(now - 76700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 76800l) { sequence_no_[0]++; }
      break;
    } case 56: {
      setBioFreq(0, 500l, 0);
      if (now > 78600l) { sequence_no_[0]++; }
      break;
    } case 57: {
      long t = constrain(now - 80300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 80400l) { sequence_no_[0]++; }
      break;
    } case 58: {
      setBioFreq(0, 500l, 0);
      if (now > 82800l) { sequence_no_[0]++; }
      break;
    } case 59: {
      long t = constrain(now - 84500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 84600l) { sequence_no_[0]++; }
      break;
    } case 60: {
      setBioFreq(0, 500l, 0);
      if (now > 87300l) { sequence_no_[0]++; }
      break;
    } case 61: {
      long t = constrain(now - 88100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 988l, 30 - value);
      if (now > 88200l) { sequence_no_[0]++; }
      break;
    } case 62: {
      setBioFreq(0, 500l, 0);
      if (now > 90000l) { sequence_no_[0]++; }
      break;
    } case 63: {
      long t = constrain(now - 90800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 90900l) { sequence_no_[0]++; }
      break;
    } case 64: {
      setBioFreq(0, 500l, 0);
      if (now > 91800l) { sequence_no_[0]++; }
      break;
    } case 65: {
      long t = constrain(now - 93500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 93600l) { sequence_no_[0]++; }
      break;
    } case 66: {
      setBioFreq(0, 500l, 0);
      if (now > 95400l) { sequence_no_[0]++; }
      break;
    } case 67: {
      long t = constrain(now - 97100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 97200l) { sequence_no_[0]++; }
      break;
    } case 68: {
      setBioFreq(0, 500l, 0);
      if (now > 97800l) { sequence_no_[0]++; }
      break;
    } case 69: {
      long t = constrain(now - 98300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 98400l) { sequence_no_[0]++; }
      break;
    } case 70: {
      setBioFreq(0, 500l, 0);
      if (now > 99000l) { sequence_no_[0]++; }
      break;
    } case 71: {
      long t = constrain(now - 100100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 100200l) { sequence_no_[0]++; }
      break;
    } case 72: {
      setBioFreq(0, 500l, 0);
      if (now > 101400l) { sequence_no_[0]++; }
      break;
    } case 73: {
      long t = constrain(now - 103700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 103800l) { sequence_no_[0]++; }
      break;
    } case 74: {
      setBioFreq(0, 500l, 0);
      if (now > 104400l) { sequence_no_[0]++; }
      break;
    } case 75: {
      long t = constrain(now - 104900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 105000l) { sequence_no_[0]++; }
      break;
    } case 76: {
      setBioFreq(0, 500l, 0);
      if (now > 105600l) { sequence_no_[0]++; }
      break;
    } case 77: {
      long t = constrain(now - 106700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 106800l) { sequence_no_[0]++; }
      break;
    } case 78: {
      setBioFreq(0, 500l, 0);
      if (now > 107400l) { sequence_no_[0]++; }
      break;
    } case 79: {
      long t = constrain(now - 107900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 108000l) { sequence_no_[0]++; }
      break;
    } case 80: {
      setBioFreq(0, 500l, 0);
      if (now > 109800l) { sequence_no_[0]++; }
      break;
    } case 81: {
      long t = constrain(now - 111500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1175l, 30 - value);
      if (now > 111600l) { sequence_no_[0]++; }
      break;
    } case 82: {
      setBioFreq(0, 500l, 0);
      if (now > 112200l) { sequence_no_[0]++; }
      break;
    } case 83: {
      long t = constrain(now - 114500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 114600l) { sequence_no_[0]++; }
      break;
    } case 84: {
      setBioFreq(0, 500l, 0);
      if (now > 116400l) { sequence_no_[0]++; }
      break;
    } case 85: {
      long t = constrain(now - 117500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 117600l) { sequence_no_[0]++; }
      break;
    } case 86: {
      setBioFreq(0, 500l, 0);
      if (now > 119400l) { sequence_no_[0]++; }
      break;
    } case 87: {
      long t = constrain(now - 119600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 119700l) { sequence_no_[0]++; }
      break;
    } case 88: {
      setBioFreq(0, 500l, 0);
      if (now > 120000l) { sequence_no_[0]++; }
      break;
    } case 89: {
      long t = constrain(now - 120200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 120300l) { sequence_no_[0]++; }
      break;
    } case 90: {
      setBioFreq(0, 500l, 0);
      if (now > 120600l) { sequence_no_[0]++; }
      break;
    } case 91: {
      long t = constrain(now - 122300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1245l, 30 - value);
      if (now > 122400l) { sequence_no_[0]++; }
      break;
    } case 92: {
      setBioFreq(0, 500l, 0);
      if (now > 124200l) { sequence_no_[0]++; }
      break;
    } case 93: {
      long t = constrain(now - 124700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 124800l) { sequence_no_[0]++; }
      break;
    } case 94: {
      setBioFreq(0, 500l, 0);
      if (now > 125400l) { sequence_no_[0]++; }
      break;
    } case 95: {
      long t = constrain(now - 126500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 126600l) { sequence_no_[0]++; }
      break;
    } case 96: {
      setBioFreq(0, 500l, 0);
      if (now > 127200l) { sequence_no_[0]++; }
      break;
    } case 97: {
      long t = constrain(now - 127700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 988l, 30 - value);
      if (now > 127800l) { sequence_no_[0]++; }
      break;
    } case 98: {
      setBioFreq(0, 500l, 0);
      if (now > 129000l) { sequence_no_[0]++; }
      break;
    } case 99: {
      long t = constrain(now - 129500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 129600l) { sequence_no_[0]++; }
      break;
    } case 100: {
      setBioFreq(0, 500l, 0);
      if (now > 131400l) { sequence_no_[0]++; }
      break;
    } case 101: {
      long t = constrain(now - 133100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 133200l) { sequence_no_[0]++; }
      break;
    } case 102: {
      setBioFreq(0, 500l, 0);
      if (now > 133800l) { sequence_no_[0]++; }
      break;
    } case 103: {
      long t = constrain(now - 134300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 134400l) { sequence_no_[0]++; }
      break;
    } case 104: {
      setBioFreq(0, 500l, 0);
      if (now > 136200l) { sequence_no_[0]++; }
      break;
    } case 105: {
      long t = constrain(now - 137900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 294l, 30 - value);
      if (now > 138000l) { sequence_no_[0]++; }
      break;
    } case 106: {
      setBioFreq(0, 500l, 0);
      if (now > 138600l) { sequence_no_[0]++; }
      break;
    } case 107: {
      long t = constrain(now - 139100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 139200l) { sequence_no_[0]++; }
      break;
    } case 108: {
      setBioFreq(0, 500l, 0);
      if (now > 139800l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }


   // 1
   switch (sequence_no_[1]) {
     case 0: {
       setBioFreq(1, 500l, 0);
       if (now > 15000l) { sequence_no_[1]++; }
       break;
     } case 1: {
       long t = constrain(now - 15500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 311l, 30 - value);
       if (now > 15600l) { sequence_no_[1]++; }
       break;
     } case 2: {
       setBioFreq(1, 500l, 0);
       if (now > 16800l) { sequence_no_[1]++; }
       break;
     } case 3: {
       long t = constrain(now - 17300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 330l, 30 - value);
       if (now > 17400l) { sequence_no_[1]++; }
       break;
     } case 4: {
       setBioFreq(1, 500l, 0);
       if (now > 18600l) { sequence_no_[1]++; }
       break;
     } case 5: {
       long t = constrain(now - 19700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 19800l) { sequence_no_[1]++; }
       break;
     } case 6: {
       setBioFreq(1, 500l, 0);
       if (now > 20400l) { sequence_no_[1]++; }
       break;
     } case 7: {
       long t = constrain(now - 20900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 262l, 30 - value);
       if (now > 21000l) { sequence_no_[1]++; }
       break;
     } case 8: {
       setBioFreq(1, 500l, 0);
       if (now > 22800l) { sequence_no_[1]++; }
       break;
     } case 9: {
       long t = constrain(now - 24500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 24600l) { sequence_no_[1]++; }
       break;
     } case 10: {
       setBioFreq(1, 500l, 0);
       if (now > 26400l) { sequence_no_[1]++; }
       break;
     } case 11: {
       long t = constrain(now - 28700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 28800l) { sequence_no_[1]++; }
       break;
     } case 12: {
       setBioFreq(1, 500l, 0);
       if (now > 31200l) { sequence_no_[1]++; }
       break;
     } case 13: {
       long t = constrain(now - 32300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 622l, 30 - value);
       if (now > 32400l) { sequence_no_[1]++; }
       break;
     } case 14: {
       setBioFreq(1, 500l, 0);
       if (now > 34200l) { sequence_no_[1]++; }
       break;
     } case 15: {
       long t = constrain(now - 35900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 659l, 30 - value);
       if (now > 36000l) { sequence_no_[1]++; }
       break;
     } case 16: {
       setBioFreq(1, 500l, 0);
       if (now > 37200l) { sequence_no_[1]++; }
       break;
     } case 17: {
       long t = constrain(now - 38900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 39000l) { sequence_no_[1]++; }
       break;
     } case 18: {
       setBioFreq(1, 500l, 0);
       if (now > 39600l) { sequence_no_[1]++; }
       break;
     } case 19: {
       long t = constrain(now - 40100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 262l, 30 - value);
       if (now > 40200l) { sequence_no_[1]++; }
       break;
     } case 20: {
       setBioFreq(1, 500l, 0);
       if (now > 42000l) { sequence_no_[1]++; }
       break;
     } case 21: {
       long t = constrain(now - 43700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 43800l) { sequence_no_[1]++; }
       break;
     } case 22: {
       setBioFreq(1, 500l, 0);
       if (now > 44400l) { sequence_no_[1]++; }
       break;
     } case 23: {
       long t = constrain(now - 46700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 46800l) { sequence_no_[1]++; }
       break;
     } case 24: {
       setBioFreq(1, 500l, 0);
       if (now > 47400l) { sequence_no_[1]++; }
       break;
     } case 25: {
       long t = constrain(now - 47900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 311l, 30 - value);
       if (now > 48000l) { sequence_no_[1]++; }
       break;
     } case 26: {
       setBioFreq(1, 500l, 0);
       if (now > 49800l) { sequence_no_[1]++; }
       break;
     } case 27: {
       long t = constrain(now - 50900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 330l, 30 - value);
       if (now > 51000l) { sequence_no_[1]++; }
       break;
     } case 28: {
       setBioFreq(1, 500l, 0);
       if (now > 52200l) { sequence_no_[1]++; }
       break;
     } case 29: {
       long t = constrain(now - 53300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 53400l) { sequence_no_[1]++; }
       break;
     } case 30: {
       setBioFreq(1, 500l, 0);
       if (now > 54000l) { sequence_no_[1]++; }
       break;
     } case 31: {
       long t = constrain(now - 54500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 262l, 30 - value);
       if (now > 54600l) { sequence_no_[1]++; }
       break;
     } case 32: {
       setBioFreq(1, 500l, 0);
       if (now > 55200l) { sequence_no_[1]++; }
       break;
     } case 33: {
       long t = constrain(now - 56300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 56400l) { sequence_no_[1]++; }
       break;
     } case 34: {
       setBioFreq(1, 500l, 0);
       if (now > 57000l) { sequence_no_[1]++; }
       break;
     } case 35: {
       long t = constrain(now - 57500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 57600l) { sequence_no_[1]++; }
       break;
     } case 36: {
       setBioFreq(1, 500l, 0);
       if (now > 58800l) { sequence_no_[1]++; }
       break;
     } case 37: {
       long t = constrain(now - 59300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 622l, 30 - value);
       if (now > 59400l) { sequence_no_[1]++; }
       break;
     } case 38: {
       setBioFreq(1, 500l, 0);
       if (now > 60600l) { sequence_no_[1]++; }
       break;
     } case 39: {
       long t = constrain(now - 61400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 659l, 30 - value);
       if (now > 61500l) { sequence_no_[1]++; }
       break;
     } case 40: {
       setBioFreq(1, 500l, 0);
       if (now > 62400l) { sequence_no_[1]++; }
       break;
     } case 41: {
       long t = constrain(now - 63500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 63600l) { sequence_no_[1]++; }
       break;
     } case 42: {
       setBioFreq(1, 500l, 0);
       if (now > 64800l) { sequence_no_[1]++; }
       break;
     } case 43: {
       long t = constrain(now - 65900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 523l, 30 - value);
       if (now > 66000l) { sequence_no_[1]++; }
       break;
     } case 44: {
       setBioFreq(1, 500l, 0);
       if (now > 66900l) { sequence_no_[1]++; }
       break;
     } case 45: {
       long t = constrain(now - 68000l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 68100l) { sequence_no_[1]++; }
       break;
     } case 46: {
       setBioFreq(1, 500l, 0);
       if (now > 69000l) { sequence_no_[1]++; }
       break;
     } case 47: {
       long t = constrain(now - 70100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 70200l) { sequence_no_[1]++; }
       break;
     } case 48: {
       setBioFreq(1, 500l, 0);
       if (now > 71400l) { sequence_no_[1]++; }
       break;
     } case 49: {
       long t = constrain(now - 72500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 622l, 30 - value);
       if (now > 72600l) { sequence_no_[1]++; }
       break;
     } case 50: {
       setBioFreq(1, 500l, 0);
       if (now > 73200l) { sequence_no_[1]++; }
       break;
     } case 51: {
       long t = constrain(now - 74300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 659l, 30 - value);
       if (now > 74400l) { sequence_no_[1]++; }
       break;
     } case 52: {
       setBioFreq(1, 500l, 0);
       if (now > 75600l) { sequence_no_[1]++; }
       break;
     } case 53: {
       long t = constrain(now - 76700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 76800l) { sequence_no_[1]++; }
       break;
     } case 54: {
       setBioFreq(1, 500l, 0);
       if (now > 77400l) { sequence_no_[1]++; }
       break;
     } case 55: {
       long t = constrain(now - 77900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 523l, 30 - value);
       if (now > 78000l) { sequence_no_[1]++; }
       break;
     } case 56: {
       setBioFreq(1, 500l, 0);
       if (now > 79200l) { sequence_no_[1]++; }
       break;
     } case 57: {
       long t = constrain(now - 80300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 80400l) { sequence_no_[1]++; }
       break;
     } case 58: {
       setBioFreq(1, 500l, 0);
       if (now > 82800l) { sequence_no_[1]++; }
       break;
     } case 59: {
       long t = constrain(now - 85100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 85200l) { sequence_no_[1]++; }
       break;
     } case 60: {
       setBioFreq(1, 500l, 0);
       if (now > 86700l) { sequence_no_[1]++; }
       break;
     } case 61: {
       long t = constrain(now - 88400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 311l, 30 - value);
       if (now > 88500l) { sequence_no_[1]++; }
       break;
     } case 62: {
       setBioFreq(1, 500l, 0);
       if (now > 88800l) { sequence_no_[1]++; }
       break;
     } case 63: {
       long t = constrain(now - 90500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 330l, 30 - value);
       if (now > 90600l) { sequence_no_[1]++; }
       break;
     } case 64: {
       setBioFreq(1, 500l, 0);
       if (now > 90900l) { sequence_no_[1]++; }
       break;
     } case 65: {
       long t = constrain(now - 92600l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 233l, 30 - value);
       if (now > 92700l) { sequence_no_[1]++; }
       break;
     } case 66: {
       setBioFreq(1, 500l, 0);
       if (now > 94500l) { sequence_no_[1]++; }
       break;
     } case 67: {
       long t = constrain(now - 96200l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 523l, 30 - value);
       if (now > 96300l) { sequence_no_[1]++; }
       break;
     } case 68: {
       setBioFreq(1, 500l, 0);
       if (now > 96600l) { sequence_no_[1]++; }
       break;
     } case 69: {
       long t = constrain(now - 98300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 98400l) { sequence_no_[1]++; }
       break;
     } case 70: {
       setBioFreq(1, 500l, 0);
       if (now > 98700l) { sequence_no_[1]++; }
       break;
     } case 71: {
       long t = constrain(now - 98900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 99000l) { sequence_no_[1]++; }
       break;
     } case 72: {
       setBioFreq(1, 500l, 0);
       if (now > 100800l) { sequence_no_[1]++; }
       break;
     } case 73: {
       long t = constrain(now - 102500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 622l, 30 - value);
       if (now > 102600l) { sequence_no_[1]++; }
       break;
     } case 74: {
       setBioFreq(1, 500l, 0);
       if (now > 104400l) { sequence_no_[1]++; }
       break;
     } case 75: {
       long t = constrain(now - 106100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 330l, 30 - value);
       if (now > 106200l) { sequence_no_[1]++; }
       break;
     } case 76: {
       setBioFreq(1, 500l, 0);
       if (now > 106500l) { sequence_no_[1]++; }
       break;
     } case 77: {
       long t = constrain(now - 106700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 106800l) { sequence_no_[1]++; }
       break;
     } case 78: {
       setBioFreq(1, 500l, 0);
       if (now > 108000l) { sequence_no_[1]++; }
       break;
     } case 79: {
       long t = constrain(now - 109100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 262l, 30 - value);
       if (now > 109200l) { sequence_no_[1]++; }
       break;
     } case 80: {
       setBioFreq(1, 500l, 0);
       if (now > 110400l) { sequence_no_[1]++; }
       break;
     } case 81: {
       long t = constrain(now - 111500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 111600l) { sequence_no_[1]++; }
       break;
     } case 82: {
       setBioFreq(1, 500l, 0);
       if (now > 112800l) { sequence_no_[1]++; }
       break;
     } case 83: {
       long t = constrain(now - 115100l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 440l, 30 - value);
       if (now > 115200l) { sequence_no_[1]++; }
       break;
     } case 84: {
       setBioFreq(1, 500l, 0);
       if (now > 127800l) { sequence_no_[1]++; }
       break;
     } case 85: {
       long t = constrain(now - 128900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 622l, 30 - value);
       if (now > 129000l) { sequence_no_[1]++; }
       break;
     } case 86: {
       setBioFreq(1, 500l, 0);
       if (now > 129600l) { sequence_no_[1]++; }
       break;
     } case 87: {
       long t = constrain(now - 130700l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 659l, 30 - value);
       if (now > 130800l) { sequence_no_[1]++; }
       break;
     } case 88: {
       setBioFreq(1, 500l, 0);
       if (now > 131400l) { sequence_no_[1]++; }
       break;
     } case 89: {
       long t = constrain(now - 131900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 466l, 30 - value);
       if (now > 132000l) { sequence_no_[1]++; }
       break;
     } case 90: {
       setBioFreq(1, 500l, 0);
       if (now > 133200l) { sequence_no_[1]++; }
       break;
     } case 91: {
       long t = constrain(now - 134300l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 523l, 30 - value);
       if (now > 134400l) { sequence_no_[1]++; }
       break;
     } case 92: {
       setBioFreq(1, 500l, 0);
       if (now > 136800l) { sequence_no_[1]++; }
       break;
     } case 93: {
       long t = constrain(now - 138500l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 30, 100l);
       setBioFreq(1, 392l, 30 - value);
       if (now > 138600l) { sequence_no_[1]++; }
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
