#pragma once
#include "Arduino.h"
#include "biometal.h"
#include "soundBiometalUno.h"

class BiometalContainer {
 public:
  BiometalContainer();
  void setup();
  void update(long delta_micros);
  int size() {
    return sizeof(biometals_) / sizeof(biometals_[0]);
  }
  Biometal * get(int id) {
    return biometals_[id];
  }

 private:
  Biometal * biometals_[4];
};

BiometalContainer::BiometalContainer() {
  biometals_[0] = (Biometal *)(new SoundBiometalUno(10));
  biometals_[1] = (Biometal *)(new SoundBiometalUno(3));
  biometals_[2] = new Biometal(6);
  biometals_[3] = new Biometal(5);
}

void BiometalContainer::setup() {
  for (int i = 0; i < this->size(); i++) {
    biometals_[i]->setup();
  }
}

void BiometalContainer::update(long delta_micros) {
  for (int i = 0; i < this->size(); i++) {
    biometals_[i]->update(delta_micros);
  }
}
