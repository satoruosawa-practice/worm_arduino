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
  if(que(0l, 3000000l)) {
    setBiometals(70, 0, 0, 0);
  } else if(que(3000000l, 4000000l)) {
    setBiometals(0, 70, 0, 0);
  } else if(que(4000000l, 5000000l)) {
    setBiometals(0, 0, 70, 0);
  } else if(que(5000000l, 6000000l)) {
    setBiometals(0, 0, 0, 70);
  } else {
    setBiometals(0, 0, 0, 0);
  }
}

bool Scene::que(long from, long to) {
  long now = ticker_->ellapsedMicros() - start_time_;
  if(from < now && now < to) {
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

