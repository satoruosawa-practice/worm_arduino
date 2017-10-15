unsigned int getPWM2(float ratio) {
  unsigned int max_value = OCR2A;
  unsigned int value = max_value - (unsigned int)((float)max_value * ratio);
  return value;
}

