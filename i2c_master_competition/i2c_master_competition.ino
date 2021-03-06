#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;
int ledPin = 42;  //square 
int led2Pin = 43; //triangle 
int led3Pin = 41; //circle 

int fire, tool, align = 0;
int i = 0;

int tooClose = 10; 
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x; //commands for driver slave
int y; //commands for arm slave
int wave = 30;
int rowCount = 0;
int waveCount = 0;
int delayw = 0; 
int delayf = 0;

int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16 = 0;
int sum;
int count;
int total = 0;
int ledPin4 = 36; // LED connected to digital pin 13
int ledPin3 = 34; // LED connected to digital pin 13
int ledPin2 = 32; // LED connected to digital pin 13
int ledPin1 = 30; // LED connected to digital pin 13

//halt x = 0
//foward x = 1
//reverse x = 2
//leftTurn x = 3
//rightTurn x = 4
//turnAround x = 5
//arm startingPosition y = 6
//arm grabTool y = 7
//arm scanTool y = 8
//raise are for oil rig scan y = 9
//insert tool into rig = 10


void setup()
{
   Wire.begin(); //join bus as master
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
   pinMode(led2Pin, OUTPUT);
   pinMode(led3Pin, OUTPUT);
   pinMode(ledPin1, OUTPUT); // sets the digital pin as output
   pinMode(ledPin2, OUTPUT); // sets the digital pin as output
   pinMode(ledPin3, OUTPUT); // sets the digital pin as output 
   pinMode(ledPin4, OUTPUT); // sets the digital pin as output
}

void loop()
{
  //oil rig detection code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  delay(3000);
  //raise arm to scanning position
  y = 6;
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
   delay(8000);
  //raise arm to scanning position
  y = 9;
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
  y = 9;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  delay(2500); //delay cannot be below 2500 or shit blows up
  
  //get to first rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(400); //950 is one full wave, needs to be just short of that to be centered with first rig 600 is a bit much
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); //is 2 seconds long enough to scan rig efficiently?
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT > 220)
  {
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    fire = 1;
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  delay(2000);
  
  //get to second rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1500); //need to move about 2 waves from last position to scan first rig 1800 (add 200 because first one was shortened by 200) = 1700
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); 
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT >= 220)
  {
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    fire = 2;
  }
  else
  {
    digitalWrite(led3Pin, LOW);
  }
  
  delay(2000);
  
  //get to third rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1600); //need to move about 2 waves from last position to scan second rig 1700
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); 
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT > 220)
  {
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    fire = 3;
  }
  else
  {
    digitalWrite(led2Pin, LOW);
  }
  

//tool detection code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
delay(1000); // <=========THIS DELAY IS VERY VITAL!!!!!!!! 
//back to starting position
y = 6;
Wire.beginTransmission(4);
Wire.write(y);
Wire.endTransmission();
delay(5000);

x = 2; //reverse away from tools to be able to realign
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(800); 
  
//turn left
x = 3;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(268); //250 is not enough 275 is too much

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);
  
//move forward slightly 
x = 1;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);
  
//turn right back toward tool
x = 4;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(75);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);

//move forward slightly 
x = 1;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(200);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);


//turn right
x = 4;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(75);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);
  
//move forward slightly
x = 1;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(400);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);
  
//turn right back toward tool
x = 4;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(75);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);

x = 1;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(460); //460

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(300);

x = 4;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(70);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);

x = 3;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(20);

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);

x = 1;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(60); //250

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);

/*x = 2;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(100); //300 is way too much 100 is a little too much 

x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(500);*/
/////////////////////////////////////////////////////

//get arm into scanning position
y = 8; 
Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();
y = 8;
Wire.beginTransmission(4);
Wire.write(y);
Wire.endTransmission();
delay(2000);

do
{ 
  //get arm into scanning position
  y = 8; 
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
  y = 8;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  delay(2000); 
  //scan tool  
  do
  {  
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val1 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val2 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val3 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val4 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val5 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); //sets the LED on 
    val6 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val7 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val8 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on//
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val9 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val10 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val11 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val12 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val13 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val14 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val15 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val16 = analogRead(0); // read analog input pin 0
    
    sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
    count = count + 1;
    total = total + sum;
  } while (count < 100);
  
  total = total/count;
  if (total > 56 && total < 99) // >57 && <70
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 45 && total < 57) // >46 && <57
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 20 && total < 46) // >30 && <46
  {
    //square
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    tool = 1;
  }
  else
  {
    //nothing
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  //back to starting position
  y = 6;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  delay(7000);
  
  if(tool != fire)
  {
    //turn right
    x = 4;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    //move forward slightly to next tool
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(350); //375
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    //turn left back toward tool
    x = 3;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(815); //800 was a little short
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
    
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(90); //100
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
    //i = i + 1;
  }
  else
  {
    delay(100);
  }
  
  i = i + 1;
  
} while (tool != fire || i <= 2); //2?
 
if (i == 2) //this is just in case shape sensor sees nothing
{
x = 2; //reverse slightly away from tool to have clearance to pick it up
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(10);
x = 0; 
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000);


y = 7; 
Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();
y = 7;
Wire.beginTransmission(4);
Wire.write(y);
Wire.endTransmission();
delay(5000); //5000
}
else
{
//pick up tool code/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
x = 2; //reverse slightly away from tool to have clearance to pick it up
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(20);
x = 0; 
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000);


y = 7; 
Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();
y = 7;
Wire.beginTransmission(4);
Wire.write(y);
Wire.endTransmission();
delay(5000); //5000
}

//back to starting position
/*y = 6; 
Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();
y = 6;
Wire.beginTransmission(4);
Wire.write(y);
Wire.endTransmission();
delay(5000);*/
if (i == 0)
{
  //correct to the right to get back to the center
  //right turn
  //forward
  //left turn
  //turn right
    x = 4;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(350); //375
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    x = 3;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(815); //800 was a little short
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
}
if (i == 2)
{
  //correct to the left to get back to the center
  //left turn
  //forward
  //right turn
  x = 3;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(815);
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(350); //375
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
  
    x = 4;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800); //800 was a little short
    
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(500);
}
else
{
  delay(100);
}
  
//reverse back to starting position for wave navigation///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
x = 2;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(3900); // = 780*5 (one wave * 5)  NEEDS TO BE MEASURED YET

//wave navigation code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
do
  {
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100); 
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100);
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(1000);
    
    if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
    {
      x = 0; //halt, the robot is too close to anything to move safely
    }
    else if (distanceL<wave && distanceF>wave) //wave is present
    {
      x = 1; //move forward 16"
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(950);
      waveCount = waveCount + 1;
      //digitalWrite(ledPin, HIGH);
      delayw = (880*waveCount); //-900 ?
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
    else if (distanceL>wave) //opening is present
    {
      
      x = 3; //turn left
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(730);  //750
      rowCount = rowCount + 1;
  
      distanceF = pingForward();
      Serial.println(distanceF);
  
      distanceF = pingForward();
      Serial.println(distanceF);
      do
      {
          distanceF = pingForward();
          Serial.println(distanceF);
  
          x = 1; //move forward 16"
          Serial.print("x transmitted = ");
          Serial.println(x);
          Wire.beginTransmission(2);
          Wire.write("x is ");
          Wire.write(x);
          Wire.endTransmission();
          delay(200); //900 is too far, 800 is too short
  
          distanceF = pingForward();
          Serial.println(distanceF);
      } while (distanceF > 22);
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
  
      x = 4; //turn right
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(680);
      
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(2000);
      
      x = 2; //reverse
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(delayw); //reverse back to starting position = delayw
      delayw = 0;    //reset delayw back to 900
      waveCount = 0;
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(3000);
    }
    else //fuck....
    {
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(30000);
    }
  
  } while (rowCount <= 3);

delay(2000);

//drive to rig code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(fire == 1)
{
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(400);
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1000);
}
else if(fire == 2)
{
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2100); //1700 + 400 = 2100
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1000);
}
else if(fire == 3)
{
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(3800); //1700 + 1700 + 400 = 3800
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1000);
}
else
{
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(3000);
}

//align with rig code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
do
  {
    
  //sensors = front ping sensor and right ping sensor
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  
  //this alignment is for oil rig
  //to align with tool, reserve all the < and >
  
  if(distanceF < 20 && distanceR < 20)
  {
    //robot is aligned so stop
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 1;
  }
  else if(distanceF > 20 && distanceR < 20)
  {
    delay(1000);
    //robot is too far to the left
    x = 4; //turn right
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(275);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 3; //turn back left
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 2;
  }
  else
  {
    delay(1000);
    //robot is too far to the right
    x = 3; //turn left
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(275);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 4; //turn back right
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 2;
  }
  
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  
  } while (align != 1);

//insert tool into rig code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 delay(1000);
 y = 6;
 Serial.print("y transmitted = ");
 Serial.println(y);
 Wire.beginTransmission(4);
 Wire.write("y is ");
 Wire.write(y);
 Wire.endTransmission();
 delay(4000);
 
 //reverse
 x = 2;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(200);
 x = 0;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(500);
 
 //drive forward
 x = 1;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(400);
 x = 0;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(500);
 
 //reverse to how close to you want to be to the waves
 x = 2;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(450);
 x = 0;
 Serial.print("x transmitted = ");
 Serial.println(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(500);
 
//navigate to have left ping sensor facing wave///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//use code in reverse order that was used to drive to the rig on fire
//robot will be facing oil rigs

//thus turn left
x = 3;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(800);
x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000);

//calculate delayf
if (fire == 1) //square
{
  delayf = 3800;
}
else if (fire == 2) //circle
{
  delayf = 2100;
}
else if (fire == 3) //triangle
{
  delayf = 400;
}
else //make it the same as the longest distance
{
  delayf = 3800;
}

//reverse to starting position
x = 2;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(delayf);
x = 0;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000);

//return to starting place of course wave navigation///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
do
  {
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100); 
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100);
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(1000);
    
    if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
    {
      x = 0; //halt, the robot is too close to anything to move safely
    }
    else if (distanceL<wave && distanceF>wave) //wave is present
    {
      x = 1; //move forward 16"
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(950);
      waveCount = waveCount + 1;
      //digitalWrite(ledPin, HIGH);
      delayw = (880*waveCount); //-900 ?
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
    else if (distanceL>wave) //opening is present
    {
      
      x = 3; //turn left
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(730);  //750
      rowCount = rowCount + 1;
  
      distanceF = pingForward();
      Serial.println(distanceF);
  
      distanceF = pingForward();
      Serial.println(distanceF);
      do
      {
          distanceF = pingForward();
          Serial.println(distanceF);
  
          x = 1; //move forward 16"
          Serial.print("x transmitted = ");
          Serial.println(x);
          Wire.beginTransmission(2);
          Wire.write("x is ");
          Wire.write(x);
          Wire.endTransmission();
          delay(200); //900 is too far, 800 is too short
  
          distanceF = pingForward();
          Serial.println(distanceF);
      } while (distanceF > 22);
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
  
      x = 4; //turn right
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(680);
      
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(2000);
      
      x = 2; //reverse
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(delayw); //reverse back to starting position = delayw
      delayw = 0;    //reset delayw back to 900
      waveCount = 0;
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(3000);
    }
    else //fuck....
    {
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(30000);
    }
  
  } while (rowCount <= 2); //third row is different coming back than it is going down

  distanceL= pingLeft();
  Serial.println(distanceL);
  distanceR = pingRight();
  Serial.println(distanceR);
  distanceF = pingForward();
  Serial.println(distanceF);
  delay(100); 
  distanceL= pingLeft();
  Serial.println(distanceL);
  distanceR = pingRight();
  Serial.println(distanceR);
  distanceF = pingForward();
  Serial.println(distanceF);
  delay(100);
  distanceL= pingLeft();
  Serial.println(distanceL);
  distanceR = pingRight();
  Serial.println(distanceR);
  distanceF = pingForward();
  Serial.println(distanceF);
  delay(1000);
  
  if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
    {
      x = 0; //halt, the robot is too close to anything to move safely
    }
    else if (distanceL<wave && distanceF>wave) //wave is present
    {
      x = 1; //move forward 16"
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(950);
      waveCount = waveCount + 1;
      //delayw = (880*waveCount); 
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
    
    else if (distanceL>wave) //opening is present
    {
      
      x = 3; //turn left
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(730);  //750
      
      x = 1; //move forward through opening, this will have to be timed since there is no backdrop to use as a guide for a ping sensor
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000); //NEEDS TO BE MEASURED
      
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
  
      x = 4; //turn right
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(680);
      
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(2000);
      
      waveCount = (6 - waveCount); 
      delayw = (880*waveCount);
      x = 1; //move forward to starting position
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(delayw); //reverse back to starting position = delayw
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(3000);
      
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(ledPin, LOW);
      delay(2000);
  
  }
}




int pingForward()
{
  // Send out ping signal from front sensor
  pinMode(pingFPin, OUTPUT);
  digitalWrite(pingFPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingFPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingFPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingFPin, INPUT);
  durationF = pulseIn(pingFPin, HIGH);
  forwardCm = durationF/58;
  //distanceFwd = int(durationF/29);
  return forwardCm;
}

int pingRight()
{
  // Send out ping signal from front sensor
  pinMode(pingRPin, OUTPUT);
  digitalWrite(pingRPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingRPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingRPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingRPin, INPUT);
  durationR = pulseIn(pingRPin, HIGH);
  rightCm = durationR/58;
  return rightCm;
}

int pingLeft()
{
  // Send out ping signal from front sensor
  pinMode(pingLPin, OUTPUT);
  digitalWrite(pingLPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingLPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingLPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingLPin, INPUT);
  durationL = pulseIn(pingLPin, HIGH);
  leftCm = durationL/58;
  return leftCm;
}

int pingTop()
{
  // Send out ping signal from front sensor
  pinMode(pingTPin, OUTPUT);
  digitalWrite(pingTPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingTPin, INPUT);
  durationT = pulseIn(pingTPin, HIGH);
  topCm = durationT/58;
  return topCm;
}
