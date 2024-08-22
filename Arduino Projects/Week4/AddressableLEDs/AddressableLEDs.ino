// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 4
// Exercise 3:ADDRESSABLE LEDS
// Submission code: 2351823

//include the NeoPixel library	
#include <Adafruit_NeoPixel.h>
// Pin where the TMP36 is connected
#define TEMP_SENSOR_PIN A0 
// Number of pixels in the NeoPixel ring (change this to 12)
#define NUM_PIXELS 12     
// Pin for the additional red LED
#define RED_LED_PIN 13     
// Temperature interval for each LED
//Sets the interval of each LED
#define TEMP_INTERVAL 10
// Calculate threshold step size

//creates instance of the NeoPixel
//it specifies the number of pixels, pin of the NeoPixel,colour and data transmission speed	
Adafruit_NeoPixel pixels(NUM_PIXELS, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  //sets the pinmode to INPUT determining that we are going to take the input from temp sensor
  pinMode(TEMP_SENSOR_PIN, INPUT);
  //determines the pinmode to OUTPUT determining that it will show the output
  pinMode(RED_LED_PIN, OUTPUT);
  //initialses the NeoPixel ring
  pixels.begin();
}

void loop() {
  //reads the temperature in celcius
  float tempC = readTemperature();
  //checks if the temperature is valid
  if (tempC != -100) {
    displayTemperature(tempC);
    //if not valid print the following statement
  } else {
    Serial.println("Error: Could not read temperature.");
  }
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(2000); // Delay between temperature readings
}

float readTemperature() {
  // Read analog voltage from temperature sensor
  int sensorValue = analogRead(TEMP_SENSOR_PIN);
  // Convert analog voltage to voltage (0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  // Convert voltage to Celsius temperature
  float tempC = (voltage - 0.5) * 100.0;
  //return the temperature
  return tempC;
}

void displayTemperature(float tempC) {
  // Calculate the number of LEDs to light up based on the temperature
  int numLedsToShow = calculateNumLeds(tempC);
  // Loop through the LEDs and set the color to green for LEDs that should be lit up
  for (int i = 0; i < numLedsToShow; i++) {
    // Green color for temperature indication
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); 
  }
  // Turn off remaining LEDs by setting their color to black (off)
  for (int i = numLedsToShow; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));//(0, 0, 0)indicates black colour
  }
  // Update the NeoPixel ring to reflect the changes
  pixels.show();
  //if the the number LEDs is greater than or equal to 12 the RED LEDs will be turned on
  if (numLedsToShow >= NUM_PIXELS) {
    digitalWrite(RED_LED_PIN, HIGH);
  } else {
    //if not greater than or equal to 12 the RED LED will remain off
    digitalWrite(RED_LED_PIN, LOW);
  }
}

//
int calculateNumLeds(float tempC) {
  int numLeds = tempC / TEMP_INTERVAL;
  // Ensure numLeds does not exceed NUM_PIXELS
  //min function returns the min value of the two. 
  return min(numLeds, NUM_PIXELS); 
}