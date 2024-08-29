#ifndef __UTILS_H__
#define __UTILS_H__

/// @brief gets input from user and performs validation
/// @param prompt specifies what is being asked from the user
/// @return returns a char* on success and NULL if failed
char *stringInput(char prompt[]);

/// @brief clears the input untill a new line character is found
void clearInput();

#endif // __UTILS_H__