/* Project 04
 * COLOR MIXING LAMP
 * 
 * Uses Tri-color LED, 3 phototransistors, 2 resistors, gel
 * 
 * Program Description
 *    Utilizes Pulse Width Modulation (PWM) to fade LEDs
 *    
 * Program Lessons
 *    To generate the appearance of a fading light, use 
 *    PWN (Pulse Width Modulation)
 *    Percentage of time a pin is ON is called the 'duty cycle'
 *    Lower duty cycle gives a dimmer LED
 *    Pins with ~ are designated PWN pins
 *    Phototransistors generate current proportional to the
 *    quantity of light absorbed
 *    Allos you to measure change in current
 *    
 *    Pulse Width Modulation (PWM): Rapidly turns the pin from 
 *    high and low such that it is unrecognizable to the human eye
*/

// globals
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

void setup() {
  
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {

  redSensorVal = analogRead(redSensorPin);
  delay(5);
  greenSensorVal = analogRead(greenSensorPin);
  delay(5);
  blueSensorVal = analogRead(blueSensorPin);
  delay(5);

  Serial.print("\nRaw Sensor Values \t red: ");
  Serial.print(redSensorVal);
  Serial.print("\t green: ");
  Serial.print(greenSensorVal);
  Serial.print("\t blue: ");
  Serial.print(blueSensorVal);

  redValue = redSensorVal / 4;
  greenValue = greenSensorVal / 4;
  blueValue = blueSensorVal / 4;

  Serial.print("\nMapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);
  Serial.print("\n");
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  
}
