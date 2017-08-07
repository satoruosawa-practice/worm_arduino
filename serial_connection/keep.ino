void keep(int recieved_value) {
  int on_time = 30;
  int keep_time = map(recieved_value, 0, 9, 0, 2000);
  int keep_value = 240;
  int span_time = 2000;
  analogWrite(BIOMETAL_PIN, ON_VALUE);
  delay(on_time);
  analogWrite(BIOMETAL_PIN, keep_value);
  delay(keep_time);
  analogWrite(BIOMETAL_PIN, OFF_VALUE);
  delay(span_time);
}
