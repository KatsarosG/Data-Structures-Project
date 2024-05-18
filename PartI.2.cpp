#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
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

    // HeapSort:
    Region heapSortedArray[NUMOFREGIONS]; // Create new array
    copy(begin(regionArray), end(regionArray), begin(heapSortedArray)); // Copy region array to heapSortedArray
	clockStart = clock();
    heapSort(heapSortedArray, NUMOFREGIONS); // Heap sort heapSortedArray
	clockEnd = clock();
	int heapSortDuration = clockEnd - clockStart;
    
    // Print HeapSortedArray:
    cout << "-------------HeapSortedArray by Deaths:--------------\n";
	printRegionArrayTotalDeaths(heapSortedArray);

	//Counting Sort:
	Region countingSortedArray[NUMOFREGIONS];
    copy(begin(regionArray), end(regionArray), begin(countingSortedArray)); // Copy region array to heapSortedArray
	clockStart = clock();
	countingSort(regionArray, countingSortedArray);
	clockEnd = clock();
	int countingSortDuration = clockEnd - clockStart;
	
	//Print Counting Sorted Array:
    cout << "-------------countingSorted Array by Deaths:--------------\n";
	printRegionArrayTotalDeaths(countingSortedArray);
	
	//Print Durations
  	cout<<"\n-------------Durations:--------------\n";
	cout << "Duration of HeapSort: " << heapSortDuration<< " clock ticks" << endl;
	cout << "Duration of CountingSort: " << countingSortDuration << " clock ticks" <<endl;
    return 0;
}
