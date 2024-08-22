// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 4:
// Submission code: 2345166

#include <Keypad.h> // keyboard function using keypad.h library

const byte ROWS = 4; // size of rows
const byte COLUMNS = 4; // size of rows

// initiate a 4*4 matrix to represent the keys on keypad
char Keys[ROWS][COLUMNS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; // pins connected to the rows
byte colPins[COLUMNS] = {7, 6, 5, 4}; // pins connected to the columns

// Using the keybad library create a keyboard object
// to map the keys, pins, rows and columns
Keypad keypad = Keypad(makeKeymap(Keys),rowPins,colPins,ROWS,COLUMNS); 

void setup(){ // runs once when started or resseted 
  Serial.begin(9600); // Set serial communication 
}

void loop(){ // keeps running after setup()
  char pressedKey = keypad.getKey(); // get the key pressed
  Serial.println(pressedKey); // print the pressedKey in the monitor
  delay(100); // set a delay to be able to print input properly
}