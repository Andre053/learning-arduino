/* Project 05
 * MOOD CUE
 * 
 * Uses a potentiometer, servo motor with motor arm, and capacitors
 * 
 * Program Description
 *    Use the servo motor as a gauge to point out your mood
 *    
 * Program Lessons
 *    Servo motors do not spin in a circle, but move to a specific position
 *    Servo motors expect a number of pules to tell them the angle to move
 *    The library 'Servo.h' is used to control servo motors 
 *    Pulses come at the same intervals, width varies from 1-2 secs
 *    Potentiometer allows controlling of voltage
 *    When servo starts to move, it draws more current than if it were in motion
 *    To smooth out the voltage we use capacitors
 *    Decouling capacitors reduce changes caused by the rest of the circuit
 *    Map function maps values of a given range to be within a different range
*/

#include <Servo.h> // library for servo motor

//globals
Servo myServo; // servo object

int const potAnalogIn = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9); // PWN pin 9 gives servo data
  Serial.begin(9600);
}

void loop() {

  potVal = analogRead(potAnalogIn); // value on the potentiometer, must be converted into an angle value
  Serial.print("Potentiometer Value: ");
  Serial.print(potVal);

  // 0-1023 maps to 0-179 as 180 is max
  // 1024 values can be read from the analog input, sent from the potentiometer
  // the servo motor can turn 180 degrees
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("| Angle Value: ");
  Serial.print(angle);
  Serial.print("\n");

  myServo.write(angle); // tells the servo motor to move to the new angle
  delay(15);
}
