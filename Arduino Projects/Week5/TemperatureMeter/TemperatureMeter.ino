// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 5
// Exercise 2
// Submission code: 23761449

// Define pins for all LEDs
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6

// Define temperature ranges in degrees Celsius
#define TEMP_RANGE0 0
#define TEMP_RANGE1 10
#define TEMP_RANGE2 20
#define TEMP_RANGE3 30
#define TEMP_RANGE4 40

// https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
int ThermistorPin = 0; // Thermistor pin is set at 0
int Vo; // declared for analogue voltage of the the thermistor
float R1 = 10000; // 10K Ohms used as the fixed resistor
float logR2, R2, temp; // R2: resistance fo the thermistor, logR2: calculated value for equation, temp: temperature 
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; // constants for the coefficients in Steinhart-Hart equation (used to calc temp from R2)

void setup() {
  // Configures the pins connected to LEDs as output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  Serial.begin(9600); // Initialise serial communication (for testing)
}

void loop() {
  Vo = analogRead(ThermistorPin); // voltage reading from 0-1023 (representing 0-5v)
  R2 = R1 * (1023.0 / (float)Vo - 1.0); // Calculating resistance of thermistor from R1 and analog read using Voltage divider rule
  logR2 = log(R2); // calc log of R2 to be used in the equation below
  temp = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // Calculates temp in Kelvins using Steinhart-Hart equation
  temp = temp - 273.15; // Convert Kelvin to Celsius

  // First, turn off all LEDs
  for (int i = LED1; i <= LED5; i++) {
    digitalWrite(i, LOW);
  }

  // If loops to turn on the right set of LEDs depending on the range of temperature
  if (temp < TEMP_RANGE0) { // Temperature less than 0
    // No LEDs
  } else if (temp < TEMP_RANGE1) { // Temperature less than 10
    digitalWrite(LED5, HIGH); // 1 LED
  } else if (temp < TEMP_RANGE2) { // Temperature less than 20
    digitalWrite(LED5, HIGH); // 2 LEDs from the left are on
    digitalWrite(LED4, HIGH);
  } else if (temp < TEMP_RANGE3) { // Temperature less than 30
    digitalWrite(LED5, HIGH); // 3 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
  } else if (temp < TEMP_RANGE4) { // Temperature less than 40
    digitalWrite(LED5, HIGH); // 4 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
  } else { // Temperature greater than or equal to 40
    digitalWrite(LED5, HIGH); // 5 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
  }

  Serial.print("Temperature: "); 
  Serial.print(temp);
  Serial.println(" C"); // Display temperature in Celsius

  delay(1000);
}
