#include <stdio.h>
#include "DisplayMenus.h"
#include "students.h"
#include "teachers.h"

int main(void){
        
    while(1){ //menu loop (runs until the user quits)
    
    int mainMenuNavigate= displayMainMenu(); //only returns a valid choice

        if (mainMenuNavigate==1){ //User Selects Student Menu
            
            int studentMenuNavigate = displayStudentMenu();

            if(studentMenuNavigate==1){displayAllStudents();}
            if(studentMenuNavigate==2){addStudent();}
            if(studentMenuNavigate==3){displayStudentByID();}
            if(studentMenuNavigate==4){displayStudentByName();}
            if(studentMenuNavigate==5){continue;}
        }
        else if (mainMenuNavigate==2){ // user selects subject menu

           int subjectMenuNavigate = displaySubjectMenu();
        }
        else if(mainMenuNavigate == 3){ // user selects teacher menu
           int teacherMenuNavigate = displayTeacherMenu();
           
           if(teacherMenuNavigate==1) displayAllTeachers();
           else if(teacherMenuNavigate == 2) addTeacher();
        }
        else if (mainMenuNavigate==6){
            printf("\n================= Closing School DB System =================\n");
            break;
            }

    }


    return 0;
}

