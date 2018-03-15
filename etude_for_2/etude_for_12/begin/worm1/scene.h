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
  // 0
  switch (sequence_no_[0]) {
    case 0: {
      long t = constrain(now - 1100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 1200l) { sequence_no_[0]++; }
      break;
    } case 1: {
      setBioFreq(0, 500l, 0);
      if (now > 1800l) { sequence_no_[0]++; }
      break;
    } case 2: {
      long t = constrain(now - 3500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 3600l) { sequence_no_[0]++; }
      break;
    } case 3: {
      setBioFreq(0, 500l, 0);
      if (now > 4800l) { sequence_no_[0]++; }
      break;
    } case 4: {
      long t = constrain(now - 5300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 5400l) { sequence_no_[0]++; }
      break;
    } case 5: {
      setBioFreq(0, 500l, 0);
      if (now > 6600l) { sequence_no_[0]++; }
      break;
    } case 6: {
      long t = constrain(now - 7100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 7200l) { sequence_no_[0]++; }
      break;
    } case 7: {
      setBioFreq(0, 500l, 0);
      if (now > 8400l) { sequence_no_[0]++; }
      break;
    } case 8: {
      long t = constrain(now - 9500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 9600l) { sequence_no_[0]++; }
      break;
    } case 9: {
      setBioFreq(0, 500l, 0);
      if (now > 10200l) { sequence_no_[0]++; }
      break;
    } case 10: {
      long t = constrain(now - 11900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    } case 11: {
      setBioFreq(0, 500l, 0);
      if (now > 28800l) { sequence_no_[0]++; }
      break;
    } case 12: {
      long t = constrain(now - 31100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 31200l) { sequence_no_[0]++; }
      break;
    } case 13: {
      setBioFreq(0, 500l, 0);
      if (now > 32400l) { sequence_no_[0]++; }
      break;
    } case 14: {
      long t = constrain(now - 34100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 34200l) { sequence_no_[0]++; }
      break;
    } case 15: {
      setBioFreq(0, 500l, 0);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    } case 16: {
      long t = constrain(now - 37100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 37200l) { sequence_no_[0]++; }
      break;
    } case 17: {
      setBioFreq(0, 500l, 0);
      if (now > 39000l) { sequence_no_[0]++; }
      break;
    } case 18: {
      long t = constrain(now - 39500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 39600l) { sequence_no_[0]++; }
      break;
    } case 19: {
      setBioFreq(0, 500l, 0);
      if (now > 40200l) { sequence_no_[0]++; }
      break;
    } case 20: {
      long t = constrain(now - 41900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 42000l) { sequence_no_[0]++; }
      break;
    } case 21: {
      setBioFreq(0, 500l, 0);
      if (now > 43800l) { sequence_no_[0]++; }
      break;
    } case 22: {
      long t = constrain(now - 44300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 44400l) { sequence_no_[0]++; }
      break;
    } case 23: {
      setBioFreq(0, 500l, 0);
      if (now > 46800l) { sequence_no_[0]++; }
      break;
    } case 24: {
      long t = constrain(now - 47300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 208l, 30 - value);
      if (now > 47400l) { sequence_no_[0]++; }
      break;
    } case 25: {
      setBioFreq(0, 500l, 0);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    } case 26: {
      long t = constrain(now - 49700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 49800l) { sequence_no_[0]++; }
      break;
    } case 27: {
      setBioFreq(0, 500l, 0);
      if (now > 51000l) { sequence_no_[0]++; }
      break;
    } case 28: {
      long t = constrain(now - 52100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 52200l) { sequence_no_[0]++; }
      break;
    } case 29: {
      setBioFreq(0, 500l, 0);
      if (now > 53400l) { sequence_no_[0]++; }
      break;
    } case 30: {
      long t = constrain(now - 53900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 233l, 30 - value);
      if (now > 54000l) { sequence_no_[0]++; }
      break;
    } case 31: {
      setBioFreq(0, 500l, 0);
      if (now > 54600l) { sequence_no_[0]++; }
      break;
    } case 32: {
      long t = constrain(now - 55100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 55200l) { sequence_no_[0]++; }
      break;
    } case 33: {
      setBioFreq(0, 500l, 0);
      if (now > 56400l) { sequence_no_[0]++; }
      break;
    } case 34: {
      long t = constrain(now - 56900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 57000l) { sequence_no_[0]++; }
      break;
    } case 35: {
      setBioFreq(0, 500l, 0);
      if (now > 57600l) { sequence_no_[0]++; }
      break;
    } case 36: {
      long t = constrain(now - 58100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 58200l) { sequence_no_[0]++; }
      break;
    } case 37: {
      setBioFreq(0, 500l, 0);
      if (now > 59400l) { sequence_no_[0]++; }
      break;
    } case 38: {
      long t = constrain(now - 59900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 60000l) { sequence_no_[0]++; }
      break;
    } case 39: {
      setBioFreq(0, 500l, 0);
      if (now > 60600l) { sequence_no_[0]++; }
      break;
    } case 40: {
      long t = constrain(now - 61100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 61200l) { sequence_no_[0]++; }
      break;
    } case 41: {
      setBioFreq(0, 500l, 0);
      if (now > 62400l) { sequence_no_[0]++; }
      break;
    } case 42: {
      long t = constrain(now - 63500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 63600l) { sequence_no_[0]++; }
      break;
    } case 43: {
      setBioFreq(0, 500l, 0);
      if (now > 64200l) { sequence_no_[0]++; }
      break;
    } case 44: {
      long t = constrain(now - 64700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 64800l) { sequence_no_[0]++; }
      break;
    } case 45: {
      setBioFreq(0, 500l, 0);
      if (now > 66000l) { sequence_no_[0]++; }
      break;
    } case 46: {
      long t = constrain(now - 67100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 67200l) { sequence_no_[0]++; }
      break;
    } case 47: {
      setBioFreq(0, 500l, 0);
      if (now > 68400l) { sequence_no_[0]++; }
      break;
    } case 48: {
      long t = constrain(now - 69500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 415l, 30 - value);
      if (now > 69600l) { sequence_no_[0]++; }
      break;
    } case 49: {
      setBioFreq(0, 500l, 0);
      if (now > 70200l) { sequence_no_[0]++; }
      break;
    } case 50: {
      long t = constrain(now - 71300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 71400l) { sequence_no_[0]++; }
      break;
    } case 51: {
      setBioFreq(0, 500l, 0);
      if (now > 72600l) { sequence_no_[0]++; }
      break;
    } case 52: {
      long t = constrain(now - 73100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 73200l) { sequence_no_[0]++; }
      break;
    } case 53: {
      setBioFreq(0, 500l, 0);
      if (now > 73800l) { sequence_no_[0]++; }
      break;
    } case 54: {
      long t = constrain(now - 75500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 75600l) { sequence_no_[0]++; }
      break;
    } case 55: {
      setBioFreq(0, 500l, 0);
      if (now > 76800l) { sequence_no_[0]++; }
      break;
    } case 56: {
      long t = constrain(now - 78500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 78600l) { sequence_no_[0]++; }
      break;
    } case 57: {
      setBioFreq(0, 500l, 0);
      if (now > 80400l) { sequence_no_[0]++; }
      break;
    } case 58: {
      long t = constrain(now - 82100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 82200l) { sequence_no_[0]++; }
      break;
    } case 59: {
      setBioFreq(0, 500l, 0);
      if (now > 86400l) { sequence_no_[0]++; }
      break;
    } case 60: {
      long t = constrain(now - 87200l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 87300l) { sequence_no_[0]++; }
      break;
    } case 61: {
      setBioFreq(0, 500l, 0);
      if (now > 88200l) { sequence_no_[0]++; }
      break;
    } case 62: {
      long t = constrain(now - 89900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 90000l) { sequence_no_[0]++; }
      break;
    } case 63: {
      setBioFreq(0, 500l, 0);
      if (now > 90900l) { sequence_no_[0]++; }
      break;
    } case 64: {
      long t = constrain(now - 91700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 91800l) { sequence_no_[0]++; }
      break;
    } case 65: {
      setBioFreq(0, 500l, 0);
      if (now > 93600l) { sequence_no_[0]++; }
      break;
    } case 66: {
      long t = constrain(now - 95300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 95400l) { sequence_no_[0]++; }
      break;
    } case 67: {
      setBioFreq(0, 500l, 0);
      if (now > 97200l) { sequence_no_[0]++; }
      break;
    } case 68: {
      long t = constrain(now - 97700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 97800l) { sequence_no_[0]++; }
      break;
    } case 69: {
      setBioFreq(0, 500l, 0);
      if (now > 98400l) { sequence_no_[0]++; }
      break;
    } case 70: {
      long t = constrain(now - 98900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 784l, 30 - value);
      if (now > 99000l) { sequence_no_[0]++; }
      break;
    } case 71: {
      setBioFreq(0, 500l, 0);
      if (now > 100200l) { sequence_no_[0]++; }
      break;
    } case 72: {
      long t = constrain(now - 101300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 101400l) { sequence_no_[0]++; }
      break;
    } case 73: {
      setBioFreq(0, 500l, 0);
      if (now > 103800l) { sequence_no_[0]++; }
      break;
    } case 74: {
      long t = constrain(now - 104300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 104400l) { sequence_no_[0]++; }
      break;
    } case 75: {
      setBioFreq(0, 500l, 0);
      if (now > 105000l) { sequence_no_[0]++; }
      break;
    } case 76: {
      long t = constrain(now - 105500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 105600l) { sequence_no_[0]++; }
      break;
    } case 77: {
      setBioFreq(0, 500l, 0);
      if (now > 106800l) { sequence_no_[0]++; }
      break;
    } case 78: {
      long t = constrain(now - 107300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 107400l) { sequence_no_[0]++; }
      break;
    } case 79: {
      setBioFreq(0, 500l, 0);
      if (now > 108000l) { sequence_no_[0]++; }
      break;
    } case 80: {
      long t = constrain(now - 109700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 740l, 30 - value);
      if (now > 109800l) { sequence_no_[0]++; }
      break;
    } case 81: {
      setBioFreq(0, 500l, 0);
      if (now > 111600l) { sequence_no_[0]++; }
      break;
    } case 82: {
      long t = constrain(now - 112100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1397l, 30 - value);
      if (now > 112200l) { sequence_no_[0]++; }
      break;
    } case 83: {
      setBioFreq(0, 500l, 0);
      if (now > 115200l) { sequence_no_[0]++; }
      break;
    } case 84: {
      long t = constrain(now - 116300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1661l, 30 - value);
      if (now > 116400l) { sequence_no_[0]++; }
      break;
    } case 85: {
      setBioFreq(0, 500l, 0);
      if (now > 117600l) { sequence_no_[0]++; }
      break;
    } case 86: {
      long t = constrain(now - 119300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 880l, 30 - value);
      if (now > 119400l) { sequence_no_[0]++; }
      break;
    } case 87: {
      setBioFreq(0, 500l, 0);
      if (now > 119700l) { sequence_no_[0]++; }
      break;
    } case 88: {
      long t = constrain(now - 119900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 1047l, 30 - value);
      if (now > 120000l) { sequence_no_[0]++; }
      break;
    } case 89: {
      setBioFreq(0, 500l, 0);
      if (now > 120300l) { sequence_no_[0]++; }
      break;
    } case 90: {
      long t = constrain(now - 120500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 932l, 30 - value);
      if (now > 120600l) { sequence_no_[0]++; }
      break;
    } case 91: {
      setBioFreq(0, 500l, 0);
      if (now > 122400l) { sequence_no_[0]++; }
      break;
    } case 92: {
      long t = constrain(now - 124100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 124200l) { sequence_no_[0]++; }
      break;
    } case 93: {
      setBioFreq(0, 500l, 0);
      if (now > 124800l) { sequence_no_[0]++; }
      break;
    } case 94: {
      long t = constrain(now - 125300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 698l, 30 - value);
      if (now > 125400l) { sequence_no_[0]++; }
      break;
    } case 95: {
      setBioFreq(0, 500l, 0);
      if (now > 126600l) { sequence_no_[0]++; }
      break;
    } case 96: {
      long t = constrain(now - 127100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 127200l) { sequence_no_[0]++; }
      break;
    } case 97: {
      setBioFreq(0, 500l, 0);
      if (now > 127800l) { sequence_no_[0]++; }
      break;
    } case 98: {
      long t = constrain(now - 128900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 440l, 30 - value);
      if (now > 129000l) { sequence_no_[0]++; }
      break;
    } case 99: {
      setBioFreq(0, 500l, 0);
      if (now > 129600l) { sequence_no_[0]++; }
      break;
    } case 100: {
      long t = constrain(now - 131300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 523l, 30 - value);
      if (now > 131400l) { sequence_no_[0]++; }
      break;
    } case 101: {
      setBioFreq(0, 500l, 0);
      if (now > 133200l) { sequence_no_[0]++; }
      break;
    } case 102: {
      long t = constrain(now - 133700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 466l, 30 - value);
      if (now > 133800l) { sequence_no_[0]++; }
      break;
    } case 103: {
      setBioFreq(0, 500l, 0);
      if (now > 134400l) { sequence_no_[0]++; }
      break;
    } case 104: {
      long t = constrain(now - 136100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 370l, 30 - value);
      if (now > 136200l) { sequence_no_[0]++; }
      break;
    } case 105: {
      setBioFreq(0, 500l, 0);
      if (now > 138000l) { sequence_no_[0]++; }
      break;
    } case 106: {
      long t = constrain(now - 138500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 349l, 30 - value);
      if (now > 138600l) { sequence_no_[0]++; }
      break;
    } case 107: {
      setBioFreq(0, 500l, 0);
      if (now > 139200l) { sequence_no_[0]++; }
      break;
    } case 108: {
      long t = constrain(now - 139700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(0, 831l, 30 - value);
      if (now > 139800l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }

  // 1
  switch (sequence_no_[1]) {
    case 0: {
      setBioFreq(1, 500l, 0);
      if (now > 13800l) { sequence_no_[1]++; }
      break;
    } case 1: {
      long t = constrain(now - 14900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 15000l) { sequence_no_[1]++; }
      break;
    } case 2: {
      setBioFreq(1, 500l, 0);
      if (now > 15600l) { sequence_no_[1]++; }
      break;
    } case 3: {
      long t = constrain(now - 16700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 16800l) { sequence_no_[1]++; }
      break;
    } case 4: {
      setBioFreq(1, 500l, 0);
      if (now > 17400l) { sequence_no_[1]++; }
      break;
    } case 5: {
      long t = constrain(now - 18500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 18600l) { sequence_no_[1]++; }
      break;
    } case 6: {
      setBioFreq(1, 500l, 0);
      if (now > 19800l) { sequence_no_[1]++; }
      break;
    } case 7: {
      long t = constrain(now - 20300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 20400l) { sequence_no_[1]++; }
      break;
    } case 8: {
      setBioFreq(1, 500l, 0);
      if (now > 21000l) { sequence_no_[1]++; }
      break;
    } case 9: {
      long t = constrain(now - 22700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 294l, 30 - value);
      if (now > 22800l) { sequence_no_[1]++; }
      break;
    } case 10: {
      setBioFreq(1, 500l, 0);
      if (now > 24600l) { sequence_no_[1]++; }
      break;
    } case 11: {
      long t = constrain(now - 26300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 26400l) { sequence_no_[1]++; }
      break;
    } case 12: {
      setBioFreq(1, 500l, 0);
      if (now > 28800l) { sequence_no_[1]++; }
      break;
    } case 13: {
      long t = constrain(now - 31100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 31200l) { sequence_no_[1]++; }
      break;
    } case 14: {
      setBioFreq(1, 500l, 0);
      if (now > 32400l) { sequence_no_[1]++; }
      break;
    } case 15: {
      long t = constrain(now - 34100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 34200l) { sequence_no_[1]++; }
      break;
    } case 16: {
      setBioFreq(1, 500l, 0);
      if (now > 36000l) { sequence_no_[1]++; }
      break;
    } case 17: {
      long t = constrain(now - 37100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 37200l) { sequence_no_[1]++; }
      break;
    } case 18: {
      setBioFreq(1, 500l, 0);
      if (now > 39000l) { sequence_no_[1]++; }
      break;
    } case 19: {
      long t = constrain(now - 39500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 39600l) { sequence_no_[1]++; }
      break;
    } case 20: {
      setBioFreq(1, 500l, 0);
      if (now > 40200l) { sequence_no_[1]++; }
      break;
    } case 21: {
      long t = constrain(now - 41900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 294l, 30 - value);
      if (now > 42000l) { sequence_no_[1]++; }
      break;
    } case 22: {
      setBioFreq(1, 500l, 0);
      if (now > 43800l) { sequence_no_[1]++; }
      break;
    } case 23: {
      long t = constrain(now - 44300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 44400l) { sequence_no_[1]++; }
      break;
    } case 24: {
      setBioFreq(1, 500l, 0);
      if (now > 46800l) { sequence_no_[1]++; }
      break;
    } case 25: {
      long t = constrain(now - 47300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 47400l) { sequence_no_[1]++; }
      break;
    } case 26: {
      setBioFreq(1, 500l, 0);
      if (now > 48000l) { sequence_no_[1]++; }
      break;
    } case 27: {
      long t = constrain(now - 49700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 49800l) { sequence_no_[1]++; }
      break;
    } case 28: {
      setBioFreq(1, 500l, 0);
      if (now > 51000l) { sequence_no_[1]++; }
      break;
    } case 29: {
      long t = constrain(now - 52100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 52200l) { sequence_no_[1]++; }
      break;
    } case 30: {
      setBioFreq(1, 500l, 0);
      if (now > 53400l) { sequence_no_[1]++; }
      break;
    } case 31: {
      long t = constrain(now - 53900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 54000l) { sequence_no_[1]++; }
      break;
    } case 32: {
      setBioFreq(1, 500l, 0);
      if (now > 54600l) { sequence_no_[1]++; }
      break;
    } case 33: {
      long t = constrain(now - 55100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 294l, 30 - value);
      if (now > 55200l) { sequence_no_[1]++; }
      break;
    } case 34: {
      setBioFreq(1, 500l, 0);
      if (now > 56400l) { sequence_no_[1]++; }
      break;
    } case 35: {
      long t = constrain(now - 56900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 277l, 30 - value);
      if (now > 57000l) { sequence_no_[1]++; }
      break;
    } case 36: {
      setBioFreq(1, 500l, 0);
      if (now > 57600l) { sequence_no_[1]++; }
      break;
    } case 37: {
      long t = constrain(now - 58700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 58800l) { sequence_no_[1]++; }
      break;
    } case 38: {
      setBioFreq(1, 500l, 0);
      if (now > 59400l) { sequence_no_[1]++; }
      break;
    } case 39: {
      long t = constrain(now - 60500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 740l, 30 - value);
      if (now > 60600l) { sequence_no_[1]++; }
      break;
    } case 40: {
      setBioFreq(1, 500l, 0);
      if (now > 61500l) { sequence_no_[1]++; }
      break;
    } case 41: {
      long t = constrain(now - 62300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 831l, 30 - value);
      if (now > 62400l) { sequence_no_[1]++; }
      break;
    } case 42: {
      setBioFreq(1, 500l, 0);
      if (now > 63600l) { sequence_no_[1]++; }
      break;
    } case 43: {
      long t = constrain(now - 64700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 64800l) { sequence_no_[1]++; }
      break;
    } case 44: {
      setBioFreq(1, 500l, 0);
      if (now > 66000l) { sequence_no_[1]++; }
      break;
    } case 45: {
      long t = constrain(now - 66800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 66900l) { sequence_no_[1]++; }
      break;
    } case 46: {
      setBioFreq(1, 500l, 0);
      if (now > 68100l) { sequence_no_[1]++; }
      break;
    } case 47: {
      long t = constrain(now - 68900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 69000l) { sequence_no_[1]++; }
      break;
    } case 48: {
      setBioFreq(1, 500l, 0);
      if (now > 70200l) { sequence_no_[1]++; }
      break;
    } case 49: {
      long t = constrain(now - 71300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 698l, 30 - value);
      if (now > 71400l) { sequence_no_[1]++; }
      break;
    } case 50: {
      setBioFreq(1, 500l, 0);
      if (now > 72600l) { sequence_no_[1]++; }
      break;
    } case 51: {
      long t = constrain(now - 73100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 740l, 30 - value);
      if (now > 73200l) { sequence_no_[1]++; }
      break;
    } case 52: {
      setBioFreq(1, 500l, 0);
      if (now > 74400l) { sequence_no_[1]++; }
      break;
    } case 53: {
      long t = constrain(now - 75500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 831l, 30 - value);
      if (now > 75600l) { sequence_no_[1]++; }
      break;
    } case 54: {
      setBioFreq(1, 500l, 0);
      if (now > 76800l) { sequence_no_[1]++; }
      break;
    } case 55: {
      long t = constrain(now - 77300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 77400l) { sequence_no_[1]++; }
      break;
    } case 56: {
      setBioFreq(1, 500l, 0);
      if (now > 78000l) { sequence_no_[1]++; }
      break;
    } case 57: {
      long t = constrain(now - 79100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 79200l) { sequence_no_[1]++; }
      break;
    } case 58: {
      setBioFreq(1, 500l, 0);
      if (now > 80400l) { sequence_no_[1]++; }
      break;
    } case 59: {
      long t = constrain(now - 82700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 82800l) { sequence_no_[1]++; }
      break;
    } case 60: {
      setBioFreq(1, 500l, 0);
      if (now > 86400l) { sequence_no_[1]++; }
      break;
    } case 61: {
      long t = constrain(now - 86600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 86700l) { sequence_no_[1]++; }
      break;
    } case 62: {
      setBioFreq(1, 500l, 0);
      if (now > 88500l) { sequence_no_[1]++; }
      break;
    } case 63: {
      long t = constrain(now - 88700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 88800l) { sequence_no_[1]++; }
      break;
    } case 64: {
      setBioFreq(1, 500l, 0);
      if (now > 90600l) { sequence_no_[1]++; }
      break;
    } case 65: {
      long t = constrain(now - 90800l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 90900l) { sequence_no_[1]++; }
      break;
    } case 66: {
      setBioFreq(1, 500l, 0);
      if (now > 92700l) { sequence_no_[1]++; }
      break;
    } case 67: {
      long t = constrain(now - 94400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 247l, 30 - value);
      if (now > 94500l) { sequence_no_[1]++; }
      break;
    } case 68: {
      setBioFreq(1, 500l, 0);
      if (now > 96300l) { sequence_no_[1]++; }
      break;
    } case 69: {
      long t = constrain(now - 96500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 96600l) { sequence_no_[1]++; }
      break;
    } case 70: {
      setBioFreq(1, 500l, 0);
      if (now > 98400l) { sequence_no_[1]++; }
      break;
    } case 71: {
      long t = constrain(now - 98600l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 98700l) { sequence_no_[1]++; }
      break;
    } case 72: {
      setBioFreq(1, 500l, 0);
      if (now > 99000l) { sequence_no_[1]++; }
      break;
    } case 73: {
      long t = constrain(now - 100700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 698l, 30 - value);
      if (now > 100800l) { sequence_no_[1]++; }
      break;
    } case 74: {
      setBioFreq(1, 500l, 0);
      if (now > 102600l) { sequence_no_[1]++; }
      break;
    } case 75: {
      long t = constrain(now - 104300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 370l, 30 - value);
      if (now > 104400l) { sequence_no_[1]++; }
      break;
    } case 76: {
      setBioFreq(1, 500l, 0);
      if (now > 106200l) { sequence_no_[1]++; }
      break;
    } case 77: {
      long t = constrain(now - 106400l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 415l, 30 - value);
      if (now > 106500l) { sequence_no_[1]++; }
      break;
    } case 78: {
      setBioFreq(1, 500l, 0);
      if (now > 106800l) { sequence_no_[1]++; }
      break;
    } case 79: {
      long t = constrain(now - 107900l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 108000l) { sequence_no_[1]++; }
      break;
    } case 80: {
      setBioFreq(1, 500l, 0);
      if (now > 109200l) { sequence_no_[1]++; }
      break;
    } case 81: {
      long t = constrain(now - 110300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 294l, 30 - value);
      if (now > 110400l) { sequence_no_[1]++; }
      break;
    } case 82: {
      setBioFreq(1, 500l, 0);
      if (now > 111600l) { sequence_no_[1]++; }
      break;
    } case 83: {
      long t = constrain(now - 112700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 554l, 30 - value);
      if (now > 112800l) { sequence_no_[1]++; }
      break;
    } case 84: {
      setBioFreq(1, 500l, 0);
      if (now > 126600l) { sequence_no_[1]++; }
      break;
    } case 85: {
      long t = constrain(now - 127700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 349l, 30 - value);
      if (now > 127800l) { sequence_no_[1]++; }
      break;
    } case 86: {
      setBioFreq(1, 500l, 0);
      if (now > 129000l) { sequence_no_[1]++; }
      break;
    } case 87: {
      long t = constrain(now - 129500l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 740l, 30 - value);
      if (now > 129600l) { sequence_no_[1]++; }
      break;
    } case 88: {
      setBioFreq(1, 500l, 0);
      if (now > 130800l) { sequence_no_[1]++; }
      break;
    } case 89: {
      long t = constrain(now - 131300l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 831l, 30 - value);
      if (now > 131400l) { sequence_no_[1]++; }
      break;
    } case 90: {
      setBioFreq(1, 500l, 0);
      if (now > 132000l) { sequence_no_[1]++; }
      break;
    } case 91: {
      long t = constrain(now - 133100l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 494l, 30 - value);
      if (now > 133200l) { sequence_no_[1]++; }
      break;
    } case 92: {
      setBioFreq(1, 500l, 0);
      if (now > 134400l) { sequence_no_[1]++; }
      break;
    } case 93: {
      long t = constrain(now - 136700l, 0l, 100l);
      int value = ease_in_cubicL(t, 0l, 30, 100l);
      setBioFreq(1, 587l, 30 - value);
      if (now > 136800l) { sequence_no_[1]++; }
      break;
    } case 94: {
      setBioFreq(1, 500l, 0);
      if (now > 138600l) { sequence_no_[1]++; }
      break;
    } default:
      setBioFreq(1, 500l, 0);
      break;
  }
}
