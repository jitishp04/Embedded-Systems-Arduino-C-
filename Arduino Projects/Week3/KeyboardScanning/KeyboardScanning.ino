// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 3:Keyboard Scanning
// Submission code: 2345166
const int numRows = 4;
const int numCols = 4;

// Define the key map: a 4x4 matrix that maps keys on the keypad to characters.map
char keys[numRows][numCols] = {
  {'1', '2', '3', 'A'},//First row of the keypad matrix
  {'4', '5', '6', 'B'},//Second row of the keypad matrix
  {'7', '8', '9', 'C'},//Third row of the keypad matrix
  {'*', '0', '#', 'D'}//Fourth row of the keypad matrix
};

// Define the pins for rows and columns
// An array holding the pin numbers for the rows of the keypad.
int rowPins[numRows] = {11, 10, 9, 8};
// An array holding the pin numbers for the coloumns of the keypad.
int colPins[numCols] = {7, 6, 5, 4};

void setup() {
  Serial.begin(9600);
  // Set column pins as inputs with pull-up resistors enabled
  for (int col = 0; col<  numCols; col++) {
    // Set the current column pin as input with pull-up resistor enabled.
    pinMode(colPins[col], INPUT_PULLUP);
  }
  // Set row pins as outputs
  
  // Iterate over each row pin
  for (int row = 0; row < numRows; row++) {
    // Set the current row pin as output.
    pinMode(rowPins[row], OUTPUT);
    // Set the current row pin to HIGH initially.
    digitalWrite(rowPins[row], HIGH);
  }
}

void loop() {
  // Scan each row
  for (int row = 0; row < numRows; row++) {
    // Set current row low to scan
    digitalWrite(rowPins[row], LOW);
    
    // Check each column for key press
    for (int col = 0; col < numCols; col++) {
      if (digitalRead(colPins[col]) == LOW) { // Key pressed
        // Print the pressed key
        Serial.println(keys[row][col]);
        // Wait for debounce
        delay(50);
        // Wait until key released
        while (digitalRead(colPins[col]) == LOW);
        delay(50);
      }
    }
    
    // Reset current row to high
    digitalWrite(rowPins[row], HIGH);
  }
}
