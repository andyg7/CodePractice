
struct HashTable {
	int size;
	int * bucket;
};

void creatHashTable(struct HashTable * b, int bucketSize, int (*f1)(void * arg));
