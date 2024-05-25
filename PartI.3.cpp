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

	// QuickSort The array
	Region quickSortedArray[NUMOFREGIONS]; // Create new sorted array
	copy(begin(regionArray), end(regionArray), begin(quickSortedArray));
	quickSort(quickSortedArray, 0, NUMOFREGIONS-1);

	int b1,b2;
	cout << "Give Range Start: "; 
	cin >> b1;
	cout << "Give Range End: ";
	cin >> b2; 
	cout<<"---------------- THE REGIONS in that Range of births are:---------\n";
	cout << "--With Binary Search:--" << endl;
	clockStart = clock();	
	birthsInRangeBinary(b1, b2, quickSortedArray);
	clockEnd = clock();
	int binaryDuration = clockEnd - clockStart;

	cout << "\n--With Interpolation Search:--" << endl;
	clockStart = clock();
	birthsInRangeInterpolation(b1, b2, quickSortedArray);
	clockEnd = clock();
	int BISDuration = clockEnd - clockStart;
	
	//Print Durations
  	cout<<"\n-------------Durations:--------------\n";
	cout << "Duration of Binary Search: " << binaryDuration<< " clock ticks" << endl;
	cout << "Duration of Binary Interpolation Search: " << BISDuration << " clock ticks" <<endl;

    return 0;
}
