#include "init.h"
#include "basicFunctions.h"
#include "searchFunctions.h"
#include "PartII.A.h"
#include <string.h>
#include <ostream>
using namespace std;

void QuestionA1(vector<Node>);
void QuestionA2(vector<Node>);
void QuestionA3(vector<Node>&);
void QuestionA4(vector<Node>&);

int PartIIA(Region regionArray[], vector<Node> &nodeVector) {
	// Take user input
	string action;
	cout << "What do you want to do? [show/search/modify/delete/exit/help]: "; 
	cin >> action; 
	// perform action
	if (action.compare("help") == 0) {
		// Display help menu
		cout << "show		Show Binary Search Tree in inorder Traversal." << endl 
			<< "search		Search births for period and region." << endl 
			<< "modify		Modify birth count for a period and region." << endl 
			<< "delete		Delete a region." << endl 
			<< "exit		Quit application" << endl << endl;
	} else if (action.compare("show") == 0) {
		QuestionA1(nodeVector);
	} else if (action.compare("search") == 0) {
		QuestionA2(nodeVector);
	} else if (action.compare("modify") == 0) {
		QuestionA3(nodeVector);
	} else if (action.compare("delete") == 0) {
		QuestionA4(nodeVector);
	} else if (action.compare("exit") == 0) {
		// Exit with exit code 0
		return 0;
	} else {
		// Exit with exit code 1 for user error
		cout << "Error: Option '" << action << "' not found." << endl;
		return 1;
	}
	// Exit Part II A with exit code 2 for successfull run
	return 2;

}

void QuestionA1(vector<Node> nodeVector) {
    inorderTraversal(nodeVector, 0);  // Assuming root is at index 0
    cout << endl;

}

void QuestionA2(vector<Node> nodeVector) {
	string searchString;
	cout << "\nType Region name to search: ";
	getline(cin >> ws, searchString); // Input searchString for region
	int found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found
	if (found != -1) {		// if found
		int searchPeriod;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		if (searchPeriod > 2005 && searchPeriod < 2022) {
			int births;
			births = nodeVector[found].region.period(searchPeriod)->births; // get births of found region and period
			cout << "Births in " << searchString << " on " << searchPeriod << " are: " << births << endl; // print output
		} else {
			cout << "Year must be between 2005 and 2022!" << endl;
		}
	} else {
		cout << "Region Not Found!" << endl;
	}
}

void QuestionA3(vector<Node> &nodeVector) {
	string searchString;
	cout << "\nType Region name to modify: ";
	getline(cin >> ws, searchString); // Input searchString for region
	int found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found
	if (found != -1) {		// if found
		int searchPeriod = 0;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		if (searchPeriod > 2005 && searchPeriod < 2022) {
			int births;
			cout << "Type new Birth cout for year " << searchPeriod << ": ";
			cin >> births;
			nodeVector[found].region.period(searchPeriod)->births = births;
		} else {
			cout << "Year must be between 2005 and 2022!" << endl;
		}
	} else {
		cout << "Region Not Found!" << endl;
	}
}

void QuestionA4(vector<Node> &nodeVector) {
	int found;
    string searchString;
    cout << "Type Region name to delete: ";
    getline(cin >> ws, searchString); // Input searchString for region
    found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found

    if (found != -1) {        // if found
		if (nodeVector[found].right != -1) { // if right child exists:
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
		} else if (nodeVector[found].left != -1) { // if right child does not exist but left child exist
			int left = nodeVector[found].left;
			int parent = nodeVector[found].parent;
			nodeVector.erase(nodeVector.begin() + found);
			for (int i = 0; i < nodeVector.size(); i++) {
				if (nodeVector[i].right > found)
					nodeVector[i].right--;
				if (nodeVector[i].left > found)
					nodeVector[i].left--;
				if (nodeVector[i].parent > found)
					nodeVector[i].parent--;
			}

			if (left > found) {left--;}
			if (parent > found) {parent--;}
			
			if (nodeVector[parent].left == found) {
				nodeVector[parent].left = left;
				nodeVector[left].parent = parent;
			} else {
				nodeVector[parent].right = left;
				nodeVector[left].parent = parent;
			}		
		} else { // if no childs
			int parent = nodeVector[found].parent;
			if (nodeVector[parent].left == found) {
				nodeVector[parent].left = -1;
			} else {
				nodeVector[parent].right = -1;
			}		
			nodeVector.erase(nodeVector.begin() + found);
			for (int i = 0; i < nodeVector.size(); i++) {
				if (nodeVector[i].right > found)
					nodeVector[i].right--;
				if (nodeVector[i].left > found)
					nodeVector[i].left--;
				if (nodeVector[i].parent > found)
					nodeVector[i].parent--;
			}
			
		}

    } else {
        cout << "Region Not Found!" << endl;
    }
}
