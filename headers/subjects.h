
#ifndef __SUBJECT_H__
#define __SUBJECT_H__



struct Subject{
    short id;
    char* name;
    struct Teacher *subjectTeacher;
    struct  Enrollment *enrollments;
    struct Subject * next;
};

/// @brief Displays all subjects
void displayAllSubjects();

/// @brief Adds a new subject , gets input from user for name
void addSubject();

/// @brief sets the new added subject in the link list
/// @param id id of the subject
/// @param name name of the subject
/// @return returns the new added subject
struct Subject* createSubject(short id, char* name);

/// @brief finds the id for the new subject based on the id of last subject that was added
/// @return retunrs new id
short findSubjectrAvailID();

/// @brief Finds and displays Subject by ID
void displaySubjectByID();

/// @brief Finds ands displays subject by Name
void displaySubjectByName();


#endif