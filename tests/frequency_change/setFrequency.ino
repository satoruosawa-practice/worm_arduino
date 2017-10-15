void setFrequency2(long frequency) {
  long value = 8000000l / frequency;
  if(value < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000001;
    OCR2A = (unsigned int)(value);
  } else if (value / 8l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000010;
    OCR2A = (unsigned int)(value / 8l);
  } else if (value / 32l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000011;
    OCR2A = (unsigned int)(value / 32l);
  } else if (value / 64l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000100;
    OCR2A = (unsigned int)(value / 64l);
  } else if (value / 128l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000101;
    OCR2A = (unsigned int)(value / 128l);
  } else if (value / 256l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000110;
    OCR2A = (unsigned int)(value / 256l);
  } else if (value / 1024l < 256l) {
    TCCR2B &= B11111000;
    TCCR2B |= B00000111;
    OCR2A = (unsigned int)(value / 1024l);
  }
}

