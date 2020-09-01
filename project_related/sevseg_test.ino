#include "SevSeg.h"
SevSeg sevseg; 

const int trigPin = 1;
const int echoPin = 0;
long duration;
int distance;
int switchState = 0;

void setup(){
  pinMode(A5,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  Serial.begin(9600);
  
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop(){
  switchState = digitalRead(A5);

  if (switchState == HIGH) {
    digitalWrite(trigPin, LOW);     // clear trigger
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);    // send wave
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);  
    distance =  duration *0.034/2;

//  Serial.println(duration);
//  Serial.println(distance);

    sevseg.setNumber(distance);
    delay(300);
  }
  
  sevseg.refreshDisplay(); 
}
