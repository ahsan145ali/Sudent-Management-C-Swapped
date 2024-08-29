#include <stdio.h>
#include "teachers.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

struct Teacher firstTeacher = {1, "John Doe", NULL, NULL}; //Creates first student
struct Teacher* headTeacher = &firstTeacher; //sets first student address to be head of linked list.

void displayAllTeachers(){
    printf("\n=================== Display All Teachers ===================\n");
    printf("\n");
    struct Teacher *temp = headTeacher;
    while (temp != NULL) { //iterates through linked list, printing out details of each node (student)
        printf("ID: %d \n", temp->id); 
        printf("Name: %s \n", temp->name); 
        printf("Subjects Address: %p \n", (void*)temp->subject);
        printf("Next Address: %p \n", (void*)temp->next);
        temp = temp->next; 
        printf("\n");
    }
}
  
void addTeacher(){ //Retrieves user input on new student and calls createStudent()
    printf("\n====================== Create Student ======================\n");
    printf("\n");
    short id = findTeacherAvailID(headTeacher); // finds the ID of the next created student.
    clearInput();
    char* name = stringInput("Name"); // gets input from user and allocates size to store the user name
    printf("New Teacher created.\n");
    printf("\n");
    struct Teacher* newTeacher = createTeacher(id,name); //pointer stored in newStudent variable (not used at the moment)
}

struct Teacher* createTeacher(short id, char* name){ // creates new student and appends to linked list
    struct Teacher* tail = findTeacherTail(headTeacher); //stores tail so that previous tail'next' address can be added
    struct Teacher* newTeacher = malloc(sizeof(struct Teacher));
    tail->next = newTeacher;
    
    newTeacher->id = id;

    newTeacher->name = malloc(strlen(name) + 1); //this ensures that persistent memory is assigned to the name
    strcpy(newTeacher->name, name); //and copies it into this memory

    newTeacher->subject = NULL; //new students are not enrolled in anything

    newTeacher->next = NULL; //this node becomes the tail

    return newTeacher;
}//use malloc here

short findTeacherAvailID(struct Teacher* head){ //finds the next available ID (auto increment)
    struct Teacher* tail = findTeacherTail(head); //calls get tail to find previous tail of linked list
    short newID = (tail->id)+1; //adds one to tail ID to find newID
    return newID; //returns the newID
}

struct Teacher* findTeacherTail(struct Teacher* head){ //finds linked list tail
    struct Teacher *temp = head;
    while ((temp->next) != NULL){ // searches for linked list node with next = NULl and deduces this is the tail
        temp = temp -> next;
    }
    return temp; //returns the tail
}