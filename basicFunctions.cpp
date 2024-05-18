// Εδώ μπενουν τα Function Definitions, δηλαδή τα σώματα των συναρτίσεων που δηλώθηκαν στο basicFunctions.h

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

void printRegionArrayTotalBirths(Region arr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << arr[i].name << ": " << arr[i].totalBirths << endl;
	}
}

void printRegionArrayTotalDeaths(Region arr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << arr[i].name << ": " << arr[i].totalDeaths << endl;
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
			regionArray[i].periodArray[year].births = rowArray[i+(year*NUMOFREGIONS*2)].count; //  PARADEIGMA: 3η PERIOXH 4hs xronias einai i=2 kai year=3	
		}
	}
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert year deaths for each region
		for (int year = 0; year < 18; year++){
			regionArray[i].periodArray[year].deaths = rowArray[(i+NUMOFREGIONS)+(year*NUMOFREGIONS*2)].count;// to idio gia deaths 	
		}
	}
}


void calcTotalBirths(Region regionArray[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		regionArray[i].calculateTotalBirths();
	}
}

void calcTotalDeaths(Region regionArray[]) {
		for(int i = 0; i < NUMOFREGIONS; i++){
        regionArray[i].calculateTotalDeaths();
		}
	}


