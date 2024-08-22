// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 2
// Exercise 1:
// Submission code: 2351841

#include <stdlib.h> // standard c library
#include <stdio.h> // standard c i/o libary 

enum DIRECTION {N,E,S,W}; // enum of all directions N=0, E=1, ...

typedef struct { // typedef ROBOT to be a construct consisting of:
    int xpos;               // x coordinate
    int ypos;               // y coordinate
    enum DIRECTION dir;     // direction of robot
} ROBOT;                    // type defined as ROBOT

void move(ROBOT *robot){    // move function inputs a pointer to a ROBOT (declared in main) to move it in the correct direction
    switch ((*robot).dir) { // gets the direction of the robot to know the orientation 
        case N: // if the robot is facing North
            (*robot).ypos++;        // increment y-position by 1
            break;  // or else break as the max y positon has been reached
        case E: // if the robot is facing East
            (*robot).xpos++;      // increment x-position by 1
            break;  // or else break as the max x positon has been reached
        case S: // if the robot is facing South
            (*robot).ypos--;     // decrease the y-position by 1
            break;  // or else break as the minimum amount is already reached
        case W: // if the robot is facing West
            (*robot).xpos--;     // decrease the x-position by 1
            break; // or else break as the minimum amount is already reached
    }
}

void turn(ROBOT *robot){ // turn function inputs a pointer to a ROBOT (declared in main) to rotate it clockwise
    if ((*robot).dir == W) { // if the robot's direction is West
        (*robot).dir = N;    // set the direction as North as after turning clockwise it will be facing North again
    } else {                 // or else
        (*robot).dir++;      // increment the direction by 1 in the order of the enum (N->E->S->W)
    }
}


void printDirection(ROBOT *robot){ // For testing and visual purposes printing the direction of a ROBOT (declared in main)
        switch ((*robot).dir) { //create a switch case to identify the current direction of the robot
        case N: // if the direction is N: print North and then break the switch case
            printf("North \n");
            break;
        case E: // if the direction is E: print East and then break the switch case
            printf("East \n");
            break;
        case S: // if the direction is S: print South and then break the switch case
            printf("South \n");
            break;
        case W: // if the direction is W: print West and then break the switch case
            printf("West \n");
            break;
    }
}

int main(){
    char instructions[10]; // create a string used to store the user input of instructions for the robot (alter as per liking)
    char endCharacter;  // declare a endcharacter used to breakk the while loop

    while(endCharacter != 'n'){ //until the endcharacter inputed is not n run this loop
        ROBOT robot = { // initialise a robot
            .xpos = 100,    // inputing the value greater than the max allowed to be able to loop until a valid value is inputed (0-99)
            .ypos = 100,    // inputing the value greater than the max allowed to be able to loop until a valid value is inputed (0-99)
            .dir = N        // By default the robot faces North
        };

        while (robot.xpos < 0 || robot.xpos > 99) { // run the loop until a valid input is scanned for robot.xpos (0-99)
            printf("Enter starting x-position between 0-99: ");
            scanf("%d", &robot.xpos);   // store the input at the address of the robot's x-position

            if (robot.xpos < 0 || robot.xpos > 99) {    // if it is not valid give a error and prompt 
                printf("Invalid x-position, enter a value (0-99)\n");
            }
        }

        while (robot.ypos < 0 || robot.ypos > 99) { // run the loop until a valid input is scanned for robot.ypos (0-99)
            printf("Enter starting y-position between 0-99: ");
            scanf("%d", &robot.ypos); // store the input at the address of the robot's y-position

            if (robot.ypos < 0 || robot.ypos > 99) { // if it is not valid give a error and prompt 
                printf("Invalid y-position, enter a value (0-99)\n");
            }
        }

        printf("String of characters (m for moving in the latest direction, or t for turning clockwise): ");
        scanf("%s", &instructions); //place the inputed instructions at the address

        // printing all the values of the current state of the robot
        printf("Current instructions and position: %s, ", instructions);
        printf("x: %d, y: %d, ", robot.xpos, robot.ypos);
        printDirection(&robot); // calling the print function with the input as the adress of the robot to print its direction

        for (int i = 0; instructions[i] != '\0'; i++) { // for loop to iterate over all the instrictions until met with a null character acting as end of string
            if(instructions[i] == 'm'){ // if the character is m
                move(&robot);   // call the move function with the input as the address of the robot 
            }else if(instructions[i] == 't'){   // if the character is t
                turn(&robot);   // call the turn function with the input as the address of the robot 
            }
        }

        // printing all the values of the final state of the robot
        printf("Final instructions and position: %s, ", instructions);
        printf("x: %d, y: %d, ", robot.xpos, robot.ypos);
        printDirection(&robot); // calling the print function with the input as the adress of the robot to print its direction

        //using to loop the cycle to initialise a new robot or end the program
        printf("Would you like to try again? y or n: ");
        scanf(" %c", &endCharacter); // storing the input at the adress of endcharacter to see if it matches 'n' to end the program
    }
    return 0;
}