int inputSerial() {
  char c = Serial.read();
  if ('0' <= c && c <= '9') {
    int received_value = int(c - '0');
    return received_value;
  }
  return 0;
}

