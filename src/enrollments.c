#include <stdlib.h>
#include <stdio.h>
#include "enrollments.h"
#include "students.h"
#include "subjects.h"
struct Enrollment* headEnroll = NULL;
struct Enrollment* headTail = NULL;

void enrollStudent(struct Student* st , struct Subject* sb)    {

    if(headEnroll == NULL){ // no student is enrolled yet
        struct Enrollment *ptr = malloc(sizeof(struct Enrollment));
        if(ptr!=NULL){ // mem assigned
            ptr->studentptr = st;
            ptr->subjectptr = sb;
            ptr->next = NULL;
            ptr->grade = '\0';
            headEnroll =  ptr;
            headTail = ptr;
            sb->enrollments = ptr;
            st->enrollments = ptr;
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
            ptr->studentptr = st;
            ptr->subjectptr = sb;
            ptr->next = NULL;
            ptr->grade = '\0';
            sb->enrollments = ptr;
            st->enrollments = ptr;
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
