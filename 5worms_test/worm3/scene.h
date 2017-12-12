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


  // 0
   switch (sequence_no_[0]) {
     case 0: {
       setBioFreq(0, 480l, 0);
       if (now > 5000l) { sequence_no_[0]++; }
       break;
     } case 1: {
       setBioFreq(0, 480l, 40);
       if (now > 5100l) { sequence_no_[0]++; }
       break;
     } case 2: {
      setBioFreq(0, 392l, 0);
       if (now > 6250l) { sequence_no_[0]++; }
       break;
     } case 3: {
       setBioFreq(0, 480l, 40);
       if (now > 6350l) { sequence_no_[0]++; }
       break;
     } case 4: {
      setBioFreq(0, 392l, 0);
       if (now > 7500l) { sequence_no_[0]++; }
       break;
     } case 5: {
       setBioFreq(0, 480l, 40);
       if (now > 7600l) { sequence_no_[0]++; }
       break;
     } case 6: {
      setBioFreq(0, 392l, 0);
       if (now > 8750l) { sequence_no_[0]++; }
       break;
     } case 7: {
       setBioFreq(0, 480l, 40);
       if (now > 8850l) { sequence_no_[0]++; }
       break;
     } default:
       setBioFreq(0, 500l, 0);
       break;
   }

   // 1
  switch (sequence_no_[1]) {
    case 0: {
      setBioFreq(1, 262l, 0);
      if (now > 5625l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBioFreq(1, 840l, 40);
      if (now > 5725l) { sequence_no_[1]++; }
      break;
    } case 2: {
       setBioFreq(1, 440l, 0);
       if (now > 6875l) { sequence_no_[1]++; }
       break;
    } case 3: {
      setBioFreq(1, 840l, 40);
      if (now > 6975l) { sequence_no_[1]++; }
      break;
    } case 4: {
       setBioFreq(1, 440l, 0);
       if (now > 8125l) { sequence_no_[1]++; }
       break;
    } case 5: {
      setBioFreq(1, 840l, 40);
      if (now > 8225l) { sequence_no_[1]++; }
      break;
    } case 6: {
       setBioFreq(1, 440l, 0);
       if (now > 9375l) { sequence_no_[1]++; }
       break;
    } case 7: {
      setBioFreq(1, 840l, 40);
      if (now > 9475l) { sequence_no_[1]++; }
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
