// trigger action
const int buttonPin = 2;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Inputモードでプルアップ抵抗を有効に

  Serial.begin(9600);
  delay(50);

  analogWrite(9,255);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if(buttonState ==LOW){
    action(10, 15);
    delay(1500);
  }
}

void action(int ontime, int span){
    int i = 0;
    int ON = 0; //pnpの時はON=0, OFF=255;
    int OFF = 255;
    
    while(1){

    if (i == 0){
        analogWrite(9, ON);
        Serial.println("9 on");
    }
    if (i == ontime){
        analogWrite(9, OFF);
        Serial.println("9 off");
    }
    if (i == span){
        analogWrite(10, ON);
        Serial.println("10 on");
    }
    if (i == span + ontime){
        analogWrite(10, OFF);
        Serial.println("10 off");
    }
    if (i == span * 2){
        analogWrite(11, ON);
        Serial.println("11 on");
    }
    if (i == span * 2 + ontime){
        analogWrite(11, OFF);
        Serial.println("11 off");
        break;
    }
    delay(10);
    i++;
    }
}

