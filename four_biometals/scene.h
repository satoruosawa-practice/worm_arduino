#pragma once
#include "Arduino.h"
#include "global.h"
#include "ticker.h"
#include "biometal.h"
#include "biometalContainer.h"

class Scene {
 public:
  Scene(Ticker &ticker, BiometalContainer &biometals);
  void scequence();

 private:
  bool que(long from, long to);
  BiometalContainer * biometals_;
  Ticker * ticker_;
  long scequence_time_;
  long start_time_;
};

Scene::Scene(Ticker &ticker, BiometalContainer &biometals) {
  ticker_ = &ticker;
  biometals_ = &biometals;
  scequence_time_ = 0l;
  start_time_ = ticker_->ellapsedMicros();
}

void Scene::scequence() {
//  Serial.print("time: ");
//  Serial.print(ticker_->ellapsedMicros());
//  Serial.print("heat: ");
//  Serial.print(biometals_->get(0)->heatParam());
//  Serial.print("pwm: ");
//  Serial.println(biometals_->get(0)->pwm());
  if(que(2000000l, 3000000l)) {
    biometals_->get(0)->setDeg(70, ticker_->deltaMicros());
  } else if(que(3000000l, 4000000l)) {
    biometals_->get(1)->setDeg(70, ticker_->deltaMicros());
  } else if(que(4000000l, 5000000l)) {
    biometals_->get(2)->setDeg(70, ticker_->deltaMicros());
  } else if(que(5000000l, 6000000l)) {
    biometals_->get(3)->setDeg(70, ticker_->deltaMicros());
  } else {
    biometals_->get(0)->setDeg(0, ticker_->deltaMicros());
    biometals_->get(1)->setDeg(0, ticker_->deltaMicros());
    biometals_->get(2)->setDeg(0, ticker_->deltaMicros());
    biometals_->get(3)->setDeg(0, ticker_->deltaMicros());
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

//bool Scene::que(long que_time) {
////  Serial.println(que_time);
////  Serial.println(ticker_.ellapsedMicros());
//
//  if(que_time < ticker_->ellapsedMicros() - start_time_ && 
//     scequence_time_ < que_time) {
//    scequence_time_ = que_time;
//    return true;
//  } else {
//    return false;
//  }
//}

