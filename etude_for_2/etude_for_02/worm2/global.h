#pragma once
int ON_VALUE = 0;
int OFF_VALUE = 255;

int ease_in_quadratic(int t, int b, int c, int d) {
  // t: time
  // b: y start
  // c: y dist
  // d: t duration
  float delta_t = float(t) / float(d);
  return int(float(c) * delta_t * delta_t + float(b));
}

int ease_in_cubic(int t, int b, int c, int d) {
  float delta_t = float(t) / float(d);
  return int(float(c) * delta_t * delta_t * delta_t + float(b));
}

long ease_in_cubicL(long t, long b, long c, long d) {
  float delta_t = float(t) / float(d);
  return long(float(c) * delta_t * delta_t * delta_t + float(b));
}

long ease_out_cubicL(long t, long b, long c, long d) {
  float delta_t = float(t) / float(d);
  delta_t -= 1.0;
  return long(float(c)*(delta_t * delta_t * delta_t + 1.0) + float(b));
}
