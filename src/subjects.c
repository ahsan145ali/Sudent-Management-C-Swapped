#include <stdio.h>
#include "subjects.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "teachers.h"
#include "enrollments.h"
#include "students.h"

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
        if(temp->subjectTeacher != NULL)  printf("Teacher: %s \n", temp->subjectTeacher->name);
        else printf("Teacher: NOT ASSIGNED \n");
        if(temp->enrollments != NULL)  printf("Enrolled Student: %s \n", temp->enrollments->studentptr->name);
        else printf("Enrolled: No student enrolled yet \n");
        temp = temp->next; 
        printf("\n");
    }
}

void addSubject(){
    printf("\n====================== Add Subject ======================\n");
    printf("\n");
    short id = 0;
    if(headSubject == NULL){
        id = 1;
    }
    else
    {
        id = findSubjectrAvailID(); // finds the ID of the next created student.
    }
     clearInput();
     char* name = stringInput("subject"); // gets input from user and allocates size to store the user name
     struct Subject* newSubject = createSubject(id,name); //pointer stored in newStudent variable
     if(newSubject != NULL)
     {
         printf("New subject created.\n");
         printf("\n");
     }
     else{
        printf("Subject creation failed");
        return;
     }

}


struct Subject* createSubject(short id, char* name){
    struct Subject* newSubject = malloc(sizeof(struct Subject));
    if(newSubject == NULL){
        printf("Memory Allocation Failed \n");
        exit(EXIT_FAILURE);
    }    
    newSubject->id = id;

    newSubject->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    if(newSubject->name == NULL)
    {
        printf("Memory allocation to name failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newSubject->name, name, strlen(name)); //and copies it into this memory

    newSubject->subjectTeacher = NULL;
    newSubject->enrollments = NULL; //new subject do es not habe any enrollment in anything
    newSubject->next = NULL; // next is null to signify end of the list

    if(headSubject == NULL)
    {
        headSubject = newSubject;
        tailSubject = newSubject;
    }
    else{
    tailSubject->next = newSubject;
    tailSubject = newSubject; // set tail to new added node as it is the last
    }
    return newSubject;
}

short findSubjectrAvailID(){
    short newID = (tailSubject->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

struct Subject* retrieveSubjectByID(){
    printf("\n==================== Find Subject By ID ====================\n");
    short id;
    int result;
    printf("\nEnter Subject ID:");
    result = scanf("%hd",&id); 
    printf("\n");

    if (result != 1) { //sanitises input - calls itself recursively until valid input (only accepts integers)
        while (getchar() != '\n');  // Read and discard characters until a newline is found
        printf("Invalid selection, please input a valid ID number.\n");
        return retrieveSubjectByID();
    }

    struct Subject *temp = headSubject;

     while (temp != NULL) { //cycles through subjects until end of list or subject found
        if((temp->id) == id){ //if teacher found
            printf("ID: %d \n", temp->id); 
            printf("Name: %s \n", temp->name); 
            if(temp->subjectTeacher != NULL)  printf("Teacher: %s \n", temp->subjectTeacher->name);
            else printf("Teacher: NOT ASSIGNED \n");
            if(temp->enrollments != NULL)  printf("Enrolled Student: %s \n", temp->enrollments->studentptr->name);
            else printf("Enrolled: No student enrolled yet \n");
            printf("\n");
            return temp;
        }
        temp = temp->next; 
    }
    printf("Subject with ID: %hd not found \n" , id);
    return NULL;
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
                if(temp->subjectTeacher != NULL)  printf("Teacher: %s \n", temp->subjectTeacher->name);
                else printf("Teacher: NOT ASSIGNED \n");
                if(temp->enrollments != NULL)  printf("Enrolled Student: %s \n", temp->enrollments->studentptr->name);
                else printf("Enrolled: No student enrolled yet \n");
                printf("\n");
                return;
            }
            temp = temp->next;
        }
        printf("Subject with name %s not found \n" , name);
    
    
}

int readSubjectFromFile(){
    FILE* fptr = fopen("subjects.txt","r"); // open file in read mode
    if(fptr == NULL) // check if file was not opened
    {
        printf("Failed to open file \n");
        return EXIT_FAILURE;
    }
    short id;
    char name[256];

    // Read data from the file
    while (fscanf(fptr, "%hd,%255[^\n]%*c", &id, name) == 2) {
         struct Subject* newSubject = createSubject(id, name);// create new subject based on data from file
         if (newSubject == NULL) {
             printf("Subject Creation Failed");
             fclose(fptr);
             return EXIT_FAILURE;
         }
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}

void freeSubjects() {
    struct Subject* current = headSubject;
    struct Subject* nextSubject = NULL;

    while (current != NULL) {
        nextSubject = current->next; // set next Subject
        
        // Free the allocated memory for the name
        if (current->name != NULL) {
            free(current->name); // free current name
        }

    

        // Free the Subject structure
        free(current);
        
        current = nextSubject;
    }

    // Reset the head and tail pointers
    headSubject = NULL;
    tailSubject = NULL;
}