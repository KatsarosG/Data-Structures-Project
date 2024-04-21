#include "basicFunctions.h"
#include "init.h"

string inputLine;
string inputData;

void readFile(ifstream &file, Row RowStructArray[]) {
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

void printDataAtIndex(int n, Row RowStructArray[]) {
	cout << "Data at Line: " << n << endl << "\t";
	cout << RowStructArray[n].period << " " << RowStructArray[n].BirthDeath << " " << RowStructArray[n].region << " " << RowStructArray[n].count << endl;
}

void makeRegionArray(Region regionArray[], Row rowArray[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert region names
		regionArray[i].name = rowArray[i].region;	
	}	
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert year births for each region
		for (int year = 0; year < 18; year++){
			regionArray[i].periodArray[year].births = rowArray[i+(year*NUMOFREGIONS*2)].count;	
		}
	}
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert year deaths for each region
		for (int year = 0; year < 18; year++){
			regionArray[i].periodArray[year].deaths = rowArray[(i+NUMOFREGIONS)+(year*NUMOFREGIONS*2)].count;	
		}
	}
}