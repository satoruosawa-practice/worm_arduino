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

 private:
  bool queMicros(long from, long to);
  bool queMillis(long from, long to);
  void setBiometals(int value1, int value2, int value3, int value4);
  void setBio(int index, int value);
  BiometalContainer * biometals_;
  Ticker * ticker_;
  long sequence_time_;
  long start_time_;
};

Scene::Scene(Ticker &ticker, BiometalContainer &biometals) {
  ticker_ = &ticker;
  biometals_ = &biometals;
  sequence_time_ = 0l;
  start_time_ = ticker_->ellapsedMicros();
}

void Scene::sequence() {
  // 0
  if(queMillis(0l, 3000l)) {
    setBio(0, 70);
  } else if(queMillis(3000l, 3000l)) {
    setBio(0, 0);
  } else if(queMillis(5000l, 5500l)) {
    setBio(0, 70);
  } else if(queMillis(6000l, 8000l)) {
    setBio(0, 0);
  } else if(queMillis(8000l, 11000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 8000l, 0l, 70l, 3000l);
    setBio(0, value);
  } else if(queMillis(11000l, 14000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 11000l, 0l, 70l, 3000l);
    setBio(0, 70l - value);
  } else if(queMillis(14000l, 17000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 14000l, 0l, 70l, 3000l);
    setBio(0, value);
  } else if(queMillis(17000l, 20000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 17000l, 0, 70l, 3000l);
    setBio(0, 70l - value);
  } else if(queMillis(20000l, 23000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 20000l, 0l, 70l, 3000l);
    setBio(0, value);
  } else if(queMillis(23000l, 26000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 23000l, 0l, 70l, 3000l);
    setBio(0, 70l - value);
  } else if(queMillis(26000l, 27000l)) {
    setBio(0, 0);
  } else if(queMillis(27000l, 28000l)) {
    setBio(0, 70);
  } else {
    setBio(0, 0);
  }
  // 1
  if(queMillis(0l, 3000l)) {
    setBio(1, 0);
  } else if(queMillis(3000l, 3000l)) {
    setBio(1, 0);
  } else if(queMillis(4000l, 4500l)) {
    setBio(1, 70);
  } else if(queMillis(10000l, 14000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 10000l, 0l, 70l, 4000l);
    setBio(1, value);
  } else if(queMillis(14000l, 18000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 14000l, 0l, 70l, 4000l);
    setBio(1, 70l - value);
  } else if(queMillis(18000l, 22000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 18000l, 0l, 70l, 4000l);
    setBio(1, value);
  } else if(queMillis(22000l, 26000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 22000l, 0, 70l, 4000l);
    setBio(1, 70l - value);
  } else if(queMillis(26000l, 28000l)) {
    setBio(1, 0);
  } else if(queMillis(28000l, 30000l)) {
    setBio(1, 70);
  } else {
    setBio(1, 0);
  }
  // 2
  if(queMillis(0l, 3000l)) {
    setBio(2, 0);
  } else if(queMillis(3000l, 3000l)) {
    setBio(2, 0);
  } else if(queMillis(4500l, 5000l)) {
    setBio(2, 70);
  } else if(queMillis(12000l, 14500l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 12000l, 0l, 70l, 2000l);
    setBio(2, value);
  } else if(queMillis(14500l, 17000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 14500l, 0l, 70l, 2000l);
    setBio(2, 70l - value);
  } else if(queMillis(17000l, 19500l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 17000l, 0l, 70l, 2000l);
    setBio(2, value);
  } else if(queMillis(19500l, 22000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 19500l, 0l, 70l, 2000l);
    setBio(2, 70l - value);
  } else if(queMillis(22000l, 24500l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 22000l, 0l, 70l, 2000l);
    setBio(2, value);
  } else if(queMillis(24500l, 26000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 24500l, 0l, 70l, 2000l);
    setBio(2, 70l - value);
  } else if(queMillis(26000l, 28000l)) {
    setBio(2, 0);
  } else if(queMillis(28000l, 30000l)) {
    setBio(2, 70);
  } else {
    setBio(2, 0);
  }
  // 3
  if(queMillis(0l, 3000l)) {
    setBio(3, 70);
  } else if(queMillis(3000l, 3000l)) {
    setBio(3, 0);
  } else if(queMillis(5000l, 5500l)) {
    setBio(3, 70);
  } else if(queMillis(14000l, 17500l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 14000l, 0l, 70l, 2000l);
    setBio(3, value);
  } else if(queMillis(17500l, 21000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 17500l, 0l, 70l, 2000l);
    setBio(3, 70l - value);
  } else if(queMillis(21000l, 24500l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 21000l, 0l, 70l, 2000l);
    setBio(3, value);
  } else if(queMillis(24500l, 26000l)) {
    int value = ease_in_cubicL(ticker_->ellapsedMillis() - 24500l, 0l, 70l, 2000l);
    setBio(3, 70l - value);
  } else if(queMillis(26000l, 27000l)) {
    setBio(3, 0);
  } else if(queMillis(27000l, 28000l)) {
    setBio(3, 70);
  } else {
    setBio(3, 0);
  }
}

bool Scene::queMicros(long from, long to) {
  long now = ticker_->ellapsedMicros() - start_time_;
  if(from < now && now <= to) {
    return true;
  } else {
    return false;
  }
}

bool Scene::queMillis(long from, long to) {
  long now = ticker_->ellapsedMillis() - start_time_ / 1000l;
  if(from < now && now <= to) {
    return true;
  } else {
    return false;
  }
}

void Scene::setBio(int index, int value) {
  biometals_->get(index)->setDeg(value, ticker_->deltaMicros());
}
