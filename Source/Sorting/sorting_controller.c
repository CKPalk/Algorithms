
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#include "Selection/selection_sort.h"



int main( int argc, char ** argv ) {

	int f;
	while ((f = getopt( argc, argv, "?" )) != -1) {
		switch (f) {
			case '?':
				printf( "Usage: \"./sorting <algorithm> <elems to sort>\"\n\nAlgorithms:\n  insertion\n  bubble\n  selection\n  shell\n  merge\n\n" );
				break;
			default:
				printf( "I don't know what you're trying to tell me!\n" );
				abort();
		}
	}
}
