// (C) Jitish Rajankumar Padhya, Raghav Tengse, Utkarsh Singh, group: 23 (2024)
// Work package 2
// Exercise 3:
// Submission code: 2351841

#include <stdio.h> // standard c library
#include <stdlib.h>  // standard c i/o libary 
#include <string.h>


// -----typedefs -------
// defination of the structure named PERSON
typedef struct {
    //bellow are the members of the PERSON structure
    // array containing the firstname with a maximum length of 20 characters
    char firstname[20];
    //array containing the lastname with a maximum length of 20 characters
    char famname[20];
    //array containing the personal number with a maximum of 13 characters.
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration
PERSON input_record(void);              // Reads a person’s record.
void write_new_file(PERSON *inrecord);  // Creates a file and
                                        // writes the first record
void printfile(void);                   // Prints out all persons in the file
void search_by_firstname(char *name);   // Prints out the person if
                                        // in list
void append_file(PERSON *inrecord);     // appends a new person to the file

//function defination of input name which takes an integer parameter 'choice'.
//The function prompts the user to input either a first name or a family name, determined by the value of the 'choice' parameter.
//It then stores the entered information in the respective member of the 'queryPerson' structure.
PERSON input_name(int choice){
    //creates a variable queryPerson of type PERSON
    PERSON queryPerson;
    //checks if the value of choice is 1
    if(choice == 1){
        // if it true then we print the following.
        printf("Enter first name: ");
        // takes the input from the user and stores it in firstname of queryPerson
        scanf("%s", queryPerson.firstname);
        //return the queryPerson structure with firstName.
        return queryPerson;

        // if the choice is not 1
    } else {
        //prints the string.
        printf("Enter family name: ");
        //takes the input from the user and stores it in the family name of queryPerson
        scanf("%s", queryPerson.famname);
        // Return the 'queryPerson' structure containing the entered family name.
        return queryPerson;
    }
}

//function defination of input name which takes no parameter
//collects user input for a PERSON record, including the first name, last name, and personal number with a specific format
//The entered information is then stored in the 'ppPost' structure, which is returned by the function.
PERSON input_record(void){
    //declares a variable 'ppPost' of type PERSON to store the user-input.
    PERSON ppPost;
    // Display a prompt asking the user to enter the first name
    printf("Enter first name: ");
    //takes the user input and stores it in firstname member of ppPOST
    scanf("%s", ppPost.firstname);
    // Display a prompt asking the user to enter the family name
    printf("Enter last name: ");
    //takes the user input and stores it in famname member of ppPOST
    scanf("%s", ppPost.famname);
    // Display a prompt asking the user to enter the personal number
    printf("Enter personal number (yyyymmddnnnc): ");
    //takes the user input and stores it in pers_number member of ppPOST
    scanf("%s", ppPost.pers_number);
    //returns the ppPost structure containing the entered firstname, famname and personal number
    return ppPost;
}

//decalres a function for creating new files, deleteting the old one if it exists
//Alos, writing the content of the provided 'inrecord' structure into the binary file.
void write_new_file(PERSON *inrecord){
    // Declare a string containing the filename for the binary file.
  	char* binaryFilename = "myBinaryFile.bin";
    // Attempt to delete the existing file.
    if (remove(binaryFilename) != 0) {
        printf("Error deleting old file\n"); // Ignore errors if the file doesn't exist
    }
    // Open a new binary file in write mode ("wb").
    // 'w' stands for write, and 'b' stands for binary.
    FILE* newBinaryFile = fopen(binaryFilename, "wb");
    //checks if the file was opened successfully.
    if(newBinaryFile != NULL){
        // Write the content of the 'inrecord' structure to the binary file.
        //we are using fwrite to write the data of the inrecord structure to the binary file 
        //increcord is the pointer to the array of the elements to be written
        //sizeof(Person) is the size in bytes of each element to be written
        //1 is the number of elements to be written
        //newBinaryFile is the pointer to a FILE object that specifies an output stream 
        fwrite(inrecord, sizeof(PERSON), 1, newBinaryFile);
    }else{
        // Display an error message and exit the program if the file couldn't be opened.
        printf("Error opening file %s in creating", binaryFilename);
        exit(1);
    }
    //closes the binary file
    fclose(newBinaryFile);
    // Display a success message after creating the file and writing the first record
    printf("File created\n");
}


void append_file(PERSON *inrecord) {
    // File name for the binary file.
    char* binaryFilename = "myBinaryFile.bin";
    //Open the existing binary file in append mode(ab)
    FILE* existingBinaryFile = fopen(binaryFilename, "ab");
    // Check if the file was opened successfully
    if ( existingBinaryFile == NULL) {
        printf("File doesn't exist");
        exit(1);
    }
    if (existingBinaryFile != NULL) {
        // Write the content of 'inrecord' to the end of the existing binary file.
        fwrite(inrecord, sizeof(PERSON), 1, existingBinaryFile);
    } else {
        printf("Error opening file %s for appending", binaryFilename);
        exit(1);
    }
    //closes the file
    fclose(existingBinaryFile);
    // Display a success message after appending the record.
    printf("Record appended successfully.\n");
}

//function opens a binary file in read mode.
//It attempts to read the first record, and then prints the content of each PERSON record in the file
void printfile(void){
//opens the binary file in read mode
FILE *binaryFile = fopen("myBinaryFile.bin", "rb");
    //checks if the file was opened successfully
    if (binaryFile == NULL) {
        printf("File doesnt exist");
        exit(1);
    }
    // Declare a variable to store the data of each PERSON record.
    PERSON currentPerson;   
    // Variable to store the number of bytes read during fread.
    size_t bytesRead;
    //attempts to read the first record from the binary file
    bytesRead = fread(&currentPerson, sizeof(PERSON), 1, binaryFile);
    //checks if the file is empty
    if (bytesRead ==0){
        printf("The file is empty. \n");
    }
    else
    {
        // Loop through the file and print each PERSON record.
        while (fread(&currentPerson, sizeof(PERSON), 1, binaryFile) == 1){
            // Print the data as strings
        printf("First Name : %s\n", currentPerson.firstname);
        printf("Last  Name : %s\n", currentPerson.famname);
        printf("Personal Number: %s\n", currentPerson.pers_number);
        printf("------------------------\n");
        } 
    }
    //closes the binary file.
     fclose(binaryFile);
}

void search_by_firstname(char *name){
    // Declare a variable to store the data of each PERSON record.
    PERSON currentPerson;
    //opens the binary file in read mode
    FILE *binaryFile = fopen("myBinaryFile.bin", "rb");
    // Loop through the binary file and read each PERSON record.
    size_t bytesRead = fread(&currentPerson, sizeof(PERSON), 1, binaryFile);
    //checks if the file is empty
    if (bytesRead == 0){
        printf("The file is empty. \n");
    }
    while (fread(&currentPerson, sizeof(PERSON), 1, binaryFile) == 1) {
        // Check if the first name of the current record matches the provided 'name'
        // Print the data as strings
        if(strcmp(currentPerson.firstname,name)==0){
            printf("First Name : %s\n", currentPerson.firstname);
            printf("Last  Name : %s\n", currentPerson.famname);
            printf("Personal Number: %s\n", currentPerson.pers_number);
            printf("------------------------\n");
        }
    }
}
void search_by_famname(char *famname){
    // Declare a variable to store the data of each PERSON record.
    PERSON currentPerson;
    //opens the binary file in read mode
    FILE *binaryFile = fopen("myBinaryFile.bin", "rb");

    size_t bytesRead = fread(&currentPerson, sizeof(PERSON), 1, binaryFile);
    //checks if the file is empty
    if (bytesRead == 0){
        printf("The file is empty. \n");
    }
    
    while (fread(&currentPerson, sizeof(PERSON), 1, binaryFile) == 1) {
        // Check if the first name of the current record matches the provided 'name'
        // Print the data as strings
        if(strcmp(currentPerson.famname,famname)==0){
            printf("First Name : %s\n", currentPerson.firstname);
            printf("Last  Name : %s\n", currentPerson.famname);
            printf("Personal Number: %s\n", currentPerson.pers_number);
            printf("------------------------\n");
        }
    }
}

//works as a main function
int main(void){
    // Declare variables for user input and a PERSON structure.
    int input;
    PERSON ppost;
    PERSON dummyPerson = { "ABCD", "EFGH", "200305269098" };		// intialized as dummy data
	PERSON* dummyPtr = &dummyPerson;

    // Create a menu-based loop that continues until the user chooses to exit (input == 5)
    while(input !=5){
        printf("1 Create a new and delete the old file. \n");
        printf("2 Add a new person to the file. \n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file. \n");
        printf("5 Exit the program. \n");
        printf("Input: ");
        //Read user inout for menu selection
        scanf("%d", &input);
        
        
    //creates a switch case which takes input as a parameter
        switch (input) {
            // Option 1: Create a new file and delete the old one.
            // Get user input for a new record and write it to a new file.
            case 1:
            write_new_file(dummyPtr); 
            break;
            // Option 2: Adds a new person to the existing file.
            // Get user input for a new record and append it to the existing file.
            case 2: ppost = input_record();
             append_file(&ppost); 
             break;
            // Option 3: Search for a person in the file.
            // Prompt the user to choose between searching by first name or family name
            case 3: 
            printf("Press 1 to search by first name, Press 2 to search by family name \n");
            int search_option;
            scanf("%d",&search_option);
            //switch to select if we want to search by first name or family name
                switch (search_option)
                    {
                        //search by first name
                        //Get user input for a first name and search for matching records.
                    case 1:
                        ppost= input_name(1); 
                        search_by_firstname(ppost.firstname);
                        break;
                    case 2:
                        //search by family name
                        //Get user input for a family name and search for matching records.
                        ppost= input_name(2); 
                        search_by_famname(ppost.famname);
                        break;
                    
                    default:
                        //displays error message for an incorrect option
                        printf("Incorrect option entered");
                        break;
                    }
            break;
            // Option 4: Print out all records in the file.
            // Invoke the function to print all records in the binary file
            case 4: printfile();
             break;
            //Option 5 exits the program
            // This case will break out of the loop, leading to the program termination.
            case 5: 
            break;
            // Default case: Display an error message for invalid input
            default: printf("Invalid input.\n"); 
            break;
        }
    }
    //returns 0 meaning program completion.
    return(0);
}