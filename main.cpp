// Εδώ τεστάρουμε οτι δουλέβουν οι συναρτίσεις που εχουμε γράψει

#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];

int main() {
	readFile(DataFile, dataArray);
	DataFile.close();
	
	makeRegionArray(regionArray, dataArray);
	calcTotalBirths(regionArray);
	
	// Print array:
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << regionArray[i].name << ": " << regionArray[i].totalBirths << endl;
	}
	cout << "\n--------\n";

	// MergeSort:
	Region mergeSortedArray[NUMOFREGIONS];	// Create new array
	copy(begin(regionArray), end(regionArray), begin(mergeSortedArray));	// Copy region array to mergeSortedArray
	mergeSort(mergeSortedArray, 0, NUMOFREGIONS-1);	// Merge sort mergeSortedArray
	
	// Print MergeSortedArray:
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << mergeSortedArray[i].name << ": " << mergeSortedArray[i].totalBirths << endl;
	}
}

