/* Project 07
 * KEYBOARD INSTRUMENT
 * 
 * Uses a switch, piezo, and 10 kilohm, 1 megohm, and 220 ohm resistors
 * 
 * Program Description
 *    Use resistors and some buttons to build a small musical keyboard
 *    
 * Program Lessons
 *    Resistor ladder: A way to read a number of switches using the analog input
 *    When each button is pressed, a different voltage level will be passed to the input pin
 *    If two buttons are pressed at the same time, a unique input is given
 *    
 * What Next?
 *    tone() can only create square waves, no sine waves or triangles
 *    Only a single tone can play at a time
 *    
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
