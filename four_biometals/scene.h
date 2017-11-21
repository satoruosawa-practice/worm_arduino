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
      setBio(0, 0);
      if (now > 2500l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBio(0, 70);
      if (now > 2700l) { sequence_no_[0]++; }
      break;
    } case 2: {
      setBio(0, 0);
      if (now > 7750l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBio(0, 70);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 4: {
      setBio(0, 0);
      if (now > 12750l) { sequence_no_[0]++; }
      break;
    } case 5: {
      setBio(0, 70);
      if (now > 13000l) { sequence_no_[0]++; }
      break;
    } case 6: {
      setBio(0, 0);
      if (now > 17750l) { sequence_no_[0]++; }
      break;
    } case 7: {
      setBio(0, 70);
      if (now > 18000l) { sequence_no_[0]++; }
      break;
    } case 8: {
      setBio(0, 0);
      if (now > 22750l) { sequence_no_[0]++; }
      break;
    } case 9: {
      setBio(0, 70);
      if (now > 23000l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBio(0, 0);
      if (now > 27750l) { sequence_no_[0]++; }
      break;
    } case 11: {
      setBio(0, 70);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    } case 12: {
      setBio(0, 0);
      if (now > 32750l) { sequence_no_[0]++; }
      break;
    } case 13: {
      setBio(0, 70);
      if (now > 33000l) { sequence_no_[0]++; }
      break;
    } case 14: {
      setBio(0, 0);
      if (now > 37750l) { sequence_no_[0]++; }
      break;
    } case 15: {
      setBio(0, 70);
      if (now > 38000l) { sequence_no_[0]++; }
      break;
    } case 16: {
      setBio(0, 0);
      if (now > 42750l) { sequence_no_[0]++; }
      break;
    } case 17: {
      setBio(0, 70);
      if (now > 43000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      setBio(0, 0);
      if (now > 47750l) { sequence_no_[0]++; }
      break;
    } case 19: {
      setBio(0, 70);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    } case 20: {
      setBio(0, 0);
      if (now > 52750l) { sequence_no_[0]++; }
      break;
    } case 21: {
      setBio(0, 70);
      if (now > 53000l) { sequence_no_[0]++; }
      break;
    } case 22: {
      setBio(0, 0);
      if (now > 57750l) { sequence_no_[0]++; }
      break;
    } case 23: {
      setBio(0, 70);
      if (now > 58000l) { sequence_no_[0]++; }
      break;
    } case 24: {
      setBio(0, 0);
      if (now > 62750l) { sequence_no_[0]++; }
      break;
    } case 25: {
      setBio(0, 70);
      if (now > 63000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      setBio(0, 0);
      if (now > 67750l) { sequence_no_[0]++; }
      break;
    } case 27: {
      setBio(0, 70);
      if (now > 68000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      setBio(0, 0);
      if (now > 72750l) { sequence_no_[0]++; }
      break;
    } case 29: {
      setBio(0, 70);
      if (now > 73000l) { sequence_no_[0]++; }
      break;
    } case 30: {
      setBio(0, 0);
      if (now > 77750l) { sequence_no_[0]++; }
      break;
    } case 31: {
      setBio(0, 70);
      if (now > 78000l) { sequence_no_[0]++; }
      break;
    } case 32: {
      setBio(0, 0);
      if (now > 82750l) { sequence_no_[0]++; }
      break;
    } case 33: {
      setBio(0, 70);
      if (now > 83000l) { sequence_no_[0]++; }
      break;
    } case 34: {
      setBio(0, 0);
      if (now > 87750l) { sequence_no_[0]++; }
      break;
    } case 35: {
      setBio(0, 70);
      if (now > 88000l) { sequence_no_[0]++; }
      break;
    } default:
      setBio(0, 0);
      break;
  }

  // 1
  switch (sequence_no_[1] % 2) {
    case 0: {
      setBio(1, 0);
      if (now > 750l + long(sequence_no_[1]) * 750l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBio(1, 70);
      if (now > 800l + long(sequence_no_[1] - 1) * 750l) { sequence_no_[1]++; }
      break;
    } default:
      setBio(1, 0);
      break;
  }

  // 2
  switch (sequence_no_[2] % 2) {
    case 0: {
      setBio(2, 70);
      if (now > 200l + long(sequence_no_[2]) * 2000l) { sequence_no_[2]++; }
      break;
    } case 1: {
      setBio(2, 0);
      if (now > 4000l + long(sequence_no_[2] - 1) * 2000l) { sequence_no_[2]++; }
      break;
    } default:
      setBio(2, 0);
      break;
  }

   // 3
   switch (sequence_no_[3] % 4) {
     case 0: {
       int value = ease_in_cubicL(now - long(sequence_no_[3]) * 1250l, 0l, 70l, 200l);
       setBio(3, value);
       if (now > 200l + long(sequence_no_[3]) * 1250l) { sequence_no_[3]++; }
       break;
     } case 1: {
       setBio(3, 0);
       if (now > 500l + long(sequence_no_[3] - 1) * 1250l) { sequence_no_[3]++; }
       break;
     } case 2: {
       int value = ease_in_cubicL(now - 500l - long(sequence_no_[3] - 2) * 1250l, 0l, 70l, 500l);
       setBio(3, value);
       if (now > 1500l + long(sequence_no_[3] - 2) * 1250l) { sequence_no_[3]++; }
       break;
     } case 3: {
       setBio(3, 0);
       if (now > 5000l + long(sequence_no_[3] - 3) * 1250l) { sequence_no_[3]++; }
       break;
     } default:
       setBio(3, 0);
       break;
   }
}
