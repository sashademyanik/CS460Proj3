#include <stdio.h>
#include "heap.h"


/* Min-heapify array A with n elements at index i. */
void minheap_heapify(PCB *A[], int i, int n){
	int right = 2 * (i+1);
	int left = right - 1;
	int min = i;
	PCB *tmp = 0;
	
	if (left < n && A[left]->priority < A[i]->priority) {
		min = left;
	}
	
	if (right < n && A[right]->priority < A[min]->priority) {
		min = right;
	}
	
	if (min != i) {
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
		
		minheap_heapify(A, min, n);
	}
}


/* 
 * Sort array A with n elements using min-heapify. Uses a for loop that calls
 * heapify for every parent node starting at the bottom.
 */
void minheap_build(PCB *A[], int n){
	for(int i = n; i > 0; i--){
		int parent = (i-1) / 2;
		minheap_heapify(A, parent, n);
	}
}

