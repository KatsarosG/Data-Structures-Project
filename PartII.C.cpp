#include "init.h"
#include "basicFunctions.h"
#include "searchFunctions.h"
#include "PartII.C.h"
#include <list>
using namespace std;

void QuestionC1(list<Region>*);
void QuestionC2(list<Region>*);
void QuestionC3(list<Region>*);

int PartIIC(list<Region> hashTable[]) {
	// Take user input
	string action;
	cout << "What do you want to do? [search/modify/delete/exit/help]: "; 
	cin >> action; 
	// perform action
	if (action.compare("help") == 0) {
		// Display help menu
		cout << "show		Show Binary Search Tree in inorder Traversal." << endl 
			<< "search		Search births for period and region." << endl 
			<< "modify		Modify birth count for a period and region." << endl 
			<< "delete		Delete a region." << endl 
			<< "exit		Quit application" << endl << endl;
	} else if (action.compare("search") == 0) {
		QuestionC1(hashTable);
	} else if (action.compare("modify") == 0) {
		QuestionC2(hashTable);
	} else if (action.compare("delete") == 0) {
		QuestionC3(hashTable);
	} else if (action.compare("exit") == 0) {
		// Exit with exit code 0
		return 0;
	} else {
		// Exit with exit code 1 for user error
		cout << "Error: Option '" << action << "' not found." << endl << endl;
		return 1;
	}
	
	// Exit Part II A with exit code 2 for successfull run
	return 2;

}

void QuestionC1(list<Region> hashTable[]) {
	string searchRegion;
	int searchPeriod;
	cout << "Give Region name to search: ";
	getline(cin >> ws, searchRegion); // Input searchString for region
	cout << "Give Period to search: ";
	cin >> searchPeriod;
	if (searchPeriod >= 2005 && searchPeriod <= 2022) {
		int hash = hashingFunction(searchRegion, M);
		bool foundFlag = false;
		for (list<Region>::iterator j = hashTable[hash].begin(); j != hashTable[hash].end(); ++j)
			if (j->name == searchRegion) {
				foundFlag = true;
				cout << j->name << ": " << j->period(searchPeriod)->births << endl;
				break;
			}
		if (foundFlag == false) {
			cout << "Region " << searchRegion << " not found!" << endl;
		}
	} else {
		cout << "Period must be between 2005 and 2022!" << endl;
	}
	cout << endl;
}

void QuestionC2(list<Region> hashTable[]) {
	string searchRegion;
	int searchPeriod;
	cout << "Give Region name to modify: ";
	getline(cin >> ws, searchRegion); // Input searchString for region
	cout << "Give Period to modify: ";
	cin >> searchPeriod;
	if (searchPeriod >= 2005 && searchPeriod <= 2022) {
		bool foundFlag = false;
		int hash = hashingFunction(searchRegion, M);
		for (list<Region>::iterator j = hashTable[hash].begin(); j != hashTable[hash].end(); ++j)
			if (j->name == searchRegion) {
				foundFlag = true;
				int inputVal;
				cout << "Give new Value: ";
				cin >> inputVal;
				j->period(searchPeriod)->births = inputVal;
				j->calculateTotalBirths();
				break;
			}
		if (foundFlag == false) {
			cout << "Region " << searchRegion << " not found!" << endl;
		}
	} else {
		cout << "Period must be between 2005 and 2022!" << endl;
	}
	cout << endl;
}

void QuestionC3(list<Region> hashTable[]) {
	string searchRegion;
	cout << "Give region name to delete: ";
	getline(cin >> ws, searchRegion);
	int hash = hashingFunction(searchRegion, M);
	for (list<Region>::iterator j = hashTable[hash].begin(); j != hashTable[hash].end(); ++j)
		if (j->name == searchRegion) {
			hashTable[hash].erase(j);
			cout << endl;
			break;
		}
}
