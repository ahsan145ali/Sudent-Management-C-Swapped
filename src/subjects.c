#include <stdio.h>
#include "subjects.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

struct Subject* headSubject = NULL; // Maintains the head of the link list
struct Subject* tailSubject = NULL; // Maintains the tail of the link list



void displayAllSubjects(){
    printf("\n=================== Display All Subjects ===================\n");
    printf("\n");
    struct Subject *temp = headSubject;
    if(temp == NULL){
        printf("No Subject \n");
        return;
    }
    while (temp != NULL) { //iterates through linked list, printing out details of each node 
        printf("ID: %d \n", temp->id); 
        printf("Name: %s \n", temp->name); 
        printf("Teacher Address: %p \n", (void*)temp->subjectTeacher);
        printf("Enrollment Address: %p \n", (void*)temp->enrollments);
        printf("Next Address: %p \n", (void*)temp->next);
        temp = temp->next; 
        printf("\n");
    }
}

void addSubject(){
    printf("\n====================== Add Subject ======================\n");
    printf("\n");
    short id = 0;
    if(headSubject == NULL){
        struct Subject* ptr = malloc(sizeof(struct Subject));
        id = 1;
        clearInput();
        char* name = stringInput("subject"); // gets input from user and allocates size to store the user name
        printf("New Subject created.\n");
        printf("\n");
        ptr->id = id;
        ptr->name = malloc(strlen(name) * sizeof(char));
        strncpy(ptr->name , name , strlen(name));
        ptr->subjectTeacher = NULL;
        ptr->next = NULL;
        ptr->enrollments = NULL;
        headSubject = ptr;
        tailSubject = ptr;
    }
    else{
        id = findSubjectrAvailID(); // finds the ID of the next created student.
        clearInput();
        char* name = stringInput("subject"); // gets input from user and allocates size to store the user name
        printf("New subject created.\n");
        printf("\n");
        struct Subject* newSubject = createSubject(id,name); //pointer stored in newStudent variable (not used at the moment)
    }
}


struct Subject* createSubject(short id, char* name){
    struct Subject* newSubject = malloc(sizeof(struct Subject));
    tailSubject->next = newSubject;
    
    newSubject->id = id;

    newSubject->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    strcpy(newSubject->name, name); //and copies it into this memory

    newSubject->subjectTeacher = NULL;
    newSubject->enrollments = NULL; //new subject do es not habe any enrollment in anything
    newSubject->next = NULL; // next is null to signify end of the list

    tailSubject = newSubject; // set tail to new added node as it is the last
    return newSubject;
}

short findSubjectrAvailID(){
    short newID = (tailSubject->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

void displaySubjectByID(){
    printf("\n==================== Find Subject By ID ====================\n");
    short id;
    int result;
    printf("\nEnter Subject ID:");
    result = scanf("%hd",&id); 
    printf("\n");

    if (result != 1) { //sanitises input - calls itself recursively until valid input (only accepts integers)
        while (getchar() != '\n');  // Read and discard characters until a newline is found
        printf("Invalid selection, please input a valid ID number.\n");
        return displaySubjectByID();
    }

    struct Subject *temp = headSubject;

     while (temp != NULL) { //cycles through subjects until end of list or subject found
        if((temp->id) == id){ //if teacher found
            printf("ID: %d \n", temp->id); //print details
            printf("Name: %s \n", temp->name); 
            printf("Teacher Address: %p \n", (void*)temp->subjectTeacher);
            printf("Enrollment Address: %p \n", (void*)temp->enrollments);
            printf("Next Address: %p \n", (void*)temp->next);
            return;
        }
        temp = temp->next; 
    }
    printf("Subject with ID: %hd not found \n" , id);
}

void displaySubjectByName(){
    printf("\n=================== Find Subject By Name ===================\n");

        clearInput();
        char *name = stringInput("Subject Name: ");
        if(name == NULL) return displaySubjectByName();

        // Once valid string has been input, search linked list
        struct Subject* temp = headSubject;
       

        while (temp != NULL) { 
            if (strcmp(temp->name, name) == 0) { // strcomp compares the input string to the name field of student struct
                printf("ID: %d \n", temp->id);
                printf("Name: %s \n", temp->name);
                printf("Enrollment Address: %p \n", (void*)temp->enrollments);
                printf("Next Address: %p \n\n", (void*)temp->next);
                return;
            }
            temp = temp->next;
        }
        printf("Subject with name %s not found \n" , name);
    
    
}