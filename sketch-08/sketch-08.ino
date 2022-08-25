/* Project 08
 * DIGITAL HOURGLASS
 * 
 * Uses an LED, 10 kilohm resistors, 220 ohm resistors, and a tilt sensor
 * 
 * Program Description
 *    Create a digital hourglass which turns on an LED every 10 min
 *    Use a tilt switch to change the state of the hourglass
 *    
 * Program Lessons
 *    delay() stops Arduino execution, freezing the current state; use millis() to help solve the problem
 *    Tilt switch is an on/off sensor that detects orientation with a small cavity inside with a metal ball
 *    the ball connects two leads when it rolls to one side, closing the switch
 *    6 LEDs allows the hourglass to run for an hour (10 min each)
 *    
 * What Next?
 *     Accelerometers are another type of tilt sensor, but they give out much more information
*/

// globals
int keyVal;

// array of frequencies we want to play
// middle C, D, E, and F
int notes[] = {262, 294, 330, 349}; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  keyVal = analogRead(A0);
  Serial.println(keyVal);

  // utilizes the resistor ladder, each button having a different voltage 
  if (keyVal == 1023) tone(8, notes[0]);
  else if (keyVal >= 990 && keyVal <= 1010) tone(8, notes[1]);
  else if (keyVal >= 505 && keyVal <= 515) tone(8, notes[2]);
  else if (keyVal >= 5 && keyVal <= 10) tone(8, notes[3]);
  else noTone(8); // stops playing sound
}
