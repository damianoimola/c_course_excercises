#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_BUFF 128

int elements = 0;


int menu();
int displaylist();
int add();
int rmv();
int displaystats();
int quit();
int execute(int input);
int add_to_csv(char *name, double price);
int remove_from_csv(char *name);
int getinteger();
char *getstring();
double getprice();
void clear();



int main(int argn, int *argc[]){
	int welcome = 1;
	char *c = malloc(sizeof(*c));
	while(1){
		if(welcome){
			welcome = 0;
			puts("Benvenuto nel tuo gestionale per la lista della spesa!");
		}
		int res = menu();
		if(res == 0){
			return 0;
		} else if(res == -1){
			continue;
		}
	}
}


int menu(){		
	puts("Cosa vuoi fare?");
	printf("\t1) Aggiungere un elemento alla lista\n\t2) Rimuovere un elemento dalla lista\n\t3) Stampa statistiche\n\t4) Esci");
	int res;

	int input = getinteger();
	if(input<1 && input >4){
		clear();
		return -1;
	}
	
	res = execute(input);
	if(res == -1){
		clear();
		return -1;
	}


	//res = displaylist();
	if(res == -1){
		return -1;
	}
}



int execute(int input){
	switch(input){
		case 1:
			return add();
		case 2:
			return rmv();
		case 3:
			//return displaystats();
			return 1;
		case 4:
			return 0;
		default:
			/* TODO: handle
			 * this should necer happen
			 */
			return 0;
	}
}


int add(){
	clear();
	puts("Come si chiama il prodotto?");
	// everithing can be converted in string, so no need to check
	char *name = getstring();
	double price;
	while(1){
		puts("Se conosci il prezzo inseriscilo, altrimenti lascialo vuoto");
		price = getprice();
		if(price == -1){
			continue;
		}
		break;
	}


	// handling csv file
	int res = add_to_csv(name, price);
	if(res == -1){
		exit(1);
	}
	
}


int rmv(){
	clear();
	puts("Come si chiama il prodotto?");
	// everithing can be converted in string, so no need to check
	char *name;
	getstring(&name);
	int res = remove_from_csv(name);
	if(res == -1){
		puts("An error has occurred");
	}
}


int add_to_csv(char *name, double price){
	FILE *csv = NULL;
	csv = fopen("shopping-list.csv", "w");
	if(csv == NULL){
		puts("failed to open csv!");
		return -1;
	}
	// cursto at the end
	fseek(csv, 0, SEEK_END);
	int res = fprintf(csv, "%s,%lf\n", name, price);
	if(res < 0){
		puts("An error has occurred while appending item to the shopping list csv file.");
		return -1;
	}
	printf("Hai appena aggiunto l'oggetto\n Nome:%s, Prezzo:%lf\n alla lista", name, price);
	return EXIT_SUCCESS;
}


int remove_from_csv(char *name){
	FILE *csv = NULL;
	csv = fopen("shopping-list.csv", "wr+");
	if(csv == NULL){
		puts("failed to open csv!");
		exit(1);
	}
	char *content;
        fread(content, 1, elements, csv);
	int filelen = strlen(content);
	int cursor = 0;
	char *line, *item_name;
	while(1){
		int newlineindex = strcspn(content+cursor, "\n");
		// read a line
		fread(line, 1, newlineindex-cursor, csv);
		int linelen = strlen(line);
		cursor += linelen;
		// read the name
		item_name = strtok(line, ",");
		if(item_name == name){
			// posizionati alla fine della riga da elmininare
			// e leggi il contenuto fino alla fine
			fseek(csv, cursor, SEEK_SET);
			char *other;
			fread(other, 1, filelen-cursor, csv);
			fseek(csv, cursor-linelen, SEEK_SET);
			// riscrivi il restante contenuto del file
			fwrite(other, 1, strlen(other), csv);
			break;
		} 
	}
	puts("Se l'oggetto era presente, lo hai rimosso.");
}



char *getstring(char ** str){
	char string[MAX_BUFF];
	if(fgets(string, MAX_BUFF, stdin)){
		int newlineindex = strcspn(string, "\n");
		string[newlineindex] =0;
	}
	*str = strdup(string);
}

double getprice(){
	char strprice[MAX_BUFF];
	double price;
	if(fgets(strprice, MAX_BUFF, stdin)){
		price = strtod(strprice, NULL);
	} else {
		return -1;
	}
	return price;
}

int getinteger(){
	char strint[MAX_BUFF];
	int integer;
	if(fgets(strint, MAX_BUFF, stdin)){
		integer = atoi(strint);
	} else {
		return -1;
	}
	return integer;
}


void clear(){
	system("cls");
	system("clear");
}



