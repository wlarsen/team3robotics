#include <Wire.h>

int PinPWM_motor1 = 11; //ch 2 left back
int PinPWM_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 9; //ch 3 left front

int PinMove_motor1 = 12; //ch 2 left back 
int PinMove_motor2 = 4; //ch 4 right back
int PinMove_motor3 = 7; //ch 1 right front
int PinMove_motor4 = 8; //ch 3 left front

//motor1 & motor4 = left
//motor2 & motor3 = right

void setup()
{ 
  Serial.begin(9600);
  //Wire.onReceive(func); //func to be called when slave receives data
  //Wire.begin(2); //slave join i2c bus with address #2
  pinMode(PinPWM_motor1, OUTPUT); //initialize motor PWM
  pinMode(PinPWM_motor2, OUTPUT);
  pinMode(PinPWM_motor3, OUTPUT);
  pinMode(PinPWM_motor4, OUTPUT);
  pinMode(PinMove_motor1, OUTPUT); //initialize motor DIR  
  pinMode(PinMove_motor2, OUTPUT);
  pinMode(PinMove_motor3, OUTPUT);
  pinMode(PinMove_motor4, OUTPUT);
}

void loop()
{
  
  //halt();
  forward();
  halt();
  //reverse();
  //halt();
  //turnAround();
  //halt();
}

void forward()
{
  //to move forward
  analogWrite(PinPWM_motor1, 100); //Mega:100/ Uno:50/100 (for wood floor at home/for track at school)
  analogWrite(PinPWM_motor2, 150); //Mega:50/ Uno:125/175
  analogWrite(PinPWM_motor3, 150); //Mega:50/ Uno:125/175
  analogWrite(PinPWM_motor4, 100); //Mega:100/ Uno:50/100
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  //delay(1450); //time it takes for robot to move 16" forward
  delay(100); //650 = 16" forward 650*2 = 1300
}

void reverse()
{
  //to backup
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 150);
  analogWrite(PinPWM_motor3, 150);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
}

void rightTurn()
{
  //turn 90 degrees right
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 150);
  analogWrite(PinPWM_motor3, 150);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1125);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
}

void leftTurn()
{
  //turn 90 degrees left
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 150);
  analogWrite(PinPWM_motor3, 150);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(1150);
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
}

void turnAround()
{
  //turn 180 degrees left
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 150);
  analogWrite(PinPWM_motor3, 150);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(1800); //time it takes to turn 180 degrees
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1000);
}

void halt()
{
  //to stop
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(2000);
}
