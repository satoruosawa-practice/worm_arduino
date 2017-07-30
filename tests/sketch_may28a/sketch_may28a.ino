int relay_pin = 9;
int biomoetal4_pin = 5;

int on = 0;
int keep = 240;
int off = 255;

int on_time = 30;
int keep_time = 1000;
int span = 2000;

void setup () {
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
  pinMode(biomoetal4_pin, OUTPUT);

  analogWrite(biomoetal4_pin, off);  
  delay(50);
  analogWrite(relay_pin,255);
  delay(100);
}

void loop () {
  analogWrite(biomoetal4_pin, on);
  delay(on_time);
  analogWrite(biomoetal4_pin, keep);
  delay(keep_time);
  analogWrite(biomoetal4_pin, off);
  delay(span);
}

