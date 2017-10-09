#include "global.h"
#include "tick.h"
#include "biometal.h"

const int JOYSTIC_X_PIN = 0;
const int JOYSTIC_Y_PIN = 1;
const int SENSOR_PIN = 2;
const int RELAY_PIN = 9;

const int BIOMETAL_PIN1 = 3;
const int BIOMETAL_PIN2A = 5;
const int BIOMETAL_PIN2B = 6;
const int BIOMETAL_PIN2C = 10;


Tick TICK = Tick();
Biometal BIOMETAL1 = Biometal(BIOMETAL_PIN1);
Biometal BIOMETAL2A = Biometal(BIOMETAL_PIN2A);
Biometal BIOMETAL2B = Biometal(BIOMETAL_PIN2B);
Biometal BIOMETAL2C = Biometal(BIOMETAL_PIN2C);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  BIOMETAL1.setupBio();
  BIOMETAL2A.setupBio();
  BIOMETAL2B.setupBio();
  BIOMETAL2C.setupBio();
  Serial.begin(115200);
  TICK.setupTick();
 
  delay(50);
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  TICK.updateTick();
  BIOMETAL1.updateBio(TICK.diffMicros());
  BIOMETAL2A.updateBio(TICK.diffMicros());
  BIOMETAL2B.updateBio(TICK.diffMicros());
  BIOMETAL2C.updateBio(TICK.diffMicros());

  int joystic_x = analogRead(JOYSTIC_X_PIN);
  int joystic_y = analogRead(JOYSTIC_Y_PIN);

  double joystic_xd = double(joystic_x - 500);
  double joystic_yd = double(joystic_y - 500);
  
  float amp = float(sqrt(joystic_xd * joystic_xd + joystic_yd * joystic_yd));
  float theta = float(atan2(joystic_yd, joystic_xd));

  int biometal2a = int(map(long(amp * sin(theta)),
                           -500l, 500l,
                           -255l, 255l));
  int biometal2b = int(map(long(amp * sin(theta + TWO_PI / 3.0)),
                           -500l, 500l,
                           -255l, 255l));
  int biometal2c = int(map(long(amp * sin(theta + TWO_PI * 2.0 / 3.0)),
                           -500l, 500l,
                           -255l, 255l));
  biometal2a = constrain(biometal2a, 0, 255);
  biometal2b = constrain(biometal2b, 0, 255);
  biometal2c = constrain(biometal2c, 0, 255);
  BIOMETAL2A.setPwm(biometal2a, TICK.diffMicros());
  BIOMETAL2B.setPwm(biometal2b, TICK.diffMicros());
  BIOMETAL2C.setPwm(biometal2c, TICK.diffMicros());

//  Serial.print("  biometal2a: ");
//  Serial.print(biometal2a);
//  Serial.print("  biometal2b: ");
//  Serial.print(biometal2b);
//  Serial.print("  biometal2c: ");
//  Serial.println(biometal2c);

  int sensor = analogRead(SENSOR_PIN);
//  sensor = map(sensor, 20, 800, 0, 255);
//  sensor = constrain(sensor, 0, 255);
//  sensor = ease_in_cubic(sensor, 0, 255, 255);
//  BIOMETAL1.setPwm(sensor, TICK.diffMicros());

  sensor = map(sensor, 20, 800, 0, 70);
  sensor = constrain(sensor, 0, 70);
  sensor = ease_in_cubic(sensor, 0, 70, 70);
  BIOMETAL1.setDeg(sensor, TICK.diffMicros());
}

