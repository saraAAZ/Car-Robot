//sensor pins
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

//define Variables
long duration;
int distance1; 


int distance = 100;

char getstr;
const int LeftMotorForward = 5;
const int LeftMotorBackward = 6;
const int RightMotorForward = 9;
const int RightMotorBackward = 7;
const int speedA = 4;
const int speedB = 10;
int speed = 250;


void forward()
{
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println(" forward");
}

void back()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  Serial.println(" back");
}

void left()
{
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  Serial.println("left");
}

void right()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println(" right");
}

void stop()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  Serial.println("Stop!");
}

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  distance = read();

}

void loop()
{

  int distanceRight = 0;
  int distanceLeft = 0;
    if (distance <= 20){
      stop();
      
   
    }
     else
  if (Serial1.available()) {
    getstr = ((char)Serial1.read());
    Serial.println(getstr);
   
   
 
    if (getstr == 'F')
    {
      forward();
    }
    else if (getstr == 'B')
    {
      back();
    }
    else if (getstr == 'R')
    {
      right();

    }
    else if (getstr == 'L') 
    {
      left();
    }
   
    else if (getstr == '1' )
    {
      speed = 100;


    }
    else if (getstr == '2' )
    {
      speed = 120;


    }
       else if (getstr == '3' )
    {
      speed = 140;


    }
        else if (getstr == '4' )
    {
      speed = 160;


    }
        else if (getstr == '5' )
    {
      speed = 180;


    }
        else if (getstr == '6' )
    {
      speed = 200;


    }
       else if (getstr == '7' )
    {
      speed = 220;


    }   else if (getstr == '8' )
    {
      speed = 240;


    }
     else if (getstr == '9' )
    {
      speed = 250;


    }
  }

  distance = read();
  analogWrite(speedA, speed);
  analogWrite(speedB, speed);
}

int read() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance1 = duration * 0.034 / 2;
  return distance1;

}
