// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 2
// Submission code: 2345166
const int temperaturePin = A0; // Analog pin for temperature sensor
const int lightPin = A1;       // Analog pin for light sensor
const int greenLedPin = 7;     // Pin for green LED
const int redLedPin = 8;       // Pin for red LED
const int blueLedPin = 9;      // Pin for blue LED
//temprature thresholds as per the requirement WP3
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
  //variables to store the temperature
  int temperature = readTemperature();
  //variable to store the light intensity
  int lightIntensity = readLightIntensity();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C, Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");
  //varibale to store the threshold index of temprature
  int tempIndex = getThresholdIndex(temperature, temperatureThresholds, 4);
  //varibale to store the threshold index of light intensity
  int lightIndex = getThresholdIndex(lightIntensity, lightThresholds, 4);
  
  Serial.print("Temperature Index: ");
  Serial.print(tempIndex);
  Serial.print(", Light Index: ");
  Serial.println(lightIndex);
  //if light and threshold have same intensity. 
  // This indicates normal dependencies. So, the green light is set to high.
  if (tempIndex == lightIndex) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  //temperature index is lower than the light index 
  // This indicates the temperature is lower. So, the blue light is set to high.
  } else if (tempIndex < lightIndex) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
  } else {
   //temperature index is greater than the light index 
   // This indicates the temperature is higher. So, the RED light is set to high
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
  }
  
  delay(1000); // Periodicity in seconds
}

int readTemperature() {
  // Read analog voltage from temperature sensor
  int sensorValue = analogRead(temperaturePin);
  // Convert analog voltage to voltage (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  // Convert voltage to Celsius temperature
  float temperatureC = (voltage - 0.5) * 100;
  // Convert temperature to integer and return
  return (int)temperatureC;
}

int readLightIntensity() {
  // Read analog value from light sensor
  int sensorValue = analogRead(lightPin);
  // Map the analog value to a percentage representing light intensity
  // The map() function scales the sensor value from the range [0, 1023] to [0, 100]
  // This ensures that the light intensity percentage is within a manageable range
  return map(sensorValue, 0, 1023, 0, 100);
}

int getThresholdIndex(int value, const int thresholds[], int size) {
  // Iterate through the thresholds array
  for (int i = 0; i < size; i++) {
    // Check if the given value is less than the current threshold
    // If true, return the index of the current threshold
    if (value < thresholds[i]) {
      return i;
    }
  }
  // If the value is greater than or equal to all thresholds,
  // return the index of the last threshold
  return size - 1;
}
