//Moisture Sensor Variables
const int sensor_pin = A1; 
float moisture_percentage;
int sensor_analog;

//Servo Code
#include <Servo.h> 
Servo myservo;


void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
  myservo.attach(9);
  myservo.write(90);  // set servo to mid-point
  
 }
void loop(){
  int IR = digitalRead(2);
  Serial.println(IR);
  delay(2000);
   if(IR==0)
  {

  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100-( (sensor_analog/1023.00) * 100 ) );
  //Serial.println(sensor_analog);
  Serial.println(moisture_percentage);
  servo();
  
  }
  else
  {
    myservo.write(90);
    //myservo.detach();
  }
}


void servo()
{
if(moisture_percentage<=33)
  {
   myservo.write(25);
   delay(5000);
   myservo.write(90);
   delay(100);
   //myservo.detach();
   }
  else
   {
    myservo.write(135);
    delay(5000);
    myservo.write(90);
    delay(100);
   //myservo.detach();
    }
}
