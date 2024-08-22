// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 2
// Exercise 2:
// Submission code: 2351841

#include <stdio.h> // standard c library
#include <stdlib.h>  // standard c i/o libary 
#include <time.h>   // time library mainly used for random seed for randomisation

// Constants
#define MAX 5 //  Max initial length of the random list

// Struct definition
typedef struct q { 
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE; 

// Function declarations
REGTYPE* random_list(void);  // create a random list of length MAX returning the head of the list
REGTYPE* add_first(REGTYPE *temp, int data); // add the new node to the top input the head pointer, and data (number) and return the new node pointer

// Main program
// code influenced from: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm 
int main() {
    int nr = 0; // initialise the post number at 0
    REGTYPE *act_post, *head = NULL;  // initialisng the act_post pointer to go through the list, and head of the list (initially null)

    srand(time(0)); // Random seed
    head = random_list(); //head pointer is than the head of random list generated 

    printf("Random:");
    act_post = head; // set act_post as head to have a starting pointer to go through the list
    while (act_post != NULL) {  // while act_post pointer is not null 
        printf("\n Post nr %d : %d", nr++, act_post->number);   // print the post nr along with the number stored there
        act_post = act_post->next;  // then set the pointer to the next post/ node
    }

    // for tests
    head = add_first(head, 42); // add 42 at the top of the list 
    head = add_first(head, 8);  // then add 8 so now 8 is at the top of the list while the MAX has been increased by 2
    printf("\n\n New :");
    act_post = head; // set act_post as head to have a starting pointer to go through the list
    nr = 0; // reset the number back to 0, to print from 0 onwards
    while (act_post != NULL) { // while act_post pointer is not null 
        printf("\n Post nr %d : %d", nr++, act_post->number); // print the post nr along with the number stored there
        act_post = act_post->next; // then set the pointer to the next post/ node
    }

    // Free the allocated memory
    while ((act_post = head) != NULL) { // after all the printing run a while loop throughh the list
        head = act_post->next;  // setting the head as the next act_post
        free(act_post); // and freeing the allocated memory
    }
    return 0;
}

// Function definitions
REGTYPE* random_list(void) {
    int i; // declare i used in the loop
    REGTYPE *top = NULL, *item; // declare the pointer of top of the list and item being added 
    for (i = 0; i < MAX; i++) { // loop to create the initial max number of nodes
        item =(REGTYPE*)malloc(sizeof(REGTYPE)); // allocate memory for a new node
        if(item == NULL){ // if there is issue with memery allocation
            printf("Error in memory allocation \n");
            break;
        }else{
            item->number = rand() % 101;  // Random number between 0 and 100 to be the number of the new node
            item->next = top;  // Inserting the new new node to the top 
            item->prev = NULL;
            top = item; // assigning the top pointer as the new node
        }
    }
    return top; // return the new top pointer
}


REGTYPE* add_first(REGTYPE *temp, int data) {
    REGTYPE *newNode; // a new node declared
    newNode =(REGTYPE*)malloc(sizeof(REGTYPE)); // allocate memory for a new node 
    if(newNode == NULL){ // if there is issue with memery allocation
        printf("Error in memory allocation \n");
    }else{
    newNode->number = data; // Set the input data for the new node number
    newNode->next = temp;  // Point the new node to the current head setting it to be the first node
    newNode->prev = NULL; // There is no previous to the top of the list
    }
    return newNode; // return the new head
}