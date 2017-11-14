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
       setBioFreq(0, 392l, 0);
       if (now > 800l) { sequence_no_[0]++; }
       break;
     } case 1: {
      int value = ease_in_cubicL(now - 800l, 0l, 70l, 800l);
      value = constrain(value, 0l, 70l);
       setBioFreq(0, 392l, value);
       if (now > 4000l) { sequence_no_[0]++; }
       break;
     } case 2: {
       setBioFreq(0, 330l, 70);
       if (now > 7200l) { sequence_no_[0]++; }
       break;
     } case 3: {
       setBioFreq(0, 370l, 0);
       if (now > 8000l) { sequence_no_[0]++; }
       break;
     } case 4: {
      int value = ease_in_cubicL(now - 8000l, 0l, 70l, 800l);
      value = constrain(value, 0l, 70l);
       setBioFreq(0, 370l, value);
       if (now > 12000l) { sequence_no_[0]++; }
       break;
     } case 5: {
       setBioFreq(0, 311l, 70);
       if (now > 15200l) { sequence_no_[0]++; }
       break;
     } case 6: {
       setBioFreq(0, 349l, 0);
       if (now > 18400l) { sequence_no_[0]++; }
       break;
     } case 7: {
       setBioFreq(0, 349l, 70);
       if (now > 20000l) { sequence_no_[0]++; }
       break;
     } case 8: {
       setBioFreq(0, 587l, 70);
       if (now > 24000l) { sequence_no_[0]++; }
       break;
     } case 9: {
       setBioFreq(0, 659l, 70);
       if (now > 26400l) { sequence_no_[0]++; }
       break;
     } case 10: {
       setBioFreq(0, 330l, 0);
       if (now > 27200l) { sequence_no_[0]++; }
       break;
     } case 11: {
       setBioFreq(0, 330l, 70);
       if (now > 28000l) { sequence_no_[0]++; }
       break;
     } case 12: {
       setBioFreq(0, 277l, 70);
       if (now > 31200l) { sequence_no_[0]++; }
       break;
     } case 13: {
       setBioFreq(0, 311l, 0);
       if (now > 32000l) { sequence_no_[0]++; }
       break;
     } default:
       setBioFreq(0, 500l, 0);
       break;
   }

   // 1
  switch (sequence_no_[1]) {
    case 0: {
      setBioFreq(1, 262l, 0);
      if (now > 9600l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBioFreq(1, 622l, 70);
      if (now > 12800l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBioFreq(1, 740l, 70);
      if (now > 16000l) { sequence_no_[1]++; }
      break;
    } case 3: {
      setBioFreq(1, 587l, 70);
      if (now > 20000l) { sequence_no_[1]++; }
      break;
    } case 4: {
      setBioFreq(1, 698l, 70);
      if (now > 22400l) { sequence_no_[1]++; }
      break;
    } case 5: {
      setBioFreq(1, 698l, 0);
      if (now > 23200l) { sequence_no_[1]++; }
      break;
    } case 6: {
      setBioFreq(1, 698l, 70);
      if (now > 24000l) { sequence_no_[1]++; }
      break;
    } case 7: {
      setBioFreq(1, 554l, 70);
      if (now > 28000l) { sequence_no_[1]++; }
      break;
    } case 8: {
      setBioFreq(1, 698l, 0);
      if (now > 28800l) { sequence_no_[1]++; }
      break;
    } case 9: {
      setBioFreq(1, 659l, 70);
      if (now > 31200l) { sequence_no_[1]++; }
      break;
    } case 10: {
      setBioFreq(1, 523l, 0);
      if (now > 32000l) { sequence_no_[1]++; }
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
