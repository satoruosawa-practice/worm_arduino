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
      long t = constrain(now - 100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 200l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBioFreq(0, 500l, 0);
      if (now > 1400l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 3700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 3800l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBioFreq(0, 500l, 0);
      if (now > 4400l) { sequence_no_[0]++; }
      break;
    } case 4: {
      long t = constrain(now - 4900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 5000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      setBioFreq(0, 500l, 0);
      if (now > 5600l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 6700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 6800l) { sequence_no_[0]++; }
      break;
    } case 7: {
      setBioFreq(0, 500l, 0);
      if (now > 7400l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 7900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 9: {
      setBioFreq(0, 500l, 0);
      if (now > 9800l) { sequence_no_[0]++; }
      break;
    } case 10: {
      long t = constrain(now - 11500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1175l, 30 - value);
      if (now > 11600l) { sequence_no_[0]++; }
      break;
    } case 11: {
      setBioFreq(0, 500l, 0);
      if (now > 12200l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 14500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 14600l) { sequence_no_[0]++; }
      break;
    } case 13: {
      setBioFreq(0, 500l, 0);
      if (now > 16400l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 17500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 17600l) { sequence_no_[0]++; }
      break;
    } case 15: {
      setBioFreq(0, 500l, 0);
      if (now > 19400l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 19600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 19700l) { sequence_no_[0]++; }
      break;
    } case 17: {
      setBioFreq(0, 500l, 0);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 20200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 20300l) { sequence_no_[0]++; }
      break;
    } case 19: {
      setBioFreq(0, 500l, 0);
      if (now > 20600l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 22300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1245l, 30 - value);
      if (now > 22400l) { sequence_no_[0]++; }
      break;
    } case 21: {
      setBioFreq(0, 500l, 0);
      if (now > 24200l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 24700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 24800l) { sequence_no_[0]++; }
      break;
    } case 23: {
      setBioFreq(0, 500l, 0);
      if (now > 25400l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 26500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1319l, 30 - value);
      if (now > 26600l) { sequence_no_[0]++; }
      break;
    } case 25: {
      setBioFreq(0, 500l, 0);
      if (now > 27200l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 27700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 988l, 30 - value);
      if (now > 27800l) { sequence_no_[0]++; }
      break;
    } case 27: {
      setBioFreq(0, 500l, 0);
      if (now > 29000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 29500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 29600l) { sequence_no_[0]++; }
      break;
    } case 29: {
      setBioFreq(0, 500l, 0);
      if (now > 31400l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 33100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 33200l) { sequence_no_[0]++; }
      break;
    } case 31: {
      setBioFreq(0, 500l, 0);
      if (now > 33800l) { sequence_no_[0]++; }
      break;
    } case 32: {
      long t = constrain(now - 34300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 34400l) { sequence_no_[0]++; }
      break;
    } case 33: {
      setBioFreq(0, 500l, 0);
      if (now > 36200l) { sequence_no_[0]++; }
      break;
    } case 34: {
      long t = constrain(now - 37900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 294l, 30 - value);
      if (now > 38000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      setBioFreq(0, 500l, 0);
      if (now > 38600l) { sequence_no_[0]++; }
      break;
    } case 36: {
      long t = constrain(now - 39100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 659l, 30 - value);
      if (now > 39200l) { sequence_no_[0]++; }
      break;
    } case 37: {
      setBioFreq(0, 500l, 0);
      if (now > 39800l) { sequence_no_[0]++; }
      break;
    } case 38: {
      long t = constrain(now - 40300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 40400l) { sequence_no_[0]++; }
      break;
    } case 39: {
      setBioFreq(0, 500l, 0);
      if (now > 42200l) { sequence_no_[0]++; }
      break;
    } case 40: {
      long t = constrain(now - 42400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1109l, 30 - value);
      if (now > 42500l) { sequence_no_[0]++; }
      break;
    } case 41: {
      setBioFreq(0, 500l, 0);
      if (now > 42800l) { sequence_no_[0]++; }
      break;
    } case 42: {
      long t = constrain(now - 43900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 44000l) { sequence_no_[0]++; }
      break;
    } case 43: {
      setBioFreq(0, 500l, 0);
      if (now > 45200l) { sequence_no_[0]++; }
      break;
    } case 44: {
      long t = constrain(now - 45700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 622l, 30 - value);
      if (now > 45800l) { sequence_no_[0]++; }
      break;
    } case 45: {
      setBioFreq(0, 500l, 0);
      if (now > 46400l) { sequence_no_[0]++; }
      break;
    } case 46: {
      long t = constrain(now - 46900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 47000l) { sequence_no_[0]++; }
      break;
    } case 47: {
      setBioFreq(0, 500l, 0);
      if (now > 47600l) { sequence_no_[0]++; }
      break;
    } case 48: {
      long t = constrain(now - 49300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 330l, 30 - value);
      if (now > 49400l) { sequence_no_[0]++; }
      break;
    } case 49: {
      setBioFreq(0, 500l, 0);
      if (now > 51200l) { sequence_no_[0]++; }
      break;
    } case 50: {
      long t = constrain(now - 51700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 247l, 30 - value);
      if (now > 51800l) { sequence_no_[0]++; }
      break;
    } case 51: {
      setBioFreq(0, 500l, 0);
      if (now > 52400l) { sequence_no_[0]++; }
      break;
    } case 52: {
      long t = constrain(now - 53500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 53600l) { sequence_no_[0]++; }
      break;
    } case 53: {
      setBioFreq(0, 500l, 0);
      if (now > 54200l) { sequence_no_[0]++; }
      break;
    } case 54: {
      long t = constrain(now - 54700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 54800l) { sequence_no_[0]++; }
      break;
    } case 55: {
      setBioFreq(0, 500l, 0);
      if (now > 56000l) { sequence_no_[0]++; }
      break;
    } case 56: {
      long t = constrain(now - 56500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 56600l) { sequence_no_[0]++; }
      break;
    } case 57: {
      setBioFreq(0, 500l, 0);
      if (now > 57800l) { sequence_no_[0]++; }
      break;
    } case 58: {
      long t = constrain(now - 58300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 294l, 30 - value);
      if (now > 58400l) { sequence_no_[0]++; }
      break;
    } case 59: {
      setBioFreq(0, 500l, 0);
      if (now > 59600l) { sequence_no_[0]++; }
      break;
    } case 60: {
      long t = constrain(now - 61300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 61400l) { sequence_no_[0]++; }
      break;
    } case 61: {
      setBioFreq(0, 500l, 0);
      if (now > 61850l) { sequence_no_[0]++; }
      break;
    } case 62: {
      long t = constrain(now - 62200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 494l, 30 - value);
      if (now > 62300l) { sequence_no_[0]++; }
      break;
    } case 63: {
      setBioFreq(0, 500l, 0);
      if (now > 62750l) { sequence_no_[0]++; }
      break;
    } case 64: {
      long t = constrain(now - 62950l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 554l, 30 - value);
      if (now > 63050l) { sequence_no_[0]++; }
      break;
    } case 65: {
      setBioFreq(0, 500l, 0);
      if (now > 63500l) { sequence_no_[0]++; }
      break;
    } case 66: {
      long t = constrain(now - 63700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 196l, 30 - value);
      if (now > 63800l) { sequence_no_[0]++; }
      break;
    } case 67: {
      setBioFreq(0, 500l, 0);
      if (now > 64100l) { sequence_no_[0]++; }
      break;
    } case 68: {
      long t = constrain(now - 64300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 311l, 30 - value);
      if (now > 64400l) { sequence_no_[0]++; }
      break;
    } case 69: {
      setBioFreq(0, 500l, 0);
      if (now > 64700l) { sequence_no_[0]++; }
      break;
    } case 70: {
      long t = constrain(now - 64900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 587l, 30 - value);
      if (now > 65000l) { sequence_no_[0]++; }
      break;
    } case 71: {
      setBioFreq(0, 500l, 0);
      if (now > 65300l) { sequence_no_[0]++; }
      break;
    } case 72: {
      setBioFreq(0, 2637l, 30);
      if (now > 68900l) { sequence_no_[0]++; }
      break;
    } case 73: {
      long t = constrain(now - 72400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 2637l, 30 - value);
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
      setBioFreq(1, 500l, 0);
      if (now > 800l) { sequence_no_[1]++; }
      break;
    } case 1: {
      long t = constrain(now - 2500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 622l, 30 - value);
      if (now > 2600l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBioFreq(1, 500l, 0);
      if (now > 4400l) { sequence_no_[1]++; }
      break;
    } case 3: {
      long t = constrain(now - 6100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 330l, 30 - value);
      if (now > 6200l) { sequence_no_[1]++; }
      break;
    } case 4: {
      setBioFreq(1, 500l, 0);
      if (now > 6500l) { sequence_no_[1]++; }
      break;
    } case 5: {
      long t = constrain(now - 6700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 466l, 30 - value);
      if (now > 6800l) { sequence_no_[1]++; }
      break;
    } case 6: {
      setBioFreq(1, 500l, 0);
      if (now > 8000l) { sequence_no_[1]++; }
      break;
    } case 7: {
      long t = constrain(now - 9100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 9200l) { sequence_no_[1]++; }
      break;
    } case 8: {
      setBioFreq(1, 500l, 0);
      if (now > 10400l) { sequence_no_[1]++; }
      break;
    } case 9: {
      long t = constrain(now - 11500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 392l, 30 - value);
      if (now > 11600l) { sequence_no_[1]++; }
      break;
    } case 10: {
      setBioFreq(1, 500l, 0);
      if (now > 12800l) { sequence_no_[1]++; }
      break;
    } case 11: {
      long t = constrain(now - 15100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 440l, 30 - value);
      if (now > 15200l) { sequence_no_[1]++; }
      break;
    } case 12: {
      setBioFreq(1, 500l, 0);
      if (now > 27800l) { sequence_no_[1]++; }
      break;
    } case 13: {
      long t = constrain(now - 28900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 622l, 30 - value);
      if (now > 29000l) { sequence_no_[1]++; }
      break;
    } case 14: {
      setBioFreq(1, 500l, 0);
      if (now > 29600l) { sequence_no_[1]++; }
      break;
    } case 15: {
      long t = constrain(now - 30700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 659l, 30 - value);
      if (now > 30800l) { sequence_no_[1]++; }
      break;
    } case 16: {
      setBioFreq(1, 500l, 0);
      if (now > 31400l) { sequence_no_[1]++; }
      break;
    } case 17: {
      long t = constrain(now - 31900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 466l, 30 - value);
      if (now > 32000l) { sequence_no_[1]++; }
      break;
    } case 18: {
      setBioFreq(1, 500l, 0);
      if (now > 33200l) { sequence_no_[1]++; }
      break;
    } case 19: {
      long t = constrain(now - 34300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 34400l) { sequence_no_[1]++; }
      break;
    } case 20: {
      setBioFreq(1, 500l, 0);
      if (now > 36800l) { sequence_no_[1]++; }
      break;
    } case 21: {
      long t = constrain(now - 38500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 392l, 30 - value);
      if (now > 38600l) { sequence_no_[1]++; }
      break;
    } case 22: {
      setBioFreq(1, 500l, 0);
      if (now > 40400l) { sequence_no_[1]++; }
      break;
    } case 23: {
      long t = constrain(now - 40900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 440l, 30 - value);
      if (now > 41000l) { sequence_no_[1]++; }
      break;
    } case 24: {
      setBioFreq(1, 500l, 0);
      if (now > 41600l) { sequence_no_[1]++; }
      break;
    } case 25: {
      long t = constrain(now - 42700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 311l, 30 - value);
      if (now > 42800l) { sequence_no_[1]++; }
      break;
    } case 26: {
      setBioFreq(1, 500l, 0);
      if (now > 44000l) { sequence_no_[1]++; }
      break;
    } case 27: {
      long t = constrain(now - 44500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 330l, 30 - value);
      if (now > 44600l) { sequence_no_[1]++; }
      break;
    } case 28: {
      setBioFreq(1, 500l, 0);
      if (now > 45200l) { sequence_no_[1]++; }
      break;
    } case 29: {
      long t = constrain(now - 45700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 466l, 30 - value);
      if (now > 45800l) { sequence_no_[1]++; }
      break;
    } case 30: {
      setBioFreq(1, 500l, 0);
      if (now > 47000l) { sequence_no_[1]++; }
      break;
    } case 31: {
      long t = constrain(now - 48100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 48200l) { sequence_no_[1]++; }
      break;
    } case 32: {
      setBioFreq(1, 500l, 0);
      if (now > 48500l) { sequence_no_[1]++; }
      break;
    } case 33: {
      long t = constrain(now - 48700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 392l, 30 - value);
      if (now > 48800l) { sequence_no_[1]++; }
      break;
    } case 34: {
      setBioFreq(1, 500l, 0);
      if (now > 49100l) { sequence_no_[1]++; }
      break;
    } case 35: {
      setBioFreq(1, 880l, 30);
      if (now > 49400l) { sequence_no_[1]++; }
      break;
    } case 36: {
      long t = constrain(now - 50500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 50600l) { sequence_no_[1]++; }
      break;
    } case 37: {
      setBioFreq(1, 500l, 0);
      if (now > 51200l) { sequence_no_[1]++; }
      break;
    } case 38: {
      long t = constrain(now - 52000l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 622l, 30 - value);
      if (now > 52100l) { sequence_no_[1]++; }
      break;
    } case 39: {
      setBioFreq(1, 500l, 0);
      if (now > 53000l) { sequence_no_[1]++; }
      break;
    } case 40: {
      long t = constrain(now - 53800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 659l, 30 - value);
      if (now > 53900l) { sequence_no_[1]++; }
      break;
    } case 41: {
      setBioFreq(1, 500l, 0);
      if (now > 55100l) { sequence_no_[1]++; }
      break;
    } case 42: {
      long t = constrain(now - 56200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 466l, 30 - value);
      if (now > 56300l) { sequence_no_[1]++; }
      break;
    } case 43: {
      setBioFreq(1, 500l, 0);
      if (now > 57200l) { sequence_no_[1]++; }
      break;
    } case 44: {
      long t = constrain(now - 58000l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 58100l) { sequence_no_[1]++; }
      break;
    } case 45: {
      setBioFreq(1, 500l, 0);
      if (now > 59000l) { sequence_no_[1]++; }
      break;
    } case 46: {
      long t = constrain(now - 59800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 392l, 30 - value);
      if (now > 59900l) { sequence_no_[1]++; }
      break;
    } case 47: {
      setBioFreq(1, 500l, 0);
      if (now > 61700l) { sequence_no_[1]++; }
      break;
    } case 48: {
      setBioFreq(1, 880l, 30);
      if (now > 65300l) { sequence_no_[1]++; }
      break;
    } case 49: {
      long t = constrain(now - 68800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 68900l) { sequence_no_[1]++; }
      break;
    } case 50: {
      long t = constrain(now - 72400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 72500l) { sequence_no_[1]++; }
      break;
    } case 51: {
      long t = constrain(now - 72700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 880l, 30 - value);
      if (now > 72800l) { sequence_no_[1]++; }
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
