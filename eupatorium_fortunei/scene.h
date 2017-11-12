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
      setBio(0, 70);
      if (now > 3000l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBio(0, 0);
      if (now > 5000l) { sequence_no_[0]++; }
      break;
    } case 2: {
      setBio(0, 70);
      if (now > 5500l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBio(0, 0);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    } case 4: {
      int value = ease_in_cubicL(now - 8000l, 0l, 70l, 3000l);
      setBio(0, value);
      if (now > 11000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      int value = ease_in_cubicL(now - 11000l, 0l, 70l, 3000l);
      setBio(0, 70l - value);
      if (now > 14000l) { sequence_no_[0]++; }
      break;
    } case 6: {
      int value = ease_in_cubicL(now - 14000l, 0l, 70l, 3000l);
      setBio(0, value);
      if (now > 17000l) { sequence_no_[0]++; }
      break;
    } case 7: {
      int value = ease_in_cubicL(now - 17000l, 0l, 70l, 3000l);
      setBio(0, 70l - value);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    } case 8: {
      int value = ease_in_cubicL(now - 20000l, 0l, 70l, 3000l);
      setBio(0, value);
      if (now > 23000l) { sequence_no_[0]++; }
      break;
    } case 9: {
      int value = ease_in_cubicL(now - 23000l, 0l, 70l, 3000l);
      setBio(0, 70l - value);
      if (now > 26000l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBio(0, 0);
      if (now > 27000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      setBio(0, 70);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    } default:
      setBio(0, 0);
      break;
  }

  // 1
  switch (sequence_no_[1]) {
    case 0: {
      setBio(1, 0);
      if (now > 4000l) { sequence_no_[1]++; }
      break;
    } case 1: {
      setBio(1, 70);
      if (now > 4500l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBio(1, 0);
      if (now > 10000l) { sequence_no_[1]++; }
      break;
    } case 3: {
      int value = ease_in_cubicL(now - 10000l, 0l, 70l, 4000l);
      setBio(1, value);
      if (now > 14000l) { sequence_no_[1]++; }
      break;
    } case 4: {
      int value = ease_in_cubicL(now - 14000l, 0l, 70l, 4000l);
      setBio(1, 70l - value);
      if (now > 18000l) { sequence_no_[1]++; }
      break;
    } case 5: {
      int value = ease_in_cubicL(now - 18000l, 0l, 70l, 4000l);
      setBio(1, value);
      if (now > 22000l) { sequence_no_[1]++; }
      break;
    } case 6: {
      int value = ease_in_cubicL(now - 22000l, 0l, 70l, 4000l);
      setBio(1, 70l - value);
      if (now > 26000l) { sequence_no_[1]++; }
      break;
    } case 7: {
      setBio(1, 0);
      if (now > 28000l) { sequence_no_[1]++; }
      break;
    } case 8: {
      setBio(1, 70);
      if (now > 30000l) { sequence_no_[1]++; }
      break;
    } default:
      setBio(1, 0);
      break;
  }

  // 2
  switch (sequence_no_[2]) {
    case 0: {
      setBio(2, 0);
      if (now > 4500l) { sequence_no_[2]++; }
      break;
    } case 1: {
      setBio(2, 70);
      if (now > 5000l) { sequence_no_[2]++; }
      break;
    } case 2: {
      setBio(2, 0);
      if (now > 12000l) { sequence_no_[2]++; }
      break;
    } case 3: {
      int value = ease_in_cubicL(now - 12000l, 0l, 70l, 2500l);
      setBio(2, value);
      if (now > 14500l) { sequence_no_[2]++; }
      break;
    } case 4: {
      int value = ease_in_cubicL(now - 14500l, 0l, 70l, 2500l);
      setBio(2, 70l - value);
      if (now > 17000l) { sequence_no_[2]++; }
      break;
    } case 5: {
      int value = ease_in_cubicL(now - 17000l, 0l, 70l, 2500l);
      setBio(2, value);
      if (now > 19500l) { sequence_no_[2]++; }
      break;
    } case 6: {
      int value = ease_in_cubicL(now - 19500l, 0l, 70l, 2500l);
      setBio(2, 70l - value);
      if (now > 22000l) { sequence_no_[2]++; }
      break;
    } case 7: {
      int value = ease_in_cubicL(now - 22000l, 0l, 70l, 2500l);
      setBio(2, value);
      if (now > 24500l) { sequence_no_[2]++; }
      break;
    } case 8: {
      int value = ease_in_cubicL(now - 24500l, 0l, 70l, 1500l);
      setBio(2, 70l - value);
      if (now > 26000l) { sequence_no_[2]++; }
      break;
    } case 9: {
      setBio(2, 0);
      if (now > 28000l) { sequence_no_[2]++; }
      break;
    } case 10: {
      setBio(2, 70);
      if (now > 30000l) { sequence_no_[2]++; }
      break;
    } default:
      setBio(2, 0);
      break;
  }

  // 3
  switch (sequence_no_[3]) {
    case 0: {
      setBio(3, 0);
      if (now > 5000l) { sequence_no_[3]++; }
      break;
    } case 1: {
      setBio(3, 70);
      if (now > 5500l) { sequence_no_[3]++; }
      break;
    } case 2: {
      setBio(3, 0);
      if (now > 14000l) { sequence_no_[3]++; }
      break;
    } case 3: {
      int value = ease_in_cubicL(now - 14000l, 0l, 70l, 3500l);
      setBio(3, value);
      if (now > 17500l) { sequence_no_[3]++; }
      break;
    } case 4: {
      int value = ease_in_cubicL(now - 17500l, 0l, 70l, 3500l);
      setBio(3, 70l - value);
      if (now > 21000l) { sequence_no_[3]++; }
      break;
    } case 5: {
      int value = ease_in_cubicL(now - 21000l, 0l, 70l, 3500l);
      setBio(3, value);
      if (now > 24500l) { sequence_no_[3]++; }
      break;
    } case 6: {
      int value = ease_in_cubicL(now - 24500l, 0l, 70l, 1500l);
      setBio(3, 70l - value);
      if (now > 26000l) { sequence_no_[3]++; }
      break;
    } case 7: {
      setBio(3, 0);
      if (now > 27000l) { sequence_no_[3]++; }
      break;
    } case 8: {
      setBio(3, 70);
      if (now > 28000l) { sequence_no_[3]++; }
      break;
    } default:
      setBio(3, 0);
      break;
  }
}
