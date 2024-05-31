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
void Question2();
void Question4();

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
	makeTree(nodeVector);

  // print tree
   for (int i = 0; i < nodeVector.size(); i++) {
        cout << i << ": " << nodeVector[i].region.name << ": " << endl;
        cout << "\tParent: " << nodeVector[i].parent << endl;
        cout << "\tLeft: " << nodeVector[i].left << endl;
        cout << "\tRight: " << nodeVector[i].right << endl;
    }	

   Question4();

  // print tree
   for (int i = 0; i < nodeVector.size(); i++) {
        cout << i << ": " << nodeVector[i].region.name << ": " << endl;
        cout << "\tParent: " << nodeVector[i].parent << endl;
        cout << "\tLeft: " << nodeVector[i].left << endl;
        cout << "\tRight: " << nodeVector[i].right << endl;
    }	
	return 0;
}

void Question2() {
	string searchString;
	cout << "Type Region name to search: ";
	getline(cin >> ws, searchString); // Input searchString for region
	int found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found
	if (found != -1) {		// if found
		int searchPeriod;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		int births;
		births = nodeVector[found].region.period(searchPeriod).births; // get births of found region and period
		cout << "Births in " << searchString << " on " << searchPeriod << " are: " << births << endl; // print output
	} else {
		cout << "Region Not Found!" << endl;
	}
}

void Question4() {
	int found;
    string searchString;
    cout << "Type Region name to delete: ";
    getline(cin, searchString); // Input searchString for region
    found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found

    if (found != -1) {        // if found
		//find order successor
		int orderSuccessor = findOrderSuccessor(nodeVector, nodeVector[found].right);
		swap(nodeVector[found].region, nodeVector[orderSuccessor].region);
		nodeVector[nodeVector[orderSuccessor].parent].left = -1;
		nodeVector.erase(nodeVector.begin() + orderSuccessor);
		for (int i = 0; i < nodeVector.size(); i++) {
			if (nodeVector[i].right > orderSuccessor)
				nodeVector[i].right--;
			if (nodeVector[i].left > orderSuccessor)
				nodeVector[i].left--;
			if (nodeVector[i].parent > orderSuccessor)
				nodeVector[i].parent--;
		}

    } else {
        cout << "Region Not Found!" << endl;
    }
}
