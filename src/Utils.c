#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

/// @brief gets input from user and performs validation
/// @param prompt specifies what is being asked from the user
/// @return returns a char* on success and NULL if failed
char *stringInput(char prompt[]){

    char temp[100]; // temporary char[] to get input
    printf("Input %s : " , prompt);
    
        if(fgets(temp,sizeof(temp) , stdin) != NULL){ // get input from user which does not exceed size of temp
            // removing the new line character
            if(strlen(temp) > 0 && temp[strlen(temp) - 1] == '\n'){ // check if input size is more then 0 and last character is a newline character
                temp[strlen(temp) - 1] = '\0'; // replace newline character with the Null character
            }
            // Allocate the memory for result
            char *result = malloc(strlen(temp) +1);
            if(result == NULL){
                printf("Memory allocation failed to result");
                exit(1);
            }
            strncpy(result,temp,strlen(temp)); // copy input from temp to result
            return result;
            
        }
        else{
            printf("Error reading input\n.");
            printf("Enter Again\n.");
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }

            return NULL;
         }
    

}

/// @brief clears the input untill a new line character is found
void clearInput(){
    while (getchar() != '\n');  // Read and discard characters until a newline is found
}