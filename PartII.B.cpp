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
void Question1(int);
void Question2(int);

int main() {
	clock_t clockStart, clockEnd;
	readFile(DataFile, dataArray);
	DataFile.close();
	
	// make region array
	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
  	
	// make nodeVector
	nodeVector = makeNodeVector(regionArray);
	makeTree(nodeVector, "births");

	Question1(0);
	Question2(0);

	// print tree
	/*
	cout << "\n----------\n";	
	for (int i = 0; i < nodeVector.size(); i++) {
		cout << i << ": " << nodeVector[i].region.name << ": " << nodeVector[i].region.totalBirths << ": " << endl;
		cout << "\tParent: " << nodeVector[i].parent << endl;
		cout << "\tLeft: " << nodeVector[i].left << endl;
		cout << "\tRight: " << nodeVector[i].right << endl;
	}
	*/
	
	
	return 0;
}

void Question1(int i) {
	if (nodeVector[i].left == -1) {
		cout << "Region with least total births: " << nodeVector[i].region.name << " with " << nodeVector[i].region.totalBirths << " total births." << endl;
	} else {
		Question1(nodeVector[i].left);
	}
}

void Question2(int i) {
	if (nodeVector[i].right == -1) {
		cout << "Region with most total births: " << nodeVector[i].region.name << " with " << nodeVector[i].region.totalBirths << " total births." << endl;
	} else {
		Question2(nodeVector[i].right);
	}
}
