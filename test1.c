
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findIndex (char *nameArray[10], char name[14]) {
	int i;
	for (i = 0; i < sizeof(&nameArray); i++) {
		if (strncmp(nameArray[i], name, 10) == 0) {
			return i;
		}
	}
	fprintf(stderr, "Error in findIndex: name %s \n", name);
	return 1;
}

int main() {

	FILE *input = fopen("gift1.in", "r");

	FILE *log = fopen("log", "a");

	//reading initial groupsize
	int groupSize;

	fscanf(input, "%d\n", &groupSize);

	fprintf(log, "groupSize: %d\n", groupSize);

	//reading names of group members
	int i;

	//each status is the person's dollar amount
	//now setting that to zero
	
	//also adding names into names array
	char name[14];

	char *names[groupSize];
	int statuses[groupSize];

	for (i = 0; i < groupSize; i++) {
		//names
		fscanf(input, "%s\n", name);
                fprintf(log, "name: %s\n", name);
		names[i] = name;
//		strcpy(names[i], name);
	
		//status
		statuses[i]  = 0;

	}
}
