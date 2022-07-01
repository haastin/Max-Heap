#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "util.h"
 
//pass pointers in so that the values assigned to the variables in the function aren't unupdated outside of the function
int nextCommand(int* i, int* v, int* f) { 
	
	char c; 
	
	while (1) { //infinite loop that depends on our cases to break
		
		scanf("%c", &c); //take in a character for command input
		
		//for each potential case of commands open up input for one variable at a time for each variable needed depending on the command chosen

		if (c == ' ' || c == '\t' || c == '\n') //any chars that provide some sort of spacing shouldn't be interpreted as commands 
		{ continue; } 
		
		if (c == 'S' || c == 'R' || c == 'W') 
		{ break; } //if a valid command is entered than leave the loop
		
		if (c == 'K' || c == 'k') 
		{ scanf("%d", i); scanf("%d", v); scanf("%d", f); break; }
		
		if (c == 'I')
		{
			scanf("%d", i); scanf("%d", v); break;
		}
		
		if (c == 'D')
		{
			scanf("%d", i);  break;
		}
		
		if (c == 'C')
		{
			scanf("%d", i); break;
		}
		
		else { //if no valid char or spacing input is enetered than do not exit the loop until a valid input is enetered
			printf("Invalid Command\n");
		}
	} 
	
	return c; //return the chosen command (the pointers passed in will also be potentially changed to reflecr which command was chosen)
}

struct ELEMENT* BuildArray(struct ELEMENT* A) {
	
	FILE* fp; //create a pointer to a file

	fp = fopen("HEAPinput.txt", "r");
	
	int input;
	
	char buffer[10];
	
	int index = 0;
	
	if (fp) {

		while (fgets(buffer, 10, fp)) {

			input = atoi(buffer); //converted char to int
			
			if (index == 0) { //if no elements yet stored in our array pointer
				A = (struct ELEMENT*) malloc(sizeof(struct ELEMENT) * (input + 1)); //allocate memory to the array
			}
			
			if (A) { //to avoid dereferencing null pointer

				A[index].key = input; //store each value per line in the text file in each element's key field in our element array
				index++;
			}

		}

		fclose(fp);
	}
	
	A = &A[0];
	
	return A;

}

