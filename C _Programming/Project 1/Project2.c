/*
Name: Project 2
Date: 12/4/2017
Purpose: Create an applicatoin that can be marketed as a solution for data collection and visualization
Author: Ako-Akeem Boyd
*/
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 24
#define COLUMNS 80
#include <stdio.h>;
#include <conio.h>;
#include <math.h>;
#include <stdlib.h>

void ClearPage(char a[ROWS][COLUMNS]);
char DisplayPage(char a[ROWS][COLUMNS]);
void DisplayPage2(char page[ROWS][COLUMNS], char word[]);
void getBatches(int min, int max, float binCount[5][5], int dataMax[], float data[5][50]);
char Statistics(char title[], char selection[], char banks[5][15], float data[5][50], char page[ROWS][COLUMNS]);
void NewPage(char title[], char selection[], char choice[], char page[ROWS][COLUMNS]);
void InsertText(char title[], char selection[], char page[ROWS][COLUMNS], int length[]);
char DisplayTitle(char title[], char selection[], char choice[], char page[ROWS][COLUMNS]);
void BankTitle(char title[], char selection[], char choice[], char banks[5][15], int n, char page[ROWS][COLUMNS]);
char MeasurementPage(char title[], char selection[], char banks[5][15], float data[5][50], char page[ROWS][COLUMNS]);
char DisplayTitle3(char title[], char selection[], char choice[], float data[5][50], int addBank, int start[5], char page[ROWS][COLUMNS], int dataMax[5]);
void graph(char title[], char selection, float binCount[5][5], char page[ROWS][COLUMNS]);
/*
Accepts a title and status message, clears and sets up the pages array to have borders,
place a title in the header section, and a status message in the footer section
*/
void main() {
	char page[ROWS][COLUMNS];
	float data[5][50] = { { 40.9799,  116.0669,   85.9172,   68.7723,   58.2823,  134.4404,   98.5348,  122.7901,  101.6063,   96.7513,  138.5480,  156.4141,  225.6080,   52.1351,   68.8695,  171.8917,  100.5100,   50.9367,  135.7771,  197.6621,  155.3947,  217.8692,  145.2271,  213.2265,  103.0094,   63.0110,  109.4438,  179.5122,   64.1896,  151.7637,   89.9294,  147.5592,   65.0080,  124.2995,   19.7718,   95.3456,  143.1024,  103.9498,  181.8278,   88.4360,    3.7394,   58.4182,  172.7824,  114.3388,  138.9612,  167.2100,   13.9787,   87.7661,   84.7849,   69.0931 },
	{ 74.5375,  125.6304,   78.8468,  116.8234,   59.1139,   80.2257,   56.5132,   97.6082,   72.4638,   94.4041,  100.0447,   77.6504,  106.6752,  149.2786,   95.7392,   79.6464,  107.3942,   81.6782,   46.7879,   94.5649,   79.8498,   71.7135,  118.2936,  135.9020,   64.3232,   83.1027,   55.7705,  100.4132,    9.0623,  109.7034,   86.5670,   87.8499,  116.4033,   71.7600,   76.0060,   41.8850,   30.0918,   58.8934,   88.4264,   63.7637,   39.9941,  112.1806,   58.6374,   79.6614,   79.9755,   72.5169,   91.8973,   72.0796,   30.0797,   49.1307 },
	{ 132.1547,   57.1705,  102.6408,   72.9314,   61.2720,   68.9429,   99.9167,  128.6833,  114.1941,  173.2060,  107.7307,   44.1230,  120.4867,  123.5686,  135.8268,  144.9913,  183.9042,   92.6092,  133.0404,  119.3412,   90.9868,  226.8154,  107.1191,   49.5236,  208.5050,  136.2773,   64.0480,  151.0175,  183.4891,   75.1979,  126.7588,  113.0480,   61.8302,  179.1860,  119.2285,  146.8109,   84.1786,   87.2220,  135.7181,  125.3407,  212.4108,  106.2447,  230.6277,  195.4263,   22.7461,   35.9729,   91.3233,  110.7092,  120.4467,  161.8475 },
	{ 83.8865,   83.9255,  109.9410,  118.9768,  133.9445,  172.9147,  151.0837,   32.4692,  154.8674,  160.5743,  151.8172,  185.5040,  136.3549,   86.3503,  112.5336,   -2.4509,  143.6643,  125.8473,   90.4448,   87.2646,   65.9669,  117.6135,  138.9672,  103.4819,   95.0051,  118.2011,  111.2620,   72.1367,  184.6274,  142.0455,  184.0470,   95.1135,   64.0642,  160.3825,  122.0600,   82.1896,  115.5435,   19.5575,  174.1959,   70.9405,   85.5756,  186.9740,   74.5378,   99.3571,   94.6918,  200.9874,  124.0450,   65.9472,   63.7741,  206.7838 },
	{ 216.8729,  201.7534,   57.2030,  109.3231,  110.0534,  135.3750,   91.3837,   71.1176,   97.6595,  174.1046,  238.6324,  131.4644,  106.6688,  155.0836,   95.6205,  213.1240,  175.3426,   58.6217,   86.5057,  187.0465,  139.4042,  139.6529,   34.6333,  131.3929,  154.2816,   88.1605,   69.8697,  110.7190,   67.2984,  116.4230,  133.9599,  188.6638,  128.9921,   92.8992,  201.7095,  161.2608,  131.5381,  153.5817,   94.5961,  162.8176,  133.4252,  151.2488,   67.6331,  196.7835,  141.7213,   24.1432,  143.4970,  183.7176,  151.9271,  189.0391 } };
	char banks[5][15] = { "Bank 1", "Bank 2", "Bank 3", "Bank 4", "Bank 5" };
	int	dataMax[5] = { 0,0,0,0,0 };
	int dataMax2[5] = { (50 - dataMax[0]), (50 - dataMax[1]), (50 - dataMax[2]), (50 - dataMax[3]), (50 - dataMax[4]) };
	char titlepage = '0';
	char measurepage = '0';
	char statspage = '0';
	char visualpage = '0';
	int count = 0;
	int start[5] = { 0 };
	int i, j, k, l;
	float min, max;
	min = data[0][0];
	max = data[0][0];
	float binCount[5][5] = { 0 };
	for (k = 0; k < 5; k++) {
		for (j = 0; j < 50; j++) {
			if (data[k][j] <= min) min = data[k][j];
			if (data[k][j] >= max) max = data[k][j];
		}
	}
	do {
		//Displays title page with options
		titlepage = DisplayTitle("Morgan State Data Visualizer", "Please enter a menu selection", "[1]Manage Measurements\n[2]View Measurement Data & Statistics\n[3]Visualize Measurements\n[4]Exit\n", page);
		if (titlepage == '1') {
			do {
				measurepage = DisplayTitle("Manage Measurements", "Please enter a menu selection", "[1]Clear Measurements\n[2]Add to Measurements\n[3]Change Memory Bank Label\n[4]Return to Main Menu\n", page);
				if (measurepage == '1') {
					do {
						//Clear entries of a specified bank
						measurepage = DisplayTitle("Clear Measurements", "Please enter a menu selection", "[1]Clear Bank 1\n[2]Clear Bank 2\n[3]Clear Bank 3\n[4]Clear Bank 4\n[5]Clear Bank 5\n[6]Return to Manage Measurements\n", page);
					} while (!(measurepage >= '1' && measurepage <= '6'));

					if (measurepage == '1') {
						for (i = 0; i < 50; i++) {
							data[0][i] = 0;
						}
						measurepage = DisplayTitle("Data Bank Cleared", "Press any key to return", "All data from Bank 1 has been cleared\n", page);
						dataMax[0] = 50;
						measurepage = '0';
					}
					else if (measurepage == '2') {
						for (i = 0; i < 50; i++) {
							data[1][i] = 0;
						}
						measurepage = DisplayTitle("Data Bank Cleared", "Press any key to return", "All data from Bank 2 has been cleared\n", page);
						dataMax[1] = 50;
						measurepage = '0';
					}
					else if (measurepage == '3') {
						for (i = 0; i < 50; i++) {
							data[2][i] = 0;
						}
						measurepage = DisplayTitle("Data Bank Cleared", "Press any key to return", "All data from Bank 3 has been cleared\n", page);
						dataMax[2] = 50;
						measurepage = '0';
					}
					else if (measurepage == '4') {
						for (i = 0; i < 50; i++) {
							data[3][i] = 0;
						}
							measurepage = DisplayTitle("Data Bank Cleared", "Press any key to return", "All data from Bank 4 has been cleared\n", page);
							dataMax[3] = 50;
							measurepage = '0';
					}
					else if (measurepage == '5') {
						for (i = 0; i < 50; i++) {
							data[4][i] = 0;
						}
						measurepage = DisplayTitle("Data Bank Cleared", "Press any key to return", "All data from Bank 5 has been cleared\n", page);
						dataMax[4] = 50;
						measurepage = '0';
					}
					else if (measurepage == '6') {
						measurepage = '0';
						}
				}
				else if (measurepage == '2') {
					do{
						//Add Entries to a specified bank
						measurepage = DisplayTitle("Add to Measurements", "Please enter a menu selection", "[1]Add to Bank 1\n[2]Add to Bank 2\n[3]Add to Bank 3\n[4]Add to Bank 4\n[5]Add to Bank 5\n[6]Return to Manage Measurements\n", page);
					
					if (measurepage == '1') {
							start[0] = 50 - dataMax[0];
							if (start[0] == 50) {
								measurepage = DisplayTitle("Add to Bank 1", "Press any key to return", "Bank 1 is full\n", page);
								measurepage = '0';
							}
							else {
								int addBank = 0;
								measurepage = DisplayTitle3("Add to Bank 1", "Please enter your measurements", "This measurement bank has room for 50 additional measurements\nPlease enter additional measurements seperated by a comma.\n", data, addBank, start, page, dataMax);
							}
						}
						else if (measurepage == '2') {
							start[1] = 50 - dataMax[1];
							if (start[1] == 50) {
								measurepage = DisplayTitle("Add to Bank 2", "Press any key to return", "Bank 2 is full\n", page);
								measurepage = '0';
							}
							else {
								int addBank = 1;
								measurepage = DisplayTitle3("Add to Bank 2", "Please enter your measurements", "This measurement bank has room for 50 additional measurements\nPlease enter additional measurements seperated by a comma.\n", data, addBank, start, page, dataMax);
							}
						}
						else if (measurepage == '3') {
							start[2] = 50 - dataMax[2];
							if (start[2] == 50) {
								measurepage = DisplayTitle("Add to Bank 3", "Press any key to return", "Bank 3 is full\n", page);
								measurepage = '0';
							}
							else {
								int addBank = 2;
								measurepage = DisplayTitle3("Add to Bank 3", "Please enter your measurements", "This measurement bank has room for 50 additional measurements\nPlease enter additional measurements seperated by a comma.\n", data, addBank, start, page, dataMax);
							}
						}
						else if (measurepage == '4') {
							start[3] = 50 - dataMax[3];
							if (start[3] == 50) {
								measurepage = DisplayTitle("Add to Bank 4", "Press any key to return", "Bank 4 is full\n", page);
								measurepage = '0';
							}
							else {
								int addBank = 3;
								measurepage = DisplayTitle3("Add to Bank 4", "Please enter your measurements", "This measurement bank has room for 50 additional measurements\nPlease enter additional measurements seperated by a comma.\n", data, addBank, start, page, dataMax);
							}
						}
						else if (measurepage == '5') {
							start[4] = 50 - dataMax[4];
							if (start[4] == 50) {
								measurepage = DisplayTitle("Add to Bank 5", "Press any key to return", "Bank 5 is full\n", page);
								measurepage = '0';
							}
							else {
								int addBank = 4;
								measurepage = DisplayTitle3("Add to Bank 5", "Please enter your measurements", "This measurement bank has room for 50 additional measurements\nPlease enter additional measurements seperated by a comma.\n", data, addBank, start, page, dataMax);
							}
						}
						else if (measurepage == '6') {
							break;
						}
					} while (!(measurepage >= '1' && measurepage <= '6'));
				}
				else if (measurepage == '3') {
					do {
						//Change Name of specified bank
						measurepage = DisplayTitle("Change Memory Bank Label", "Please enter a menu selection", "[1]Change label for Bank 1\n[2]Change label for Bank 2\n[3]Change label for Bank 3\n[4]Change label for Bank 4\n[5]Change label for Bank 5\n[6]Return to Manage Measurements\n", page);
						char sentence[1000] = "Change label for ";
						if (measurepage == '1') {
							BankTitle(strcat(sentence, banks[0]), "Please enter the new label", "Enter a descriptive label for this measurement.\nPlease note the label is limited to 12 characters.\n", banks, 0, page);
							measurepage = '0';
						}
						else if (measurepage == '2') {
							BankTitle(strcat(sentence, banks[1]), "Please enter the new label", "Enter a descriptive label for this measurement.\nPlease note the label is limited to 12 characters.\n", banks, 1, page);
							measurepage = '0';
						}
						else if (measurepage == '3') {
							BankTitle(strcat(sentence, banks[2]), "Please enter the new label", "Enter a descriptive label for this measurement.\nPlease note the label is limited to 12 characters.\n", banks, 2, page);
							measurepage = '0';
						}
						else if (measurepage == '4') {
							BankTitle(strcat(sentence, banks[3]), "Please enter the new label", "Enter a descriptive label for this measurement.\nPlease note the label is limited to 12 characters.\n", banks, 3, page);
							measurepage = '0';
						}
						else if (measurepage == '5') {
							BankTitle(strcat(sentence, banks[4]), "Please enter the new label", "Enter a descriptive label for this measurement.\nPlease note the label is limited to 12 characters.\n", banks, 4, page);
							measurepage = '0';							}
						else if (measurepage == '6') {
							break;
						}
					}while(!(measurepage >= '1' && measurepage <= '6'));
				}
				else if (measurepage == '4') {
					titlepage = '0';
					break;
				}
			}while (!(measurepage >= '1' && measurepage <= '4'));
		}
		else if (titlepage == '2') {
			do{
				//View Data of Banks in a table or through statisics
				statspage = DisplayTitle("View Measurement Data & Statistics", "Please enter a menu selection", "[1]View All Measurements\n[2]View Statistics\n[3]Return to Main Menu\n", page);
				if (statspage == '1') {
					statspage = MeasurementPage("View All Measurements", "Press any key to return", banks, data, page);
				}
				else if (statspage == '2') {
					statspage = Statistics("View Statistics", "Press any key to return", banks, data, page);
					
				}
				else if (statspage == '3') {
					titlepage = '0';
					break;
				}
			} while (!(statspage >= '1' && statspage <= '3'));
		}
		else if (titlepage == '3') {
			do {
				//Display Bank data in histogram or scatter plot
				visualpage = DisplayTitle("Visualize Measurements", "Please enter a menu selection", "[1]Show Histogram\n[2]Show Scatter Plot\n[3]Return to Main Menu\n", page);
				if (visualpage == '1') {
					getBatches(min, max, binCount, dataMax2, data);
					graph("Histogram", "Press any key to return", binCount, page);
				}
				else if (visualpage == '2') {
					visualpage = DisplayTitle("View Statistics", "Please enter a menu selection", "[1]Add to Bank 1\n[2]Add to Bank 2\n[3]Add to Bank 3\n[4]Add to Bank 4\n[5]Add to Bank 5\n[6]Return to Manage Measurements\n", page);
				}
				else if (visualpage == '3') {
					titlepage = '0';
					break;
				}
			} while (!(visualpage >= '1' && visualpage <= '3'));
		}
		else if (titlepage == '4') {
			system("cls");
		}
	} while (!(titlepage >= '1' && titlepage <= '4'));
		system("pause");
}


void getBatches(int min, int max, float binCount[5][5], int dataMax[], float data[5][50]) {

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


	//Get the number of measurements
	for (int l = 0; l < 5; l++) {
		int bin1count = 0;
		int bin2count = 0;
		int bin3count = 0;
		int bin4count = 0;
		int bin5count = 0;
		count = dataMax[l];

		//Gets a measurement, updates the corresponding bin
		for (int i = 0; i < count; i++) {
			measurement = data[l][i];
			bin1count += updateBin(measurement, bin1, binWidth);
			bin2count += updateBin(measurement, bin2, binWidth);
			bin3count += updateBin(measurement, bin3, binWidth);
			bin4count += updateBin(measurement, bin4, binWidth);
			bin5count += updateBin(measurement, bin5, binWidth);
		}

		//Updates the running count of bin number
		binCount[l][0] += bin1count;
		binCount[l][1] += bin2count;
		binCount[l][2] += bin3count;
		binCount[l][3] += bin4count;
		binCount[l][4] += bin5count;
	}
}
int updateBin(int measurement, int bin, int binWidth) {
	int count = 0;
	//Determine if the measurement is in the specified bin
	if (measurement >= bin && measurement < bin + binWidth) count = 1;
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

void graph(char title[], char selection[], float binCount[5][5], char page[ROWS][COLUMNS]) {
	char block = 178;
	char leftT = 204;
	char rightT = 185;
	char bar = 178;
	char topLeft = 201;
	char bottomLeft = 200;
	char hor = 205;
	char vert = 186;
	char topRight = 187;
	char bottomRight = 188;
	char bottomLine = 196;
	char corner = 192;
	int i, j, start1, start2, end1, end2;
	int emptySpace = 0;
	int length[2] = { 0 };
	char line = 179;
	//char *p3 = choice;
	int row = 4;
	int col = 0;
	ClearPage(page);

	page[0][0] = topLeft;
	for (i = 1; i < (COLUMNS - 1); i++) {
		page[0][i] = hor;
	}
	page[0][79] = topRight;
	page[1][0] = vert;
	InsertText(title, selection, page, length);
	start1 = ((COLUMNS - length[0]) / 2);
	end1 = start1 + length[0];
	for (j = 1; j < start1 - 2; j++) {
		page[1][j] = bar;
	}
	for (j = end1 + 2; j < (COLUMNS - 1); j++) {
		page[1][j] = bar;
	}
	page[1][79] = vert;
	page[2][0] = leftT;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[2][j] = hor;
	}
	page[2][79] = rightT;

	emptySpace = 3;
	for (i = emptySpace; i < ROWS - 20; i++) {
		page[i][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			page[i][j] = ' ';
		}
		page[i][79] = vert;
	}

	

	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++)
		binCount[j][k] /= 10; //Normalize bin count numbers
	}
	//Prints histogram
	for (float i = 1.0; i >= 0; i -= 0.10) {
		page[row][col] = vert;
		col++;
		char string[1000];
		char *p = string;
		sprintf(string, "%.1f", i);
		while (*p != '\0') page[row][col++] = *p++;
		page[row][col] = line;
		//printf("%2.1lf%c", i, line);
		col++;
		//If the count at the bin is greater to or equal to i, print a bar at the the position. Else print a space.
		for (int j = 0; j < 5; j++) {
			if (binCount[0][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[1][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[2][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[3][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[4][j] + .001 >= i) {
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			col += 2;
		}
		page[row][79] = vert;
		row++;
		col = 0;
		page[row][0] = vert;
		page[row][4] = line;
		col++;
		//If the count at the bin is greater to or equal to i, print a bar at the the position. Else print a space.
		for (int j = 0; j < 5; j++) {
			if (binCount[0][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[1][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[2][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[3][j] + .001 >= i) {
				page[row][col] = block;
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			if (binCount[4][j] + .001 >= i) {
				col++;
				//printf("%c%c%c%c    ", block, block, block, block);
			}
			else {
				col++;
			}
			col += 2;
		}
		page[row][79] = vert;
		row++;
		col = 0;
	}
	page[row][col] = vert;
	col++;
	page[row][col] = corner;
	for (int j = 0; j < 35; j++) page[row][col++] = 196; 
	page[row][79] = vert;
	page[20][0] = vert;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[20][j] = bottomLine;
	}
	page[20][79] = vert;
	page[21][0] = vert;

	for (j = (COLUMNS - length[1]); j < (COLUMNS - 1); j++) {
		page[21][j] = ' ';
	}
	page[21][79] = vert;
	page[22][0] = bottomLeft;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[22][j] = hor;
	}
	page[22][79] = bottomRight;
	DisplayPage(page);
}

//Set all the elements of the pages array to spaces
void ClearPage(char page[ROWS][COLUMNS]) {
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			page[i][j] = ' ';
		}
	}
}

//Clear the console and display the content of the pages array
char DisplayPage(char page[ROWS][COLUMNS]) {
	char selNumber = '0';
	system("cls");
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%c", page[i][j]);
		}
	}
	selNumber = _getch();
	return selNumber;
}
//Clears the console and display the content of the pages array. Requires an input upon exiting.
void DisplayPage2(char page[ROWS][COLUMNS], char word[]) {
	system("cls");
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%c", page[i][j]);
		}
	}
	fgets(word, 1000, stdin);	
}

//Clears the console and display the content of the pages array. Requires an input upon exiting. For adding entries into the bank
void DisplayPage3(char page[ROWS][COLUMNS], float data[5][50], int start[5], int bank, int dataMax[5]) {
	system("cls");
	char word[1000];
	int i, j;
	char *p1 = word;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%c", page[i][j]);
		}
	}
	fgets(word, 1000, stdin);
	do {
		if (*p1 == ',') *p1++;
		else if (*p1 == '\n') break;
		char string1[1000];
		char *p2 = string1;
		while (*p1 != ',' && *p1 != '\n') {
			*p2++ = *p1++;
		}
		double x = atof(string1);
		data[bank][start[bank]++] = x;
	}while (*p1 != '\n');
	dataMax[bank] -= start[bank];
}

//Calls New Page, InsertText, ClearPage, and DisplayPage to add values bank data
char DisplayTitle3(char title[], char selection[], char choice[], float data[5][50], int addBank, int start[5], char page[ROWS][COLUMNS], int dataMax[5]) {
	NewPage(title, selection, choice, page);
	DisplayPage3(page, data, start, addBank, dataMax);
	return '0';
}

//Creates a new page by filling the pages array with the given parameters required for that page. 
void NewPage(char title[], char selection[], char choice[], char page[ROWS][COLUMNS]) {
	char leftT = 204;
	char rightT = 185;
	char bar = 178;
	char topLeft = 201;
	char bottomLeft = 200;
	char hor = 205;
	char vert = 186;
	char topRight = 187;
	char bottomRight = 188;
	char bottomLine = 196;
	int i, j, start1, start2, end1, end2;
	int emptySpace = 0;
	int length[2] = { 0 };
	char *p3 = choice;
	int row = 4;
	ClearPage(page);

	page[0][0] = topLeft;
	for (i = 1; i < (COLUMNS - 1); i++) {
		page[0][i] = hor;
	}
	page[0][79] = topRight;
	page[1][0] = vert;
	InsertText(title, selection, page, length);
	start1 = ((COLUMNS - length[0]) / 2);
	end1 = start1 + length[0];
	for (j = 1; j < start1 - 2; j++) {
		page[1][j] = bar;
	}
	for (j = end1 + 2; j < (COLUMNS - 1); j++) {
		page[1][j] = bar;
	}
	page[1][79] = vert;
	page[2][0] = leftT;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[2][j] = hor;
	}
	page[2][79] = rightT;

	emptySpace = 3;
	for (i = emptySpace; i < ROWS - 20; i++) {
		page[i][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			page[i][j] = ' ';
		}
		page[i][79] = vert;
	}
	do {
		page[row][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			if (*p3 == '\n') {
				for (int k = j; k < (COLUMNS - 1); k++) {
					page[row][k] = ' ';
				}
				p3++;
				break;
			}
			else {
				page[row][j] = *p3;
				p3++;
			}
		}
		page[row][79] = vert;
		row++;
	} while (*p3 != '\0');
	emptySpace = row;
	for (i = emptySpace; i < ROWS - 4; i++) {
		page[i][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			page[i][j] = ' ';
		}
		page[i][79] = vert;
	}
	page[20][0] = vert;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[20][j] = bottomLine;
	}
	page[20][79] = vert;
	page[21][0] = vert;

	for (j = (COLUMNS - length[1]); j < (COLUMNS - 1); j++) {
		page[21][j] = ' ';
	}
	page[21][79] = vert;
	page[22][0] = bottomLeft;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[22][j] = hor;
	}
	page[22][79] = bottomRight;
}

//Place a given string of text at a specific row and column starting within the pages array
void InsertText(char title[], char selection[], char page[ROWS][COLUMNS], int length[]) {
	int count1 = strlen(title);
	int count2 = strlen(selection);
	char *p1 = title;
	char *p2 = selection;
	int start1 = ((COLUMNS - count1) / 2);
	int end1 = start1 + count1;
	int i, j;

	for (i = start1; i < end1; i++){
		page[1][i] = *p1;
		p1++;
		(length[0])++;
	}
	
	for (j = 1; j <= count2 + 1; j++) {
		page[21][j] = *p2;
		p2++;
		length[1]++;
	}
}
//Changes the bank title
void BankTitle(char title[], char selection[], char choice[], char banks[5][15], int n, char page[ROWS][COLUMNS]) {
	char word[1000];
	NewPage(title, selection, choice, page);
	DisplayPage2(page, word);
	char *b = word;
	int pos = 0;
	if (n == 0) {
		do {
			if (*b != '\n')
				banks[n][pos++] = *b++;
		} while (*b != '\n');
	}
	if (n == 1) {
		do {
			if (*b != '\n') banks[n][pos++] = *b++;
		} while (*b != '\n');
	}
	if (n == 2) {
		do {
			if (*b != '\n') banks[n][pos++] = *b++;
		} while (*b != '\n');
	}
	if (n == 3) {
		do {
			if (*b != '\n') banks[n][pos++] = *b++;
		} while (*b != '\n');
	}
	if (n == 4) {
		do {
			if (*b != '\n') banks[n][pos++] = *b++;
		} while (*b != '\n');
	}
		while (banks[n][pos] != '\0') banks[n][pos++] = '\0';
}
	
//Calls NewPage, InsertText, and DisplayPage to display a menu page and return a valid menu selection
char DisplayTitle(char title[], char selection[], char choice[], char page[ROWS][COLUMNS]) {
	NewPage(title, selection, choice, page);
	char page1 = DisplayPage(page);
	return page1;
}

//Creates table for the bank statistics
char MeasurementPage(char title[], char selection[], char banks[5][15], float data[5][50], char page[ROWS][COLUMNS]) {
	int u, d, p;
	char bank1[50][50];
	char bank2[50][50];
	char bank3[50][50];
	char bank4[50][50];
	char bank5[50][50];
	char string1[1000];
	u = 0;
	for (d = 0; d < 50; d++) {
		sprintf(string1, "%.4f", data[u][d]);
		char *p2 = string1;

		for (p = 0; p < 50; p++) {
			if (*p2 != '\0') {
				bank1[d][p] = *p2++;
			}
			else {
				bank1[d][p] = '\0';
				break;
			}
		}
	}
	u++;
	for (d = 0; d < 50; d++) {
		sprintf(string1, "%.4f", data[u][d]);
		char *p2 = string1;

		for (p = 0; p < 50; p++) {
			if (*p2 != '\0') {
				bank2[d][p] = *p2++;
			}
			else {
				bank2[d][p] = '\0';
				break;
			}
		}
	}
	u++;
	for (d = 0; d < 50; d++) {
		sprintf(string1, "%.4f", data[u][d]);
		char *p2 = string1;

		for (p = 0; p < 50; p++) {
			if (*p2 != '\0') {
				bank3[d][p] = *p2++;
			}
			else {
				bank3[d][p] = '\0';
				break;
			}
		}
	}
	u++;
	for (d = 0; d < 50; d++) {
		sprintf(string1, "%.4f", data[u][d]);
		char *p2 = string1;

		for (p = 0; p < 50; p++) {
			if (*p2 != '\0') {
				bank4[d][p] = *p2++;
			}
			else {
				bank4[d][p] = '\0';
				break;
			}
		}
	}
	u++;
	for (d = 0; d < 50; d++) {
		sprintf(string1, "%.4f", data[u][d]);
		char *p2 = string1;

		for (p = 0; p < 50; p++) {
			if (*p2 != '\0') {
				bank5[d][p] = *p2++;
			}
			else {
				bank5[d][p] = '\0';
				break;
			}
		}
	}
	char cross = 197;
	char lc = 195;
	char rc = 180;
	char bar = 178;
	char topLeft = 201;
	char bottomLeft = 200;
	char hor = 205;
	char vert = 186;
	char topRight = 187;
	char bottomRight = 188;
	char bottomLine = 196;
	char leftc = 218;
	char rightc = 191;
	char line = 179;
	int i, j, start1, start2, end1, end2;
	int emptySpace = 0;
	int length[2] = { 0 };
	int row = 0;
	int a = 0;
	int b = 0;
	int col = 0;
	int count = 0;
	char ut = 194;
	char bt = 193;
	char *p3;
	ClearPage(page);

	page[0][0] = topLeft;
	for (i = 1; i < (COLUMNS - 1); i++) {
		page[0][i] = hor;
	}
	page[0][79] = topRight;
	page[1][0] = vert;
	InsertText(title, selection, page, length);
	start1 = ((COLUMNS - length[0]) / 2);
	end1 = start1 + length[0];
	for (j = 1; j < start1 - 2; j++) {
		page[1][j] = bar;
	}
	for (j = end1 + 2; j < (COLUMNS - 1); j++) {
		page[1][j] = bar;
	}
	page[1][79] = vert;

	emptySpace = 2;
	for (i = emptySpace; i < ROWS - 20; i++) {
		page[i][0] = vert;
		page[i][79] = vert;
	}
	page[4][0] = vert;
	page[4][3] = leftc;
	for (j = 4; j < (COLUMNS - 4); j++) {
		page[4][j] = bottomLine;
	}
	col = 6;
	while (col < 63) {
		page[4][col] = ut;
		col += 14;
	}
	page[4][76] = rightc;
	page[4][79] = vert;
	page[5][0] = vert;
	page[5][3] = line;
	page[5][6] = line;
	col = 6;
	int start;
	do {
		start = col;
		do {
			
			if (banks[a][b] != '\0') {
				page[5][++col] = banks[a][b++];
				count++;
			}
		} while (banks[a][b] != '\0');

		col = start + 14;
		page[5][col] = line;
		a++;
		b = 0;
		count = 0;
	} while (a < 5);
	page[5][79] = vert;
	page[6][0] = vert;
	page[6][3] = lc;
	for (j = 4; j < (COLUMNS - 4); j++) {
		page[6][j] = bottomLine;
	}
	col = 6;
	while (col < 63) {
		page[6][col] = cross;
		col += 14;
	}
	page[6][76] = rc;
	page[6][79] = vert;
	row = 7;
	col = 0;
	int entry = 1;
	char string[50];
	u = 0;
	d = 0;
	do {
		sprintf(string, "%d", entry);
		char *p = string;
		page[row][col] = vert;
		col += 3;
		page[row][col] = line;
		col++;
		while (*p != '\0') page[row][col++] = *p++;
		col = 6;
		page[row][col] = line;
		count = 0;
		do {
			if (bank1[u][d] != '\0') {
				page[row][++col] = bank1[u][d++];
			}
		} while (bank1[u][d] != '\0');
		while (col < 20) {
			col++;
		}
		page[row][col] = line;
		count = 0;
		d = 0;
		do {
			if (bank2[u][d] != '\0') {
				page[row][++col] = bank2[u][d++];
			}
		} while (bank2[u][d] != '\0');
		while (col < 34) {
			col++;
		}
		page[row][col] = line;
		d = 0;
		do {
			if (bank3[u][d] != '\0') {
				page[row][++col] = bank3[u][d++];
			}
		} while (bank3[u][d] != '\0');
		while (col < 48) {
			col++;
		}
		page[row][col] = line;
		d = 0;
		do {
			if (bank4[u][d] != '\0') {
				page[row][++col] = bank4[u][d++];
				count++;
			}
		} while (bank4[u][d] != '\0');
		while (col < 62) {
			col++;
		}
		page[row][col] = line;
		count = 0;
		d = 0;
		do {
			if (bank5[u][d] != '\0') {
				page[row][++col] = bank5[u][d++];
				count++;
			}
		} while (bank5[u][d] != '\0');
		while (col < 76) {
			col++;
		}
		page[row][col] = line;
		count = 0;
		d = 0;
		page[row][79] = vert;
		row++;
		u++;
		entry++;
		col = 0;
	} while (entry < 13);
	
	emptySpace = row;
	for (i = emptySpace; i < ROWS - 4; i++) {
		page[i][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			page[i][j] = ' ';
		}
		page[i][79] = vert;
	}
	page[20][0] = vert;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[20][j] = bottomLine;
	}
	page[20][79] = vert;
	page[21][0] = vert;

	for (j = (COLUMNS - length[1]); j < (COLUMNS - 1); j++) {
		page[21][j] = ' ';
	}
	page[21][79] = vert;
	page[22][0] = bottomLeft;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[22][j] = hor;
	}
	page[22][79] = bottomRight;
	char z = DisplayPage(page);
	return '0';
}

//Creates page for the statistics
char Statistics(char title[], char selection[], char banks[5][15], float data[5][50], char page[ROWS][COLUMNS]) {
	char avg[5][15];
	char string[1000];
	int b, d, a;
	float temp;
	for (b = 0; b < 5; b++) {
		float sum = 0;
		for (d = 0; d < 50; d++) {
			sum += data[b][d];
		}
		temp = sum / 50;
		sprintf(string, "%.2f", temp);
		char *p2 = string;
		
		for (d = 0; d < 15; d++) {
			if (*p2 != '\0') {
				avg[b][d] = *p2++;
			}
			else {
				avg[b][d] = '\0';
				break;
			}
		}
	}
	b = 0;
	d = 0;
	char average[] = "Average: ";
	char *p3 = avg;
	float *num = avg;
	char *avgp = average;
	char *savg = average;
	int r = 0;
	int c = 0;
	char leftT = 204;
	char rightT = 185;
	char bar = 178;
	char topLeft = 201;
	char bottomLeft = 200;
	char hor = 205;
	char vert = 186;
	char topRight = 187;
	char bottomRight = 188;
	char bottomLine = 196;
	int i, j, k, start1, start2, end1, end2;
	int emptySpace = 0;
	int length[2] = { 0 };
	char *p1 = banks;
	int row = 3;
	ClearPage(page);
	page[0][0] = topLeft;
	for (i = 1; i < (COLUMNS - 1); i++) {
		page[0][i] = hor;
	}
	page[0][79] = topRight;
	page[1][0] = vert;
	InsertText(title, selection, page, length);
	start1 = ((COLUMNS - length[0]) / 2);
	end1 = start1 + length[0];
	for (j = 1; j < start1 - 2; j++) {
		page[1][j] = bar;
	}
	for (j = end1 + 2; j < (COLUMNS - 1); j++) {
		page[1][j] = bar;
	}
	page[1][79] = vert;
	page[2][0] = leftT;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[2][j] = hor;
	}
	page[2][79] = rightT;

	do {
		c = 0;
		//r++;
		page[row][0] = vert;
		for (j = 1; j < (COLUMNS / 2); j++) {
			if (banks[r][c] != '\0') {
				page[row][j] = banks[r][c++];
			}
			else {
				r++;
				c = 0;
				for (j = 40; j < (COLUMNS - 1); j++) {
					if (banks[r][c] != '\0') {
						page[row][j] = banks[r][c++];
					}
					else {
						r++;
						c = 0;
						break;
					}
				}
			}
		}
		page[row][79] = vert;
		page[++row][0] = vert;
		for (j = 1; j < 20; j++) {
			page[row][j] = bottomLine;
		}
		for (j = 40; j < 60; j++) {
			page[row][j] = bottomLine;
		}
		page[row][79] = vert;
		page[++row][0] = vert;
		c = 0;
		do {
			if (*avgp != '\0') page[row][++c] = *avgp++;
		} while (*avgp != '\0');
		do {
			if (avg[b][d] != '\0') page[row][++c] = avg[b][d++];
		} while (avg[b][d] != '\0');
		b++;
		d = 0;
		avgp = savg;
		c = 40;
		do {
			if (*avgp != '\0') page[row][c++] = *avgp++;
		} while (*avgp != '\0');
		do {
			if (avg[b][d] != '\0') page[row][++c] = avg[b][d++];
		} while (avg[b][d] != '\0');
		b++;
		d = 0;
		page[row][79] = vert;
		for (j = 0; j < 3; j++) {
			page[++row][0] = vert;
			page[row][79] = vert;
		}
		avgp = savg;
	} while (row != 13);
	c = 0;
	page[row][0] = vert;
	for (j = 1; j < (COLUMNS / 2); j++) {
		if (banks[r][c] != '\0') {
			page[row][j] = banks[r][c++];
		}
		else {
			break;
		}
	}
	page[row][79] = vert;
	page[++row][0] = vert;
	for (j = 1; j < 20; j++) {
		page[row][j] = bottomLine;
	}
	page[row][79] = vert;
	page[++row][0] = vert;
	c = 0;
	avgp = savg;
	do {
		if (*avgp != '\0') page[row][++c] = *avgp++;
	} while (*avgp != '\0');
	do {
		if (avg[b][d] != '\0') page[row][++c] = avg[b][d++];
	} while (avg[b][d] != '\0');
	page[row][79] = vert;
	row++;
	emptySpace = row;
	for (i = emptySpace; i < ROWS - 4; i++) {
		page[i][0] = vert;
		for (j = 1; j < (COLUMNS - 1); j++) {
			page[i][j] = ' ';
		}
		page[i][79] = vert;
	}
	page[20][0] = vert;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[20][j] = bottomLine;
	}
	page[20][79] = vert;
	page[21][0] = vert;

	for (j = (COLUMNS - length[1]); j < (COLUMNS - 1); j++) {
		page[21][j] = ' ';
	}
	page[21][79] = vert;
	page[22][0] = bottomLeft;
	for (j = 1; j < (COLUMNS - 1); j++) {
		page[22][j] = hor;
	}
	page[22][79] = bottomRight;
	char e = DisplayPage(page);
	return '0';
}
