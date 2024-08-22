// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 3.1
// Submission code: 2345166

void setup() {
  //define the bit rate at which data is sent
 Serial.begin(9600);
}
void loop() {
  //store analog data in a variable
  float tempAnalogData = analogRead(A0);
  //formula to convert analog data to voltage
  //where 5.0 is the voltage provided
  //and 1023 is the possible values for resistance, ranging from 
  //0 to 1023
  float voltage = (tempAnalogData * 5.0)/1023.0;
  //calculating the temperature using the voltage reading
  float temperature = (voltage - 0.5)/0.01;
  
  //printing the values returned from the analogReading
  Serial.print(temperature);
  Serial.print("°C");
  Serial.println("");

  // 500ms delay between every reading provided
  delay(500);
}
