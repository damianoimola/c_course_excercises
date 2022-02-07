#ifndef CONFIG_H
#define CONFIG_H

typedef enum type{
	CHAR, SHORT, INT, FLOAT, DOUBLE, LONG, LONGLONG, STRING
} type_t;

typedef union mlttype{
	char c;
	short sh;
	int i;
	float f;
	double d;
	long l;
	long long ll;
	// care, cannot be there
	//char * s;
} ctype;

typedef struct node_t {
	struct node_t * next;
	type_t datatype;
	ctype val;
} node;


typedef struct description {
	ctype val;
	type_t type;
} desc;





/*
 *
 *	PARSE.C EXTERN FUNCS
 *
 */
extern void parseargs(desc ** descs, int n, char ** argv);



#endif
