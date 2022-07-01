#ifndef HEAP_H
#define HEAP_H

struct ELEMENT { 
	int key; //each element has a key value
};

struct HEAP {
	int capacity; //maximum amount of elements the heap has memory to store currently
	int size; //the current number of elements in the heap
	struct ELEMENT* H; //a pointer to an array of elements with an index ranging from 0 to capacity (once intialized)
};

struct HEAP* Initialize(int n);
/* returns an object of type HEAP with capacity n and size 0.  
This function performs dynamic memory allocation, given the demand n. */

void BuildHeap(struct HEAP* heap, struct ELEMENT A[], int n);
/* where heap is a HEAP object, A is an array of type ELEMENT, and n is the size of array A. 
This function copies the elements in A into heap->H(starting from H[1]and uses the linear time 
build heap algorithm to obtain a max-heap of size n from the given array A. */

void Insert(struct HEAP* heap, int flag, int k);
/* inserts  an  element  with key equal to k into  the  max-heap heap. When flag=1, the 
function does not do any additional printing.  When flag=2, the function prints out the heap content 
before the insertion, and the heap content after the insertion. */

int DeleteMax(struct HEAP* heap, int flag);
/* deletes the element with maximum key and returns it to the caller. When flag=1, the function does 
not do any additional printing.  When flag=2, the function prints out the heap content before the deletion, 
and the heap content after the deletion. */

void IncreaseKey(struct HEAP* heap, int flag, int index, int value);
/* ncreases the key field of the heap element pointed to by index to value, which should not be smaller 
than the current value. When flag=1,the function does not do any additional printing.  When flag=2, the 
function prints out the heap content before the increase key operation, and the heap content after the 
increase key operation. */

void printHeap(struct HEAP* heap);
/* which prints out the heap information, including capacity, size, and the key fields of the elements in 
the array. */

#endif /* HEAP_H */