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


  //     long t = constrain(now - 11200l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //      setBioFreq(0, 370l, value);
  //      if (now > 12000l) { sequence_no_[0]++; }
  //      break;

  // 0
  switch (sequence_no_[0]) {
    case 0: {
      long t = constrain(now - 900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 392l, 10 - value);
      if (now > 1000l) { sequence_no_[0]++; }
      break;
    } case 1: {
      long t = constrain(now - 2900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 392l, 10 - value);
      if (now > 3000l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 3900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 494l, 10 - value);
      if (now > 4000l) { sequence_no_[0]++; }
      break;
    } case 3: {
      long t = constrain(now - 5900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 740l, 10 - value);
      if (now > 6000l) { sequence_no_[0]++; }
      break;
    } case 4: {
      long t = constrain(now - 6900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 7000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 8900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 784l, 10 - value);
      if (now > 9000l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 9900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 494l, 10 - value);
      if (now > 10000l) { sequence_no_[0]++; }
      break;
    } case 7: {
      long t = constrain(now - 11900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 13900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 1245l, 10 - value);
      if (now > 14000l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 17900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 784l, 10 - value);
      if (now > 18000l) { sequence_no_[0]++; }
      break;
    } case 10: {
      long t = constrain(now - 21900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 988l, 10 - value);
      if (now > 22000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 22400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 740l, 10 - value);
      if (now > 22500l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 22900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 23000l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 23900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 392l, 10 - value);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 24900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 494l, 10 - value);
      if (now > 25000l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 25900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 26000l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 27900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 28900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 196l, 10 - value);
      if (now > 29000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 29233l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 247l, 10 - value);
      if (now > 29333l) { sequence_no_[0]++; }
      break;
    } case 19: {
      long t = constrain(now - 29567l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 29667l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 29900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 30000l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 30900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 784l, 10 - value);
      if (now > 31000l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 32900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 784l, 10 - value);
      if (now > 33000l) { sequence_no_[0]++; }
      break;
    } case 23: {
      long t = constrain(now - 34900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 988l, 10 - value);
      if (now > 35000l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } case 25: {
      long t = constrain(now - 36900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 37000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 38900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 392l, 10 - value);
      if (now > 39000l) { sequence_no_[0]++; }
      break;
    } case 27: {
      long t = constrain(now - 39900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 494l, 10 - value);
      if (now > 40000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 41900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 42000l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 44900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 311l, 10 - value);
      if (now > 45000l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 47900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 392l, 10 - value);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 48900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 247l, 10 - value);
      if (now > 49000l) { sequence_no_[0]++; }
      break;
    } case 32: {
      long t = constrain(now - 50900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 370l, 10 - value);
      if (now > 51000l) { sequence_no_[0]++; }
      break;
    } case 33: {
      long t = constrain(now - 52900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 622l, 10 - value);
      if (now > 53000l) { sequence_no_[0]++; }
      break;
    } case 34: {
      setBioFreq(0, 784l, 10);
      if (now > 54000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 54900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 784l, 10 - value);
      if (now > 55000l) { sequence_no_[0]++; }
      break;
    } case 36: {
      long t = constrain(now - 55900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 494l, 10 - value);
      if (now > 56000l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 56900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 185l, 10 - value);
      if (now > 57000l) { sequence_no_[0]++; }
      break;
    } case 38: {
      long t = constrain(now - 59900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 311l, 10 - value);
      if (now > 60000l) { sequence_no_[0]++; }
      break;
    } case 39: {
      long t = constrain(now - 62900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 311l, 10 - value);
      if (now > 63000l) { sequence_no_[0]++; }
      break;
    } case 40: {
      setBioFreq(0, 500l, 0);
      if (now > 66000l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }
   // 1
   switch (sequence_no_[1]) {
     case 0: {
       setBioFreq(1, 500l, 0);
       if (now > 1000l) { sequence_no_[1]++; }
       break;
     } case 1: {
       long t = constrain(now - 2900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 311l, 10 - value);
       if (now > 3000l) { sequence_no_[1]++; }
       break;
     } case 2: {
       long t = constrain(now - 4900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 5000l) { sequence_no_[1]++; }
       break;
     } case 3: {
       setBioFreq(1, 587l, 10);
       if (now > 6000l) { sequence_no_[1]++; }
       break;
     } case 4: {
       long t = constrain(now - 6900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 7000l) { sequence_no_[1]++; }
       break;
     } case 5: {
       long t = constrain(now - 8900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 9000l) { sequence_no_[1]++; }
       break;
     } case 6: {
       long t = constrain(now - 9400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 9500l) { sequence_no_[1]++; }
       break;
     } case 7: {
       long t = constrain(now - 10400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 10500l) { sequence_no_[1]++; }
       break;
     } case 8: {
       long t = constrain(now - 10900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 11000l) { sequence_no_[1]++; }
       break;
     } case 9: {
       long t = constrain(now - 11900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 988l, 10 - value);
       if (now > 12000l) { sequence_no_[1]++; }
       break;
     } case 10: {
       long t = constrain(now - 12900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 13000l) { sequence_no_[1]++; }
       break;
     } case 11: {
       long t = constrain(now - 13900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 14000l) { sequence_no_[1]++; }
       break;
     } case 12: {
       long t = constrain(now - 14900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 1175l, 10 - value);
       if (now > 15000l) { sequence_no_[1]++; }
       break;
     } case 13: {
       long t = constrain(now - 16900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 17000l) { sequence_no_[1]++; }
       break;
     } case 14: {
       setBioFreq(1, 1245l, 10);
       if (now > 18000l) { sequence_no_[1]++; }
       break;
     } case 15: {
       long t = constrain(now - 18900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 1175l, 10 - value);
       if (now > 19000l) { sequence_no_[1]++; }
       break;
     } case 16: {
       long t = constrain(now - 19900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 20000l) { sequence_no_[1]++; }
       break;
     } case 17: {
       long t = constrain(now - 20900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 21000l) { sequence_no_[1]++; }
       break;
     } case 18: {
       long t = constrain(now - 22900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 988l, 10 - value);
       if (now > 23000l) { sequence_no_[1]++; }
       break;
     } case 19: {
       long t = constrain(now - 23900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 24000l) { sequence_no_[1]++; }
       break;
     } case 20: {
       long t = constrain(now - 24900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 25000l) { sequence_no_[1]++; }
       break;
     } case 21: {
       long t = constrain(now - 25900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 26000l) { sequence_no_[1]++; }
       break;
     } case 22: {
       long t = constrain(now - 27400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 27500l) { sequence_no_[1]++; }
       break;
     } case 23: {
       long t = constrain(now - 28900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 311l, 10 - value);
       if (now > 29000l) { sequence_no_[1]++; }
       break;
     } case 24: {
       setBioFreq(1, 392l, 10);
       if (now > 30000l) { sequence_no_[1]++; }
       break;
     } case 25: {
       long t = constrain(now - 30400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 30500l) { sequence_no_[1]++; }
       break;
     } case 26: {
       long t = constrain(now - 31400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 31500l) { sequence_no_[1]++; }
       break;
     } case 27: {
       long t = constrain(now - 31900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 32000l) { sequence_no_[1]++; }
       break;
     } case 28: {
       long t = constrain(now - 33900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 311l, 10 - value);
       if (now > 34000l) { sequence_no_[1]++; }
       break;
     } case 29: {
       long t = constrain(now - 34900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 35000l) { sequence_no_[1]++; }
       break;
     } case 30: {
       setBioFreq(1, 156l, 10);
       if (now > 36000l) { sequence_no_[1]++; }
       break;
     } case 31: {
       long t = constrain(now - 36900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 156l, 10 - value);
       if (now > 37000l) { sequence_no_[1]++; }
       break;
     } case 32: {
       long t = constrain(now - 37900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 196l, 10 - value);
       if (now > 38000l) { sequence_no_[1]++; }
       break;
     } case 33: {
       long t = constrain(now - 38233l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 294l, 10 - value);
       if (now > 38333l) { sequence_no_[1]++; }
       break;
     } case 34: {
       long t = constrain(now - 38567l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 38667l) { sequence_no_[1]++; }
       break;
     } case 35: {
       long t = constrain(now - 38900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 39000l) { sequence_no_[1]++; }
       break;
     } case 36: {
       long t = constrain(now - 39400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 39500l) { sequence_no_[1]++; }
       break;
     } case 37: {
       long t = constrain(now - 39900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 587l, 10 - value);
       if (now > 40000l) { sequence_no_[1]++; }
       break;
     } case 38: {
       long t = constrain(now - 41900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 988l, 10 - value);
       if (now > 42000l) { sequence_no_[1]++; }
       break;
     } case 39: {
       long t = constrain(now - 42900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 1245l, 10 - value);
       if (now > 43000l) { sequence_no_[1]++; }
       break;
     } case 40: {
       long t = constrain(now - 44900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 45000l) { sequence_no_[1]++; }
       break;
     } case 41: {
       long t = constrain(now - 45900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 1175l, 10 - value);
       if (now > 46000l) { sequence_no_[1]++; }
       break;
     } case 42: {
       long t = constrain(now - 47900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 48000l) { sequence_no_[1]++; }
       break;
     } case 43: {
       long t = constrain(now - 49900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 50000l) { sequence_no_[1]++; }
       break;
     } case 44: {
       long t = constrain(now - 50400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 392l, 10 - value);
       if (now > 50500l) { sequence_no_[1]++; }
       break;
     } case 45: {
       long t = constrain(now - 50900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 294l, 10 - value);
       if (now > 51000l) { sequence_no_[1]++; }
       break;
     } case 46: {
       long t = constrain(now - 51400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 51500l) { sequence_no_[1]++; }
       break;
     } case 47: {
       long t = constrain(now - 51900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 52000l) { sequence_no_[1]++; }
       break;
     } case 48: {
       long t = constrain(now - 52400l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 52500l) { sequence_no_[1]++; }
       break;
     } case 49: {
       long t = constrain(now - 52900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 1175l, 10 - value);
       if (now > 53000l) { sequence_no_[1]++; }
       break;
     } case 50: {
       setBioFreq(1, 494l, 10);
       if (now > 54000l) { sequence_no_[1]++; }
       break;
     } case 51: {
       long t = constrain(now - 54900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 494l, 10 - value);
       if (now > 55000l) { sequence_no_[1]++; }
       break;
     } case 52: {
       long t = constrain(now - 56900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 622l, 10 - value);
       if (now > 57000l) { sequence_no_[1]++; }
       break;
     } case 53: {
       long t = constrain(now - 58900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 784l, 10 - value);
       if (now > 59000l) { sequence_no_[1]++; }
       break;
     } case 54: {
       setBioFreq(1, 988l, 10);
       if (now > 60000l) { sequence_no_[1]++; }
       break;
     } case 55: {
       long t = constrain(now - 62900l, 0l, 100l);
       int value = ease_in_cubicL(t, 0l, 10, 100l);
       setBioFreq(1, 988l, 10 - value);
       if (now > 63000l) { sequence_no_[1]++; }
       break;
     } case 56: {
       setBioFreq(1, 500l, 0);
       if (now > 66000l) { sequence_no_[1]++; }
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
