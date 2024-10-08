#include <stdio.h>
#include "students.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "subjects.h"
#include "enrollments.h"
#include "teachers.h"

struct Student* headStudent = NULL; // Maintains the head of the link list
struct Student* tailStudent = NULL; // Maintains the tail of the link list

void displayAllStudents() { //Displays information of all students
    printf("\n=================== Display All Students ===================\n");
    printf("\n");
    struct Student *temp = headStudent;
    while (temp != NULL) { //iterates through linked list, printing out details of each node (student)
        printf("ID: %d \n", temp->id); 
        printf("Name: %s \n", temp->name); 
        if(temp->enrollments!=NULL)  
        {
            printf("Enrolled in: %s \nGrade: %c \n", temp->enrollments->subjectptr->name , temp->enrollments->grade);
            if(temp->enrollments->subjectptr != NULL && temp->enrollments->subjectptr->subjectTeacher != NULL )
            {
                printf("Teacher: %s \n" , temp->enrollments->subjectptr->subjectTeacher->name);
            }
        }
        else printf("Enrolled: Not yet enrolled in any subject \n");
        temp = temp->next; 
        printf("\n");
    }
}

void addStudent(){ //Retrieves user input on new student and calls createStudent()
    printf("\n====================== Create Student ======================\n");
    printf("\n");
     short id = 0;
    if(headStudent == NULL){
        id = 1; // If this is the first student, assign ID 1
    }
    else{
        id = findAvailID(); // finds the ID of the next created student.
    }
    clearInput();
    char* name = stringInput("Name"); // gets input from user and allocates size to store the user name
    struct Student* newStudent = createStudent(id,name); //pointer stored in newStudent variable (not used at the moment)
    free(name); // Free the memory allocated for the name input
    if(newStudent != NULL)
     {
         printf("New Student created.\n");
         printf("\n");
     }
     else{
        printf("Student creation failed");
        return;
     }

}

short findAvailID(){ //finds the next available ID (auto increment)
    short newID = (tailStudent->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

struct Student* createStudent(short id, char* name){ // creates new student and appends to linked list
    struct Student* newStudent = malloc(sizeof(struct Student));
   if(newStudent == NULL){
        printf("Memory Allocation Failed \n");
        exit(EXIT_FAILURE);
    }  
    
    newStudent->id = id;

    newStudent->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    strncpy(newStudent->name, name,strlen(name)); //and copies it into this memory

    newStudent->enrollments = NULL; //new students are not enrolled in anything

    newStudent->next = NULL; //this node becomes the tail
    if(headStudent == NULL)
    {
        headStudent = newStudent;
        tailStudent = newStudent;
    }
    else{
    tailStudent->next = newStudent;
    tailStudent = newStudent;
    }

    return newStudent;
}//use malloc here


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

    
    struct Student *temp = headStudent;
    

    while (temp != NULL) { //cycles through students until end of list or student found
        if((temp->id) == id){ //if student found
            printf("ID: %d \n", temp->id); 
            printf("Name: %s \n", temp->name); 
            if(temp->enrollments!=NULL)  
            {
                printf("Enrolled in: %s \nGrade: %c \n", temp->enrollments->subjectptr->name , temp->enrollments->grade);
                    if(temp->enrollments->subjectptr != NULL && temp->enrollments->subjectptr->subjectTeacher != NULL )
                    {
                        printf("Teacher: %s \n" , temp->enrollments->subjectptr->subjectTeacher->name);
                    }
            }
            else printf("Enrolled: Not yet enrolled in any subject \n");
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
        struct Student* temp = headStudent;

        while (temp != NULL) { 
            if (strcmp(temp->name, name) == 0) { // strcomp compares the input string to the name field of student struct
                printf("ID: %d \n", temp->id); 
                printf("Name: %s \n", temp->name); 
                if(temp->enrollments!=NULL)  
                {
                    printf("Enrolled in: %s \nGrade: %c \n", temp->enrollments->subjectptr->name , temp->enrollments->grade);
                        if(temp->enrollments->subjectptr != NULL && temp->enrollments->subjectptr->subjectTeacher != NULL )
                        {
                            printf("Teacher: %s \n" , temp->enrollments->subjectptr->subjectTeacher->name);
                        }
                }
                else printf("Enrolled: Not yet enrolled in any subject \n");
                return;
            }
            temp = temp->next;
        }

        printf("Student not found, please try a different name.\n");
        
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

void assignGrade(){
    printf("\n=================== Enroll a Student ===================\n");
    printf("Input Student ID to assign grade in a subject: \n");
    struct Student* st = retrieveStudentByID();
    if(st != NULL) // check if student was retrieved successfully
    {
        if(st->enrollments == NULL)
        {
            printf("Student not enrolled in any subject \n");
            return;
        }
        printf("Assign Grade for Subject %s \n" , st->enrollments->subjectptr->name);
        char c;
        clearInput();
        if(scanf("%c" , &c) == 1){
            st->enrollments->grade = c;
            printf("Assigned %c Grade for Subject %s \n" , st->enrollments->grade,st->enrollments->subjectptr->name);
        }
        else{
            clearInput();
            printf("Invalid Input");
        }

    }
    else
    {
        return; // return if student not retrieved
    }
}

int readStudentFromFile(){
    FILE* fptr = fopen("students.txt","r"); // open file in read mode
    if(fptr == NULL) // check if file was not opened
    {
        printf("Failed to open file \n");
        return EXIT_FAILURE;
    }
    short id;
    char name[256];

    // Read data from the file
    while (fscanf(fptr, "%hd,%255[^\n]%*c", &id, name) == 2) { 
         struct Student* newStudent = createStudent(id, name); // create new student based on data from file
         if (newStudent == NULL) {
             printf("Student Creation Failed");
             fclose(fptr); // close the file
             return EXIT_FAILURE;
         }
    }
    fclose(fptr); // close file
    return EXIT_SUCCESS;
}

void freeStudents() {
    struct Student* current = headStudent;
    struct Student* nextStudent = NULL;

    while (current != NULL) {
        nextStudent = current->next; // set next student
        
        // Free the allocated memory for the name
        if (current->name != NULL) {
            free(current->name); // free current name
        }

       
        // Free the student structure
        free(current);
        
        current = nextStudent;
    }

    // Reset the head and tail pointers
    headStudent = NULL;
    tailStudent = NULL;
}