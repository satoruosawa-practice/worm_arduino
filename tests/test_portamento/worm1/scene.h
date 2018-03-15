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
  float frequency;
  float phase;

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
  frequency = 30.0;
  phase = 0.0;
}

void Scene::reset() {
  for (int i = 0; i < biometals_->size(); i++) {
    sequence_no_ [i] = 0;
  }
}

void Scene::sequence() {
  long now = ticker_->ellapsedMillis();
  // 0
  // switch (sequence_no_[0]) {
  //   case 0: {
  //     long t = constrain(now - 1100l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 30, 100l);
  //     setBioFreq(0, 415l, 30 - value);
  //     if (now > 1200l) { sequence_no_[0]++; }
  //     break;
  //   } case 1: {
  //     setBioFreq(0, 500l, 0);
  //     if (now > 1800l) { sequence_no_[0]++; }
  //     break;
  //   } case 2: {
  //     long t = constrain(now - 3500l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 30, 100l);
  //     setBioFreq(0, 440l, 30 - value);
  //     if (now > 3600l) { sequence_no_[0]++; }
  //     break;
  //   } case 3: {
  //     setBioFreq(0, 500l, 0);
  //     if (now > 4800l) { sequence_no_[0]++; }
  //     break;
  //   } case 4: {
  //     long t = constrain(now - 5300l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 30, 100l);
  //     setBioFreq(0, 523l, 30 - value);
  //     if (now > 5400l) { sequence_no_[0]++; }
  //     break;
  //   } default:
  //     setBioFreq(0, 500l, 0);
  //     break;
  // }
  setBioFreq(0, (long)frequency, (int)(20 * (1.2 + sin(phase)) / 2.2));
  phase += 0.0005;
  frequency = frequency * 1.00003;
  // 1
}
