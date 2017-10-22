#pragma once
#include "Arduino.h"
#include "biometal.h"

class BiometalContainer {
 public:
  BiometalContainer();
  void setupBio();
  void updateBio(long delta_micros);
  int size() {
    return sizeof(biometals_) / sizeof(biometals_[0]);
  }
  Biometal * get(int id) {
    return biometals_[id];
  }

 private:
  int length_;
  Biometal * biometals_[4];
};

BiometalContainer::BiometalContainer() {
  length_ = 4;
  biometals_[0] = new Biometal(3);
  biometals_[1] = new Biometal(6);
  biometals_[2] = new Biometal(5);
  biometals_[3] = new Biometal(10);
}

void BiometalContainer::setupBio() {
  for (int i = 0; i < length_; i++) {
    biometals_[i]->setupBio();
  }
}

void BiometalContainer::updateBio(long delta_micros) {
  for (int i = 0; i < length_; i++) {
    biometals_[i]->updateBio(delta_micros);
  }
}

