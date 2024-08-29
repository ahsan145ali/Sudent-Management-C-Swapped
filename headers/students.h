#ifndef __STUDENTS_H__
#define __STUDENTS_H__

struct Enrollment; //forward declaration to allow it to be contained in Student struct

//strudent struct declaration
struct Student {
    short id;
    char* name;
    struct Enrollment* enrollments;
    struct Student* next;
};


//extern struct Student firstStudent;
//extern struct Student* head;

// Function declarations
void displayAllStudents();
void addStudent();
void displayStudentByID();
void displayStudentByName();
short findAvailID(struct Student* head);
struct Student* createStudent(short id, char* name);
struct Student* findTail(struct Student* head);


#endif // __STUDENTS_H__

