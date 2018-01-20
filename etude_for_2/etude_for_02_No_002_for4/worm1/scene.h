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
      long t = constrain(now - 2082l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 2182l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBioFreq(0, 500l, 0);
      if (now > 3273l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 4809l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 4909l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBioFreq(0, 500l, 0);
      if (now > 6545l) { sequence_no_[0]++; }
      break;
    } case 4: {
      setBioFreq(0, 500l, 0);
      if (now > 7091l) { sequence_no_[0]++; }
      break;
    } case 5: {
      long t = constrain(now - 7536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1568l, 30 - value);
      if (now > 7636l) { sequence_no_[0]++; }
      break;
    } case 6: {
      setBioFreq(0, 500l, 0);
      if (now > 9818l) { sequence_no_[0]++; }
      break;
    } case 7: {
      long t = constrain(now - 10264l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 10364l) { sequence_no_[0]++; }
      break;
    } case 8: {
      setBioFreq(0, 500l, 0);
      if (now > 10636l) { sequence_no_[0]++; }
      break;
    } case 9: {
      long t = constrain(now - 10809l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 196l, 30 - value);
      if (now > 10909l) { sequence_no_[0]++; }
      break;
    } case 10: {
      setBioFreq(0, 500l, 0);
      if (now > 12545l) { sequence_no_[0]++; }
      break;
    } case 11: {
      long t = constrain(now - 12991l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 13091l) { sequence_no_[0]++; }
      break;
    } case 12: {
      setBioFreq(0, 500l, 0);
      if (now > 14182l) { sequence_no_[0]++; }
      break;
    } case 13: {
      setBioFreq(0, 500l, 0);
      if (now > 14727l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 15173l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 15273l) { sequence_no_[0]++; }
      break;
    } case 15: {
      setBioFreq(0, 500l, 0);
      if (now > 16364l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 17355l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 17455l) { sequence_no_[0]++; }
      break;
    } case 17: {
      setBioFreq(0, 500l, 0);
      if (now > 18545l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 18991l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 19091l) { sequence_no_[0]++; }
      break;
    } case 19: {
      setBioFreq(0, 500l, 0);
      if (now > 19364l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 19536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 196l, 30 - value);
      if (now > 19636l) { sequence_no_[0]++; }
      break;
    } case 21: {
      setBioFreq(0, 500l, 0);
      if (now > 19909l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 20082l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 20182l) { sequence_no_[0]++; }
      break;
    } case 23: {
      setBioFreq(0, 500l, 0);
      if (now > 20455l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 20627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1568l, 30 - value);
      if (now > 20727l) { sequence_no_[0]++; }
      break;
    } case 25: {
      setBioFreq(0, 500l, 0);
      if (now > 21545l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 22264l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 22364l) { sequence_no_[0]++; }
      break;
    } case 27: {
      setBioFreq(0, 500l, 0);
      if (now > 22909l) { sequence_no_[0]++; }
      break;
    } case 28: {
      setBioFreq(0, 500l, 0);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    } case 29: {
      long t = constrain(now - 24991l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 25091l) { sequence_no_[0]++; }
      break;
    } case 30: {
      setBioFreq(0, 500l, 0);
      if (now > 26182l) { sequence_no_[0]++; }
      break;
    } case 31: {
      long t = constrain(now - 26627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1568l, 30 - value);
      if (now > 26727l) { sequence_no_[0]++; }
      break;
    } case 32: {
      setBioFreq(0, 500l, 0);
      if (now > 28364l) { sequence_no_[0]++; }
      break;
    } case 33: {
      long t = constrain(now - 29355l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 29455l) { sequence_no_[0]++; }
      break;
    } case 34: {
      setBioFreq(0, 500l, 0);
      if (now > 30545l) { sequence_no_[0]++; }
      break;
    } case 35: {
      long t = constrain(now - 32627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
      if (now > 32727l) { sequence_no_[0]++; }
      break;
    } case 36: {
      setBioFreq(0, 392l, 30);
      if (now > 34909l) { sequence_no_[0]++; }
      break;
    } case 37: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 392l, 30 - value);
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
      if (now > 1091l) { sequence_no_[1]++; }
      break;
    } case 1: {
      long t = constrain(now - 3173l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 3273l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBioFreq(1, 500l, 0);
      if (now > 3818l) { sequence_no_[1]++; }
      break;
    } case 3: {
      long t = constrain(now - 4264l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 4364l) { sequence_no_[1]++; }
      break;
    } case 4: {
      setBioFreq(1, 500l, 0);
      if (now > 5182l) { sequence_no_[1]++; }
      break;
    } case 5: {
      long t = constrain(now - 5627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 5727l) { sequence_no_[1]++; }
      break;
    } case 6: {
      setBioFreq(1, 500l, 0);
      if (now > 6545l) { sequence_no_[1]++; }
      break;
    } case 7: {
      long t = constrain(now - 7536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 7636l) { sequence_no_[1]++; }
      break;
    } case 8: {
      setBioFreq(1, 500l, 0);
      if (now > 8182l) { sequence_no_[1]++; }
      break;
    } case 9: {
      setBioFreq(1, 500l, 0);
      if (now > 8727l) { sequence_no_[1]++; }
      break;
    } case 10: {
      long t = constrain(now - 9718l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 9818l) { sequence_no_[1]++; }
      break;
    } case 11: {
      setBioFreq(1, 500l, 0);
      if (now > 10909l) { sequence_no_[1]++; }
      break;
    } case 12: {
      long t = constrain(now - 11082l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 11182l) { sequence_no_[1]++; }
      break;
    } case 13: {
      setBioFreq(1, 500l, 0);
      if (now > 11455l) { sequence_no_[1]++; }
      break;
    } case 14: {
      long t = constrain(now - 11627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 11727l) { sequence_no_[1]++; }
      break;
    } case 15: {
      setBioFreq(1, 500l, 0);
      if (now > 12000l) { sequence_no_[1]++; }
      break;
    } case 16: {
      long t = constrain(now - 12445l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 12545l) { sequence_no_[1]++; }
      break;
    } case 17: {
      setBioFreq(1, 500l, 0);
      if (now > 13091l) { sequence_no_[1]++; }
      break;
    } case 18: {
      setBioFreq(1, 500l, 0);
      if (now > 13636l) { sequence_no_[1]++; }
      break;
    } case 19: {
      long t = constrain(now - 13809l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 13909l) { sequence_no_[1]++; }
      break;
    } case 20: {
      setBioFreq(1, 500l, 0);
      if (now > 14455l) { sequence_no_[1]++; }
      break;
    } case 21: {
      long t = constrain(now - 14900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 15000l) { sequence_no_[1]++; }
      break;
    } case 22: {
      setBioFreq(1, 500l, 0);
      if (now > 15273l) { sequence_no_[1]++; }
      break;
    } case 23: {
      long t = constrain(now - 15445l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 15545l) { sequence_no_[1]++; }
      break;
    } case 24: {
      setBioFreq(1, 500l, 0);
      if (now > 15818l) { sequence_no_[1]++; }
      break;
    } case 25: {
      long t = constrain(now - 15991l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 16091l) { sequence_no_[1]++; }
      break;
    } case 26: {
      setBioFreq(1, 500l, 0);
      if (now > 16364l) { sequence_no_[1]++; }
      break;
    } case 27: {
      long t = constrain(now - 16536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 16636l) { sequence_no_[1]++; }
      break;
    } case 28: {
      setBioFreq(1, 500l, 0);
      if (now > 17727l) { sequence_no_[1]++; }
      break;
    } case 29: {
      long t = constrain(now - 18718l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 18818l) { sequence_no_[1]++; }
      break;
    } case 30: {
      setBioFreq(1, 500l, 0);
      if (now > 19364l) { sequence_no_[1]++; }
      break;
    } case 31: {
      long t = constrain(now - 19536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 19636l) { sequence_no_[1]++; }
      break;
    } case 32: {
      setBioFreq(1, 500l, 0);
      if (now > 19909l) { sequence_no_[1]++; }
      break;
    } case 33: {
      long t = constrain(now - 20082l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 20182l) { sequence_no_[1]++; }
      break;
    } case 34: {
      setBioFreq(1, 500l, 0);
      if (now > 20455l) { sequence_no_[1]++; }
      break;
    } case 35: {
      long t = constrain(now - 20627l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 20727l) { sequence_no_[1]++; }
      break;
    } case 36: {
      setBioFreq(1, 500l, 0);
      if (now > 21273l) { sequence_no_[1]++; }
      break;
    } case 37: {
      long t = constrain(now - 21718l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 21818l) { sequence_no_[1]++; }
      break;
    } case 38: {
      setBioFreq(1, 500l, 0);
      if (now > 22091l) { sequence_no_[1]++; }
      break;
    } case 39: {
      long t = constrain(now - 22264l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 22364l) { sequence_no_[1]++; }
      break;
    } case 40: {
      setBioFreq(1, 500l, 0);
      if (now > 22636l) { sequence_no_[1]++; }
      break;
    } case 41: {
      long t = constrain(now - 22809l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 523l, 30 - value);
      if (now > 22909l) { sequence_no_[1]++; }
      break;
    } case 42: {
      setBioFreq(1, 500l, 0);
      if (now > 23182l) { sequence_no_[1]++; }
      break;
    } case 43: {
      long t = constrain(now - 23355l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 23455l) { sequence_no_[1]++; }
      break;
    } case 44: {
      setBioFreq(1, 500l, 0);
      if (now > 23727l) { sequence_no_[1]++; }
      break;
    } case 45: {
      long t = constrain(now - 23900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 1047l, 30 - value);
      if (now > 24000l) { sequence_no_[1]++; }
      break;
    } case 46: {
      setBioFreq(1, 500l, 0);
      if (now > 24273l) { sequence_no_[1]++; }
      break;
    } case 47: {
      long t = constrain(now - 24445l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 24545l) { sequence_no_[1]++; }
      break;
    } case 48: {
      setBioFreq(1, 500l, 0);
      if (now > 25636l) { sequence_no_[1]++; }
      break;
    } case 49: {
      long t = constrain(now - 26082l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 26182l) { sequence_no_[1]++; }
      break;
    } case 50: {
      setBioFreq(1, 500l, 0);
      if (now > 26727l) { sequence_no_[1]++; }
      break;
    } case 51: {
      long t = constrain(now - 27173l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 988l, 30 - value);
      if (now > 27273l) { sequence_no_[1]++; }
      break;
    } case 52: {
      setBioFreq(1, 500l, 0);
      if (now > 28364l) { sequence_no_[1]++; }
      break;
    } case 53: {
      long t = constrain(now - 29355l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 29455l) { sequence_no_[1]++; }
      break;
    } case 54: {
      setBioFreq(1, 500l, 0);
      if (now > 30545l) { sequence_no_[1]++; }
      break;
    } case 55: {
      long t = constrain(now - 31536l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 31636l) { sequence_no_[1]++; }
      break;
    } case 56: {
      setBioFreq(1, 500l, 0);
      if (now > 32727l) { sequence_no_[1]++; }
      break;
    } case 57: {
      long t = constrain(now - 34264l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 262l, 30 - value);
      if (now > 34364l) { sequence_no_[1]++; }
      break;
    } case 58: {
      long t = constrain(now - 35900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
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
