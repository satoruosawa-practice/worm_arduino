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
      setBioFreq(0, 523l, 10);
      if (now > 1500l) { sequence_no_[0]++; }
      break;
    } case 1: {
      long t = constrain(now - 2900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 3000l) { sequence_no_[0]++; }
      break;
    } case 2: {
      setBioFreq(0, 500l, 0);
      if (now > 3750l) { sequence_no_[0]++; }
      break;
    } case 3: {
      long t = constrain(now - 4400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 4500l) { sequence_no_[0]++; }
      break;
    } case 4: {
      setBioFreq(0, 1047l, 10);
      if (now > 6000l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 7400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 1047l, 10 - value);
      if (now > 7500l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 8900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 9000l) { sequence_no_[0]++; }
      break;
    } case 7: {
      setBioFreq(0, 500l, 0);
      if (now > 9750l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 10400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 262l, 10 - value);
      if (now > 10500l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 11150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 11250l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBioFreq(0, 1047l, 10);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 12650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 1047l, 10 - value);
      if (now > 12750l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 13400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 13500l) { sequence_no_[0]++; }
      break;
    } case 13: {
      long t = constrain(now - 14900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 2093l, 10 - value);
      if (now > 15000l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 16400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 16500l) { sequence_no_[0]++; }
      break;
    } case 15: {
      long t = constrain(now - 17150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 1047l, 10 - value);
      if (now > 17250l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 17900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 262l, 10 - value);
      if (now > 18000l) { sequence_no_[0]++; }
      break;
    } case 17: {
      long t = constrain(now - 18650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 18750l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 20150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 2093l, 10 - value);
      if (now > 20250l) { sequence_no_[0]++; }
      break;
    } case 19: {
      setBioFreq(0, 523l, 10);
      if (now > 21000l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 21650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 21750l) { sequence_no_[0]++; }
      break;
    } case 21: {
      long t = constrain(now - 23150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 262l, 10 - value);
      if (now > 23250l) { sequence_no_[0]++; }
      break;
    } case 22: {
      setBioFreq(0, 2093l, 10);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    } case 23: {
      long t = constrain(now - 24650l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 2093l, 10 - value);
      if (now > 24750l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 26150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 1047l, 10 - value);
      if (now > 26250l) { sequence_no_[0]++; }
      break;
    } case 25: {
      setBioFreq(0, 523l, 10);
      if (now > 27000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 29150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 29250l) { sequence_no_[0]++; }
      break;
    } case 27: {
      setBioFreq(0, 523l, 10);
      if (now > 30000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 32150l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 32250l) { sequence_no_[0]++; }
      break;
    } case 29: {
      setBioFreq(0, 523l, 10);
      if (now > 33000l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 10, 100l);
      setBioFreq(0, 523l, 10 - value);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }
     // 1
     switch (sequence_no_[1]) {
       case 0: {
         setBioFreq(1, 500l, 0);
         if (now > 1500l) { sequence_no_[1]++; }
         break;
       } case 1: {
         setBioFreq(1, 262l, 10);
         if (now > 3000l) { sequence_no_[1]++; }
         break;
       } case 2: {
         long t = constrain(now - 4400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 4500l) { sequence_no_[1]++; }
         break;
       } case 3: {
         setBioFreq(1, 500l, 0);
         if (now > 5250l) { sequence_no_[1]++; }
         break;
       } case 4: {
         long t = constrain(now - 5900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 6000l) { sequence_no_[1]++; }
         break;
       } case 5: {
         setBioFreq(1, 262l, 10);
         if (now > 7500l) { sequence_no_[1]++; }
         break;
       } case 6: {
         long t = constrain(now - 8900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 9000l) { sequence_no_[1]++; }
         break;
       } case 7: {
         long t = constrain(now - 10400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 10500l) { sequence_no_[1]++; }
         break;
       } case 8: {
         setBioFreq(1, 500l, 0);
         if (now > 11250l) { sequence_no_[1]++; }
         break;
       } case 9: {
         long t = constrain(now - 11900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 1047l, 10 - value);
         if (now > 12000l) { sequence_no_[1]++; }
         break;
       } case 10: {
         long t = constrain(now - 12650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 12750l) { sequence_no_[1]++; }
         break;
       } case 11: {
         long t = constrain(now - 14150l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 14250l) { sequence_no_[1]++; }
         break;
       } case 12: {
         long t = constrain(now - 14900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 131l, 10 - value);
         if (now > 15000l) { sequence_no_[1]++; }
         break;
       } case 13: {
         long t = constrain(now - 15650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 15750l) { sequence_no_[1]++; }
         break;
       } case 14: {
         long t = constrain(now - 17900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 18000l) { sequence_no_[1]++; }
         break;
       } case 15: {
         long t = constrain(now - 18650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 1047l, 10 - value);
         if (now > 18750l) { sequence_no_[1]++; }
         break;
       } case 16: {
         long t = constrain(now - 19400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 19500l) { sequence_no_[1]++; }
         break;
       } case 17: {
         long t = constrain(now - 20150l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 20250l) { sequence_no_[1]++; }
         break;
       } case 18: {
         long t = constrain(now - 20900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 131l, 10 - value);
         if (now > 21000l) { sequence_no_[1]++; }
         break;
       } case 19: {
         long t = constrain(now - 22400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 22500l) { sequence_no_[1]++; }
         break;
       } case 20: {
         long t = constrain(now - 23900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 24000l) { sequence_no_[1]++; }
         break;
       } case 21: {
         long t = constrain(now - 24650l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 24750l) { sequence_no_[1]++; }
         break;
       } case 22: {
         long t = constrain(now - 25400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 1047l, 10 - value);
         if (now > 25500l) { sequence_no_[1]++; }
         break;
       } case 23: {
         long t = constrain(now - 26900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 27000l) { sequence_no_[1]++; }
         break;
       } case 24: {
         long t = constrain(now - 28400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 131l, 10 - value);
         if (now > 28500l) { sequence_no_[1]++; }
         break;
       } case 25: {
         long t = constrain(now - 29900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 30000l) { sequence_no_[1]++; }
         break;
       } case 26: {
         long t = constrain(now - 31400l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 1047l, 10 - value);
         if (now > 31500l) { sequence_no_[1]++; }
         break;
       } case 27: {
         long t = constrain(now - 32900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 262l, 10 - value);
         if (now > 33000l) { sequence_no_[1]++; }
         break;
       } case 28: {
         long t = constrain(now - 35900l, 0l, 100l);
         int value = ease_in_cubicL(t, 0l, 10, 100l);
         setBioFreq(1, 523l, 10 - value);
         if (now > 36000l) { sequence_no_[1]++; }
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
