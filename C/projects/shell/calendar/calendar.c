#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calendar.h"



#define DAYS_OF_WEEK 7

int week_day(int day, int month, int year);
int month_days(int month, int leap_year);
char * month_name(int month);
void show_calendar(int year, int month);




int main(void){
	show_calendar(2021, 10);
	return 0;
}














void show_calendar(int year, int month){
	int dow = DAYS_OF_WEEK;
	struct year selectedyear = {12, 
		(double)year/4, 
		365, 
		year%4==0 ? 1 : 0};


	int monthdays = month_days(month, selectedyear.is_leap);
	char * monthname = month_name(month);
	struct month selectedmonth = {monthdays, monthname};

	printf("####\t MESE: %s; GIORNI: %d\t####\n", monthname, selectedmonth.days);
	int calrows = ceil(((double)selectedmonth.days)/dow);
	int day = 1;
	for(int j=0; j<=calrows; j++){
		for(int i=0; (i<dow) && (day<=selectedmonth.days); i++){
			int wkday = week_day(day, month, year);
			printf("(%d)", wkday);
			if(wkday == i){
				// day+=1;
				// printf("%02d\t", wkday+(j*dow));
				printf("%02d\t", day);
				day+=1;
			} else {
				printf("\t");
			}
		}
		puts("");
	}
}

// TODO: REMAP MONTHS
// 1=MARCH, 2=APRIL, ..., 10=DECEMBER
// 11=JANUARY, 12=FEBRUARY
int week_day(int day, int month, int year){
	char stringyear[2];
	int std_month = (year-2)%12;
	sprintf(stringyear, "%d", year);
        // itoa(year, stringyear, 10);
	int century = (int)(stringyear[0] + stringyear[1]);
	// int w = (int)(day + ceil(2.6*month - 0.2)-2*century + year + ceil(year/4) + (century/4)) % 7;

	int w = (int)(day + floor(2.6*std_month - 0.2)-2*century + year + floor(year/4) + (century/4)) % 7;
	return w;
}

int month_days(int month, int leap_year){
	FILE * fileptr;
	fileptr = fopen("config.txt", "r");
	int monthdays = -1;
	
	int c = getc(fileptr);
	// fino a che non ragiiungo la fine del file
	while(c != EOF){
		// recupero una riga
		char line[20];
		int cursor = 0;
		while(c != '\n'){
			line[cursor] = c;
			c = getc(fileptr);
			cursor +=1;
		}
		line[cursor] = '\0';
		// remove last '\n' getting
		// the next line char
		c = getc(fileptr);

		// se l'indice del mese è quello richiesto
		// ritorna il numero di giorni
		char * tok = strtok(line, ",");
		if(atoi(tok) == month){
			int add_by_leap = (month == 2) && (leap_year) != 0 ? 1 : 0;
			strtok(NULL, ",");
			monthdays = atoi(strtok(NULL, ",")) + add_by_leap;
		}

	}
	fclose(fileptr);

	if(monthdays == -1){
		return 0;
	}

	return monthdays;
}


char * month_name(int month){
	FILE * fileptr;
	fileptr = fopen("config.txt", "r");
	char * monthname;

	int c = getc(fileptr);
	// fino a che non ragiiungo la fine del file
	while(c != EOF){
		// recupero una riga
		char line[20];
		int cursor = 0;
		while(c != '\n'){
			line[cursor] = c;
			c = getc(fileptr);
			cursor +=1;
		}
		line[cursor] = '\0';
		// remove last '\n' getting
		// the next line char
		c = getc(fileptr);

		// se l'indice del mese è quello richiesto
		// ritorna il nome
		char * tok = strtok(line, ",");
		if(atoi(tok) == month){
			monthname = strdup(strtok(NULL, ","));
			// senza il return, lavorando con i puntatori
			// si sovrascrive monthname
			fclose(fileptr);
			return monthname;
		}
	}
	fclose(fileptr);

	return monthname;
}
