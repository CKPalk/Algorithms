

#include "selection_sort.h"

void swap( int *array, int idx1, int idx2 ) {
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

void selection_sort( int *array, int length ) {
	for (int i = 0; i < length-1; i++) {
		int min = array[i];
		int min_idx = i;
		for (int j = i; j < length; j++) {
			if (array[j] < min) {
				min = array[j];
				min_idx = j;
			}
		}
		swap( array, i, min_idx );
	}
}
