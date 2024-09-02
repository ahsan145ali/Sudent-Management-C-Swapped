#ifndef __STUDENTS_H__
#define __STUDENTS_H__


//strudent struct declaration
struct Student {
    short id;
    char* name;
    struct Enrollment* enrollments;
    struct Student* next;
};



// Function declarations

/// @brief displays all current students
void displayAllStudents();

/// @brief gets id and name input and invokes a function to create student based on entered data
void addStudent();

/// @brief get students by id 
/// @return student pointer 
struct Student* retrieveStudentByID();

/// @brief display a student by their name
void displayStudentByName();

/// @brief find the next available id
/// @return new id
short findAvailID();

/// @brief creates a new students and add them to link list head and tail accordingly
/// @param id id of the new student
/// @param name name of the new student
/// @return returns newly created student
struct Student* createStudent(short id, char* name);

/// @brief enrolls students in a subjects and sets the enrollment
void enrollStudentinSubject();

/// @brief assigns grade based on input
void assignGrade();

/// @brief free allocated memory
void freeStudents();

/// @brief read data from a file
/// @return returns 1 if failed and 0 if success
int readStudentFromFile();

#endif // __STUDENTS_H__

