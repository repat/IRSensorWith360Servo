//! "how near" you come to the sensor, see documentation
const int PROXIMITY = 50;
//! integer for turning left, see documentation
const int LEFT = 1000;
//! integer for turning right, see documentation
const int RIGHT = 2000;
//! delay between sensor to notice, also for debugging
const int SHORTDELAY = 100;
//! spining time in miliseconds
const int SPINTIME = 4000;
//! time for servo to stop in miliseconds
const int STOPTIME = 1500;
//! arduino pin the IR sensor is connected to
const int SENSORPIN = 0;
//! arduino pin the servo is connected to
const int SERVOPIN = 9;
//! waits for servo to reach position
const int SERVODELAY = 15;

// declarations
//! spins the servo
void spinLeft(int spinDirection);
