#pragma once
int ON_VALUE = 0;
int OFF_VALUE = 255;

int ease_in_quadratic(int t, int b, int c, int d) {
  float delta_t = float(t) / float(d);
  return int(float(c) * delta_t * delta_t + float(b));
}

int ease_in_cubic(int t, int b, int c, int d) {
  float delta_t = float(t) / float(d);
  return int(float(c) * delta_t * delta_t * delta_t + float(b));
}

