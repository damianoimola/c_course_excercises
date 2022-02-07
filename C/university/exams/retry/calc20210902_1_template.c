#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_SIZE 64

/**
 * Questa è la definizione della struttura dati synstr
 */
struct dynstr {
	char *s;
	size_t len;
	size_t buffer;
};

/**
 * Permette la concatenazione di una parte di stringa su una stringa dinamica
 * @param ds	 la stringa dinamica a cui concatenare la stringa
 * @param suffix il suffisso da concatenare alla stringa dinamica
 */
void append(struct dynstr *ds, const char *suffix)
{
	size_t sufflen = strlen(suffix);
	if(ds->buffer < ds->len+sufflen){
		ds->s = realloc(ds->s, ds->buffer*2);
		if(!ds->s){
			// ...
			exit(EXIT_FAILURE);
		}
		ds->buffer*=2;
	}

	for(int i=0; <sufflen; i++){
		ds->*(s + len+i) = *(suffix +i);
	}
	ds->len+=sufflen;

}

/**
 * Permette la concatenazione di una parte di stringa su una stringa dinamica
 * @param ds	 la stringa dinamica a cui concatenare la stringa
 * @param suffix il suffisso da concatenare alla stringa dinamica
 */
void append(struct dynstr *ds, const char *suffix)
{
	size_t sufflen = strlen(suffix);
	if(ds->buffer < ds->len + sufflen){
		ds->s = realloc(ds->s, ds->len+sufflen);
		if(!ds->s){

		}
	}
	char *from = (char *) suffix + strlen(suffix);
	char *to = (char *) ds->s + ds->
	
}

/**
 * Inizializza una struttura dati dynstr
 * @param ds	la stringa dinamica da inizializzare
 * @param len	la lunghezza iniziale del buffer conservato da ds
 */
void dynstr_init(struct dynstr *ds, size_t len)
{
	ds->s = malloc(len);
	ds->buffer = len;
	ds->len = 0;
}

/**
 * Stampa a schermo una stringa dinamica
 * @param ds	la stringa dinamica da stampare a schermo
 */
void print(struct dynstr *ds)
{
	printf("%s", ds->s);
}

int main(void)
{
	struct dynstr ds;
	dynstr_init(&ds, 8);

	append(&ds, "Hello ");
	append(&ds, "world, ");
	append(&ds, "this ");
	append(&ds, "is ");
	append(&ds, "my ");
	append(&ds, "program");

	print(&ds); // Expected print: "Hello world, this is my program"

	return 0;
}
