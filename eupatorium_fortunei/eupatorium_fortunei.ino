#include "global.h"
#include "ticker.h"
#include "biometalContainer.h"
#include "scene.h"

const int RELAY_PIN = 9;

Ticker * TICKER = new Ticker();
BiometalContainer * BIOMETAL_CONTAINER = new BiometalContainer();
Scene * SCENE = new Scene(*TICKER, *BIOMETAL_CONTAINER);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  TCCR2B &= B11110111;
  TCCR2B |= B00001000;  // WGM22, 21, 20 = 101
  TCCR1A &= B11011111;
  TCCR1A |= B00100000;
  TCCR1B &= B11101111;
  TCCR1B |= B00010000;  // WGM13, 12, 11, 10 = 1001
  BIOMETAL_CONTAINER->setup();
  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
  TICKER->reset();
}

void loop() {
  
  TICKER->update();
  BIOMETAL_CONTAINER->update(TICKER->deltaMicros());
  SCENE->sequence();
  int sensor = analogRead(2);
  if (sensor > 500) {
     TICKER->reset();
     SCENE->reset();
  }
}
