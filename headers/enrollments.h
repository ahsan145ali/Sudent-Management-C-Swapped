#ifndef __ENROLLMENTS_H__
#define __ENROLLMENTS_H__

struct Student;
struct Subject;

struct Enrollment{
    Student *studentptr;
    Subject *subjectptr;
    char grade[3];
    Enrollment* next;

};






#endif