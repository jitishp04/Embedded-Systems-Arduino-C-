// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 4
// Exercise 2:
// Submission code: 2351823

#include <Servo.h>

Servo myServo;  // servo object to control motor
int ServoOverFlow = 0;  //counts the timer2 overflow for the servo
int seconds = 0;  // time counter

//interrupt function for timer2
ISR(TIMER2_OVF_vect){  
//increments the servo overflow by 1,everytime an overflow occurs
  ServoOverFlow++;
}

void setup(){
  myServo.attach(5);  //this attaches the servo to pin 5
  Serial.begin(9600); //define baud rate
  
  // TCCR2B is an inbuilt servo variable that tracks
  // the timer inside the servo component
  //each CLOCKSELECT is toggled to reduce the cycles
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); 
  // toggle the interrupts specifically for overflow events
  TIMSK2 |= (1 << TOIE2); 
  //initializes the interupt
  sei();  
}

void loop(){
  //if the overflow is 61(essentially 1 second
  //it resets the servo and counts 1 second
  if (ServoOverFlow >= 61) {
    ServoOverFlow = 0; // overflow reset
    seconds++;//increments to 1 second
    
    //it moves the rotar by 1 degree every second
    //it has a max limit of 180 and is in sync with 
	// the 0-60 second limit of the timer
    myServo.write(map(seconds % 60, 0, 60, 0, 180));
     
    //prints seconds
    Serial.print("Seconds: ");  
    Serial.println(seconds);
    
    //resets timer if 1 minute has passed
    if(seconds == 10){
      seconds = 0;
    }
  }
}
