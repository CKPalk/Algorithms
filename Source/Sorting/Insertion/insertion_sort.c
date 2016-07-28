
#include "insertion_sort.h"
#include <string.h>


void swap( int *array, int idx1, int idx2 ) {
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
	return;
}

int findIndexByBinarySearch( int *array, int lo, int hi, int target ) {
	int possible_indexes = hi - lo;
	if (possible_indexes == 0) {
		return lo;
	}
	else if (possible_indexes == 1) {
		return (target > array[lo] ? hi : lo );
	}

	int mid = (possible_indexes / 2) + lo;
	if (target > array[mid]) {
		return findIndexByBinarySearch( array, mid+1, hi, target );
	}
	else {
		return findIndexByBinarySearch( array, lo, mid, target );
	}
}

int elemsToShift( int *array, int length, int elem_index ) {
	int index = findIndexByBinarySearch( array, 0, elem_index-1, array[elem_index] );
	return index;
}


/**
 * This is a naive implementation that is the default insertion sort. It swaps values down until they are in the correct
 * position.
*/
void insertion_sort_naive( int *array, int length ) {
	for (int i = 1; i < length; i++) {
		for (int j = i; (j > 0) && (array[j-1] > array[j]); j--) {
			swap( array, j, j-1 );
		}
	}
}


/**
 * This implementation will count the number of elements that must be moved instead of swapping them on each loop
 * iteration and instead bulking the shift to the end and using a memcpy()
*/
void insertion_sort( int *array, int length ) {
	for (int i = 1; i < length; i++) {
		int elems_to_shift = 0;
		for (int j = i-1; (j >= 0) && (array[j] > array[i]); j--) {
			elems_to_shift++;
		}
		int elem = array[i];
		int start_idx = i - elems_to_shift;
		memcpy( array + (start_idx + 1), array + start_idx, elems_to_shift * sizeof(int) );
		array[start_idx] = elem;
	}
}


/**
 * Another implementation would be a binary search in the already sorted side of the array, instead of looking at each
 * element. Binary search for the correct index to push the value into
*/
void insertion_sort_binary( int *array, int length ) {
	for (int i = 1; i < length; i++) {
		int elem = array[i];
		int start_idx = findIndexByBinarySearch( array, 0, i, elem );
		int elems_to_shift = i - start_idx;
		memcpy( array + (start_idx + 1), array + start_idx, elems_to_shift * sizeof(int) );
		array[start_idx] = elem;
	}
}
