/* Project 06
 * LIGHT THEREMIN
 * 
 * Uses a Piezo, photransistors, and 10 kilohm resistors
 * 
 * Program Description
 *    Uses a phototransistor and a piezo to create a light based theramin
 *    A theramin is an instument which makes sounds based on the movements of hands
 *    This theramin will make sound based on the light absorbed by the phototransistor
 *    
 * Program Lessons
 *    Use the tone() function to enulate the sounds of a theramin
 *    tone() has a 50% duty cycle at all times (half on, half off), analogWrite() changes depending on the voltage
 *    A piezo vibrates when it receives electricity, upon movement it displaces air around it creating sound waves
 *    millis() gives the amount of miliseconds since the Arduino was powered on
 *    
 * What Next?
 *    Try out using different output frequency values
 *    
*/

// globals
int pitch;
int sensorVal;

// these are used to find the max and min values in setup()
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn on ledPin to test the sensor

  // calibrate the sensors max and min values, running the loop for 5 seconds
  while (millis() < 5000) {
    sensorVal = analogRead(A0);
    if (sensorVal > sensorHigh) 
      sensorHigh = sensorVal;
    if (sensorVal < sensorLow) 
      sensorLow = sensorVal;
  }
  digitalWrite(ledPin, LOW); // finished testing sensor, turn pin off
  
  Serial.begin(9600);
}

void loop() {
  
  sensorVal = analogRead(A0); // read sensor value 

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print("\n");

  // value of pitch is mapped from sensorVal
  // sensorLow to sensorHigh are bounds for incoming values
  // 50 to 4000 are suggested starting values for output
  pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000); 

  // tone takes 3 args: pin to play sound on, frequency to play, how long to play the note
  tone(8, pitch, 20);
  
  delay(10);
}
