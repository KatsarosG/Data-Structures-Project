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

	int b1,b2;
	cout << "Insert [b1,b2] range:"; 
	cin >>  b1;
	cin >>  b2; 
	cout<<"---------------- THE REGIONS in that Range of births are:---------\n";

	// QuickSort
	Region quickSortedArray[NUMOFREGIONS]; // Create new array
	copy(begin(regionArray), end(regionArray), begin(quickSortedArray));

	quickSort(quickSortedArray, 0, NUMOFREGIONS-1);

	birthsinRegion(b1, b2, quickSortedArray);

	return 0;
}
