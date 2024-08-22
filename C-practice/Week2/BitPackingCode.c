// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 2
// Exercise 4 (Packing):
// Submission code: 2351841

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//Checks if inputs are valid according to the schema in the exercise
bool inputValidator(int engine_on,int gear_pos,int key_pos,int brake1,int brake2){
    bool engine = (engine_on >= 0 && engine_on <= 1) ? true : false; //engine should be either 1 and 0
    bool gear = (gear_pos <= 7 && gear_pos >= 0)? true: false; //gear should be 0 to 7
    bool key = (key_pos >= 0 && key_pos <= 2)?true: false; //key should be 0 , 1 or 2
    bool brakeOne = (brake1 >= 0 && brake1 <= 1) ? true : false; //brake1 should be either 1 and 0
    bool brakeTwo = (brake2 >= 0 && brake2 <= 1) ? true : false;//brake2 should be either 1 and 0
    if (engine && gear && key && brakeOne && brakeTwo) { //if loop that calls are the ternary operators to cheeck if the input is valid
        return true; //returns true for valid input
    }
    return false; //returns false for invalid input
}
//checks if number input is a valid number
bool numberValidator(char* num){
    int counter = 0; //counter to increment the index
     while (num[counter] != '\0') {
        if (!isdigit((unsigned char)num[counter])) //isdigit function checks if the char is a number
            return false; //returns false if input is not a number
        counter++; //increments counter
    }
    return true; //returns true if input is a number
}
int main(int argc , char* argv[]){
// the code requires 5 inputs,hence if 5 inputs(excluding the file name) are not provided, an error message is printed
if(argc != 6){
    printf("Missing or extra input"); //prints error message
    return 0; //quits the program if error is detected
} else {
    //fill all the variables with the correct values from the terminal
        int engine_on = strtol(argv[1],NULL,10);
        int gear_pos  = strtol(argv[2],NULL,10); 
        int key_pos   = strtol(argv[3],NULL,10); 
        int brake1    = strtol(argv[4],NULL,10); 
        int brake2    = strtol(argv[5],NULL,10); 
        int bitShifting[] = {4, 2, 1, 0}; // array containing the number of left shifts for variables
        //checks if the input is a valid number or not
        for(int i = 1; i< argc ; i++){
            if(!numberValidator(argv[i])){
                printf("The input is not a number");
                return 0;//quits the program if error is detected
            }
        }

// checks validity
// calls the inputValidator which checks if the inputs are right
        if(inputValidator(engine_on,gear_pos,key_pos,brake1,brake2)){
            unsigned char hexanum = 0; //char which stores the hexadecimal number
            if(engine_on == 1){ //if engine is on(= 1) it provides 0x80 (hexadecimal for 10000000), such that he 7th bit is a 1 
                hexanum|= 0x80;
            }
            for (int i = 2; i < argc; i++) { //for loop that does a left bit shift for each value based on its bit spacing/bit position
            hexanum|= strtol(argv[i],NULL,10) << bitShifting[i-2]; // does a bit shift and does an OR operator to combine the results
            }
            printf("%02X\n", hexanum); //prints the result as a hexadecimal number
        } else {
            printf("Error: Invalid input\n"); //if errors were detected, returns an error for invalid input
            return 0;
        }

    }   
}