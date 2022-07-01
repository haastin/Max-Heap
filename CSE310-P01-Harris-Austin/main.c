#include "heap.h"
#include "util.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	char c; //used to chose which command a user wants to execute
	int i, v, f; //our potential inputs for the command

	struct HEAP* heap = NULL; //pointer to our heap once it is created

	while (1) { //infinite loop to ensure any amount of commands can be entered until a user wants to stop

		char c = nextCommand(&i, &v, &f); //used to chose which command and what inputs for that command a user wants
		
		switch (c) {
			case 'S': printf("COMMAND: %c\n", c); //stop the program
					exit(0);
			
			case 'D': printf("COMMAND: %c %d\n", c, i);  //delete the maximum element from the heap
					if (heap != NULL) {  
					DeleteMax(heap, i);
					}
					else
					printf("Error: heap not initialized\n");
					break;
			
			case 'I': printf("COMMAND: %c %d %d\n", c, i, v); //insert an element into the heap
					if (heap != NULL) { 
					Insert(heap, i, v);
					}
					else
					printf("Error: heap not initialized\n");
					break;
			
			case 'C': printf("COMMAND: %c %d\n", c, i); //create an empty heap
					if(heap!= NULL){
						free(heap);
						heap = Initialize(i);
					}
					else{
					heap = Initialize(i);
					}
					break;
			
			case 'R': printf("COMMAND: %c\n", c); //build a maxheap given data in a text file
					if (heap != NULL) { 
						
						struct ELEMENT* A = NULL;
						A = BuildArray(A); //build an array from the text file
							
							if (A != NULL) { //if array is built correctly
								int total = A->key;
								BuildHeap(heap, A, total);
							}
							else { //if arr don't do anything for command R
								printf("Array had error being built");
							}
					}
					else
					printf("Error: heap not initialized\n");
					break;
			
			case 'W': printf("COMMAND: %c\n", c); //print out data about the heap
					if(heap != NULL){
					printHeap(heap);
					} 
					else
					printf("Error: heap not initialized\n");
					break;
			
			case 'K': printf("COMMAND: %c %d %d %d\n", c, i, v, f); //increase the key of a user-chosen index in the heap
					if (heap != NULL){
					IncreaseKey(heap, i, v, f);
					}
					else
					printf("Error: heap not initialized\n");
					break;
			
			default:
					break;
		}
	}
	exit(0);
}