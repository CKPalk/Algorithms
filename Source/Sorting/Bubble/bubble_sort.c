
void swap( int *array, int idx1, int idx2 ) {
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

void bubble_sort( int *array, int length ) {
	for (int i = length; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			if (array[j] < array[j-1])
				swap( array, j, j-1 );
		}
	}
}
