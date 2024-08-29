#include <stdio.h>
#include "subjects.h"
#include <stdlib.h>
#include <string.h>

struct Subject firstSubject = {1, "Mathematics", NULL, NULL,NULL}; //Creates first student
struct Subject* head = &firstSubject; //sets first student address to be head of linked list.

