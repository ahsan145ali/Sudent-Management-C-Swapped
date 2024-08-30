#ifndef __ENROLLMENTS_H__
#define __ENROLLMENTS_H__


struct Enrollment{
    struct Student *studentptr;
    struct Subject *subjectptr;
    char grade;
    struct Enrollment* next;

};


void enrollStudent(struct Student* st , struct Subject* sb);



#endif