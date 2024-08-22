// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 6:
// Submission code: 2345166

#include <stdio.h> //standard input/output library in c
#include <stdlib.h> //standard library in c
#include <string.h> // used mainly for strcpy function

#define MAX_LENGTH 20   // max length of the array (string)

void copyString(char copiedString[], char inputString[]) {  // own implementation of copy strings which takes input of the string to copied into and input 
   int i = 0;
   while(inputString[i] != '\0' || i <= MAX_LENGTH) { // while loop to itterate through until max length or end of string is reached
      copiedString[i] = inputString[i];   //set copied string's i-th element to input string's i-th element
      printf("%c", copiedString[i]);
      i++;
   }
   printf("\n");
   copiedString[i] = '\0'; // end the copied string with \0 to represent end of string
}


int main() {
   char inputString[MAX_LENGTH], strcpyString[MAX_LENGTH], ownCopyString[MAX_LENGTH]; // declare all string required

   printf("Enter a string (up to 20 characters): ");
   fgets(inputString, MAX_LENGTH, stdin); // reads the string from specified string (file or keyboard) and stores it at inputString
                                          // https://stackoverflow.com/questions/74657348/reading-files-with-fgets 
                                          // has max number of characters as MAX_LENGTH and standard input as whichever of file or keyboard

   inputString[strcspn(inputString, "\n")] = 0;
   strcpy(strcpyString, inputString);  // copying using strcpy function already available in c

   copyString(ownCopyString, inputString);   // copying string using our own function

   
   printf("Copied using strcpy: %s\n", strcpyString); // printing strcpy string
   printf("Copied without using library function: %s\n", ownCopyString); // printing our own function's copied string 

    return 0;
}
