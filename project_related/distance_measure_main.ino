#include "SevSeg.h"
SevSeg sevseg; 

const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;

const int analogInPin = A1;
int sensorValue = 0;
int state = 4;
 
void setup(){
  pinMode(A5,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  Serial.begin(9600);
  
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {1, 2, 3, 5, 6, 0, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop(){
  readSwitch();

  if (state == 0) {
    digitalWrite(trigPin, LOW);     // clear trigger
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);    // send wave
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);  
    distance =  duration *0.034/2;

    sevseg.setNumber(distance);
    state = 4;                      // STOPS CONSTANT READSWITCH ISSUE
    delay(40);
  }

//  if (state == 1) {
//    
//  }
  
  sevseg.refreshDisplay(); 
}

void readSwitch () {                                  
  sensorValue = analogRead(analogInPin);              

  if (sensorValue < 800 && sensorValue > 750) {       
    state = 0;
    delay(100);                                       
  }
  if (sensorValue < 749 && sensorValue > 650) {       
    state = 1;
    delay(100);                                       
  }
  if (sensorValue < 649 && sensorValue > 425) {       
    state = 2;
    delay(100);                                       
  }
  if (sensorValue < 425 && sensorValue >= 0) {        
    state = 3;
    delay(100);                                       
  }
  delay(1);                                        
}
