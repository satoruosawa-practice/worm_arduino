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

  // soprano
  switch (sequence_no_[0]) {
    case 0: {
      setBioFreq(0, 500l, 0);
      if (now > 4000l) { sequence_no_[0]++; }
      break;
    }  case 1: {
      setBioFreq(0, 500l, 0);
      if (now > 8000l) { sequence_no_[0]++; }
      break;
    }  case 2: {
      setBioFreq(0, 500l, 0);
      if (now > 9600l) { sequence_no_[0]++; }
      break;
    }  case 3: {
      setBioFreq(0, 622l, 10);
      if (now > 12000l) { sequence_no_[0]++; }
      break;
    }  case 4: {
      setBioFreq(0, 622l, 10);
      if (now > 12800l) { sequence_no_[0]++; }
      break;
    }  case 5: {
      setBioFreq(0, 740l, 10);
      if (now > 16000l) { sequence_no_[0]++; }
      break;
    }  case 6: {
      setBioFreq(0, 587l, 10);
      if (now > 19200l) { sequence_no_[0]++; }
      break;
    }  case 7: {
      setBioFreq(0, 587l, 10);
      if (now > 20000l) { sequence_no_[0]++; }
      break;
    }  case 8: {
      setBioFreq(0, 698l, 10);
      if (now > 22400l) { sequence_no_[0]++; }
      break;
    }  case 9: {
      setBioFreq(0, 500l, 0);
      if (now > 23200l) { sequence_no_[0]++; }
      break;
    }  case 10: {
      setBioFreq(0, 698l, 10);
      if (now > 24000l) { sequence_no_[0]++; }
      break;
    }  case 11: {
      setBioFreq(0, 554l, 10);
      if (now > 27200l) { sequence_no_[0]++; }
      break;
    }  case 12: {
      setBioFreq(0, 554l, 10);
      if (now > 28000l) { sequence_no_[0]++; }
      break;
    }  case 13: {
      setBioFreq(0, 500l, 0);
      if (now > 28800l) { sequence_no_[0]++; }
      break;
    }  case 14: {
      setBioFreq(0, 659l, 10);
      if (now > 31200l) { sequence_no_[0]++; }
      break;
    }  case 15: {
      setBioFreq(0, 500l, 0);
      if (now > 32000l) { sequence_no_[0]++; }
      break;
    }  case 16: {
      setBioFreq(0, 500l, 0);
      if (now > 32800l) { sequence_no_[0]++; }
      break;
    }  case 17: {
      setBioFreq(0, 523l, 10);
      if (now > 35200l) { sequence_no_[0]++; }
      break;
    }  case 18: {
      setBioFreq(0, 554l, 10);
      if (now > 36000l) { sequence_no_[0]++; }
      break;
    }  case 19: {
      setBioFreq(0, 587l, 10);
      if (now > 38400l) { sequence_no_[0]++; }
      break;
    }  case 20: {
      setBioFreq(0, 784l, 10);
      if (now > 40000l) { sequence_no_[0]++; }
      break;
    }  case 21: {
      setBioFreq(0, 784l, 10);
      if (now > 42400l) { sequence_no_[0]++; }
      break;
    }  case 22: {
      setBioFreq(0, 587l, 10);
      if (now > 44000l) { sequence_no_[0]++; }
      break;
    }  case 23: {
      setBioFreq(0, 494l, 10);
      if (now > 45600l) { sequence_no_[0]++; }
      break;
    }  case 24: {
      setBioFreq(0, 587l, 10);
      if (now > 47200l) { sequence_no_[0]++; }
      break;
    }  case 25: {
      setBioFreq(0, 500l, 0);
      if (now > 48000l) { sequence_no_[0]++; }
      break;
    }  case 26: {
      setBioFreq(0, 466l, 10);
      if (now > 49600l) { sequence_no_[0]++; }
      break;
    }  case 27: {
      setBioFreq(0, 494l, 10);
      if (now > 52000l) { sequence_no_[0]++; }
      break;
    }  case 28: {
      setBioFreq(0, 523l, 10);
      if (now > 53600l) { sequence_no_[0]++; }
      break;
    }  case 29: {
      setBioFreq(0, 698l, 10);
      if (now > 55200l) { sequence_no_[0]++; }
      break;
    }  case 30: {
      setBioFreq(0, 500l, 0);
      if (now > 56000l) { sequence_no_[0]++; }
      break;
    }  case 31: {
      setBioFreq(0, 698l, 10);
      if (now > 57600l) { sequence_no_[0]++; }
      break;
    }  case 32: {
      setBioFreq(0, 523l, 10);
      if (now > 59200l) { sequence_no_[0]++; }
      break;
    }  case 33: {
      setBioFreq(0, 500l, 0);
      if (now > 60000l) { sequence_no_[0]++; }
      break;
    }  case 34: {
      setBioFreq(0, 880l, 10);
      if (now > 61600l) { sequence_no_[0]++; }
      break;
    }  case 35: {
      setBioFreq(0, 523l, 10);
      if (now > 64000l) { sequence_no_[0]++; }
      break;
    }  case 36: {
      setBioFreq(0, 500l, 0);
      if (now > 65600l) { sequence_no_[0]++; }
      break;
    }  case 37: {
      setBioFreq(0, 415l, 10);
      if (now > 68000l) { sequence_no_[0]++; }
      break;
    }  case 38: {
      setBioFreq(0, 494l, 10);
      if (now > 70400l) { sequence_no_[0]++; }
      break;
    }  case 39: {
      setBioFreq(0, 494l, 10);
      if (now > 71200l) { sequence_no_[0]++; }
      break;
    }  case 40: {
      setBioFreq(0, 500l, 0);
      if (now > 72000l) { sequence_no_[0]++; }
      break;
    }  case 41: {
      setBioFreq(0, 784l, 10);
      if (now > 75200l) { sequence_no_[0]++; }
      break;
    }  case 42: {
      setBioFreq(0, 784l, 10);
      if (now > 76000l) { sequence_no_[0]++; }
      break;
    }  case 43: {
      setBioFreq(0, 466l, 10);
      if (now > 79200l) { sequence_no_[0]++; }
      break;
    }  case 44: {
      setBioFreq(0, 500l, 0);
      if (now > 80000l) { sequence_no_[0]++; }
      break;
    }  case 45: {
      setBioFreq(0, 740l, 10);
      if (now > 83200l) { sequence_no_[0]++; }
      break;
    }  case 46: {
      setBioFreq(0, 740l, 10);
      if (now > 84000l) { sequence_no_[0]++; }
      break;
    }  case 47: {
      setBioFreq(0, 440l, 10);
      if (now > 87200l) { sequence_no_[0]++; }
      break;
    }  case 48: {
      setBioFreq(0, 500l, 0);
      if (now > 88000l) { sequence_no_[0]++; }
      break;
    }  case 49: {
      setBioFreq(0, 500l, 0);
      if (now > 88800l) { sequence_no_[0]++; }
      break;
    }  case 50: {
      setBioFreq(0, 698l, 10);
      if (now > 92000l) { sequence_no_[0]++; }
      break;
    }  case 51: {
      setBioFreq(0, 831l, 10);
      if (now > 95200l) { sequence_no_[0]++; }
      break;
    }  case 52: {
      setBioFreq(0, 500l, 0);
      if (now > 96000l) { sequence_no_[0]++; }
      break;
    }  case 53: {
      setBioFreq(0, 500l, 0);
      if (now > 96800l) { sequence_no_[0]++; }
      break;
    }  case 54: {
      setBioFreq(0, 659l, 10);
      if (now > 97600l) { sequence_no_[0]++; }
      break;
    }  case 55: {
      setBioFreq(0, 698l, 10);
      if (now > 99200l) { sequence_no_[0]++; }
      break;
    }  case 56: {
      setBioFreq(0, 523l, 10);
      if (now > 100000l) { sequence_no_[0]++; }
      break;
    }  case 57: {
      setBioFreq(0, 500l, 0);
      if (now > 100800l) { sequence_no_[0]++; }
      break;
    }  case 58: {
      setBioFreq(0, 494l, 10);
      if (now > 102400l) { sequence_no_[0]++; }
      break;
    }  case 59: {
      setBioFreq(0, 659l, 10);
      if (now > 104000l) { sequence_no_[0]++; }
      break;
    }  case 60: {
      setBioFreq(0, 740l, 10);
      if (now > 105600l) { sequence_no_[0]++; }
      break;
    }  case 61: {
      setBioFreq(0, 622l, 10);
      if (now > 108000l) { sequence_no_[0]++; }
      break;
    }  case 62: {
      setBioFreq(0, 500l, 0);
      if (now > 108800l) { sequence_no_[0]++; }
      break;
    }  case 63: {
      setBioFreq(0, 740l, 10);
      if (now > 109600l) { sequence_no_[0]++; }
      break;
    }  case 64: {
      setBioFreq(0, 698l, 10);
      if (now > 110400l) { sequence_no_[0]++; }
      break;
    }  case 65: {
      setBioFreq(0, 466l, 10);
      if (now > 112000l) { sequence_no_[0]++; }
      break;
    }  case 66: {
      setBioFreq(0, 466l, 10);
      if (now > 113600l) { sequence_no_[0]++; }
      break;
    }  case 67: {
      setBioFreq(0, 698l, 10);
      if (now > 116000l) { sequence_no_[0]++; }
      break;
    }  case 68: {
      setBioFreq(0, 587l, 10);
      if (now > 116800l) { sequence_no_[0]++; }
      break;
    }  case 69: {
      setBioFreq(0, 698l, 10);
      if (now > 117600l) { sequence_no_[0]++; }
      break;
    }  case 70: {
      setBioFreq(0, 659l, 10);
      if (now > 120000l) { sequence_no_[0]++; }
      break;
    }  case 71: {
      setBioFreq(0, 500l, 0);
      if (now > 124000l) { sequence_no_[0]++; }
      break;
    }  case 72: {
      setBioFreq(0, 500l, 0);
      if (now > 128000l) { sequence_no_[0]++; }
      break;
    }  case 73: {
      setBioFreq(0, 330l, 10);
      if (now > 129600l) { sequence_no_[0]++; }
      break;
    }  case 74: {
      setBioFreq(0, 523l, 10);
      if (now > 132000l) { sequence_no_[0]++; }
      break;
    }  case 75: {
      setBioFreq(0, 500l, 0);
      if (now > 132800l) { sequence_no_[0]++; }
      break;
    }  case 76: {
      setBioFreq(0, 554l, 10);
      if (now > 133200l) { sequence_no_[0]++; }
      break;
    }  case 77: {
      setBioFreq(0, 494l, 10);
      if (now > 133600l) { sequence_no_[0]++; }
      break;
    }  case 78: {
      setBioFreq(0, 415l, 10);
      if (now > 134000l) { sequence_no_[0]++; }
      break;
    }  case 79: {
      setBioFreq(0, 554l, 10);
      if (now > 134400l) { sequence_no_[0]++; }
      break;
    }  case 80: {
      setBioFreq(0, 494l, 10);
      if (now > 136000l) { sequence_no_[0]++; }
      break;
    }  case 81: {
      setBioFreq(0, 466l, 10);
      if (now > 137600l) { sequence_no_[0]++; }
      break;
    }  case 82: {
      setBioFreq(0, 415l, 10);
      if (now > 139200l) { sequence_no_[0]++; }
      break;
    }  case 83: {
      setBioFreq(0, 500l, 0);
      if (now > 140000l) { sequence_no_[0]++; }
      break;
    }  case 84: {
      setBioFreq(0, 415l, 10);
      if (now > 141600l) { sequence_no_[0]++; }
      break;
    }  case 85: {
      setBioFreq(0, 466l, 10);
      if (now > 144000l) { sequence_no_[0]++; }
      break;
    }  case 86: {
      setBioFreq(0, 500l, 0);
      if (now > 145600l) { sequence_no_[0]++; }
      break;
    }  case 87: {
      setBioFreq(0, 415l, 10);
      if (now > 147200l) { sequence_no_[0]++; }
      break;
    }  case 88: {
      setBioFreq(0, 415l, 10);
      if (now > 148000l) { sequence_no_[0]++; }
      break;
    }  case 89: {
      setBioFreq(0, 500l, 0);
      if (now > 148800l) { sequence_no_[0]++; }
      break;
    }  case 90: {
      setBioFreq(0, 392l, 10);
      if (now > 149600l) { sequence_no_[0]++; }
      break;
    }  case 91: {
      setBioFreq(0, 466l, 10);
      if (now > 151200l) { sequence_no_[0]++; }
      break;
    }  case 92: {
      setBioFreq(0, 500l, 0);
      if (now > 152000l) { sequence_no_[0]++; }
      break;
    }  case 93: {
      setBioFreq(0, 466l, 10);
      if (now > 153600l) { sequence_no_[0]++; }
      break;
    }  case 94: {
      setBioFreq(0, 523l, 10);
      if (now > 156000l) { sequence_no_[0]++; }
      break;
    }  case 95: {
      setBioFreq(0, 500l, 0);
      if (now > 158400l) { sequence_no_[0]++; }
      break;
    }  case 96: {
      setBioFreq(0, 587l, 10);
      if (now > 159200l) { sequence_no_[0]++; }
      break;
    }  case 97: {
      setBioFreq(0, 784l, 10);
      if (now > 160000l) { sequence_no_[0]++; }
      break;
    }  case 98: {
      setBioFreq(0, 784l, 10);
      if (now > 160800l) { sequence_no_[0]++; }
      break;
    }  case 99: {
      setBioFreq(0, 587l, 10);
      if (now > 161600l) { sequence_no_[0]++; }
      break;
    }  case 100: {
      setBioFreq(0, 659l, 10);
      if (now > 163200l) { sequence_no_[0]++; }
      break;
    }  case 101: {
      setBioFreq(0, 500l, 0);
      if (now > 164000l) { sequence_no_[0]++; }
      break;
    }  case 102: {
      setBioFreq(0, 698l, 10);
      if (now > 167200l) { sequence_no_[0]++; }
      break;
    }  case 103: {
      setBioFreq(0, 500l, 0);
      if (now > 168000l) { sequence_no_[0]++; }
      break;
    }  case 104: {
      setBioFreq(0, 659l, 10);
      if (now > 170400l) { sequence_no_[0]++; }
      break;
    }  case 105: {
      setBioFreq(0, 659l, 10);
      if (now > 172000l) { sequence_no_[0]++; }
      break;
    }  case 106: {
      setBioFreq(0, 523l, 10);
      if (now > 173600l) { sequence_no_[0]++; }
      break;
    }  case 107: {
      setBioFreq(0, 523l, 10);
      if (now > 176000l) { sequence_no_[0]++; }
      break;
    }  case 108: {
      setBioFreq(0, 415l, 10);
      if (now > 178400l) { sequence_no_[0]++; }
      break;
    }  case 109: {
      setBioFreq(0, 415l, 10);
      if (now > 180000l) { sequence_no_[0]++; }
      break;
    }  case 110: {
      setBioFreq(0, 466l, 10);
      if (now > 181600l) { sequence_no_[0]++; }
      break;
    }  case 111: {
      setBioFreq(0, 466l, 10);
      if (now > 184000l) { sequence_no_[0]++; }
      break;
    }  case 112: {
      setBioFreq(0, 500l, 0);
      if (now > 186400l) { sequence_no_[0]++; }
      break;
    }  case 113: {
      setBioFreq(0, 500l, 0);
      if (now > 188000l) { sequence_no_[0]++; }
      break;
    }  case 114: {
      setBioFreq(0, 500l, 0);
      if (now > 189600l) { sequence_no_[0]++; }
      break;
    }  case 115: {
      setBioFreq(0, 500l, 0);
      if (now > 192000l) { sequence_no_[0]++; }
      break;
    }  case 116: {
      setBioFreq(0, 659l, 10);
      if (now > 194400l) { sequence_no_[0]++; }
      break;
    }  case 117: {
      setBioFreq(0, 523l, 10);
      if (now > 195200l) { sequence_no_[0]++; }
      break;
    }  case 118: {
      setBioFreq(0, 659l, 10);
      if (now > 196000l) { sequence_no_[0]++; }
      break;
    }  case 119: {
      setBioFreq(0, 622l, 10);
      if (now > 197200l) { sequence_no_[0]++; }
      break;
    }  case 120: {
      setBioFreq(0, 659l, 10);
      if (now > 197600l) { sequence_no_[0]++; }
      break;
    }  case 121: {
      setBioFreq(0, 622l, 10);
      if (now > 200000l) { sequence_no_[0]++; }
      break;
    }  case 122: {
      setBioFreq(0, 622l, 10);
      if (now > 202400l) { sequence_no_[0]++; }
      break;
    }  case 123: {
      setBioFreq(0, 466l, 10);
      if (now > 204000l) { sequence_no_[0]++; }
      break;
    }  case 124: {
      setBioFreq(0, 466l, 10);
      if (now > 204800l) { sequence_no_[0]++; }
      break;
    }  case 125: {
      setBioFreq(0, 415l, 10);
      if (now > 205600l) { sequence_no_[0]++; }
      break;
    }  case 126: {
      setBioFreq(0, 415l, 10);
      if (now > 206400l) { sequence_no_[0]++; }
      break;
    }  case 127: {
      setBioFreq(0, 392l, 10);
      if (now > 208000l) { sequence_no_[0]++; }
      break;
    }  case 128: {
      setBioFreq(0, 587l, 10);
      if (now > 210400l) { sequence_no_[0]++; }
      break;
    }  case 129: {
      setBioFreq(0, 415l, 10);
      if (now > 212000l) { sequence_no_[0]++; }
      break;
    }  case 130: {
      setBioFreq(0, 415l, 10);
      if (now > 212800l) { sequence_no_[0]++; }
      break;
    }  case 131: {
      setBioFreq(0, 740l, 10);
      if (now > 213600l) { sequence_no_[0]++; }
      break;
    }  case 132: {
      setBioFreq(0, 698l, 10);
      if (now > 216000l) { sequence_no_[0]++; }
      break;
    }  case 133: {
      setBioFreq(0, 500l, 0);
      if (now > 216800l) { sequence_no_[0]++; }
      break;
    }  case 134: {
      setBioFreq(0, 554l, 10);
      if (now > 218400l) { sequence_no_[0]++; }
      break;
    }  case 135: {
      setBioFreq(0, 554l, 10);
      if (now > 219200l) { sequence_no_[0]++; }
      break;
    }  case 136: {
      setBioFreq(0, 523l, 10);
      if (now > 220000l) { sequence_no_[0]++; }
      break;
    }  case 137: {
      setBioFreq(0, 659l, 10);
      if (now > 221600l) { sequence_no_[0]++; }
      break;
    }  case 138: {
      setBioFreq(0, 622l, 10);
      if (now > 224000l) { sequence_no_[0]++; }
      break;
    }  case 139: {
      setBioFreq(0, 523l, 10);
      if (now > 226400l) { sequence_no_[0]++; }
      break;
    }  case 140: {
      setBioFreq(0, 500l, 0);
      if (now > 228000l) { sequence_no_[0]++; }
      break;
    }  case 141: {
      setBioFreq(0, 500l, 0);
      if (now > 229600l) { sequence_no_[0]++; }
      break;
    }  case 142: {
      setBioFreq(0, 784l, 10);
      if (now > 231200l) { sequence_no_[0]++; }
      break;
    }  case 143: {
      setBioFreq(0, 392l, 10);
      if (now > 232000l) { sequence_no_[0]++; }
      break;
    }  case 144: {
      setBioFreq(0, 494l, 10);
      if (now > 234400l) { sequence_no_[0]++; }
      break;
    }  case 145: {
      setBioFreq(0, 415l, 10);
      if (now > 236000l) { sequence_no_[0]++; }
      break;
    }  case 146: {
      setBioFreq(0, 740l, 10);
      if (now > 237600l) { sequence_no_[0]++; }
      break;
    }  case 147: {
      setBioFreq(0, 698l, 10);
      if (now > 240000l) { sequence_no_[0]++; }
      break;
    }  case 148: {
      setBioFreq(0, 466l, 10);
      if (now > 242400l) { sequence_no_[0]++; }
      break;
    }  case 149: {
      setBioFreq(0, 523l, 10);
      if (now > 244000l) { sequence_no_[0]++; }
      break;
    }  case 150: {
      setBioFreq(0, 659l, 10);
      if (now > 245600l) { sequence_no_[0]++; }
      break;
    }  case 151: {
      setBioFreq(0, 622l, 10);
      if (now > 248000l) { sequence_no_[0]++; }
      break;
    }  case 152: {
      setBioFreq(0, 440l, 10);
      if (now > 249600l) { sequence_no_[0]++; }
      break;
    }  case 153: {
      setBioFreq(0, 415l, 10);
      if (now > 250400l) { sequence_no_[0]++; }
      break;
    }  case 154: {
      setBioFreq(0, 415l, 10);
      if (now > 251200l) { sequence_no_[0]++; }
      break;
    }  case 155: {
      setBioFreq(0, 392l, 10);
      if (now > 252000l) { sequence_no_[0]++; }
      break;
    }  case 156: {
      setBioFreq(0, 415l, 10);
      if (now > 253600l) { sequence_no_[0]++; }
      break;
    }  case 157: {
      setBioFreq(0, 415l, 10);
      if (now > 256000l) { sequence_no_[0]++; }
      break;
    }  case 158: {
      setBioFreq(0, 392l, 10);
      if (now > 258400l) { sequence_no_[0]++; }
      break;
    }  case 159: {
      setBioFreq(0, 494l, 10);
      if (now > 259200l) { sequence_no_[0]++; }
      break;
    }  case 160: {
      setBioFreq(0, 415l, 10);
      if (now > 260000l) { sequence_no_[0]++; }
      break;
    }  case 161: {
      setBioFreq(0, 784l, 10);
      if (now > 260800l) { sequence_no_[0]++; }
      break;
    }  case 162: {
      setBioFreq(0, 740l, 10);
      if (now > 261600l) { sequence_no_[0]++; }
      break;
    }  case 163: {
      setBioFreq(0, 698l, 10);
      if (now > 264000l) { sequence_no_[0]++; }
      break;
    }  case 164: {
      setBioFreq(0, 698l, 10);
      if (now > 266400l) { sequence_no_[0]++; }
      break;
    }  case 165: {
      setBioFreq(0, 698l, 10);
      if (now > 268800l) { sequence_no_[0]++; }
      break;
    }  case 166: {
      setBioFreq(0, 698l, 10);
      if (now > 271200l) { sequence_no_[0]++; }
      break;
    }  case 167: {
      setBioFreq(0, 698l, 10);
      if (now > 273600l) { sequence_no_[0]++; }
      break;
    } default:
      setBioFreq(0, 500l, 0);
      break;
  }
  // alto
  switch (sequence_no_[1]) {
    case 0: {
      setBioFreq(1, 500l, 0);
      if (now > 800l) { sequence_no_[1]++; }
      break;
    }  case 1: {
      setBioFreq(1, 392l, 10);
      if (now > 4000l) { sequence_no_[1]++; }
      break;
    }  case 2: {
      setBioFreq(1, 330l, 10);
      if (now > 7200l) { sequence_no_[1]++; }
      break;
    }  case 3: {
      setBioFreq(1, 500l, 0);
      if (now > 8000l) { sequence_no_[1]++; }
      break;
    }  case 4: {
      setBioFreq(1, 370l, 10);
      if (now > 11200l) { sequence_no_[1]++; }
      break;
    }  case 5: {
      setBioFreq(1, 370l, 10);
      if (now > 12000l) { sequence_no_[1]++; }
      break;
    }  case 6: {
      setBioFreq(1, 311l, 10);
      if (now > 15200l) { sequence_no_[1]++; }
      break;
    }  case 7: {
      setBioFreq(1, 500l, 0);
      if (now > 16000l) { sequence_no_[1]++; }
      break;
    }  case 8: {
      setBioFreq(1, 500l, 0);
      if (now > 18400l) { sequence_no_[1]++; }
      break;
    }  case 9: {
      setBioFreq(1, 349l, 10);
      if (now > 20000l) { sequence_no_[1]++; }
      break;
    }  case 10: {
      setBioFreq(1, 587l, 10);
      if (now > 23200l) { sequence_no_[1]++; }
      break;
    }  case 11: {
      setBioFreq(1, 587l, 10);
      if (now > 24000l) { sequence_no_[1]++; }
      break;
    }  case 12: {
      setBioFreq(1, 659l, 10);
      if (now > 26400l) { sequence_no_[1]++; }
      break;
    }  case 13: {
      setBioFreq(1, 500l, 0);
      if (now > 27200l) { sequence_no_[1]++; }
      break;
    }  case 14: {
      setBioFreq(1, 330l, 10);
      if (now > 28000l) { sequence_no_[1]++; }
      break;
    }  case 15: {
      setBioFreq(1, 277l, 10);
      if (now > 31200l) { sequence_no_[1]++; }
      break;
    }  case 16: {
      setBioFreq(1, 500l, 0);
      if (now > 32000l) { sequence_no_[1]++; }
      break;
    }  case 17: {
      setBioFreq(1, 311l, 10);
      if (now > 34400l) { sequence_no_[1]++; }
      break;
    }  case 18: {
      setBioFreq(1, 262l, 10);
      if (now > 36000l) { sequence_no_[1]++; }
      break;
    }  case 19: {
      setBioFreq(1, 311l, 10);
      if (now > 38400l) { sequence_no_[1]++; }
      break;
    }  case 20: {
      setBioFreq(1, 294l, 10);
      if (now > 40000l) { sequence_no_[1]++; }
      break;
    }  case 21: {
      setBioFreq(1, 500l, 0);
      if (now > 40800l) { sequence_no_[1]++; }
      break;
    }  case 22: {
      setBioFreq(1, 262l, 10);
      if (now > 42400l) { sequence_no_[1]++; }
      break;
    }  case 23: {
      setBioFreq(1, 392l, 10);
      if (now > 44000l) { sequence_no_[1]++; }
      break;
    }  case 24: {
      setBioFreq(1, 370l, 10);
      if (now > 46400l) { sequence_no_[1]++; }
      break;
    }  case 25: {
      setBioFreq(1, 494l, 10);
      if (now > 48000l) { sequence_no_[1]++; }
      break;
    }  case 26: {
      setBioFreq(1, 554l, 10);
      if (now > 50400l) { sequence_no_[1]++; }
      break;
    }  case 27: {
      setBioFreq(1, 466l, 10);
      if (now > 52000l) { sequence_no_[1]++; }
      break;
    }  case 28: {
      setBioFreq(1, 500l, 0);
      if (now > 52800l) { sequence_no_[1]++; }
      break;
    }  case 29: {
      setBioFreq(1, 554l, 10);
      if (now > 53600l) { sequence_no_[1]++; }
      break;
    }  case 30: {
      setBioFreq(1, 523l, 10);
      if (now > 55200l) { sequence_no_[1]++; }
      break;
    }  case 31: {
      setBioFreq(1, 500l, 0);
      if (now > 56000l) { sequence_no_[1]++; }
      break;
    }  case 32: {
      setBioFreq(1, 466l, 10);
      if (now > 58400l) { sequence_no_[1]++; }
      break;
    }  case 33: {
      setBioFreq(1, 349l, 10);
      if (now > 60000l) { sequence_no_[1]++; }
      break;
    }  case 34: {
      setBioFreq(1, 330l, 10);
      if (now > 61600l) { sequence_no_[1]++; }
      break;
    }  case 35: {
      setBioFreq(1, 440l, 10);
      if (now > 64000l) { sequence_no_[1]++; }
      break;
    }  case 36: {
      setBioFreq(1, 494l, 10);
      if (now > 67200l) { sequence_no_[1]++; }
      break;
    }  case 37: {
      setBioFreq(1, 500l, 0);
      if (now > 68000l) { sequence_no_[1]++; }
      break;
    }  case 38: {
      setBioFreq(1, 415l, 10);
      if (now > 68800l) { sequence_no_[1]++; }
      break;
    }  case 39: {
      setBioFreq(1, 494l, 10);
      if (now > 69600l) { sequence_no_[1]++; }
      break;
    }  case 40: {
      setBioFreq(1, 466l, 10);
      if (now > 72000l) { sequence_no_[1]++; }
      break;
    }  case 41: {
      setBioFreq(1, 500l, 0);
      if (now > 72800l) { sequence_no_[1]++; }
      break;
    }  case 42: {
      setBioFreq(1, 415l, 10);
      if (now > 74400l) { sequence_no_[1]++; }
      break;
    }  case 43: {
      setBioFreq(1, 311l, 10);
      if (now > 75200l) { sequence_no_[1]++; }
      break;
    }  case 44: {
      setBioFreq(1, 466l, 10);
      if (now > 76000l) { sequence_no_[1]++; }
      break;
    }  case 45: {
      setBioFreq(1, 392l, 10);
      if (now > 79200l) { sequence_no_[1]++; }
      break;
    }  case 46: {
      setBioFreq(1, 392l, 10);
      if (now > 80000l) { sequence_no_[1]++; }
      break;
    }  case 47: {
      setBioFreq(1, 440l, 10);
      if (now > 83200l) { sequence_no_[1]++; }
      break;
    }  case 48: {
      setBioFreq(1, 500l, 0);
      if (now > 84000l) { sequence_no_[1]++; }
      break;
    }  case 49: {
      setBioFreq(1, 370l, 10);
      if (now > 84800l) { sequence_no_[1]++; }
      break;
    }  case 50: {
      setBioFreq(1, 440l, 10);
      if (now > 85600l) { sequence_no_[1]++; }
      break;
    }  case 51: {
      setBioFreq(1, 415l, 10);
      if (now > 88000l) { sequence_no_[1]++; }
      break;
    }  case 52: {
      setBioFreq(1, 370l, 10);
      if (now > 89600l) { sequence_no_[1]++; }
      break;
    }  case 53: {
      setBioFreq(1, 277l, 10);
      if (now > 91200l) { sequence_no_[1]++; }
      break;
    }  case 54: {
      setBioFreq(1, 415l, 10);
      if (now > 92000l) { sequence_no_[1]++; }
      break;
    }  case 55: {
      setBioFreq(1, 349l, 10);
      if (now > 95200l) { sequence_no_[1]++; }
      break;
    }  case 56: {
      setBioFreq(1, 500l, 0);
      if (now > 96000l) { sequence_no_[1]++; }
      break;
    }  case 57: {
      setBioFreq(1, 500l, 0);
      if (now > 96800l) { sequence_no_[1]++; }
      break;
    }  case 58: {
      setBioFreq(1, 392l, 10);
      if (now > 98400l) { sequence_no_[1]++; }
      break;
    }  case 59: {
      setBioFreq(1, 330l, 10);
      if (now > 100000l) { sequence_no_[1]++; }
      break;
    }  case 60: {
      setBioFreq(1, 392l, 10);
      if (now > 100800l) { sequence_no_[1]++; }
      break;
    }  case 61: {
      setBioFreq(1, 370l, 10);
      if (now > 102400l) { sequence_no_[1]++; }
      break;
    }  case 62: {
      setBioFreq(1, 494l, 10);
      if (now > 104000l) { sequence_no_[1]++; }
      break;
    }  case 63: {
      setBioFreq(1, 494l, 10);
      if (now > 105600l) { sequence_no_[1]++; }
      break;
    }  case 64: {
      setBioFreq(1, 370l, 10);
      if (now > 108000l) { sequence_no_[1]++; }
      break;
    }  case 65: {
      setBioFreq(1, 500l, 0);
      if (now > 108800l) { sequence_no_[1]++; }
      break;
    }  case 66: {
      setBioFreq(1, 311l, 10);
      if (now > 109600l) { sequence_no_[1]++; }
      break;
    }  case 67: {
      setBioFreq(1, 370l, 10);
      if (now > 110400l) { sequence_no_[1]++; }
      break;
    }  case 68: {
      setBioFreq(1, 349l, 10);
      if (now > 112000l) { sequence_no_[1]++; }
      break;
    }  case 69: {
      setBioFreq(1, 311l, 10);
      if (now > 113600l) { sequence_no_[1]++; }
      break;
    }  case 70: {
      setBioFreq(1, 466l, 10);
      if (now > 116000l) { sequence_no_[1]++; }
      break;
    }  case 71: {
      setBioFreq(1, 440l, 10);
      if (now > 116800l) { sequence_no_[1]++; }
      break;
    }  case 72: {
      setBioFreq(1, 294l, 10);
      if (now > 117600l) { sequence_no_[1]++; }
      break;
    }  case 73: {
      setBioFreq(1, 349l, 10);
      if (now > 120000l) { sequence_no_[1]++; }
      break;
    }  case 74: {
      setBioFreq(1, 294l, 10);
      if (now > 123200l) { sequence_no_[1]++; }
      break;
    }  case 75: {
      setBioFreq(1, 294l, 10);
      if (now > 124000l) { sequence_no_[1]++; }
      break;
    }  case 76: {
      setBioFreq(1, 500l, 0);
      if (now > 124800l) { sequence_no_[1]++; }
      break;
    }  case 77: {
      setBioFreq(1, 277l, 10);
      if (now > 125600l) { sequence_no_[1]++; }
      break;
    }  case 78: {
      setBioFreq(1, 330l, 10);
      if (now > 127200l) { sequence_no_[1]++; }
      break;
    }  case 79: {
      setBioFreq(1, 500l, 0);
      if (now > 128000l) { sequence_no_[1]++; }
      break;
    }  case 80: {
      setBioFreq(1, 277l, 10);
      if (now > 129600l) { sequence_no_[1]++; }
      break;
    }  case 81: {
      setBioFreq(1, 311l, 10);
      if (now > 132000l) { sequence_no_[1]++; }
      break;
    }  case 82: {
      setBioFreq(1, 500l, 0);
      if (now > 134400l) { sequence_no_[1]++; }
      break;
    }  case 83: {
      setBioFreq(1, 415l, 10);
      if (now > 135200l) { sequence_no_[1]++; }
      break;
    }  case 84: {
      setBioFreq(1, 277l, 10);
      if (now > 136000l) { sequence_no_[1]++; }
      break;
    }  case 85: {
      setBioFreq(1, 277l, 10);
      if (now > 136800l) { sequence_no_[1]++; }
      break;
    }  case 86: {
      setBioFreq(1, 415l, 10);
      if (now > 137600l) { sequence_no_[1]++; }
      break;
    }  case 87: {
      setBioFreq(1, 466l, 10);
      if (now > 139200l) { sequence_no_[1]++; }
      break;
    }  case 88: {
      setBioFreq(1, 500l, 0);
      if (now > 140000l) { sequence_no_[1]++; }
      break;
    }  case 89: {
      setBioFreq(1, 466l, 10);
      if (now > 141600l) { sequence_no_[1]++; }
      break;
    }  case 90: {
      setBioFreq(1, 415l, 10);
      if (now > 144000l) { sequence_no_[1]++; }
      break;
    }  case 91: {
      setBioFreq(1, 500l, 0);
      if (now > 144800l) { sequence_no_[1]++; }
      break;
    }  case 92: {
      setBioFreq(1, 466l, 10);
      if (now > 145200l) { sequence_no_[1]++; }
      break;
    }  case 93: {
      setBioFreq(1, 415l, 10);
      if (now > 145600l) { sequence_no_[1]++; }
      break;
    }  case 94: {
      setBioFreq(1, 349l, 10);
      if (now > 146000l) { sequence_no_[1]++; }
      break;
    }  case 95: {
      setBioFreq(1, 466l, 10);
      if (now > 146400l) { sequence_no_[1]++; }
      break;
    }  case 96: {
      setBioFreq(1, 415l, 10);
      if (now > 148000l) { sequence_no_[1]++; }
      break;
    }  case 97: {
      setBioFreq(1, 392l, 10);
      if (now > 149600l) { sequence_no_[1]++; }
      break;
    }  case 98: {
      setBioFreq(1, 349l, 10);
      if (now > 151200l) { sequence_no_[1]++; }
      break;
    }  case 99: {
      setBioFreq(1, 500l, 0);
      if (now > 152000l) { sequence_no_[1]++; }
      break;
    }  case 100: {
      setBioFreq(1, 349l, 10);
      if (now > 153600l) { sequence_no_[1]++; }
      break;
    }  case 101: {
      setBioFreq(1, 349l, 10);
      if (now > 156000l) { sequence_no_[1]++; }
      break;
    }  case 102: {
      setBioFreq(1, 349l, 10);
      if (now > 159200l) { sequence_no_[1]++; }
      break;
    }  case 103: {
      setBioFreq(1, 500l, 0);
      if (now > 160000l) { sequence_no_[1]++; }
      break;
    }  case 104: {
      setBioFreq(1, 500l, 0);
      if (now > 164000l) { sequence_no_[1]++; }
      break;
    }  case 105: {
      setBioFreq(1, 415l, 10);
      if (now > 167200l) { sequence_no_[1]++; }
      break;
    }  case 106: {
      setBioFreq(1, 500l, 0);
      if (now > 168000l) { sequence_no_[1]++; }
      break;
    }  case 107: {
      setBioFreq(1, 500l, 0);
      if (now > 170400l) { sequence_no_[1]++; }
      break;
    }  case 108: {
      setBioFreq(1, 500l, 0);
      if (now > 172000l) { sequence_no_[1]++; }
      break;
    }  case 109: {
      setBioFreq(1, 330l, 10);
      if (now > 173600l) { sequence_no_[1]++; }
      break;
    }  case 110: {
      setBioFreq(1, 311l, 10);
      if (now > 176000l) { sequence_no_[1]++; }
      break;
    }  case 111: {
      setBioFreq(1, 370l, 10);
      if (now > 178400l) { sequence_no_[1]++; }
      break;
    }  case 112: {
      setBioFreq(1, 466l, 10);
      if (now > 180000l) { sequence_no_[1]++; }
      break;
    }  case 113: {
      setBioFreq(1, 415l, 10);
      if (now > 181600l) { sequence_no_[1]++; }
      break;
    }  case 114: {
      setBioFreq(1, 392l, 10);
      if (now > 184000l) { sequence_no_[1]++; }
      break;
    }  case 115: {
      setBioFreq(1, 349l, 10);
      if (now > 185600l) { sequence_no_[1]++; }
      break;
    }  case 116: {
      setBioFreq(1, 415l, 10);
      if (now > 186400l) { sequence_no_[1]++; }
      break;
    }  case 117: {
      setBioFreq(1, 349l, 10);
      if (now > 188000l) { sequence_no_[1]++; }
      break;
    }  case 118: {
      setBioFreq(1, 330l, 10);
      if (now > 189600l) { sequence_no_[1]++; }
      break;
    }  case 119: {
      setBioFreq(1, 523l, 10);
      if (now > 192000l) { sequence_no_[1]++; }
      break;
    }  case 120: {
      setBioFreq(1, 523l, 10);
      if (now > 194400l) { sequence_no_[1]++; }
      break;
    }  case 121: {
      setBioFreq(1, 330l, 10);
      if (now > 195600l) { sequence_no_[1]++; }
      break;
    }  case 122: {
      setBioFreq(1, 440l, 10);
      if (now > 196000l) { sequence_no_[1]++; }
      break;
    }  case 123: {
      setBioFreq(1, 466l, 10);
      if (now > 196800l) { sequence_no_[1]++; }
      break;
    }  case 124: {
      setBioFreq(1, 311l, 10);
      if (now > 197600l) { sequence_no_[1]++; }
      break;
    }  case 125: {
      setBioFreq(1, 311l, 10);
      if (now > 198400l) { sequence_no_[1]++; }
      break;
    }  case 126: {
      setBioFreq(1, 466l, 10);
      if (now > 200000l) { sequence_no_[1]++; }
      break;
    }  case 127: {
      setBioFreq(1, 466l, 10);
      if (now > 202400l) { sequence_no_[1]++; }
      break;
    }  case 128: {
      setBioFreq(1, 466l, 10);
      if (now > 203200l) { sequence_no_[1]++; }
      break;
    }  case 129: {
      setBioFreq(1, 311l, 10);
      if (now > 204000l) { sequence_no_[1]++; }
      break;
    }  case 130: {
      setBioFreq(1, 294l, 10);
      if (now > 205600l) { sequence_no_[1]++; }
      break;
    }  case 131: {
      setBioFreq(1, 415l, 10);
      if (now > 208000l) { sequence_no_[1]++; }
      break;
    }  case 132: {
      setBioFreq(1, 415l, 10);
      if (now > 208800l) { sequence_no_[1]++; }
      break;
    }  case 133: {
      setBioFreq(1, 392l, 10);
      if (now > 210000l) { sequence_no_[1]++; }
      break;
    }  case 134: {
      setBioFreq(1, 370l, 10);
      if (now > 210400l) { sequence_no_[1]++; }
      break;
    }  case 135: {
      setBioFreq(1, 370l, 10);
      if (now > 212000l) { sequence_no_[1]++; }
      break;
    }  case 136: {
      setBioFreq(1, 500l, 0);
      if (now > 212800l) { sequence_no_[1]++; }
      break;
    }  case 137: {
      setBioFreq(1, 415l, 10);
      if (now > 213600l) { sequence_no_[1]++; }
      break;
    }  case 138: {
      setBioFreq(1, 415l, 10);
      if (now > 216000l) { sequence_no_[1]++; }
      break;
    }  case 139: {
      setBioFreq(1, 330l, 10);
      if (now > 217600l) { sequence_no_[1]++; }
      break;
    }  case 140: {
      setBioFreq(1, 349l, 10);
      if (now > 218400l) { sequence_no_[1]++; }
      break;
    }  case 141: {
      setBioFreq(1, 440l, 10);
      if (now > 220000l) { sequence_no_[1]++; }
      break;
    }  case 142: {
      setBioFreq(1, 466l, 10);
      if (now > 220800l) { sequence_no_[1]++; }
      break;
    }  case 143: {
      setBioFreq(1, 523l, 10);
      if (now > 221600l) { sequence_no_[1]++; }
      break;
    }  case 144: {
      setBioFreq(1, 466l, 10);
      if (now > 224000l) { sequence_no_[1]++; }
      break;
    }  case 145: {
      setBioFreq(1, 466l, 10);
      if (now > 226400l) { sequence_no_[1]++; }
      break;
    }  case 146: {
      setBioFreq(1, 523l, 10);
      if (now > 227200l) { sequence_no_[1]++; }
      break;
    }  case 147: {
      setBioFreq(1, 466l, 10);
      if (now > 228000l) { sequence_no_[1]++; }
      break;
    }  case 148: {
      setBioFreq(1, 466l, 10);
      if (now > 228800l) { sequence_no_[1]++; }
      break;
    }  case 149: {
      setBioFreq(1, 415l, 10);
      if (now > 229600l) { sequence_no_[1]++; }
      break;
    }  case 150: {
      setBioFreq(1, 392l, 10);
      if (now > 230400l) { sequence_no_[1]++; }
      break;
    }  case 151: {
      setBioFreq(1, 415l, 10);
      if (now > 232000l) { sequence_no_[1]++; }
      break;
    }  case 152: {
      setBioFreq(1, 415l, 10);
      if (now > 233600l) { sequence_no_[1]++; }
      break;
    }  case 153: {
      setBioFreq(1, 392l, 10);
      if (now > 234400l) { sequence_no_[1]++; }
      break;
    }  case 154: {
      setBioFreq(1, 494l, 10);
      if (now > 236000l) { sequence_no_[1]++; }
      break;
    }  case 155: {
      setBioFreq(1, 523l, 10);
      if (now > 236800l) { sequence_no_[1]++; }
      break;
    }  case 156: {
      setBioFreq(1, 554l, 10);
      if (now > 237600l) { sequence_no_[1]++; }
      break;
    }  case 157: {
      setBioFreq(1, 523l, 10);
      if (now > 240000l) { sequence_no_[1]++; }
      break;
    }  case 158: {
      setBioFreq(1, 523l, 10);
      if (now > 242400l) { sequence_no_[1]++; }
      break;
    }  case 159: {
      setBioFreq(1, 466l, 10);
      if (now > 243200l) { sequence_no_[1]++; }
      break;
    }  case 160: {
      setBioFreq(1, 440l, 10);
      if (now > 244000l) { sequence_no_[1]++; }
      break;
    }  case 161: {
      setBioFreq(1, 466l, 10);
      if (now > 245600l) { sequence_no_[1]++; }
      break;
    }  case 162: {
      setBioFreq(1, 440l, 10);
      if (now > 248000l) { sequence_no_[1]++; }
      break;
    }  case 163: {
      setBioFreq(1, 311l, 10);
      if (now > 250400l) { sequence_no_[1]++; }
      break;
    }  case 164: {
      setBioFreq(1, 392l, 10);
      if (now > 250800l) { sequence_no_[1]++; }
      break;
    }  case 165: {
      setBioFreq(1, 440l, 10);
      if (now > 251600l) { sequence_no_[1]++; }
      break;
    }  case 166: {
      setBioFreq(1, 466l, 10);
      if (now > 252000l) { sequence_no_[1]++; }
      break;
    }  case 167: {
      setBioFreq(1, 415l, 10);
      if (now > 253600l) { sequence_no_[1]++; }
      break;
    }  case 168: {
      setBioFreq(1, 392l, 10);
      if (now > 256000l) { sequence_no_[1]++; }
      break;
    }  case 169: {
      setBioFreq(1, 415l, 10);
      if (now > 258400l) { sequence_no_[1]++; }
      break;
    }  case 170: {
      setBioFreq(1, 415l, 10);
      if (now > 260000l) { sequence_no_[1]++; }
      break;
    }  case 171: {
      setBioFreq(1, 370l, 10);
      if (now > 261600l) { sequence_no_[1]++; }
      break;
    }  case 172: {
      setBioFreq(1, 349l, 10);
      if (now > 264000l) { sequence_no_[1]++; }
      break;
    }  case 173: {
      setBioFreq(1, 349l, 10);
      if (now > 266400l) { sequence_no_[1]++; }
      break;
    }  case 174: {
      setBioFreq(1, 349l, 10);
      if (now > 268800l) { sequence_no_[1]++; }
      break;
    }  case 175: {
      setBioFreq(1, 500l, 0);
      if (now > 271200l) { sequence_no_[1]++; }
      break;
    }  case 176: {
      setBioFreq(1, 500l, 0);
      if (now > 273600l) { sequence_no_[1]++; }
      break;
    } default:
      setBioFreq(1, 500l, 0);
      break;
  }

  // // 0
  //  switch (sequence_no_[0]) {
  //    case 0: {
  //      setBioFreq(0, 392l, 0);
  //      if (now > 800l) { sequence_no_[0]++; }
  //      break;
  //    } case 1: {
  //     setBioFreq(0, 392l, 10);
  //      if (now > 4000l) { sequence_no_[0]++; }
  //      break;
  //    } case 2: {
  //      setBioFreq(0, 330l, 10);
  //      if (now > 7200l) { sequence_no_[0]++; }
  //      break;
  //    } case 3: {
  //      setBioFreq(0, 370l, 0);
  //      if (now > 8000l) { sequence_no_[0]++; }
  //      break;
  //    } case 4: {
  //     long t = constrain(now - 11100l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //      setBioFreq(0, 370l, 10 - value);
  //      if (now > 11200l) { sequence_no_[0]++; }
  //      break;
  //    } case 5: {
  //     long t = constrain(now - 11200l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //      setBioFreq(0, 370l, value);
  //      if (now > 12000l) { sequence_no_[0]++; }
  //      break;
  //    } case 6: {
  //      setBioFreq(0, 311l, 10);
  //      if (now > 15200l) { sequence_no_[0]++; }
  //      break;
  //    } case 7: {
  //      setBioFreq(0, 349l, 0);
  //      if (now > 18400l) { sequence_no_[0]++; }
  //      break;
  //    } case 8: {
  //      setBioFreq(0, 349l, 10);
  //      if (now > 20000l) { sequence_no_[0]++; }
  //      break;
  //    } case 9: {
  //      setBioFreq(0, 587l, 10);
  //      if (now > 24000l) { sequence_no_[0]++; }
  //      break;
  //    } case 10: {
  //      setBioFreq(0, 659l, 10);
  //      if (now > 26400l) { sequence_no_[0]++; }
  //      break;
  //    } case 11: {
  //      setBioFreq(0, 330l, 0);
  //      if (now > 27200l) { sequence_no_[0]++; }
  //      break;
  //    } case 12: {
  //      setBioFreq(0, 330l, 10);
  //      if (now > 28000l) { sequence_no_[0]++; }
  //      break;
  //    } case 13: {
  //      setBioFreq(0, 277l, 10);
  //      if (now > 31200l) { sequence_no_[0]++; }
  //      break;
  //    } case 14: {
  //      setBioFreq(0, 311l, 0);
  //      if (now > 32000l) { sequence_no_[0]++; }
  //      break;
  //    } default:
  //      setBioFreq(0, 500l, 0);
  //      break;
  //  }

   // 1
  // switch (sequence_no_[1]) {
  //   case 0: {
  //     setBioFreq(1, 262l, 0);
  //     if (now > 9600l) { sequence_no_[1]++; }
  //     break;
  //   } case 1: {
  //     setBioFreq(1, 622l, 10);
  //     if (now > 12800l) { sequence_no_[1]++; }
  //     break;
  //   } case 2: {
  //     long t = constrain(now - 15900l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //     setBioFreq(1, 740l, 10 - value);
  //     if (now > 16000l) { sequence_no_[1]++; }
  //     break;
  //   } case 3: {
  //     long t = constrain(now - 16000l, 0l, 100l);
  //     int value = ease_in_cubicL(t, 0l, 10l, 100l);
  //      setBioFreq(1, 587l, value);
  //     if (now > 20000l) { sequence_no_[1]++; }
  //     break;
  //   } case 4: {
  //     setBioFreq(1, 698l, 10);
  //     if (now > 22400l) { sequence_no_[1]++; }
  //     break;
  //   } case 5: {
  //     setBioFreq(1, 698l, 0);
  //     if (now > 23200l) { sequence_no_[1]++; }
  //     break;
  //   } case 6: {
  //     setBioFreq(1, 698l, 10);
  //     if (now > 24000l) { sequence_no_[1]++; }
  //     break;
  //   } case 7: {
  //     setBioFreq(1, 554l, 10);
  //     if (now > 28000l) { sequence_no_[1]++; }
  //     break;
  //   } case 8: {
  //     setBioFreq(1, 698l, 0);
  //     if (now > 28800l) { sequence_no_[1]++; }
  //     break;
  //   } case 9: {
  //     setBioFreq(1, 659l, 10);
  //     if (now > 31200l) { sequence_no_[1]++; }
  //     break;
  //   } case 10: {
  //     setBioFreq(1, 523l, 0);
  //     if (now > 32000l) { sequence_no_[1]++; }
  //     break;
  //   } default:
  //     setBioFreq(1, 500l, 0);
  //     break;
  // }


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
