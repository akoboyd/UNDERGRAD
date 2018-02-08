/*
Name: Assignment 6
Date: 10/12/2017
Purpose: This program reads in values from a text file
		 uses recusion to identify all the points on 
		 the paths in a maze.
Author: Ako-Akeem Boyd
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <stdlib.h>;

/*Define dimensions*/
#define height 21
#define width 78

/*Define function protypes*/
void Read_Map(int x[height][width], FILE* y);
void Display_Map(int x[height][width]);

void main() {

	/*Create map array and intialize size to the dimensions*/
	int map[height][width];
	
	FILE* infile = fopen("map_6.txt", "r"); //Opens file in read mode
	Read_Map(map, infile);
	Display_Map(map);
	system("pause");
}

void Read_Map(int map[height][width], FILE* infile) {
	char temp = "";
	if (infile != NULL) { //While the file exist
		printf("Open Successful! \n");

		/*Reads in values by row then column*/
		for (int i = 0; i < height; i++) { //Row Loop
			for (int j = 0; j < width; j++) { //Column Loop
				fscanf(infile, "%c", &temp); //Reads in value and places in temp variable
				if (temp == 'X') map[i][j] = 1; //Place a 1 in array index
				else {
					map[i][j] = 0; //Place a 0 in array index
				}
				/*If there is a new line character, place a 0 in the array index until the you've reach the width of the array*/
				if (temp == '\n') {
					for (j; j < width; j++) {
						map[i][j] = 0;
					}
					break; //break out of the Column loop
				}
			}

		}
		fclose(infile); // Close file
	}
	else{	
		printf("File Not Found\n"); // Print if the file can't be found
	}	
}

void Display_Map(int map[height][width]) {
	for (int i = 0; i < height; i++) { //Row Loop
		for (int j = 0; j < width; j++) { //Column Loop
			if (map[i][j] == 0) printf("%c", 176); //Print character if the array index is equal to 0
			else {
				printf(" "); //Print space
			}
		}
		printf("\n");
	}
}