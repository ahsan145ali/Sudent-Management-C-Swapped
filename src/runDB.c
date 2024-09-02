#include <stdio.h>
#include <stdlib.h>
#include "DisplayMenus.h"
#include "students.h"
#include "teachers.h"
#include "subjects.h"
#include "enrollments.h"
int main(void){

    // attempt to read data from file when the program is initally executed
    if(readSubjectFromFile() == EXIT_FAILURE) printf("failed to read subjects from file \n");
    if(readTeacherFromFile() == EXIT_FAILURE) printf("failed to read teachers from file \n");
    if(readStudentFromFile() == EXIT_FAILURE) printf("failed to read students from file \n");
    while(1){ //menu loop (runs until the user quits)
    
    int mainMenuNavigate= displayMainMenu(); //only returns a valid choice

        if (mainMenuNavigate==1){ //User Selects Student Menu
            
            int studentMenuNavigate = displayStudentMenu(); // get selected option from user

            if(studentMenuNavigate==1){displayAllStudents();}
            else if(studentMenuNavigate==2) addStudent();
            else if(studentMenuNavigate==3) retrieveStudentByID();
            else if(studentMenuNavigate==4) displayStudentByName();
            else if(studentMenuNavigate==5) enrollStudentinSubject();
            else if(studentMenuNavigate==6) assignGrade();
        }
        else if (mainMenuNavigate==2){ // user selects subject menu

           int subjectMenuNavigate = displaySubjectMenu(); // get selected option from user
           if(subjectMenuNavigate==1) displayAllSubjects();
           else if(subjectMenuNavigate == 2) addSubject();
           else if(subjectMenuNavigate == 3) retrieveSubjectByID();
           else if(subjectMenuNavigate == 4) displaySubjectByName();
        }
        else if(mainMenuNavigate == 3){ // user selects teacher menu
           int teacherMenuNavigate = displayTeacherMenu(); // get selected option from user
           
           if(teacherMenuNavigate==1) displayAllTeachers();
           else if(teacherMenuNavigate == 2) addTeacher();
           else if(teacherMenuNavigate == 3) retrieveTeacherByID();
           else if(teacherMenuNavigate == 4) retrieveTeacherBySubject();
           else if(teacherMenuNavigate == 5) addTeacherSubject();
        }
        else if (mainMenuNavigate==4){ // exit the program
            printf("\n================= Closing School DB System =================\n");
            break;
            }

    }

    //Free allocated memory
    freeTeachers();
    freeSubjects();
    freeStudents();
    return 0;
}

