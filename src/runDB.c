#include <stdio.h>
#include "DisplayMenus.h"
#include "students.h"

int main(void){
    
int loop = 1; 
    
    while(loop == 1){ //menu loop (runs until the user quits)
    
    int mainMenuNavigate= displayMainMenu(); //only returns a valid choice

        if (mainMenuNavigate==1){ //User Selects Student Menu
            
            int studentMenuNavigate = displayStudentMenu();

            if(studentMenuNavigate==1){displayAllStudents();}
            if(studentMenuNavigate==2){addStudent();}
            if(studentMenuNavigate==3){displayStudentByID();}
            if(studentMenuNavigate==4){displayStudentByName();}
            if(studentMenuNavigate==5){continue;}
        }

        if (mainMenuNavigate==2){

           // int subjectMenuNavigate
        }

        if (mainMenuNavigate==6){
            printf("\n================= Closing School DB System =================\n");
            break;
            }

    }


    return 0;
}

