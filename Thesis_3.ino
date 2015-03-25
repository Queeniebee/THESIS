/*
Queeniebee

 */


int motor = 3;  // HeatingPad connected to PWM pin 9
int fadeValue = 255;
int index = 0;
long lastTime = 0;

void setup() {

  Serial.begin(9600);
  lastTime = millis();

}

void loop() {
  if (millis() - lastTime > 10000) {
    if (fadeValue > 100) {
      // sets the value (range from 0 to 255):
      fadeValue -= 15;
      analogWrite(motor, fadeValue);
      Serial.print("Down ");
      Serial.println(fadeValue);
      delay(3000);
      
    }

    // fade out from max to min in increments of 5 points:
    else {
      // sets the value (range from 0 to 255):
//      for (fadeValue; fadeValue >= 0; fadeValue -= 5) {
        fadeValue = 255;
        analogWrite(motor, fadeValue);
        Serial.print("Up ");
        Serial.println(fadeValue);

//      }
    }
  }

}
