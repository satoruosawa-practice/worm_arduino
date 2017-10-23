#include "global.h"
#include "ticker.h"
#include "biometalContainer.h"
#include "scene.h"

const int RELAY_PIN = 9;

Ticker * TICKER = new Ticker();
BiometalContainer * BIOMETAL_CONTAINER = new BiometalContainer();
Scene * SCENE = new Scene(*TICKER, *BIOMETAL_CONTAINER);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  BIOMETAL_CONTAINER->setupBio();
  Serial.begin(115200);
 
  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
  TICKER->setupTicker();
}

void loop() {
  TICKER->updateTicker();
  BIOMETAL_CONTAINER->updateBio(TICKER->deltaMicros());
  SCENE->sequence();

  int sensor = analogRead(2);
  if (sensor > 500) {
     TICKER->setupTicker();
  }
}

