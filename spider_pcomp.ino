//code for spider
#define trigPin 9
#define echoPin 8

//legs
#include <Servo.h> 
Servo myservo;  
int pos = 0;    

//eyes
int ledPin = 13;
int ledPin2 = 12;

void setup() 
{ 
  myservo.attach(10);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
} 
 
 
void loop() 
{     
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(1); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance); 
  
  if(distance < 30){
    for(pos = 0; pos < 90; pos += 1) 
    {                                  
      myservo.write(pos);   
      delay(5);                      
    } 
    for(pos = 90; pos>=1; pos-=1)    
    {                                
      myservo.write(pos);            
      delay(5);                     
    } 
    digitalWrite(ledPin, HIGH);  
    digitalWrite(ledPin2, HIGH);  
  } 
    
    else {
      for(pos = 0; pos < 90; pos += 1) 
      {
        myservo.write(pos);   
        delay(20);                      
      } 
      for(pos = 90; pos>=1; pos-=1)    
      {                                
        myservo.write(pos);            
        delay(20);  
      } 
      digitalWrite(ledPin, HIGH); 
      delay(10); 
      digitalWrite(ledPin, LOW);  
      digitalWrite(ledPin2, HIGH);  
      delay(10); 
      digitalWrite(ledPin2, LOW);  
      
    }
}

