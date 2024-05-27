#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
#include "searchFunctions.h"
#include <time.h>
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];

int main() {
	clock_t clockStart, clockEnd;
	readFile(DataFile, dataArray);
	DataFile.close();

	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
  
  	// QuickSort
	Region quickSortedArray[NUMOFREGIONS]; // Create new array
	copy(begin(regionArray), end(regionArray), begin(quickSortedArray));

	quickSort(quickSortedArray, 0, NUMOFREGIONS-1);
	
	// Ask Range
	int b1,b2;
	cout << "Give Range Start: "; 
	cin >> b1;
	cout << "Give Range End: ";
	cin >> b2; 
	cout<<"---------------- THE REGIONS in that Range of births are:---------\n";
	
	clockStart = clock();
	// BIS with no optimization
	birthsInRangeBIS(b1, b2, quickSortedArray);
	clockEnd = clock();

	int duration = clockEnd - clockStart;
	
	//Print Durations	
	cout << "Duration of BIS with no optimization: " << duration << " clock ticks" << endl; 

	clockStart = clock();
	// BIS with optimization
	birthsInRangeBIS(b1, b2, quickSortedArray);
	clockEnd = clock();

	duration = clockEnd - clockStart;
	
	//Print Durations	
	cout << "Duration of BIS with optimization: " << duration << " clock ticks" << endl;

	return 0;
}
