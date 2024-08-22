// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 3
// Exercise 5:
// Submission code: 2345166

#include <stdio.h> //standard input/output library in c
#include <stdlib.h> //standard library in c
#include <time.h> //used for random seed for number generation

#define MAX 10 // maximum values in the array 

int main() {
    int array[MAX]; //declare integer array of max size 10
    srand(time(0)); // random seed

    printf("Random array: ");   
    for (int i = 0; i < MAX; i++) { //loop to fill the array with random number from 1-99
        array[i] = rand() % 99 + 1; // add the random number to the i elemeent in the array
        printf("%d, ", array[i]);   // print the number (for testing)
    }
    printf("\n");

    printf("The value of the address of the array (pointer) is: %p\n", (int*)array); // pointer to the array has type %p and casting it to (int*)
    printf("First integer in the array is (array[0]): %d\n", array[0]); //0-th element in the array (array[0] and type int (%d))
    printf("The last integer in the array is: %d\n", array[MAX - 1]);   //last element in 0-based array (array[MAX-1] and type int (%d))
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));  //sizeof funtion returns long unsigned int of int (%lu)
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array)); //sizeof funtion returns long unsigned int of array (%lu)

    printf("integer values and their doubles:\n");
    for (int i = 0; i < MAX; i++) { // loop to go through the array 
        int *ptr = &array[i];   // using pointer equal to the address of the i-th element in the array
        printf("%d doubled: %d\n", *ptr, *ptr * 2); // print the pointer and its doubled value
    }

    return 0;
}
