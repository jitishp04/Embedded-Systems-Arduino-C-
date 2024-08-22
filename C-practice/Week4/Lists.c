// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 4
// Exercise 4:
// Submission code: 2351823

// standard c libraries 
#include <stdio.h>
#include <stdlib.h>

/* part a: implement search_number method
the method iterates through the whole array and returns int of the position of the numeber or if not found -1 
number = number to be searched
tab[] = array of int initialised in main()
size = size of array
*/
int search_number(int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {    // for loop itterating through the array of size, size
        if (tab[i] == number) { // if the i'th number is the number to be searched
            return i;   // return the position of the number in the array
        }
    }
    return -1; // else return -1 (not found)
}


// swap method
void swap(int* xValue, int* yValue){
    int temp = *xValue; // temporarily store the value of x
    *xValue = *yValue;  // set yvalue as xvalue
    *yValue = temp; // set temp value as yvalue
}

/* part b: implement bubble sort method (not the selection sort mentioned)
number = size of the array
tab[] = array to be sorted
*/
void sort( int number, int tab[]) {
    for (int i = 0; i < number - 1; i++) {  // iterates through all numbers in the array except the last one 
        for (int j = 0; j < number - i - 1; j++) { // loop to compare the numbers to move the value 
            if (tab[j] > tab[j + 1]) {  // if the current number is greater than the next number 
                swap(&tab[j], &tab[j + 1]); // swap the numbers
            }
        }

        //for testing (print the array after each iteration):
        printf("Iteration %d: ", i + 1);
        for (int k = 0; k < number; k++) {
            printf("%d ", tab[k]);
        }
        printf("\n");

    }
}

int main() {
    int test[] = {0, 1, 34, 1, 67, 3, 23, 12, 13, 10}; // test array (given)
    int length = sizeof(test) / sizeof(int); // length calculated through the size of bits of test array / bit size of int (4)
    int n = 1;  // number to be searched in the array

    int result = search_number(n, test, length); // store the number returned by search_number method 
    if (result != -1) { // if result is not equal to -1
        printf("%d found at position %d\n", n, result); // print the position of the number
    } else if(result == -1) { // if it is -1 
        printf("%d not found \n", n); // print not found
    }

    // print the unsorted array:
    printf("Unsorted array: ");
    for (int i = 0; i < length; i++) {  //iterate through the length of the array
        printf("%d ", test[i]);
    }
    printf("\n");

    sort(length, test); // call the sort function to sort the array

    // print the sorted array:
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {  //iterate through the length of the array
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}
