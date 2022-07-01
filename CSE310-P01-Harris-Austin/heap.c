#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include "heap.h"

struct HEAP* Initialize(int n) {
	
	struct HEAP* heap = NULL;
  
	
	if (n >= 0) { //can't have a negative amount of elements

		heap = (struct HEAP*) malloc(sizeof(struct HEAP)); //dynamically allocate memory for the heap to account for a dynamic memory size for the array of elements

		if (heap) {
			heap->capacity = n; //the amount of elements the heap's element array can hold is n
			heap->size = 0; //no elements in the heap's element array yet
			//the heap's element array is dynamically allocated because it is specified to hold an indefinite amount of elements
			heap->H = (struct ELEMENT*) malloc(sizeof(struct ELEMENT) * (heap->capacity + 1)); //+1 because H[0] is empty for algorithmic efficiency
		}
	}
		
	else {
			printf("Error: invalid heap capacity\n");
		}


	return heap;
}

void BuildHeap(struct HEAP* heap, struct ELEMENT* A, int n) {
	
    if (n > heap->capacity){ //array being transferred to our heap must be <= our heap's allocated size
        printf("Error: array size exceeds heap capacity\n");
    }
    
    else{
	
        heap->size = n; //n = the array input's length

	    //loop starts at index 1 because the heap array doesn't utilize index 0 for efficiency purposes 
	    //and A index's 0 is reserved for the total number of elements in A, the elements start at index 1
	    for (int i = 1; i <= heap->size; i++) { 
		    heap->H[i].key = A[i].key; 

	    }
    
	    //starts from the lowest levels of the tree (n/2) up because the algorithm depends on the subtree
	    //being a correctly implemented maxheap 
	    for (int j = heap->size / 2; j > 0; j--) {
		
		    //recursively implemented max heapify 
		    while (j <= heap->size) {
			
			    int left = 2 * j;
			    int right = (2 * j + 1);
			    int largest;
		
			    if ((left <= heap->size) && (heap->H[left].key > heap->H[j].key))
			    	largest = left;
			    else
				    largest = j;

			    if ((right <= heap->size) && (heap->H[right].key > heap->H[largest].key))
				    largest = right;
			
			    if (largest != j) {
				
				    int temp = heap->H[j].key;
				    heap->H[j].key = heap->H[largest].key;
				    heap->H[largest].key = temp;

				    j = largest;

			    }
			    else if (largest == j) {
				
				    break;
			    }
		    }

	    }
    }
	
}

void Insert(struct HEAP* heap, int flag, int k) { 

	if (flag != 1){ //flag must be a value of 1 or 2
        
        if(flag != 2){
        printf("Error: invalid flag value\n");
        return;
        }
    }
    
    if (flag == 2) {

        printf("Before insert operation:\n");
        printf("Capacity = %d\n", heap->capacity);
        printf("Size = %d\n", heap->size);
        
		for (int p = 1; p <= heap->size; p++) {
            printf("%d\n", heap->H[p].key);
		}
    }
		
		heap->size++; //a new element is being added to the heap's array of elements so the size needs to be updated

        if (heap->size > heap->capacity) { //if our current heap's memory is already full
			int size;
            //dynamically reallocate H's memory to successive powers of 2 using size to find the next largest power of 2 from capacity's current value
			
			if(heap->capacity == 0){
				size = 1;
			}
			else
			 	size = (int)pow(2, floor( ((log10(heap->capacity)/log10(2))+1)) ); //new maximum capacity

            heap->H = (struct ELEMENT*) realloc(heap->H, sizeof(struct ELEMENT) * size); 
           
			heap->capacity = size; //update capacity to reflect increased memory
		}
		
		int i = heap->size; 

		int parent = i / 2;

		if (heap->H) {

			heap->H[i].key = k; //updating new space in the heap to the desired key

			//the while loop preserves the already built max heap, ie when insertion occurs it is assumed 
			//that we are inserting into a correct maxheap; because of this all we have to do is make
			//comparisons to parent node's until our new element is either the root or has a parent
			//node that has a larger key than it does
			
			if (i <= heap->capacity) {
				
				while ((i > 1) && (heap->H[parent].key < heap->H[i].key)) {
					
					int temp = heap->H[i].key;
					heap->H[i].key = heap->H[parent].key;
					heap->H[parent].key = temp;

					i = parent;
					parent = i / 2;
				}
			}
		}
	   
        if (flag == 2){
            printf("After insert operation:\n");
            printf("Capacity = %d\n", heap->capacity);
            printf("Size = %d\n", heap->size);

			if (heap->H) {
				for (int p = 1; p <= heap->size; p++) {
					printf("%d\n", heap->H[p].key);
				}
			}
        }

}


int DeleteMax(struct HEAP* heap, int flag) {
    
    if(heap->size == 0){
        printf("Error: heap empty\n");
        return -1;
    }

    if (flag != 1){
        
        if(flag != 2){
        printf("Error: invalid flag value\n");
        return -1;
        }
    }
    
    if (flag == 2) {

		printf("Before delete max operation:\n");
        printf("Capacity = %d\n", heap->capacity);
        printf("Size = %d\n", heap->size);

		for (int p = 1; p <= heap->size; p++) {
			printf("%d\n", heap->H[p].key);
		}
    }

		int temp = heap->H[1].key; //store the current maximum key

		heap->H[1] = heap->H[heap->size]; //replace the current max with the current last element in the array (to simplify re-implementing a correct maxheap)

		heap->size--; //one less element, so size is decreased by one

			//since it is assumed that the maxheap passed into this function is valid
			//all subtrees of the maxheap are valid and thus top down comparisons can be made to re-implement the maxheap
			int j = 1; 
			while (j <= heap->size) {

				int left = 2 * j;
				int right = (2 * j + 1);
				int largest;

				if ((left <= heap->size) && (heap->H[left].key > heap->H[j].key))
					largest = left;
				else
					largest = j;

				if ((right <= heap->size) && (heap->H[right].key > heap->H[largest].key))
					largest = right;

				if (largest != j) {

					int temp = heap->H[j].key;
					heap->H[j].key = heap->H[largest].key;
					heap->H[largest].key = temp;

					j = largest;

				}
				else if (largest == j) {

					break;
				}

		}
   
    if (flag == 2){
		printf("After delete max operation:\n");
        printf("Capacity = %d\n", heap->capacity);
        printf("Size = %d\n", heap->size);

		for (int p = 1; p <= heap->size; p++) {
			printf("%d\n", heap->H[p].key);
		}
    }

        printf("Deleted max = %d\n", temp);
		return temp;
}   

void IncreaseKey(struct HEAP* heap, int flag, int index, int value) {
	
	if (flag != 1){
        
        if(flag != 2){
        printf("Error: invalid flag value\n");
        return;
        }
    }

	if ( (index == 0) || (index > heap->size)){
		printf("Error: invalid index\n");
		return;
	}

	if(value < heap->H[index].key){
		printf("Error: new key is smaller than current key\n");
		return;
	}
    
    if (flag == 2) {

		printf("Before increase key operation:\n");
        printf("Capacity = %d\n", heap->capacity);
        printf("Size = %d\n", heap->size);

		for (int p = 1; p <= heap->size; p++) {
			printf("%d\n", heap->H[p].key);
		}
	}

		//if the element's value we want to increase is less than the number we want to increase it to
		if (heap->H[index].key < value) { 
			//then change this element's value to the number we want to increase it to 
			heap->H[index].key = value;
		}
		
		int i = index;

		int parent = i/2;
		
		//the while loop preserves the already built max heap, ie when insertion occurs it is assumed 
		//that we are inserting into a correct maxheap, also we know that we either kept the same key
		//or increased it, so node's key that has been increased will either remain in place or go up levels
		//to replace parent node(s); because of this all we have to do is make comparisons to parent node's 
		//until our new element is either the root or has a parent node that has a larger key than it does
		while (i > 1 && heap->H[parent].key < heap->H[i].key) {
			int temp = heap->H[i].key;
			heap->H[i].key = heap->H[parent].key;
			heap->H[parent].key = temp;

			i = parent;
            parent = i/2;
		}
	
    if (flag == 2){
        printf("After increase key operation:\n");
        printf("Capacity = %d\n", heap->capacity);
        printf("Size = %d\n", heap->size);

		for (int p = 1; p <= heap->size; p++) {
			printf("%d\n", heap->H[p].key);
		}
    }

}

void printHeap(struct HEAP* heap) {
	
	printf("Capacity = %d\n", heap->capacity); //prints heap's size
	printf("Size = %d\n", heap->size); //prints heap's maximum capacity

	for (int p = 1; p <= heap->size; p++) { //prints out heap's element array's contents
		printf("%d\n", heap->H[p].key);
	}
}
