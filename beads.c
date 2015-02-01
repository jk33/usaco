/*
ID: johngke1
LANG: C
PROG: beads */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* getNumberofBeads - takes an necklace string and a point to break that necklace and outputs the maximum number of beads */

int getNumberofBeads (char necklace[], int breakingPoint) {

	printf("necklaceLength: %d rightSideLength: %d\n", necklaceLength, rightSideLength);
	int necklaceLength = strlen(necklace);
	int rightSideLength = necklaceLength - breakingPoint;

	//left side, right side of breaking point
	char leftSide[breakingPoint];
	char rightSide[rightSideLength];

	int i;

	//adding beads to leftside
	for (i = 0; i < breakingPoint; i++) {
		leftSide[i] = necklace[i];
	}
	printf("%d : leftside: %s\n", breakingPoint, leftSide);

	//adding beads to rightside
	for (i = breakingPoint; i < necklaceLength; i++) {
		rightSide[i] = necklace[i];
	}
	printf("%d : rightSide: %s\n", breakingPoint, rightSide);

	int largestLength; //largest length of consecutive beads

	for (i = (breakingPoint - 1); i > -1; i--) { //going backwards from breakingpoint
		//loop backwards through leftSide
	}

	for (i = breakingPoint; i < necklaceLength; i++) { 
		//loop forwards through rightSide
	}
		
	
	return 0;	
}

int main() {
	//reading from input
	FILE *input = fopen("beads.in", "r");

	int necklaceSize;

	fscanf(input, "%d\n", &necklaceSize);

//	printf("necklaceSize : %d\n", necklaceSize);

	int i;
	char beads[necklaceSize];

	for (i = 0; i < necklaceSize; i++) {
		fscanf(input, "%c", &beads[i]);
	}

	int largestLength; //largest length
	int currentLength; //current number

	for (i = 0; i < necklaceSize; i++) {
		currentLength = getNumberofBeads(beads, i);
		//printf("currentLength: %d ", currentLength);
		if (currentLength > largestLength) {
			largestLength = currentLength;
		}
		//printf("largestLength: %d\n", largestLength);
	}

}
