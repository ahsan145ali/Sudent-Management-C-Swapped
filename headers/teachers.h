#ifndef __TEACHER_H__
#define __TEACHER_H__


struct Teacher{
    short id;
    char* name;
    struct Subject *subject;
    struct Teacher* next;

};


/// @brief Displays all teachers
void displayAllTeachers();

/// @brief Adds a new teacher , gets input from user for name
void addTeacher();

/// @brief sets the new added teacher in the link list
/// @param id id of the teacher
/// @param name name of the teacher
/// @return returns the new added teacher
struct Teacher* createTeacher(short id, char* name);

/// @brief finds the id for the new teacher based on the id of last teacher that was added
/// @return retunrs new id
short findTeacherAvailID();

/// @brief Finds and displays teacher by ID
/// @return returns the found teacher else returns NULL
struct Teacher* retrieveTeacherByID();

void displayTeacherBySubject();

void addTeacherSubject();

#endif