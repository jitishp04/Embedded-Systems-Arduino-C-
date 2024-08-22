// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 1:
// Submission code: 2345166


//defining the pins connected to the respective components
int redLED = 13;// red led is connected to the 13th digital pin
int buttonState = 0; //button is at 0, meaning its at normal pos
int pushButton = 2;//red led is connected to the 2nd digital pin
int greenLED = 7;// green led is connected to the 7th digital pin


void setup()
{
  //define and initialise the components used in the circuit
  // i.e red LED light, push button and a green LED light
  //the pinmode also defines the type,i.e red light provides output
  //and the button takes input(i.e getting pressed
  pinMode(redLED, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(greenLED, OUTPUT);
}

void loop()
{
  //reads the state of the button(pushed or not pushed)
  buttonState = digitalRead(pushButton);
  //if buttonState is high, it indicates that the button is pressed
  if (buttonState == HIGH) {
    //this in turn switches the green light on
    digitalWrite(greenLED, HIGH);
  }else {
    //else it switches the green light off
    digitalWrite(greenLED, LOW);
  }
//the red light will switch on
  digitalWrite(redLED, HIGH);
  //delay of 500 ms
  delay(500);
  //red light switch off
  digitalWrite(redLED, LOW);
  //delay of 500 ms
  delay(500);
  //these delays cause the red light to flash at intervals
  
  
}