#include <stdio.h>
#include "DisplayMenus.h"
#include "students.h"
#include "teachers.h"
#include "subjects.h"

int main(void){
        
    while(1){ //menu loop (runs until the user quits)
    
    int mainMenuNavigate= displayMainMenu(); //only returns a valid choice

        if (mainMenuNavigate==1){ //User Selects Student Menu
            
            int studentMenuNavigate = displayStudentMenu();

            if(studentMenuNavigate==1){displayAllStudents();}
            else if(studentMenuNavigate==2) addStudent();
            else if(studentMenuNavigate==3) retrieveStudentByID();
            else if(studentMenuNavigate==4) displayStudentByName();
            else if(studentMenuNavigate==5) enrollStudentinSubject();
            else if(studentMenuNavigate==6) assignGrade();
        }
        else if (mainMenuNavigate==2){ // user selects subject menu

           int subjectMenuNavigate = displaySubjectMenu();
           if(subjectMenuNavigate==1) displayAllSubjects();
           else if(subjectMenuNavigate == 2) addSubject();
           else if(subjectMenuNavigate == 3) retrieveSubjectByID();
           else if(subjectMenuNavigate == 4) displaySubjectByName();
        }
        else if(mainMenuNavigate == 3){ // user selects teacher menu
           int teacherMenuNavigate = displayTeacherMenu();
           
           if(teacherMenuNavigate==1) displayAllTeachers();
           else if(teacherMenuNavigate == 2) addTeacher();
           else if(teacherMenuNavigate == 3) retrieveTeacherByID();
           else if(teacherMenuNavigate == 4) retrieveTeacherBySubject();
           else if(teacherMenuNavigate == 5) addTeacherSubject();
        }
        else if (mainMenuNavigate==6){
            printf("\n================= Closing School DB System =================\n");
            break;
            }

    }


    return 0;
}

