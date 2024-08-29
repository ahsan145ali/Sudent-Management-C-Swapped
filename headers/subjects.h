#ifndef __SUBJECT_H__
#define __SUBJECT_H__


struct Teacher; //forward declarations
struct Enrollment;

struct Subject{
    short id;
    char* name;
    Teacher* subjectTeacher;
    Enrollment* enrollments;
    Subject* next;
};






#endif