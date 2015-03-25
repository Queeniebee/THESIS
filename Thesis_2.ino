// by Queeniebee

#include <Wire.h>

#define NUM_RECEIVERS 3
byte x = 0;
byte y = 0;
byte z = 0;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4 Leonardo

  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
 if(Wire.endTransmission() > 0){
    Serial.println("Nope");
  }
  Wire.beginTransmission(5); // transmit to device #5 Leonardo
  Wire.write("y is ");        // sends five bytes
  Wire.write(y);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  if(Wire.endTransmission() > 0){
    Serial.println("Nope");
  }

  Wire.beginTransmission(6); // transmit to device #6 Uno
  Wire.write("z is ");        // sends five bytes
  Wire.write(z);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(100);

  y++;
  delay(100);

  z++;
  delay(300);
}


/*
#include <Wire.h>

#define PAYLOAD_SIZE 2 // how many bytes to expect from each I2C salve node
#define NODE_MAX 6 // maximum number of slave nodes (I2C addresses) to probe
#define START_NODE 2 // The starting I2C address of slave nodes
#define NODE_READ_DELAY 1000 // Some delay between I2C node reads

int nodePayload[PAYLOAD_SIZE];

void setup()
{
  Serial.begin(9600);
  Serial.println("MASTER READER NODE");
  Serial.print("Maximum Slave Nodes: ");
  Serial.println(NODE_MAX);
  Serial.print("Payload size: ");
  Serial.println(PAYLOAD_SIZE);
  Serial.println("***********************");

  Wire.begin();        // Activate I2C link
}

void loop()
{
  for (int nodeAddress = START_NODE; nodeAddress <= NODE_MAX; nodeAddress++) { // we are starting from Node address 2
    Wire.requestFrom(nodeAddress, PAYLOAD_SIZE);    // request data from node#
    if(Wire.available() == PAYLOAD_SIZE) {  // if data size is avaliable from nodes
      for (int i = 0; i < PAYLOAD_SIZE; i++) nodePayload[i] = Wire.read();  // get nodes data
      for (int j = 0; j < PAYLOAD_SIZE; j++) Serial.println(nodePayload[j]);   // print nodes data
      Serial.println("*************************");
      }
    }
    delay(NODE_READ_DELAY);
}
*/
