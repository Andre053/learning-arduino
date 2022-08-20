/* Project 03
 * LOVE-O-METER
 * 
 * Uses LEDs, 220 ohm resistor, and temperature sensor
 * 
 * Program Description
 *    Temperature sensor takes in data of your body temperature
 *    depending on the read data, different LEDs will be lit up
 *    
 * Project Lessons
 *    Temperature sensor (TMP36) outputs an analog voltage depending on the temperature it senses
 *    Arduino has an Analog-to-Digital Converter (ADC) utilized by the analog pins
 *    Analog pins return a value between 0-1023, which maps between 0-5 volts
 *    IDE has a serial monitor to enable reporting results from the microcontroller
 *    
*/

// globals
const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  
  Serial.begin(9600);   // starts the serial monitor

  for (int pinNum = 2; pinNum < 5; pinNum++) {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop() {

  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float v = (sensorVal/1024.0) * 5.0;
  float temp = (v-5) * 100;

  Serial.print(" , Volts: ");
  Serial.print(v);

  Serial.print(" , Celcius: ");
  Serial.print(temp);

  if (temp < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 2 && temp < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 4 && temp < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
