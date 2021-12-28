#include <Servo.h>                   // servo motor library
#define echoPin 6                    // hcsr-04 echo is pin 6
#define trigPin 7                    // trig is pin 7
#define buzzerPin 8                  // buzzer is pin 8

int maximumRange = 50; 
int minimumRange = 0;
Servo sg90;                          //servo motor name is sg90

int acidegeri=0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  sg90.attach(10);
  sg90.write(0);

}

void loop() {
  
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum*10);                                     // melodi is buzzer function
  motor(olcum);                                         // motor is servo motor function
  
  
  
  

}

int mesafe(int maxrange, int minrange)
{
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(1000);

  if(distance >= maxrange || distance <= minrange)
  return 0;
  return distance;
}

int melodi(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
  
}
int motor(int dis){


  if(minimumRange<dis && dis<maximumRange) {
    sg90.write(150);
    delay(5000);
   sg90.write(0);
  }
  
}
