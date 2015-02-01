/*
ID: johngke1
LANG: C
PROG: friday
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int currentDay = 1; //1st
	int currentYear;
	int actualDay;

	int month = 1;

	int daysinMonth;

	int normalYear[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31}; //normalYear[1] = January
	int leapYear[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //ditto
	int yearRange = 0;
	
	FILE* input = fopen("friday.in", "r");
	fscanf(input, "%d\n", &yearRange);

	printf("yearRange: %d\n", yearRange);
	//each time the 13th lands on this day, the corresponding array
	int dayStatuses[] = {0, 0, 0, 0, 0, 0, 0};

	int endDate = 1900 + yearRange;
	int day = 1; // represents 1/1/1900
	int dayofWeek = 1; // 1/1/1900 was a monday

	int g;

	int nextMonthStartDay = 1; //the day of week that the next month starts at

	printf("endDate: %d\n", endDate);

	for (currentYear = 1900; currentYear < endDate; currentYear++) { //looping through year
		for (month = 1; month < 13; month++) { //looping through month
			day = nextMonthStartDay; //between 1-7
			if (currentYear % 100 == 0 && currentYear %400 != 0) { //if century year but not divisible by 400
				daysinMonth = normalYear[month]; //then normal year
			}
			else if (currentYear % 400 == 0) {//if divisible by 400
				daysinMonth = leapYear[month];
			}
				
			else if (currentYear % 4 == 0) { //leap year
				daysinMonth = leapYear[month];
			}
			else {
				daysinMonth = normalYear[month];
			}

			//looping until the 13th	
			for (actualDay = 1; actualDay != 13; actualDay++) {
				day++;
			}			

			dayofWeek = (day + 1) % 7;

			dayStatuses[dayofWeek] = dayStatuses[dayofWeek] + 1;
			//looping through the rest of the days of the month	
			for (g = actualDay; g < daysinMonth; g++) {
				day++;
			}
			nextMonthStartDay = (day + 1) % 7;	
		}
	}

	fclose(input);

	FILE* output = fopen("friday.out", "w");

	fprintf(output, "%d %d %d %d %d %d %d\n", dayStatuses[0], dayStatuses[1], dayStatuses[2], dayStatuses[3], dayStatuses[4], dayStatuses[5], dayStatuses[6]);

	fclose(output);	
}	
