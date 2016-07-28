/**
 * Author: Cameron Palk
 * 
 * In-place Quicksort implementation in C
 *
*/

// Local Includes
#include "quick_sort.h"



void inPlaceQuicksort(int *, int);
void recurse		 (int *, int, int);
int  partition		 (int *, int, int);
void swap			 (int *, int, int);



void inPlaceQuicksort(int *array, int array_length) {
	return quicksort_rec( array, 0, array_length );
}



int partition( int *array, int low, int high ) {
	int pivot = array[high];
	int swap_index = low;
	for (int i = low; i < (high-1); i++) {
		if (array[i] <= pivot) {
			swap( array, i, swap_index );
			swap_index++;
		}
	}
	swap( array, swap_index, high );
	return swap_index;
}

void recurse(int *array, int low, int high) {
	if (low < high) {
		int partition_index = partition( array, low, high );
		recurse( array, low, partition_index - 1 );
		recurse( array, partition_index + 1, high );
	}
	return;
}

void swap( int *array, int idx1, int idx2 ) {
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
	return;
}
