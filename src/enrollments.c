#include <stdlib.h>
#include <stdio.h>
#include "enrollments.h"
#include "students.h"
#include "subjects.h"
struct Enrollment* headEnroll = NULL;
struct Enrollment* headTail = NULL;

void enrollStudent(struct Student* st , struct Subject* sb)    {

    if(headEnroll == NULL){ // no student is enrolled yet
        struct Enrollment *ptr = malloc(sizeof(struct Enrollment)); // allocate memory
        if(ptr!=NULL){ // mem assigned
            ptr->studentptr = st; // assign student pointer
            ptr->subjectptr = sb; // assign subject pointer
            ptr->next = NULL;
            ptr->grade = '\0'; // set grade to null
            headEnroll =  ptr;
            headTail = ptr; // set tail
            sb->enrollments = ptr; // set enrollments pointer in subjects to current enrollment pointer
            st->enrollments = ptr; // set enrollments pointer in student to current enrollment pointer
            printf("Student %s enrolled in subject %s \n" , headEnroll->studentptr->name , headEnroll->subjectptr->name);
        }
        else{
            printf("Memory allocating failed \n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        struct Enrollment *ptr = malloc(sizeof(struct Enrollment));
        if(ptr!=NULL){ // mem assigned
            ptr->studentptr = st;// assign student pointer
            ptr->subjectptr = sb;// assign subject pointer
            ptr->next = NULL;
            ptr->grade = '\0';// set grade to null
            sb->enrollments = ptr; // set enrollments pointer in subjects to current enrollment pointer
            st->enrollments = ptr; // set enrollments pointer in students to current enrollment pointer
            headTail->next = ptr; // setting current tail to ptr
            headTail = ptr; // moving tail to new position
            printf("Student %s enrolled in subject %s \n" , headTail->studentptr->name , headTail->subjectptr->name);

        }
        else{
            printf("Memory allocating failed \n");
            exit(EXIT_FAILURE);
        }

    }
}
