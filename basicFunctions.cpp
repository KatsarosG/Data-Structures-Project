#include "basicFunctions.h"

string inputLine;
string inputData;

void readFile(ifstream &file, Row *RowStructArray) {
	int lineCount = 0;
	getline(file, inputLine); 
	while (lineCount < NUMOFENTRIES) {
		getline(file, inputLine); 
		stringstream ss(inputLine);
		getline(ss, inputData, ',');
		RowStructArray[lineCount].period = stoi(inputData);
		getline(ss, inputData, ',');
		RowStructArray[lineCount].BirthDeath = (inputData == "Births")? true : false;
		getline(ss, inputData, ',');
		RowStructArray[lineCount].region = inputData;
		getline(ss, inputData, ',');
		RowStructArray[lineCount].count = stoi(inputData);
		lineCount++;
	}
}

void printDataAtIndex(int n, Row *RowStructArray) {
	cout << "Data at Line: " << n << endl << "\t";
	cout << RowStructArray[n].period << " " << RowStructArray[n].BirthDeath << " " << RowStructArray[n].region << " " << RowStructArray[n].count << endl;
}
