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
       setBioFreq(0, 262l, 50);
       if (now > 1000l) { sequence_no_[0]++; }
       break;
     } case 1: {
       setBioFreq(0, 262l, 0);
       if (now > 2000l) { sequence_no_[0]++; }
       break;
     } case 2: {
       setBioFreq(0, 277l, 50);
       if (now > 3000l) { sequence_no_[0]++; }
       break;
     } default:
       setBioFreq(0, 500l, 0);
       break;
   }

   // 1
  switch (sequence_no_[1]) {
    case 0: {
      setBioFreq(1, 262l, 0);
      if (now > 1000l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBioFreq(1, 262l, 50);
      if (now > 2000l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBioFreq(1, 277l, 0);
      if (now > 3000l) { sequence_no_[1]++; }
      break;
    } case 3: {
      setBioFreq(1, 277l, 50);
      if (now > 4000l) { sequence_no_[1]++; }
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
