/* Project 02
 * SPACESHIP INTERFACE
 * 
 * Components
 *    Uses a switch, LEDs, and resistors
 * 
 * Program Description
 *    Alternates LED colors when the switch is held down
 *    
 * Project Lessons
 *    Pins only read HIGH or LOW, it is called digital/bianary input
 *    digitalWrite() turns an output pin to HIGH, effectively turning it on
 *    Every sketch has two main functions, setup() is ran once, loop() runs continuously
 *    digitalRead() gets the state of an input pin
 *    delay() pauses execution for a number of milliseconds
 *    LEDs have a cathode, short and connects to ground, and an anode, long and connects to power
 * 
*/

int switchState = 0;

void setup() {
  
  pinMode(3, OUTPUT); // LEDs
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(2, INPUT);  // button pressed

}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
 
  } else {
    digitalWrite(3, LOW):
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
   
  }
   
}
