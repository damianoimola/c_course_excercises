/*
 *
 *
 *
 *
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"


void tokenize(desc ** descs, int n, char * argv[]);
type_t get_type(char * token);
desc * compose_element(type_t type, char * arg);





extern void parseargs(desc ** descs, int n, char ** argv){
	for(int i=1; i<n; i++){
		char * arg = argv[i];
		type_t currtype = get_type(arg);
		desc * currdesc = compose_element(currtype, arg);
		// memcpy(desc[i-1], currdesc, sizeof(desc));
		descs[i-1] = currdesc;
	}

	for(int i=1; i<n; i++){
		printf("DESCRIPTION #%d val:%d\n", i-1, *(descs[i-1]));
	}
	
}


// !!! WARNING !!!
// Temporary function, it needs to be completed
type_t get_type(char * str){
	size_t len = strlen(str);

	int alpha=0, decimal=0, integer=0;
	for(int i=0; i<len; i++){
		char c = str[i];
		if(isalpha(c)){
			return CHAR;
		} else if(isdigit(c)){
			integer = 1;
		} else if(ispunct(c)){
			decimal=1;
		}
	}

	// composing flags
	if(integer && decimal){
		return FLOAT;
	} else if(integer && !decimal){
		return INT;
	} else {
		// this should be handled
		// it it an error
	}
}

// TODO: finisci
// deve ritornare un elemento della lista di
// strutture descrittive
desc * compose_element(type_t type, char * arg){
	desc * argdesc = (desc *) malloc(sizeof(desc));
	
	ctype val;
	switch(type){
		case CHAR:
			val = (ctype) { .c=arg[0] };
			break;
		
		case INT:
			val = (ctype) { .i=atoi(arg) };
			break;

		case FLOAT:
			val = (ctype) { .f=atof(arg) };
			break;

		default:
			//do something
			puts("An error has occurred while composing element description");
	}
	
	argdesc->type = type;
	argdesc->val = val;
	return argdesc;
}



