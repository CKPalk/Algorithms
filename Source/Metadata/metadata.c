
#include "metadata.h"

Metadata *new_metadata( char *alrogithm_name ) {
	Metadata *metadata = malloc( sizeof(Metadata) * 1 );
	metadata->algorithm_name = algorithm_name;
	metadata->execution_time = -1.0;
	metadata->data = NULL;
}


void destroy_metadata( Metadata *metadata ) {
	free( metadata->algorithm_name );
	free( metadata->data );
	free( metadata );
}
