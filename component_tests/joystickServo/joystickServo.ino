#include <Servo.h>

const int Spin = 6; //  switch input
const int Xpin = A0; //  X input
const int Ypin = A1; //  Y input
//const int Mpin = 3;  // servo motor output
Servo myservo;

void setup() {
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(Spin, INPUT_PULLUP);
//  pinMode(Mpin, OUTPUT);
  myservo.attach(3); 
  myservo.write(90);
  
  digitalWrite(Spin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int Xposition = 0;
  int Yposition = 0;
  int Sstate = 0;
  int Xmap = 0;
  int Ymap = 0;
  int currentServo = 90;

  Xposition = analogRead(Xpin);
  Yposition = analogRead(Ypin);
  Sstate = digitalRead(Spin);

  Xmap = map(Xposition,0,1022,0,180);
  Ymap = map(Yposition,0,1022,0,180);
  currentServo = myservo.read();
  
  Serial.println(currentServo);

  if(Xmap != 90){
    myservo.write(Xmap);
  }
  else{
    if(currentServo >= 88 ){
      myservo.write(currentServo-1);
    }
    if(currentServo <= 82){
      myservo.write(currentServo+1);
    }
  }
 
  delay(100);
}
