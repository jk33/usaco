/*
ID: johngke1
LANG: C
PROG: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* findIndex - to loop through an array of names and find the index that corresponds to the second parameter (the name)

   this index will be used in the status array */

int findIndex (char nameArray[][14], char name[14]) {
	int i;
	for (i = 0; i < sizeof(&nameArray); i++) {
		if (strncmp(nameArray[i], name, 10) == 0 && strncmp(name, "", 10) != 0) { //checking for blank string
			return i;
		}
	}
	if (strncmp(name, "", 10) != 0) { //if blank string
		;
	}
	else {
		fprintf(stderr, "Error in findIndex: name %s \n", name);
	}
	return 1;
}

int main() {

	FILE *input = fopen("gift1.in", "r");

	//reading initial groupsize
	int groupSize;

	fscanf(input, "%d\n", &groupSize);

	//reading names of group members
	int i;
	

	//each status is the person's dollar amount
	//now setting that to zero
	
	//also adding names into names array

	char names[groupSize][14];
	int statuses[groupSize];


        for (i = 0; i < groupSize; i++) {
                fscanf(input, "%s\n", names[i]);
		printf("scanning name %s\n", names[i]);
		printf("names[%d] = %s\n", i, names[i]);
		statuses[i] = 0;
        }

	//for each name, reading amount, dollar amount, and people
	int amounttoGive;
	int numberofRecipients;
	char giverName[14];

	int g;
	int index;

	//scanning each name
	for (i = 0; i < groupSize; i++) {
		fscanf(input, "%s\n", giverName);
		fscanf(input, "%d %d", &amounttoGive, &numberofRecipients);

		printf("%s giving %d to %d people\n", giverName, amounttoGive, numberofRecipients);

		//error handling to prevent floating point exception
		if (numberofRecipients == 0) {
			fprintf(stderr, "ending at line 81\n");
		}

		else {
			//taking amounttoGive away from giverName

			int index = findIndex(names, giverName);

			//statuses[index] is the status for the giverName
			statuses[index] = statuses[index] - amounttoGive;
			
			//x evenly divided by y
			//x - (x % y) / y
			int distributedAmount = (amounttoGive - (amounttoGive % numberofRecipients)) / numberofRecipients;
			statuses[index] = statuses[index] + (amounttoGive % numberofRecipients);
			printf("giving %d to %s\n", amounttoGive % numberofRecipients, giverName);

			char recipientName[14];
			for (g = 0; g < numberofRecipients; g++) {
				//give distributedAmount to recipients			
				fscanf(input, "%s\n", recipientName);
				printf("recipientName : %s\n", recipientName); //linus
				index = findIndex(names, recipientName);
				printf("names[index] : %s\n\n", names[index]); //poulsen
//				printf("index for %s : %d\nname : %s status : %d\n", recipientName, index, names[index], statuses[index]);
				statuses[index] = statuses[index] + distributedAmount;
//				printf("	giving %d to %s\n	new status of %s : %d\n", distributedAmount, recipientName, names[index], statuses[index]);

			}
		}
	}
	//print names/amounts
	
	FILE *output = fopen("gift1.out", "w");

	for (i = 0; i < groupSize; i++) {
		fprintf(output, "%s %d\n", names[i], statuses[i]);
	}
	fclose(output);
	fclose(input);
}
