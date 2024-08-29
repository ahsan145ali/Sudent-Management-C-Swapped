
#ifndef __SUBJECT_H__
#define __SUBJECT_H__


struct Teacher; //forward declarations
struct Enrollment;

struct Subject{
    short id;
    char* name;
    struct Teacher *subjectTeacher;
    struct  Enrollment *enrollments;
    struct Subject * next;
};






#endif