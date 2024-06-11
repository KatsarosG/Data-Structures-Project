#include "init.h"
#include "basicFunctions.h"
#include "searchFunctions.h"
#include "PartII.A.h"
#include "PartII.B.h"
#include <list>
#include <string.h>
#include <ostream>
using namespace std;

ifstream DataFile("bd-dec22-births-deaths-by-region.csv");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];
list<Node> nodeVector;

int main() {
	readFile(DataFile, dataArray);
	DataFile.close();
	
	// make region array
	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
	
	string inputTxt;
	cout << "Load data on Binary Search Tree or Hash table? [bst/hash]: ";
	cin >> inputTxt;
	if (inputTxt.compare("bst") == 0) {
		// Make node vector
		makeNodeVector(nodeVector, regionArray);
		cout << "Binary Search Tree key? [region/births]: ";
		cin >> inputTxt;
		if (inputTxt.compare("region") == 0) {
			// Part II A
			// Make tree with regions
			makeTree(nodeVector, "region");
			while (PartIIA(regionArray, nodeVector) != 0) {}	
		} else if (inputTxt.compare("births") == 0) {
			// Part II B
			// Make tree with births
			makeTree(nodeVector, "births");
			while (PartIIB(nodeVector) != 0) {}
		}
	} else if (inputTxt.compare("hash") == 0) {
		//PartII.C
	} else {
		cout << "Option '" << inputTxt << "' not found!" << endl;
	}

	return 0;
}
