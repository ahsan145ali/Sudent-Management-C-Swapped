# C-School-Project
Training project - creating a database style system in C.

Instructions / Requirements:

Functional Requirements:

FR1: The program should use a command line interface (CLI) to add new information **MUST HAVE**
FR2: The CLI can be used to add students and the subjects they study **MUST HAVE**
FR3: The CLI can be used to add teachers and the subject they teach (1 subject per teacher) **MUST HAVE**
FR4: The CLI can be used to assign grades to students per subject **MUST HAVE**
FR5: The CLI can be used to find which students study a specified subject **MUST HAVE**
FR6: The CLI can be used to find which teacher teaches a specified subject **MUST HAVE**
FR7: The CLI can be used to find the grades a specified student has achieved in a specified subject **MUST HAVE**

FR8: The CLI can be used to find which teachers teach a specified student [Could_Have]
FR9: The CLI can be used to find which students are taught by a specified teacher [Could_Have]
FR10: Student/teacher data should be loaded from files when the program starts up [Could_Have]

Non-Functional Requirements:

NFR1: The program must be written in C and must compile with gcc 


Contents:

1. File Structure
2. What will each file do, how will it achieve this, what requirements will it fulfil (Proof that ).
3. Compilation Instructions
4. System Use Instructions


1. File Structure

/C-School-Project 
    README.md
    MAKEFILE
    /src/
        runDB.c
        student.c
        teacher.c
        subject.c
        enrollment.c
        load_data.c
    /headers/ 
        runDB.h
        student.h
        teacher.h
        subject.h 
        grade.h
        load_data.h 
    /data/
        students.txt
        teachers.txt
        grades.txt


2. What will each file do, how will it achieve this. 

Data will be organised similar to a linked list. 

Each student will point to an array, which contains pointers to subject structs.


README.md - contains plan and instructions on use of the softwares features
MAKEFILE - Will compile all parts of the program with different flags to allow user to load appropriate data.

[/src/]

main.c - **FR1**

Includes the main menu loop - running this will allow the user to use the CLI
Calls functions from other modules based on user input.


student.c - Implements functions to manage students **FR2** stored in a linked list.

Functions to 
add - adds a student onto the end of the list.
delete - removes a student from end of list and updates 
retrieve - cycle through links until it reaches matching id, output id to the screen.
Function to ensure ID is unique.

Struct Student { 
    short id;
    char* name;
    Enrollment enrollments*; points to an array of enrollment pointers
    student* next;
}




teacher.c - Implements functions to manage teachers **FR3**

Functions to add, delete, and retrieve teachers.
Handles assigning subjects to teachers.
Manages the relationship between teachers and subjects.
Function to ensure ID is unique - cycles linked list and checks to see if there is any matching IDs

struct Teacher {
    short id;
    char* name
    Subject* subjects
    Teacher* next;
};

subjects.c - implements functions to manage subjects **FR5 & FR6**

Functions to add, delete, and retrieve subjects.
Manages the link between subjects, students, and teachers.
Handles the enrollment of students in subjects.
Function to ensure that the subject is

struct Subject {
    short id;
    char* name;
    Teacher *teacher;       
    Enrollment *enrollments;     
    Subject *next;     

};

each subject is associated with exactly one teacher


Subject struct maintains a linked list of Enrollment structs - this will allow for FR5, finding the students which study a specific subject. 
It will also allow for FR6 - finding which teacher teaches a specific subject. 



Enrollments.c - implements functions to add and receive student enrollment in classes and store grades **FR4 & FR7**

Each Student struct contains a list of pointer to a linked list of Enrollment structs - this shows what subject the student is enrolled in.


struct Enrollment{
    Student *student;   // Pointer to the Student who received the grade
    Subject *subject;   // Pointer to the Subject the grade is for
    char grade[3]; 
    Enrollment* next;     
};

functions -

noDoubleEnrollment - When new enrollment is created, checks to ensure that the student subject pairing doesnt already exist.


load_data.c - implements functionality allowing user to load database with predetermined set of values for testing purposes

linked_list.c - contains various linked list operations e.g. add, retrieve by field, delete. 
linked list will create a node that has a next pointer and a value.

linked_list.c - contains basic linked list operations.
this file will allow append, insert, delete operaitons from the linked list.

struct node_t {
    
    Struct* entity
    struct node_t* next
}
[headers]

All files in this section will be header files.


[data]

All files in this section will contain data which will be used by load_data.c to fill the database up.

All data structures are linked list.
Data structures have relationships with eachother facilitated by pointers.


3. Complete later
4. complete later


