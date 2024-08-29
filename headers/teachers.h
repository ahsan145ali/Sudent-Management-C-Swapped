#ifndef __TEACHER_H__
#define __TEACHER_H__

struct Subject; //forward declaration

struct Teacher{
    short id;
    char* name;
    Subject *subject;
    Teacher* next;

};






#endif