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

	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << regionArray[i].name << ": " << regionArray[i].totalBirths << endl;
	}
	cout << "\n--------\n";
  
  // QuickSort
	Region quickSortedArray[NUMOFREGIONS];	// Create new array
	copy(begin(regionArray), end(regionArray), begin(quickSortedArray));

	quickSort(quickSortedArray, 0, NUMOFREGIONS-1);
  // Print QuickSorted Array
	cout<<"-------------QuickSortedArray:--------------\n";
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << quickSortedArray[i].name << ": " << quickSortedArray[i].totalBirths << endl;
	}
  
	// MergeSort:
	Region mergeSortedArray[NUMOFREGIONS];	// Create new array
	copy(begin(regionArray), end(regionArray), begin(mergeSortedArray));	// Copy region array to mergeSortedArray
	mergeSort(mergeSortedArray, 0, NUMOFREGIONS-1);	// Merge sort mergeSortedArray
	
	// Print MergeSortedArray:
  cout<<"-------------MergeSortedArray:--------------\n";
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << mergeSortedArray[i].name << ": " << mergeSortedArray[i].totalBirths << endl;
	}
}

