#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
#include "searchFunctions.h"
#include <time.h>
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];
vector<Node> nodeVector(NUMOFREGIONS);

int main() {
	clock_t clockStart, clockEnd;
	readFile(DataFile, dataArray);
	DataFile.close();

	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
  
	nodeVector = makeNodeVector(regionArray);
	makeTree(nodeVector);
	
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << i << ": " << nodeVector[i].region.name << ": " << endl;
		cout << "\tParent: " << nodeVector[i].parent << endl;
		cout << "\tLeft: " << nodeVector[i].left << endl;
		cout << "\tRight: " << nodeVector[i].right << endl;
	}

	clockStart = clock();
	// BIS with optimization
	birthsInRangeBIS(b1, b2, quickSortedArray);
	clockEnd = clock();

	duration = clockEnd - clockStart;
	
	//Print Durations	
	cout << "Duration of BIS with optimization: " << duration << " clock ticks" << endl;

	return 0;
}
