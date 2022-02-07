#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<errno.h>





/* Parametri di configurazione della cache */
#define CACHE_SIZE (64 * 1024) 
#define BLOCK_SIZE 64 
#define ADDRESS_SIZE 32 


/* Valori derivati dai soprastanti */
#define LINES (CACHE_SIZE/BLOCK_SIZE)
#define OFFSET_BITS (long)log2(BLOCK_SIZE) 
#define INDEX_BITS (long)log2(LINES) 
#define TAG_BITS (ADDRESS_SIZE - INDEX_BITS - OFFSET_BITS)

#define INDEX_MASK (((long)pow(2, INDEX_BITS) - 1) << OFFSET_BITS)
#define TAG_MASK (((long)pow(2, TAG_BITS) - 1) << (OFFSET_BITS + INDEX_BITS))

#define get_index(addr) (((addr) & INDEX_MASK) >> OFFSET_BITS)
#define get_tag(addr) (((addr) & TAG_MASK) >> (OFFSET_BITS + INDEX_BITS))

struct line{
	bool valid;
	unsigned long tag;
}
struct line cache[LINES];

int accesses=0;
int misses=0;
int hits=0;

void simulate(unsigned long long address){
	unsigned long index = get_index(address);
	unsigned long tag = get_tag(address);

	if(cache[index].valid && cache[index].tag == tag){
		hits++;
		
	} else {
		cache[index].tag = tag;
		cache[index].valid = true;
		misses++;
	}
	accesses++;
}

bool handle_err(char **err, char *s){
	if(errno == ERANGE){
		fprintf(stderr, "Oops, something strange happend, overflow occurred.\n");
		exit(EXIT_FAILURE);
	} else if(*(err) == s || (**err && **err != '\n')){
		fprintf(stderr, "Malformed input.\n");
		exit(EXIT_FAILURE);
	}
	return false;
}

int main(int argn, char *argv[]){
	if(argn<2){
		fprintf(stderr, "Usage: %s <nomefile>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file;

	if(!(file = fopen(argv[1], "r+"))){
		fprintf(stderr, "Oops, something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}

	char *s;
	char *err;
	while(fgets(s, ADDRESS_SIZE, file) != EOF){
		errno = 0; // resetting errors
		unsigned long long address = stroull(s, &err, 2);
		if(!handle_err(err, s)) simulate(address);
	}
}
