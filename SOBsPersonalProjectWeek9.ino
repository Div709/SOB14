// UltraSound Week 9
#include <Servo.h>
int inputPin = 4 ;
int outputPin = 5;
int buzzer = 2;
Servo myServo;
int angle;
int red = 11;
int green = 12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  myServo.attach(10);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outputPin,LOW); //Emitter
  delayMicroseconds(2);
  digitalWrite(outputPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(outputPin,LOW);

  int distance = pulseIn(inputPin,HIGH); // reads receiver pulse time
  distance = distance/58;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
   if (distance<10 && distance>0){
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }
  else if(distance>10 && distance<60) {
    digitalWrite(buzzer,LOW);
      angle = map(distance,10,60,0,180);
      myServo.write(angle);
      digitalWrite(green,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
    myServo.write(0);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
  }
 
}

  


