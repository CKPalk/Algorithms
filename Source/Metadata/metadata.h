

typedef struct Metadata {

	char *algorithm_name;
	double execution_time;
	void *data;

} Metadata;

Metadata *new_metadata(char *alrogithm_name);
void destroy_metadata(Metadata *metadata);
