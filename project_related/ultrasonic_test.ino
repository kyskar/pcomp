const int trigPin = 9;
const int echoPin = 10;
//const int greenPin = 3;
//const int yellowPin = 5;
//const int redPin = 6;
int limit1 = 12;
int limit2 = 5;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(greenPin, OUTPUT);
//  pinMode(yellowPin, OUTPUT);
//  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);     // clear trigger
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);    // send wave
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  
  distance =  duration *0.034/2;

//  Serial.println(duration);
  Serial.println(distance);

//  digitalWrite(redPin, LOW);
//  digitalWrite(yellowPin, LOW);
//  digitalWrite(greenPin, LOW);
//
//  if (distance <= limit1){
//    digitalWrite(redPin, LOW);
//    digitalWrite(greenPin, HIGH);
//    digitalWrite(yellowPin, HIGH);
//  }
//  if (distance >= limit1 and distance <= limit2) {
//    digitalWrite(yellowPin, LOW);
//    digitalWrite(greenPin, HIGH);
//    digitalWrite(redPin, HIGH);
//  }
//  if (distance >= limit2) {
//    digitalWrite(greenPin, LOW);
//    digitalWrite(yellowPin, HIGH);
//    digitalWrite(redPin, HIGH);
//  }
}
