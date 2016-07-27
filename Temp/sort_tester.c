

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#include "Insertion/insertion_sort.h"


const int max_rand_value = 1000000;


void printArr( int *array, int length ) {
	for (int i = 0; i < length; i++) {
		printf( "%d ", array[i] );
		if ((i % 8 == 0) && (i > 0))
			printf( "\n" );
	}
	printf( "\n" );
}

int *randomIntArray( int length ) {
	int *array = malloc( sizeof(int) * length );
	srand( time(NULL) );
	for (int i = 0; i < length; i++)
		array[i] = rand() % max_rand_value;
	return array;
}

int *copyOfArray( int *src_array, int length ) {
	size_t array_size = length * sizeof(int);
	int *array = malloc( array_size );
	memcpy( array, src_array, array_size );
	return array;
}

bool isOnlyIncreasing( int *array, int length ) {
	if (length >= 2) {
		for (int i = 1; i < length; i++) {
			if (array[i-1] > array[i])
				return false;
		}
	}
	return true;
}


int main( int argc, char **argv ) {

	if (argc != 2) {
		printf( "Usage error: \"./insertion_tester <elem count>\"" );
		return 1;
	}

	setlocale( LC_NUMERIC, "" );

	int array_length = atoi( argv[1] );

	printf( "Creating two identical randomly populated array with %'d elements\n", array_length );
	int *array1 = randomIntArray( array_length );
	int *array2 = copyOfArray( array1, array_length );


	printf( "Begin sorting of array...\n" );
	time_t start = clock();
	insertion_sort( array1, array_length );
	time_t end = clock();
	printf( "Sorting complete\n" );
	printf( "Array only increases: " );
	if (isOnlyIncreasing(array1, array_length)) {
		printf( "True\n" );
	}
	else {
		printf( "False\n" );
	}

	double sort_time = (double) (end - start) / CLOCKS_PER_SEC;

	printf( "\nInsertion sort on %'d elements took: %f seconds\n\n", array_length, sort_time );



	return 0;
}
