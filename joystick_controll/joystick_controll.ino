#include "global.h"
#include "tick.h"
#include "biometal.h"

const int JOYSTIC_X = 1;
const int JOYSTIC_Y = 2;
const int RELAY_PIN = 9;

const int BIOMETAL_PIN1 = 5;
const int BIOMETAL_PIN2 = 6;
const int BIOMETAL_PIN3 = 3;


Tick TICK = Tick();
Biometal BIOMETAL = Biometal();

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
//  pinMode(BIOMETAL_PIN1, OUTPUT);
//  pinMode(BIOMETAL_PIN2, OUTPUT);
//  pinMode(BIOMETAL_PIN3, OUTPUT);

  Serial.begin(115200);
  TICK.setupTick();
  BIOMETAL.setupBio();
 
  delay(50);
  digitalWrite(RELAY_PIN, HIGH);

}

void loop() {
  TICK.updateTick();
  BIOMETAL.updateBio(TICK.diffMicros());

  
  int joystic_x = analogRead(JOYSTIC_X);

  joystic_x = map(joystic_x, 500, 1000, 0, 255);
  joystic_x = constrain(joystic_x, 0, 255);

  BIOMETAL.set(joystic_x, TICK.diffMicros());


  analogWrite(BIOMETAL_PIN1, 255 - BIOMETAL.pwm());

  Serial.print("joy:");
  Serial.print(joystic_x);
  Serial.print("  heatParam:");
  Serial.print(BIOMETAL.heatParam());
  Serial.print("  pwm:");
  Serial.print(BIOMETAL.pwm());
  Serial.print("  sec:");
  Serial.print(TICK.ellapsedMicros() / 1000000);
  Serial.print("  diff:");
  Serial.println(TICK.diffMicros());
}
