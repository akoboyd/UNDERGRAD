/*
Name: Project 1
Date: 10/19/2017
Purpose: An application that will allow the botanist to enter a series of measurements and then display a 5-
		 bin histogram of those measurements
Author: Ako-Akeem Boyd
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;

//Function Prototypes
void getRange(float x[]);
void getBatches(int x, int y, float z[]);
int getNumMeasurements();
int getMeasurement(int x, int y, int z);
int updateBin(int x, int y, int z);
int graph(float y[], int z, int a, int b, int c, int d, int e);

void main() {

	float binCount[5] = { 0 };
	getRange(binCount);
	system("pause");
	
}
void getRange(float binCount[]) {
	int min = 0;
	int max = 0;

	//User enters max and min values. If they don't meet specifications, ask the user again.
	do {
		printf("Please enter the minimum and maximum values (min max): ");
		scanf("%d %d", &min, &max);
		if (min >= max ){
			printf("The values entered (%d and %d) are not valid. The minimum value should be less than the maximum. \n", min, max);
			while (getchar() != '\n');
		}
		else if (max - min < 5) {
			printf("The values entered (%d and %d) must have a difference of at least 5. \n", min, max);
			while (getchar() != '\n');
		}
		else {
			//printf("Successful!\n");
			getBatches(min, max, binCount);
		}
	} while (min > max || max - min < 5);
}
void getBatches(int min, int max, float binCount[]) {

	int count = 0;
	int measurement = 0;
	char response = "";

	//Calculates the bin width
	int binWidth = (max - min) / 5;

	//Establishes bins
	int bin1 = min;
	int bin2 = bin1 + binWidth;
	int bin3 = bin2 + binWidth;
	int bin4 = bin3 + binWidth;
	int bin5 = bin4 + binWidth + 1;

	/*printf("%d \n", bin1);
	printf("%d \n", bin2);
	printf("%d \n", bin3);
	printf("%d \n", bin4);
	printf("%d \n", bin5);*/

	//Initializes bin counts to 0
	int bin1count = 0;
	int bin2count = 0;
	int bin3count = 0;
	int bin4count = 0;
	int bin5count = 0;

	//Get the number of measurements
	count = getNumMeasurements();

	//Gets a measurement, updates the corresponding bin
	for (int i = 1; i <= count; i++) {
		measurement = getMeasurement(i, min, max);
		bin1count += updateBin(measurement, bin1, binWidth);
		bin2count += updateBin(measurement, bin2, binWidth);
		bin3count += updateBin(measurement, bin3, binWidth);
		bin4count += updateBin(measurement, bin4, binWidth);
		bin5count += updateBin(measurement, bin5, binWidth);
		while (getchar() != '\n');
	}

	//Updates the running count of bin number
	binCount[0] += bin1count;
	binCount[1] += bin2count;
	binCount[2] += bin3count;
	binCount[3] += bin4count;
	binCount[4] += bin5count;

	/*for (int i = 0; i <= 4; i++) {
		printf("%lf\n", binCount[i]);
		}*/
	
	//Ask user for another batch
	do {
		printf("Do you have another batch (Y/N)?: ");
		scanf("%c", &response);
		if (response == 'Y' || response == 'y') {
			printf("\n\n");
			getBatches(min, max, binCount); //Call the function again to get more values
			break;
		}
		else if (response == 'N' || response == 'n') {
			printf("\n\n");
			graph(binCount, count, bin1, bin2, bin3, bin4, bin5); //Print graph
			break;
		}
		else {
			printf("This is not a valid response. Please enter 'Y' or 'N' \n"); //Input Validation
			while (getchar() != '\n');
		}
	} while (response != 'Y' || response != 'y' || response != 'N' || response != 'n');
}
int updateBin(int measurement, int bin, int binWidth) {
	int count = 0;
	//Determine if the measurement is in the specified bin
	if (measurement >= bin && measurement < bin + binWidth ) count = 1;	
	return count;
}
int getNumMeasurements() {
	int count = 0;

	//Gets the number of measurements
	do {
		printf("How many measurements are there for this batch: ");
		scanf("%d", &count);
		if (count <= 0) { //Input Validation
			printf("There must be at least 1 measurement. \n"); 
			while (getchar() != '\n');
		}
	} while (count <= 0);
	return count;
}
int getMeasurement(int i, int min, int max) {
	int measurement = 0;
	//Gets the measurement and determines if it is in the range of the max and min
	do {
		printf("Please enter a measurement %d: ", i);
		scanf("%d", &measurement);
		if (measurement < min || measurement > max) { //Input Validation
			printf("The measurement is outside of the given range. Please try again. \n");
			while (getchar() != '\n');
		}
		else {
			break;
		}
	} while (measurement < min || measurement > max);
	return measurement;
}
int graph(float binCount[], int count, int bin1, int bin2, int bin3, int bin4, int bin5) {
	char line = 179;
	char block = 178;
	char corner = 192;
	char l = 196;

	 
	printf("\t\t\tHEIGHT OF BLACK CHERRY TREES\n\n");
	for (int j = 0; j <= 4; j++) {
		binCount[j] /= 10; //Normalize bin count numbers
		//printf("The bin count is %.2lf\n", binCount[j]);
	}
	//Prints histogram
	for(float i = 1.0; i >= 0; i -= 0.10) {
		printf("%2.1lf%c", i, line);

		//If the count at the bin is greater to or equal to i, print a bar at the the position. Else print a space.
		if (binCount[0] + .001 >= i) { 
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[1] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[2] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[3] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[4] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		printf("\n   %c", line);
		if (binCount[0] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[1] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[2] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[3] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		if (binCount[4] + .001 >= i) {
			printf("%c%c%c%c    ", block, block, block, block);
		}
		else {
			printf("        ");
		}
		printf("\n");
	}
	printf("   %c", corner);

	for (int j = 0; j < 35; j++) printf("%c", l); //Prints ASCII value and creates x axis
	printf("\n");

	printf("     %d      %d      %d      %d      %d", bin1, bin2, bin3, bin4, bin5); //Prints bin number under x axis
	printf("\n");
	return 0;
}
