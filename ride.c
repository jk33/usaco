/*
ID: johngke1
LANG: C
PROG: ride
*/

/* ride.c
	solves usaco ride problem */

#include <stdio.h>
#include <stdlib.h>

//int stringtoNumber - takes a string, converts all chars to their number in the alphabet, then multiplies those numbers together

int stringtoNumber(char inputString[]) {

	int product = 1; //all numbers will be multiplied to this number

	/* loops through string to find the letter and then multiply the char's position in the alphabet to the product var */

	char alphabet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	int g;
	for (i = 0; i < 6; i++) {
		for (g = 1; g < 27; g++) {
			if (inputString[i] == alphabet[g]) {
				product = g * product;
			}
		}
	}
	return product;
}

int main() {
	FILE *input = fopen("ride.in", "r");
	FILE *output = fopen("ride.out", "w");

	char cometString[7];
	char groupString[7];

	fscanf(input, "%s\n", cometString);	
	fscanf(input, "%s\n", groupString);

	char *cometStringP = cometString;
	char *groupStringP = groupString;
	
	int cometNumber = stringtoNumber(cometStringP);
	int groupNumber = stringtoNumber(groupStringP);	


	int cometMod = cometNumber % 47;
	int groupMod = groupNumber % 47;	

	if (cometMod == groupMod) {
		fprintf(output, "GO\n");
	}
	else {
		fprintf(output, "STAY\n");
	}

	fclose(input);
	fclose(output);

	exit(0);
}
