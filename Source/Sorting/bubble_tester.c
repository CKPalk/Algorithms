
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#include "Bubble/bubble_sort.h"


const int max_rand_value = 100000000;


void printArr( int *array, int length ) {
	for (int i = 1; i <= length; i++) {
		printf( "%d ", array[i-1] );
		if (i % 8 == 0)
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

void checkArray( int *array, int length ) {
	printf( "Array only increases: " );
	printf( isOnlyIncreasing(array, length) ? "True\n" : "False\n" );
}



double time_bubble_sort( int *array, int length ) {
	printf( "Begin selection sort of array...\n" );
	time_t start = clock();
	bubble_sort( array, length );
	time_t end = clock();
	printf( "	sorting complete.\n" );
	checkArray( array, length );
	return (double) (end - start) / CLOCKS_PER_SEC;
}
	


int main( int argc, char **argv ) {

	if (argc != 2) {
		printf( "Usage error: \"./selection_tester <elem count>\"" );
		return 1;
	}

	setlocale( LC_NUMERIC, "" );

	int array_length = atoi( argv[1] );

	printf( "Creating randomly populated array with %'d elements\n", array_length );
	int *array = randomIntArray( array_length );


	double sort_time = time_bubble_sort( array, array_length );



	printf( "\nBubble sort took: %f seconds\n", sort_time );

	free( array );

	return 0;
}


















