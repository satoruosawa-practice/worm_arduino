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
  BIOMETAL_CONTAINER->setup();
 Serial.begin(115200);

  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
  TICKER->reset();
}

void loop() {
  TICKER->update();
  BIOMETAL_CONTAINER->update(TICKER->deltaMicros());
  SCENE->sequence();
  Serial.println(BIOMETAL_CONTAINER->size());
  int sensor = analogRead(2);
  if (sensor > 500) {
     TICKER->reset();
  }
}
