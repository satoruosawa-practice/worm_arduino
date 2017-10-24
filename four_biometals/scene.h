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
  bool que(long from, long to);
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
  if(que(0l, 118500000l)) {
    if((ticker_->ellapsedMicros() / 1000000l)%14 == 0) {  // 14sec
     setBio(0, 70);
    } else if((ticker_->ellapsedMicros() / 1000000l)%14 == 7) {
     setBio(0, 50);
    } else {
      setBio(0, 0);
    }
  } else {
    setBio(0, 0);
  }
  // 1
  if(que(0l, 118500000l)) {
    if((ticker_->ellapsedMicros() / 100000l)%100 == 0) {
     setBio(1, 70);
    } else if((ticker_->ellapsedMicros() / 100000l)%100 == 50) {
     setBio(1, 50);
    } else {
      setBio(1, 0);
    }
  } else {
    setBio(1, 0);
  }
  // 2
  if(que(0l, 118500000l)) {
    if((ticker_->ellapsedMicros() / 2250000l)%2 == 0) {
     setBio(2, 70);
    } else {
      setBio(2, 0);
    }
  } else {
    setBio(2, 0);
  }
  // 3
  if(que(0l, 118500000l)) {
    if((ticker_->ellapsedMicros() / 2000000l)%2 == 0) {
     setBio(3, 70);
    } else {
      setBio(3, 0);
    }
  } else {
    setBio(3, 0);
  }

}

bool Scene::que(long from, long to) {
  long now = ticker_->ellapsedMicros() - start_time_;
  if(from < now && now <= to) {
    return true;
  } else {
    return false;
  }
}

void Scene::setBiometals(int value1, int value2, int value3, int value4) {
  biometals_->get(0)->setDeg(value1, ticker_->deltaMicros());
  biometals_->get(1)->setDeg(value2, ticker_->deltaMicros());
  biometals_->get(2)->setDeg(value3, ticker_->deltaMicros());
  biometals_->get(3)->setDeg(value4, ticker_->deltaMicros());
}

void Scene::setBio(int index, int value) {
  biometals_->get(index)->setDeg(value, ticker_->deltaMicros());
}

