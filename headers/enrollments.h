#ifndef __ENROLLMENTS_H__
#define __ENROLLMENTS_H__


struct Enrollment{
    struct Student *studentptr;
    struct Subject *subjectptr;
    char grade;
    struct Enrollment* next;

};

/// @brief Enrolls a student and sets the pointers for student and subject structure
/// @param st student pointer to student structure which is to be enrolled
/// @param sb subject pointer to subject structure in which the enrollment is being done
void enrollStudent(struct Student* st , struct Subject* sb);




#endif