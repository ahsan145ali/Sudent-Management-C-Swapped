#include <stdio.h>
#include "students.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "subjects.h"
#include "enrollments.h"
struct Student firstStudent = {1, "Samuel Elliott", NULL, NULL}; //Creates first student
struct Student* head = &firstStudent; //sets first student address to be head of linked list.


void displayAllStudents() { //Displays information of all students
    printf("\n=================== Display All Students ===================\n");
    printf("\n");
    struct Student *temp = head;
    while (temp != NULL) { //iterates through linked list, printing out details of each node (student)
        printf("ID: %d \n", temp->id); 
        printf("Name: %s \n", temp->name); 
        if(temp->enrollments!=NULL)  printf("Enrolled in: %s \n", temp->enrollments->subjectptr->name);
        else printf("Enrolled: Not yet enrolled in any subject");
        printf("Next Address: %p \n", (void*)temp->next);
        temp = temp->next; 
        printf("\n");
    }
}

void addStudent(){ //Retrieves user input on new student and calls createStudent()
    printf("\n====================== Create Student ======================\n");
    printf("\n");
    short id = findAvailID(head); // finds the ID of the next created student.
    clearInput();
    char* name = stringInput("Name"); // gets input from user and allocates size to store the user name
    printf("New student created.\n");
    printf("\n");
    struct Student* newStudent = createStudent(id,name); //pointer stored in newStudent variable (not used at the moment)
}

short findAvailID(struct Student* head){ //finds the next available ID (auto increment)
    struct Student* tail = findTail(head); //calls get tail to find previous tail of linked list
    short newID = (tail->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

struct Student* createStudent(short id, char* name){ // creates new student and appends to linked list
    struct Student* tail = findTail(head); //stores tail so that previous tail'next' address can be added
    struct Student* newStudent = malloc(sizeof(struct Student));
    tail->next = newStudent;
    
    newStudent->id = id;

    newStudent->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    strcpy(newStudent->name, name); //and copies it into this memory

    newStudent->enrollments = NULL; //new students are not enrolled in anything

    newStudent->next = NULL; //this node becomes the tail

    return newStudent;
}//use malloc here

struct Student* findTail(struct Student* head){ //finds linked list tail
    struct Student *temp = head;
    while ((temp->next) != NULL){ // searches for linked list node with next = NULl and deduces this is the tail
        temp = temp -> next;
    }
    return temp; //returns the tail
}

 struct Student* retrieveStudentByID(){ //retrieves user input of student ID and searches for student with this ID, before displauing their details)

    printf("\n==================== Find Student By ID ====================\n");
    short id;
    int result;
    printf("\nSelect Student ID:");
    result = scanf("%hd",&id); 
    printf("\n");

    if (result != 1) { //sanitises input - calls itself recursively until valid input (only accepts integers)
        while (getchar() != '\n');  // Read and discard characters until a newline is found
        printf("Invalid selection, please input a valid ID number.\n");
        return retrieveStudentByID();
    }

    
    struct Student *temp = head;
    

    while (temp != NULL) { //cycles through students until end of list or student found
        if((temp->id) == id){ //if student found
            printf("ID: %d \n", temp->id); //print details
            printf("Name: %s \n", temp->name); 
            printf("Enrollment Address: %p \n", (void*)temp->enrollments);
            printf("Next Address: %p \n", (void*)temp->next);
            return temp;
        }
        temp = temp->next; 
    }
    
    return NULL;
}

void clearInputBuffer() { //Clears input buffer to allow correct reading of string
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //removes characters that are not new line or EOF 
}

void displayStudentByName() { //Takes user input of name and compares to name fields in linked list, outputting full student struct if match found
    printf("\n=================== Find Student By Name ===================\n");

    char name[30];

    while (1) {
        printf("\nInput Student Name: ");

        clearInputBuffer(); //had to do this otherwise it was reading the new line character

        if (fgets(name, sizeof(name), stdin) != NULL) { //reads size of name from stdin
            
            name[strcspn(name, "\n")] = '\0'; //strips newline character from end of string and replaces with null terminator
            //need to do this for correct comparison of strings
            if (strlen(name) == 0) {
                printf("You must enter a name. Please try again.\n"); //no name entered -> try again.
                continue;
            }
        } else {
            // If fgets fails, clear the input buffer and try again
            while (getchar() != '\n');
            printf("Invalid input, please input a valid name.\n");
            continue;
        }

        // Once valid string has been input, search linked list
        struct Student* temp = head;
        short found = 0;

        while (temp != NULL && found == 0) { 
            if (strcmp(temp->name, name) == 0) { // strcomp compares the input string to the name field of student struct
                printf("ID: %d \n", temp->id);
                printf("Name: %s \n", temp->name);
                printf("Enrollment Address: %p \n", (void*)temp->enrollments);
                printf("Next Address: %p \n\n", (void*)temp->next);
                found = 1; // Mark as found
            }
            temp = temp->next;
        }

        if (found == 0) { // If no matching name was found
            printf("Student not found, please try a different name.\n");
            continue; // Reprompt for input.
        } else {
            break; // exit loop once student found by name
        }
    }
}

void enrollStudentinSubject(){
    printf("\n=================== Enroll a Student ===================\n");
    printf("Input Student ID to enroll in a subject: \n");
    struct Student* st = retrieveStudentByID();
    if(st !=NULL){ // check if student was retrieved successfully
        printf("Input Subject ID to set it for the student %s: \n" , st->name);
        struct Subject* sb = retrieveSubjectByID();
        if(sb != NULL){ // check if subject was retrieved successfully
            enrollStudent(st,sb); // enroll student
        }
        else{
            return ; // return if subject not retrieved
        }
    }
    else{
        return ; // return if student not retrieved
    }
}