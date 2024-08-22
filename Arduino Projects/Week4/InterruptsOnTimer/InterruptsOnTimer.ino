// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 4
// Exercise 1:
// Submission code: 2351823

// several aspects inspired from WP3-3.1
// Define pins for all LEDs
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6

// Define temperature semsor analog pin
#define TEMP_SENSOR A0

// Define temperature ranges in degrees celsius
#define TEMP_RANGE0 0
#define TEMP_RANGE1 10
#define TEMP_RANGE2 20
#define TEMP_RANGE3 30
#define TEMP_RANGE4 40

void setup() { // Runs once everytime it is started or restarted
  
  // Configures the pins connected to LEDs as output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  Serial.begin(9600); // initialise serial communication (for testing)

  // Timer interrupter 
  // https://www.tinkercad.com/things/eS19mAQ9aYu-arduino-timer-interrupt
  cli(); // disable global interrupts (clear interrupt flag)
  
  // reset values
  TCCR1A = 0; //timer control register A for Timer1
  TCCR1B = 0; //timer control register B for Timer1
  TCNT1 = 0; // counter value, set to zero to begin counting from 0 till interrupt value below
  
  OCR1A = 15624; // Output compare: when this value is reached (1 hz), interrupt ((16*10^6) / (1*1024) - 1 (must be <65536))
  TCCR1B |= (1 << WGM12); // configures CTC: resets timer to 0 when OCR1A value is reached
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler set to 1024 (intervals between interrupts
  TIMSK1 |= (1 << OCIE1A); // interrupt service routine (ISR) occurs
  sei(); //re-enable global interrupts (set interrupt flag)
}

// method is called when counter matches OCR1A value 
ISR(TIMER1_COMPA_vect) { // Timer1 ISR is used (1 hz)
  float temp = readTemperature(); // get temperature in degrees celsius

  // First turn off all LEDs 
  for (int i = LED1; i <= LED5; i++) {
    digitalWrite(i, LOW);
  }

  // If loops to turn on the right set of LEDs depending on the range of temperature
  if (temp < TEMP_RANGE0){ // temperature less than 0
  	// No LEDs
  }
  else if (temp < TEMP_RANGE1) { // temperature less than 10
    digitalWrite(LED5, HIGH);    // 1 LEDs
  }
  else if (temp < TEMP_RANGE2) { // temperature less than 20
    digitalWrite(LED5, HIGH);	 // 2 LEDs from the left are on
    digitalWrite(LED4, HIGH);
  }
  else if (temp < TEMP_RANGE3) { // temperature less than 30
    digitalWrite(LED5, HIGH);	 // 3 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else if (temp < TEMP_RANGE4) { // temperature less than 40
    digitalWrite(LED5, HIGH);	 // 4 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
  }else{	// // temperature greater than or equal to 40
    digitalWrite(LED5, HIGH);	// 5 LEDs from the left are on
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
  }
  
  // For testing purposes print temp in monitor:
  Serial.print("Temperature: ");
  Serial.print(temp); // print the float temperature 
  Serial.println(" C");
}


float readTemperature() { // Function to read temperature from sensor
  float tempValue = analogRead(TEMP_SENSOR); //analog voltage from the sensor
  float voltage = tempValue * (5.0 / 1023.0); // Convert sensor value to voltage between 0-5V
  float temperature = (voltage - 0.5) * 100; // convert volts to degrees celsius
  return (float)temperature; // return temputrature of type int
}

void loop() {
  // loop occurs in the in the interrupt method when the counter is matched
}
