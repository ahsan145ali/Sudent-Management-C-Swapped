#include <stdio.h>
#include "teachers.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "subjects.h"
#include "enrollments.h"
#include "students.h"

struct Teacher* headTeacher = NULL; // Maintains the head of the link list
struct Teacher* tailTeacher = NULL; // Maintains the tail of the link list

void displayAllTeachers(){
    printf("\n=================== Display All Teachers ===================\n");
    printf("\n");
    struct Teacher *temp = headTeacher;
    if(temp == NULL){ // checks if list is empty
        printf("No Teacher \n");
        return;
    }
    while (temp != NULL) { //iterates through linked list, printing out details of each node 
        printf("ID: %d \n", temp->id); 
        printf("Name: %s \n", temp->name); 
        if(temp->subject != NULL)  // check if teacher has assigned subject
        {
            printf("Subject : %s \n",temp->subject->name);
            // If there are enrollments, display the student's name
            if(temp->subject->enrollments != NULL && temp->subject->enrollments->studentptr != NULL)
            {
                printf("Teaching to : %s \n",temp->subject->enrollments->studentptr->name);
            }
        }
        else printf("Subject: NOT ASSIGNED \n");
        temp = temp->next; 
        printf("\n");
    }
}
  
void addTeacher(){ //Retrieves user input on new student and calls createStudent()
    printf("\n====================== Create Teacher ======================\n");
    printf("\n");
    short id = 0;
    if(headTeacher == NULL){
        id = 1; // If this is the first teacher, assign ID 1
    }
    else{
        id = findTeacherAvailID(); // finds the ID of the next created student.
    }
    clearInput();
    char* name = stringInput("Name"); // gets input from user and allocates size to store the user name
    struct Teacher* newTeacher = createTeacher(id,name); //create a new teacher based on the input provided

    free(name); // Free the memory allocated for the name input
    if(newTeacher != NULL)
     {
         printf("New Teacher created.\n");
         printf("\n");
     }
     else{
        printf("Teacher creation failed");
        return;
     }

}

struct Teacher* createTeacher(short id, char* name){ // creates new student and appends to linked list
    struct Teacher* newTeacher = malloc(sizeof(struct Teacher));
    if(newTeacher == NULL){
        printf("Memory Allocation Failed \n");
        exit(EXIT_FAILURE);
    }  
    newTeacher->id = id;

    newTeacher->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    if(newTeacher->name == NULL)
    {
        printf("Memory allocation to name failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newTeacher->name, name,strlen(name)); //and copies it into this memory

    newTeacher->subject = NULL; //new teacher does not have any subject yet
    newTeacher->next = NULL; //next is null to signify end of the list

    if(headTeacher == NULL)
    {
        headTeacher = newTeacher;
        tailTeacher = newTeacher;
    }
    else{
    tailTeacher->next = newTeacher;
    tailTeacher = newTeacher; // set tail to new added node as it is the last
    }
    return newTeacher;
}//use malloc here

short findTeacherAvailID(){ //finds the next available ID (auto increment)
    short newID = (tailTeacher->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

struct Teacher* retrieveTeacherByID(){
    printf("\n==================== Find Teacher By ID ====================\n");
    short id;
    int result;

    while (1) {
        printf("\nEnter Teacher ID:");
        result = scanf("%hd", &id); // get id from user input
        printf("\n");

        if (result == 1) { 
            break; // break loop if valid input was entered
        } else {
            clearInput();
            printf("Invalid selection, please input a valid ID number.\n");
        }
    }
   
    struct Teacher *temp = headTeacher;

     while (temp != NULL) { //cycles through teachers until end of list or teacher found
        if((temp->id) == id){ //if teacher found
            printf("ID: %d \n", temp->id); 
            printf("Name: %s \n", temp->name); 
           if(temp->subject != NULL)  // check if teacher has subject
            {
                printf("Subject : %s \n",temp->subject->name);
                    if(temp->subject->enrollments != NULL && temp->subject->enrollments->studentptr != NULL)
                    {
                        printf("Teaching to : %s \n",temp->subject->enrollments->studentptr->name);
                    }
            }
            else printf("Subject: NOT ASSIGNED \n");
            return temp;
        }
        temp = temp->next; 
    }
    printf("Teacher with ID: %hd not found \n" , id);
    return NULL;
}

struct Teacher* retrieveTeacherBySubject()
{
     printf("\n==================== Find Teacher By Subject ====================\n");
     clearInput();
     char *subject  = stringInput("subject name"); // get subject name from user input
     struct Teacher *temp = headTeacher;
     while(temp != NULL){
        if(temp->subject != NULL)
        {
            if(strncmp(temp->subject->name , subject, strlen(subject)) == 0){ // matched subjects
                printf("ID: %d \n", temp->id); 
                printf("Name: %s \n", temp->name); 
                if(temp->subject != NULL) 
                {
                    printf("Subject : %s \n",temp->subject->name);
                        if(temp->subject->enrollments != NULL && temp->subject->enrollments->studentptr != NULL)
                        {
                            printf("Teaching to : %s \n",temp->subject->enrollments->studentptr->name);
                        }
                }
                else printf("Subject: NOT ASSIGNED \n");
                return temp;
            }
        }
        temp = temp->next;
     }
     printf("No Teacher with subject %s \n" , subject);
     return NULL;

}

void addTeacherSubject(){
    printf("Input Teacher ID to set subject for that teacher: \n");
    struct Teacher* te = retrieveTeacherByID(); // gets teacher by id
    if(te != NULL) // check if teacher was retrieved successfully
    {
         printf("Input Subject ID to set it for the teacher %s: \n" , te->name);
         struct Subject *sb = retrieveSubjectByID(); // get subject by ID
         if(sb != NULL){ // checks if subject was retrived successfully
            te->subject = sb; // sets retrieved teachers subject to retrieved subject
            if(te->subject !=NULL){ // checks if subject was assigned successfully
                printf("Subject for teacher %s set to %s \n" , te->name , sb->name);
                sb->subjectTeacher = te; // set retrieved subject teacher to retrieved teacher
            }
            else{
                printf("Could not set the subject \n");
                return; // return if subject is not assigned to teacher
            }
         }
         else{
            return; // return if subject is not retrieved
         }
    }   
    else{
        return; // return if teacher is not retrieved
    }
    
}

int readTeacherFromFile(){
    FILE* fptr = fopen("teachers.txt","r"); // open file in read mode
    if(fptr == NULL) // check if file was not opened
    {
        printf("Failed to open file \n");
        return EXIT_FAILURE;
    }
    short id;
    char name[256];

    // Read data from the file
    while (fscanf(fptr, "%hd,%255[^\n]%*c", &id, name) == 2) { 
         struct Teacher* newTeacher = createTeacher(id, name); // create new teacher based on data from file
         if (newTeacher == NULL) {
             printf("Teacher Creation Failed");
             fclose(fptr); // close the file
             return EXIT_FAILURE;
         }
    }
    fclose(fptr); // close file
    return EXIT_SUCCESS;
}

void freeTeachers() {
    struct Teacher* current = headTeacher;
    struct Teacher* nextTeacher = NULL;

    while (current != NULL) {
        nextTeacher = current->next; // set next teacher
        
        // Free the allocated memory for the name
        if (current->name != NULL) {
            free(current->name); // free current name
        }

        // Free the Teacher structure
        free(current);
        
        current = nextTeacher;
    }

    // Reset the head and tail pointers
    headTeacher = NULL;
    tailTeacher = NULL;
}