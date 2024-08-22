// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 6
// Exercise 3
// Submission code: 23512271


#include <Adafruit_NeoPixel.h> //neopixel library
#include <Keypad.h> //keypad library

#define LED_PIN 3 // Pin connected to the Neopixel
#define NUM_LEDS 24 // Number of Neopixels in the strip

// Define the keypad matrix
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; // Connect the row keys to the arduino pins
byte colPins[COLS] = {9, 8, 7, 6};    // Connect the column keys to the arduino pins

//initialize the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//initialize the neopixel with neopixel type,the connected pin, neopixel colors and frequency
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

char inputString[8]; // String to store keypad inputs (7 chars + null terminator)
int inputIndex = 0; // Index to track the position in the input string
int counter = 0; //count the number of lock ins

//array storing valid input addresses
String validAddresses[] = {
  "1AC91BD", "342824A", "6D1732B", "52A64AC",
  "413553A", "34246CC", "23B393B","9999999"};
//flag to check if the address entered was valid
bool valid = false;

//flag to check if first 6 lights are locked in
bool lightsLocked = false;

void setup() {
  Serial.begin(9600);//initialize baud rate
  strip.begin(); //initialize neopixel
  strip.show(); // Initialize all pixels 
}

void loop() {
  //input keys 
  char key = keypad.getKey();
  //if statement to check if key input was registered and 
  //if inputs can still be accepted
  if (key != NO_KEY && inputIndex < 7) { 
    inputString[inputIndex] = key; // Store the key in the input string
    inputIndex++; //move to next array space
    inputString[inputIndex] = '\0';//initialize last space as null terminator
    Serial.print(key); // Print the key value
  }
  if (inputIndex == 7) { // If all inputs were registered 
    Serial.println("\nInput string:"); //print the adddress entered
    Serial.println(inputString);
    validAddress(sizeof(validAddresses)); //check if address is valid
    //this method run provides a value for the valid flag
    
    //Shows fancy lights as long as lights are not locked in
    if(!lightsLocked){
      spinningLights(); //function that shows the animation
    }
    
    // Lock in lights after spinning stops
    lockInLights(); //shows the light locked in based on counter
    counter++; //increments counter so the next char is locked in
  }
}

//function that triggered the spinning animation
void spinningLights() {
  uint32_t colors[NUM_LEDS]; // Array to store colors for each LED
  int offset = 0; // Control the change in color between pixels
  unsigned long startTime = millis(); // Record the start time of spinning

  // Loop for spinning lights for 2 seconds
  while (millis() - startTime < 2000) {
   // for loop that iterates through all pixels 
    for (int i = 0; i < NUM_LEDS; i++) {
      //if statement to control what lights turn red or blue
      if (i % 2 == 0) { 
        //even lights turn red
        colors[i] = strip.Color(255, 0, 0); // Red
      } else {
        //odd lights turn blue
        colors[i] = strip.Color(0, 0, 255); // Blue
      }
    }

    // Update colors 
    for (int i = 0; i < NUM_LEDS; i++) {
      //offset here is used to retrieve the color from the array
      strip.setPixelColor(i, colors[(i + offset) % NUM_LEDS]);
    }
    //sets colors to show
    strip.show();
    delay(100); // Controls the speed of the  animation
    offset++;
  }
}

void lockInLights() {
  strip.clear(); // Turn off all LEDs
  //first lock in
  if (counter == 0) {
  strip.setPixelColor(20, 0, 255, 0);
strip.setPixelColor(21, 0, 255, 0);
} 
  //second lock in
else if (counter == 1) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
} 
  //third lock in
else if (counter == 2) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
} 
  //fourth lock in
else if (counter == 3) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(9, 0, 255, 0);
  strip.setPixelColor(8, 0, 255, 0);
} 
  //fifth lock in
else if (counter == 4) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(9, 0, 255, 0);
  strip.setPixelColor(8, 0, 255, 0);
  strip.setPixelColor(12, 0, 255, 0);
  strip.setPixelColor(11, 0, 255, 0);
} 
  //sixth lock in
else if (counter == 5) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(9, 0, 255, 0);
  strip.setPixelColor(8, 0, 255, 0);
  strip.setPixelColor(12, 0, 255, 0);
  strip.setPixelColor(11, 0, 255, 0);
  strip.setPixelColor(14, 0, 255, 0);
  strip.setPixelColor(15, 0, 255, 0);
  lightsLocked = true;
  
  //if the address is valid, it locks in the seventh char
} else if (valid) {
  strip.setPixelColor(20, 0, 255, 0);
  strip.setPixelColor(21, 0, 255, 0);
  strip.setPixelColor(23, 0, 255, 0);
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.setPixelColor(3, 0, 255, 0);
  strip.setPixelColor(9, 0, 255, 0);
  strip.setPixelColor(8, 0, 255, 0);
  strip.setPixelColor(12, 0, 255, 0);
  strip.setPixelColor(11, 0, 255, 0);
  strip.setPixelColor(14, 0, 255, 0);
  strip.setPixelColor(15, 0, 255, 0);
  strip.setPixelColor(17, 0, 255, 0);
  strip.setPixelColor(18, 0, 255, 0);
}

//displays the lights
  strip.show();
  delay(1000); // delay in order to properly display the lights
  strip.clear(); // Turn off all LEDs
}

//if the address is invalid, this function is triggered 
//it shows a red light
void errorLights() {
  //iterates through all the lights to show red
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show(); // Display the colors on the Neopixel strip
  delay(1000); //delay in order to properly display the lights
}

//function to check address validity
//requires size parameter of the validAddresses array
void validAddress(int size) {
  //print to check if function is working
  Serial.println("validity checked, it is:");
  Serial.print(valid);
  //iterates through all the array elements
  for (int i = 0; i < size; i++) {
    //compares element and the input string
    if (strcmp(inputString, validAddresses[i].c_str()) == 0) {
      //if its a valid address, flags valid as true
      valid = true; 
      break; // Exit if a match is found
    }
  }
  if (!valid && lightsLocked) {
    errorLights(); // Call errorLights if the input is not valid and all lights are locked in
  }
}
