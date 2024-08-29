#ifndef __TEACHER_H__
#define __TEACHER_H__

struct Subject; //forward declaration

struct Teacher{
    short id;
    char* name;
    struct Subject *subject;
    struct Teacher* next;

};


void displayAllTeachers();
  
void addTeacher();

struct Teacher* createTeacher(short id, char* name);

short findTeacherAvailID(struct Teacher* head);

struct Teacher* findTeacherTail(struct Teacher* head);


#endif