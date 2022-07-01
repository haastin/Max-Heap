#ifndef UTIL_H
#define UTIL_H
#include "heap.h"

int nextCommand(int* i, int* v, int* f); 
/* returns the ASCII value of a char that is chosen by user input. For a specific command,
none, some, or all of the pointers passed to the function will be updated with values used
as inputs specific to each function. */

struct ELEMENT* BuildArray(struct ELEMENT* A);
/* returns a pointer to an array of elements with keys that match the information given
in the designated file HEAPinput.txt. */

#endif /* UTIL_H */