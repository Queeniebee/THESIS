/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int adjust = Serial.parseInt();
    if (adjust >= 0 && adjust <= 255)
    {
      analogWrite(motorPin, adjust);
    }
  }
} 
