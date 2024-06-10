#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
#include "searchFunctions.h"
#include <time.h>
#include <list>
using namespace std;

void Question1();
void Question2();

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];
list<Region> hashTable[M];
int main() {
	clock_t clockStart, clockEnd;
	readFile(DataFile, dataArray);
	DataFile.close();
	
	// make region array
	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);

	makeHashTable(hashTable, regionArray);

	for (int i = 0; i < M; i++) {
		cout << i << ": " << endl;
		for (list<Region>::iterator j = hashTable[i].begin(); j != hashTable[i].end(); ++j)
    		cout << j->name << endl;
		cout << endl;
	}

	Question2();

	for (int i = 0; i < M; i++) {
		cout << i << ": " << endl;
		for (list<Region>::iterator j = hashTable[i].begin(); j != hashTable[i].end(); ++j)
    		cout << j->name << endl;
		cout << endl;
	}
}

void Question1() {
	string searchRegion;
	int searchPeriod;
	cout << "Give Region name to search: ";
	getline(cin >> ws, searchRegion); // Input searchString for region
	cout << "Give Period to search: ";
	cin >> searchPeriod;
	int hash = hashingFunction(searchRegion, M);
	for (list<Region>::iterator j = hashTable[hash].begin(); j != hashTable[hash].end(); ++j)
		if (j->name == searchRegion) {
			cout << j->name << ": " << j->period(searchPeriod)->births << endl;
			break;
		}
	cout << endl;
}

void Question2() {
	string searchRegion;
	cout << "Give region name to delete: ";
	getline(cin >> ws, searchRegion);
	int hash = hashingFunction(searchRegion, M);
	for (list<Region>::iterator j = hashTable[hash].begin(); j != hashTable[hash].end(); ++j)
		if (j->name == searchRegion) {
			hashTable[hash].erase(j);
			break;
		}

	
}
