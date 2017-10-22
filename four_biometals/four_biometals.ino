#include "global.h"
#include "tick.h"
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
  SCENE->scequence();
//  BIOMETAL1.updateBio(TICK.deltaMicros());

//  int sensor = analogRead(SENSOR_PIN);
//  sensor = map(sensor, 20, 800, 0, 255);
//  sensor = constrain(sensor, 0, 255);
//  sensor = ease_in_cubic(sensor, 0, 255, 255);
//  BIOMETAL1.setPwm(sensor, TICK.deltaMicros());

//  sensor = map(sensor, 20, 800, 0, 70);
//  sensor = constrain(sensor, 0, 70);
//  sensor = ease_in_cubic(sensor, 0, 70, 70);
//  BIOMETAL1.setDeg(sensor, TICK.deltaMicros());
}

