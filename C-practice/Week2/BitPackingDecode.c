// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 2
// Exercise 4 (Unpacking):
// Submission code: 2351841

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// bit extraction derived from: https://stackoverflow.com/questions/10090326/how-to-extract-specific-bits-from-a-number-in-c 
void unPacker(unsigned char hexNum,int *engine,int *gear,int *key,int *brakeOne,int *brakeTwo){
    //the command numbers for the engine,gear,etc are extracted from the hexadecimal number
    //the hex number is exposed to hexadecimal representation of specific binary numbers to access the bits in the number
    // these numbers are then right shifted by the bit position/ bit size provided to each value
    //the remainder value is the decimal value that was packed into the hexadecimal
    *engine = (hexNum & 0x80) >> 7; 
    *gear  = (hexNum & 0x70) >> 4;
    *key   = (hexNum & 0x0C) >> 2;
    *brakeOne  = (hexNum & 0x02) >> 1;
    *brakeTwo  = hexNum & 0x01;
}
//checks if the value is a hexadecmial or not
bool isHex(char* input){
     for (int i = 0; input[i] != '\0'; i++) { //runs for until null terminator is detected
        if (!isxdigit((unsigned char)input[i])) { //calls isxDigit function to check if the value is a valid hexadecimal number or not
            return false;//returns false if not a hex number
        }
    }
    return true;
}
//prints out the values according to the schema provided in the exercise
void printValue(int *engine,int *gear,int *key,int *brakeOne,int *brakeTwo){
    printf("Name\t\tValue\n");
    printf("-----------------------------\n");
    printf("engine_on\t%d\n", *engine);
    printf("gear_pos\t%d\n", *gear);
    printf("key_pos\t\t%d\n", *key);
    printf("brake1\t\t%d\n", *brakeOne);
    printf("brake2\t\t%d\n", *brakeTwo);
}
int main(int argc , char* argv[]){
    //checks if valid number of inputs were provided
    if(argc != 2){
        printf("Error: Missing or excess input"); //prints error message
        return 0;
    }
    //points to the first element of the input value
    char *charPointer;

    //calls the hex number validator and returns an error message if an invalid input was entered
    if(!isHex(argv[1])){
        printf("Error: The number entered was not a hexadecimal value"); //prints error message
        return 0;
    } 
    //strtol function that representsthe string input to a hexadecimal value
    unsigned char hexInput = strtol(argv[1],&charPointer,16);
    //values to store the unpacked digits
    int engine_on; //stores engine instruction
    int gear_pos;//stores gear instruction
    int key_pos;//stores key instruction
    int brake1;//stores brake1 instruction
    int brake2;//stores brake2 instruction
    //function calls to unpack the hexadecimal value and to print the values
    unPacker(hexInput,&engine_on,&gear_pos,&key_pos,&brake1,&brake2);//unpacks the hexadecimal value
    printValue(&engine_on,&gear_pos,&key_pos,&brake1,&brake2); //prints the instructions
    
    
}