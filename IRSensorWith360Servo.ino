/**
 * \brief  IR Sensor controlling a servo
 *
 * \author  original by BARRAGAN <http://barraganstudio.com>, edited by repat<repat[at]repat.de
 * \date    June 2013
 * \version 1.1
 *
*/
#include <Servo.h> 
#include "IRSensorWith360Servo.h"
// have to look this up sometime
//#define CHANGESTATE()  (STATE ? STATE=LOW : STATE = HIGH; })

//! Servo object
Servo servo;
//! init STATE at LOW
boolean STATE = LOW;

void setup() { 
  // attach servo at pin SERVOPIN
  servo.attach(SERVOPIN);
  // debug messages at 9600 baud
  Serial.begin(9600);
} 

void loop() { 
  // read IR sensor and print it
  int sensorValue=analogRead(SENSORPIN);
  Serial.println(sensorValue);
  
  delay(SHORTDELAY);

  // if near and in state LOW
  if (sensorValue > PROXIMITY && STATE==LOW) { 
    
      spin(LEFT);
      
      // change state
      STATE = HIGH; 
      
      // if further away and in state HIGH
  } else if (sensorValue <= PROXIMITY && STATE == HIGH) {
    
      spin(RIGHT);
      
      // change state
      STATE = LOW;
  }
}

void spin(int spinDirection) {
  servo.write(spinDirection);
  delay(SERVODELAY);          

  delay(SPINTIME);
  servo.writeMicroseconds(STOPTIME);
  delay(SERVODELAY + SHORTDELAY);  
}
