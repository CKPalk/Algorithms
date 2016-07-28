/**
 * Author: Cameron Palk
 * 
 * In-place Quicksort implementation in C
 *
*/

// Local Includes
#include "quicksort.h"





void quicksort_swap( int *array, int idx1, int idx2 ) {
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
	return;
}

int quicksort_partition( int *array, int low, int high ) {
	int pivot = array[high];
	int swap_index = low;
	for (int i = low; i < (high-1); i++) {
		if (array[i] <= pivot) {
			quicksort_swap( array, i, swap_index );
			swap_index++;
		}
	}
	quicksort_swap( array, swap_index, high );
	return swap_index;
}

void quicksort_rec(int *array, int low, int high) {
	if (low < high) {
		int partition_index = quicksort_partition( array, low, high );
		quicksort_rec( array, low, partition_index - 1 );
		quicksort_rec( array, partition_index + 1, high );
	}
	return;
}



void inPlaceQuicksort(int *array, int array_length) {
	return quicksort_rec( array, 0, array_length );
}


