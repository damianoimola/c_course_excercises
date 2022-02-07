#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
// files
#include "ascii.c"
#include "calendar/calendar.c"

// pre-defined functions
// utilities
char * get_input();
// program
void loop(void);
char * read_line();
char ** split_line(char * line);
int launch(char ** args);
int execute_command(char ** args);
void print_trailing_msg();


int main(int argc, char * argv[]){
	// TODO: load config files
	loop();

	return EXIT_SUCCESS;
}



void loop(){
	char * line;
	char ** args;
	int status;

	do{
		print_trailing_msg();
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		free(line);
		free(args);
	} while(status);
}


/*
 * Get the input from custom shell, and handle
 * the reallocation of memory inc ase the input
 * is oversize (>=1024 byte)
 *
 * NOTE: in stdio.h there is the getline() 
 * function, that handle some of the code we
 * just wrote, it will clean the code, but
 * rubber the funny
 */
#define BUFFERSIZE 1024
char * read_line(){
	int buffersize = BUFFERSIZE;
	int cursor = 0;
	char * buffer = (char*) malloc(buffersize * sizeof(char));

	// ch is declared as 'int' because
	// of EOF, that is an integer
	int ch;
	while(1){
		if(!buffer){
			printf("error: buffer not allocated.");
			exit(EXIT_FAILURE);
		}

		ch = getchar();
		// EOF =  end of file
		// '\0' = string terminator
		if(ch == EOF || ch == '\n'){
			// telling the end of string
			buffer[cursor] = '\0'; 
			return buffer;
		} else {
			buffer[cursor] = ch;
		}
		cursor++;

		// handling the overtext as input
		if(cursor>=buffersize){
			buffersize += BUFFERSIZE;
			buffer = realloc(buffer, buffersize);
			 if(!buffer){
				 printf("error: buffer exceeded -> reallocation failure");
				 exit(EXIT_FAILURE);
			 }
		}
	}
}


/*
 * Tokenizza la stringa in argomenti
 */
#define ARG_SIZE 64
#define ARG_DELIMITERS " \t\r\n\a"
char ** split_line(char * line){
	int argsize = ARG_SIZE;
	int cursor = 0;
	char ** args = (char**) malloc(argsize * sizeof(char*));
	char * arg;

	if(!args){
		printf("error: memory not allocated");
		exit(EXIT_FAILURE);
	}

	// tokenizza la stringa ritornando la
	// prima occorrenza
	arg = strtok(line, ARG_DELIMITERS);
	while(arg != NULL){
		args[cursor] = arg;
		cursor++;

		if(cursor >= argsize){
			argsize += ARG_SIZE;
			args = realloc(args, argsize);
		}

		if(!args){
			printf("error: memory reallocation failed");
			exit(EXIT_FAILURE);
		}

		// passa al prossimo token della stringa
		arg = strtok(NULL, ARG_DELIMITERS);
	}
	args[cursor] = NULL;
	return args;
}



/*
 * Fa una copia del processo principale ed
 * esegue il sotto-processo con un singolo 
 * argomento, ovvero in questo caso:
 *	"args[0] arg"
 * dove args[0] rappresenta il nome del programma
 * e arg è un singolo argomento di args
 *
 * NOTA: execvp è della famiglia exec
 * ma aggetta un vettore di argomenti, in
 * particolare, la 'v' dopo exec, sta ad
 * indicare che accetta un vettore, mentre
 * la 'p' indica che gli argomenti che
 * passiamo nel vettore, li deve andare
 * a ricerare nel PATH, senza dargli il
 * percorso completo degli eseguibili
 * dei singoli argomenti
 */
int launch(char ** args){
	pid_t pid, wpid;
	int status;

	pid = fork();
	if(pid == 0){
		// CHILD process
		// run process, and if it returns -1
		// means that there was an error
		int res = execvp(args[0], args);
		if(res == -1){
			perror("Errore");
		}
		exit(EXIT_FAILURE);
	} else if (pid<0) {
		// ERROR forking
		perror("Errore");
	} else {
		// PARENT process
		do{
			// serve a capire quando il processo figlio termina
			// restituendo un valore. Ci sono molti modi
			// per far finire un processo, li gestisce tutti.
			wpid = waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

void print_trailing_msg(){
	srand(time(NULL));

	int rnd = (double) rand()/RAND_MAX * 4;
	char * messages[] = {
		"Inutile",
		"Mmmmmhhhh",
		"Ok Boomer",
		"Geek as f"
	};

	printf("%s >>>", messages[rnd]);
}







// declaration for builtin shell commands
int cd(char ** args);
int help(char ** args);
int exit_sh(char ** args);
int ascii(char ** args);
int calendar(char ** args);


char * builtin_str[] = {
	"cd", "help", "exit", "ascii", "calendar"
};

// Array di puntatori a funzioni chiamato 'builtin_func'
// Ogni funzione accetta come argomento un char**
// Ogni funzione ritorna un int
int (*builtin_func[]) (char **) = {
	&cd, &help, &exit_sh, &ascii, &calendar
};

int num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}



int cd(char ** args){
	if(args[1] == NULL){
		printf("not enough argument to \"cd\"\n");
	} else {
		// change the current working directory
		int res = chdir(args[1]);
		if(res != 0){
			perror("Errore");
		}
	}
	return 1;
}

int help(char ** args){
	printf("Damiano Imola's Shell\n");
	printf("Type programs and arguments followed by enter\n");
	printf("The following commands are builtin:\n");

	for(int i=0; i<num_builtins(); i++){
		printf("\t%s\n", builtin_str[i]);
	}

	return 1;
}

int exit_sh(char ** args){
	return 0;
}


int ascii(char ** args){
	print_ascii(args[1]);
	return 1;
}

int calendar(char ** args){
	// TODO
	puts("Still working on it\n");
	assert(args[1] != NULL || args[2] != NULL);

	show_calendar(atoi(args[1]), atoi(args[2]));
	return 1;
}







int execute_command(char ** args){
	if(args[0] == NULL){
		// empty command
		return 1;
	}

	for(int i=0; i<num_builtins(); i++){
		int res = strcmp(args[0], builtin_str[i]);
		if(res == 0){
			return (*builtin_func[i])(args);
		}
	}

	return launch(args);
}

