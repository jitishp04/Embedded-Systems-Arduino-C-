// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 5
// Exercise 3
// Submission code: 23761449


// https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
int ThermistorPin = 0; // Thermistor pin is set at 0
int Vo; // declared for analogue voltage of the the thermistor
float R1 = 10000; // 10K Ohms used as the fixed resistor
float logR2, R2, temp; // R2: resistance fo the thermistor, logR2: calculated value for equation, temp: temperature 
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; // constants for the coefficients in Steinhart-Hart equation (used to calc temp from R2)


// const int temperaturePin = A0; // Analog pin for temperature sensor
const int lightPin = A1;
const int greenLedPin = 10;
const int redLedPin = 7;
const int blueLedPin =13;
//temperature thresholds as per the requirement WP3
const int temperatureThresholds[4] = {-12, 0, 20, 21};
//light intensity thresholds as per the requirement WP3
const int lightThresholds[4] = {0, 20, 60, 100};
void setup() {
  //Configures the pins connected to LEDs as output pins.
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  Vo = analogRead(ThermistorPin); // voltage reading from 0-1023 (representing 0-5v)
  R2 = R1 * (1023.0 / (float)Vo - 1.0); // Calculating resistance of thermistor from R1 and analog read using Voltage divider rule
  logR2 = log(R2); // calc log of R2 to be used in the equation below
  temp = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // Calculates temp in Kelvins using Steinhart-Hart equation
  temp = temp - 273.15; // Convert Kelvin to Celsius

  //variable to store the light intensity
  int lightIntensity = readLightIntensity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C, Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");
  //variable to store the threshold index of temperature
  int tempIndex = getThresholdIndex(temperature,
temperatureThresholds, 4);
  //variable to store the threshold index of light intensity
  int lightIndex = getThresholdIndex(lightIntensity,
lightThresholds, 4);
  Serial.print("Temperature Index: ");
  Serial.print(tempIndex);
// Analog pin for light sensor
// Pin for green LED
// Pin for red LED
// Pin for blue LED
   Serial.print(", Light Index: ");
  Serial.println(lightIndex);
  //if light and threshold have the same intensity.
  // This indicates normal dependencies. So, the green light is set
//to high.
  if (tempIndex == lightIndex) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  //temperature index is lower than the light index
  // This indicates the temperature is lower. So, the blue light is
// set to high.
  } else if (tempIndex < lightIndex) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
  } else {
   //temperature index is greater than the light index
   // This indicates the temperature is higher. So, the RED light is
//set to high
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
}
  delay(1000); // Periodicity in seconds
}

int readLightIntensity() {
  // Read analog value from light sensor
  int sensorValue = analogRead(lightPin);
  // Map the analog value to a percentage representing light
// intensity

// The map() function scales the sensor value from the range [0,
//1023] to [0, 100]
  // This ensures that the light intensity percentage is within a
//manageable range
  return map(sensorValue, 0, 1023, 0, 100);
}
int getThresholdIndex(int value, const int thresholds[], int size) {
  // Iterate through the thresholds array
  for (int i = 0; i < size; i++) {
    // Check if the given value is less than the current threshold
    // If true, return the index of the current threshold
    if (value < thresholds[i]) {
return i; }
  }
  // If the value is greater than or equal to all thresholds,
  // return the index of the last threshold
  return size - 1;
}