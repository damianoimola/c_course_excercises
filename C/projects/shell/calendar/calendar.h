#ifndef CALENDAR_H_
#define CALENDAR_H_

struct event {
	char * description;
	int start_hour;
	int end_hour;
};

struct day {
	char * weekname;
	int number;
	struct event * events;
};

struct month {
	int days;
	char * monthname;
};

struct year {
	int months;
	int weeks;
	int days;
	int is_leap;
};



extern void show_calendar(int year, int month);
#endif // CALENDAR_H_
