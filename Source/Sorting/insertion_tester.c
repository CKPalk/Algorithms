
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#include "Insertion/insertion_sort.h"


const int max_rand_value = 100000000;
const bool run_naive = false;
const bool run_regular = false;
const bool run_binary = true;


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


double time_insertion_sort_naive( int *array, int length ) {
	printf( "Begin naive insertion sort of array...\n" );
	time_t start = clock();
	insertion_sort_naive( array, length );
	time_t end = clock();
	printf( "	sorting complete.\n" );
	checkArray( array, length );
	return (double) (end - start) / CLOCKS_PER_SEC;
}

double time_insertion_sort( int *array, int length ) {
	printf( "Begin naive insertion sort of array...\n" );
	time_t start = clock();
	insertion_sort( array, length );
	time_t end = clock();
	printf( "	sorting complete.\n" );
	checkArray( array, length );
	return (double) (end - start) / CLOCKS_PER_SEC;
}

double time_insertion_sort_binary( int *array, int length ) {
	printf( "Begin binary search insertion sort of array...\n" );
	time_t start = clock();
	insertion_sort_binary( array, length );
	time_t end = clock();
	printf( "	sorting complete.\n" );
	checkArray( array, length );
	return (double) (end - start) / CLOCKS_PER_SEC;
}


int main( int argc, char **argv ) {

	if (argc != 2) {
		printf( "Usage error: \"./insertion_tester <elem count>\"" );
		return 1;
	}

	setlocale( LC_NUMERIC, "" );

	int array_length = atoi( argv[1] );

	printf( "Creating three identical randomly populated array with %'d elements\n", array_length );
	int *array1, *array2, *array3;
	int *master = randomIntArray( array_length );
	if (run_naive)   array1 = copyOfArray( master, array_length );
	if (run_regular) array2 = copyOfArray( master, array_length );
	if (run_binary)  array3 = copyOfArray( master, array_length );

	double time_naive, time_regular, time_binary;
	if (run_naive) 	 time_naive   = time_insertion_sort_naive( array1, array_length );
	if (run_regular) time_regular = time_insertion_sort( array2, array_length );
	if (run_binary)  time_binary  = time_insertion_sort_binary( array3, array_length );

	printf( "\nInsertion sort on %'d elements took:\n", array_length );
	if (run_naive)   printf( " - Naive : %f seconds\n", time_naive );
	if (run_regular) printf( " - Normal: %f seconds\n", time_regular );
	if (run_binary)  printf( " - Binary: %f seconds\n", time_binary );

	free( array1 );
	free( array2 );
	free( array3 );

	return 0;
}


















