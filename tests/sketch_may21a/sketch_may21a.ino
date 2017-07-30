int relay_pin = 9;
int biomoetal1_pin = 2;
int biomoetal2_pin = 3;
int biomoetal3_pin = 4;
int biomoetal4_pin = 5;

int on = 0;
int off = 255;

int on_time = 150;
int span = 667 - on_time; //100BPM

void setup () {
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
  pinMode(biomoetal1_pin, OUTPUT);
  pinMode(biomoetal2_pin, OUTPUT);
  pinMode(biomoetal3_pin, OUTPUT);
  pinMode(biomoetal4_pin, OUTPUT);

  analogWrite(biomoetal1_pin, off);  
  analogWrite(biomoetal2_pin, off);  
  analogWrite(biomoetal3_pin, off);  
  analogWrite(biomoetal4_pin, off);  
  delay(50);
  analogWrite(relay_pin,255);
  delay(100);
}

void loop () {
  analogWrite(biomoetal1_pin, on);
  delay(on_time);
  analogWrite(biomoetal1_pin, off);
  delay(span);

  analogWrite(biomoetal2_pin, on);
  delay(on_time);
  analogWrite(biomoetal2_pin, off);
  delay(span);

  analogWrite(biomoetal3_pin, on);
  delay(on_time);
  analogWrite(biomoetal3_pin, off);
  delay(span);

  analogWrite(biomoetal4_pin, on);
  delay(on_time);
  analogWrite(biomoetal4_pin, off);
  delay(span);

//  delay(2000);
}

