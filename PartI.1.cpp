/*
	Part I, Question 1:
Ταξινόμηση κατά αύξουσα σειρά των περιοχών (Region) με βάση τις συνολικές τιμές των
αριθμών γεννήσεων (Count) κάνοντας χρήση των αλγορίθμων Merge Sort και Quick Sort,
σύμφωνα με τον ψευδοκώδικα που σας επεξηγήθηκε στη θεωρία (για λεπτομέρειες δείτε τις
σχετικές διαφάνειες στο e-class). Συγκρίνατε πειραματικά τους δύο (2) αλγορίθμους. Τι
παρατηρείτε?
*/

#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
#include <time.h>	// For clock
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
	
	cout<<"\n-------------Non-Sorted Array:--------------\n";
 	printRegionArray(regionArray); 
  	// QuickSort
	Region quickSortedArray[NUMOFREGIONS];	// Create new array
	copy(begin(regionArray), end(regionArray), begin(quickSortedArray)); // Copy region array to quickSortedArray
	clockStart = clock();
	quickSort(quickSortedArray, 0, NUMOFREGIONS-1);
	clockEnd = clock();
	int quickSortDuration = int(clockEnd - clockStart);

	cout<<"\n-------------QuickSortedArray:--------------\n";
	printRegionArray(quickSortedArray);  
	// MergeSort:
	Region mergeSortedArray[NUMOFREGIONS];	// Create new array
	copy(begin(regionArray), end(regionArray), begin(mergeSortedArray));	// Copy region array to mergeSortedArray
	clockStart = clock();
	mergeSort(mergeSortedArray, 0, NUMOFREGIONS-1);	// Merge sort mergeSortedArray
	clockEnd = clock();
	int mergeSortDuration = int(clockEnd - clockStart);
	
  	cout<<"\n-------------MergeSortedArray:--------------\n";
	printRegionArray(mergeSortedArray);
  	cout<<"\n-------------Durations:--------------\n";
	cout << "Duration of quickSort: " << quickSortDuration << " clock ticks" << endl;
	cout << "Duration of mergeSort: " << mergeSortDuration << " clock ticks" <<endl;
}

