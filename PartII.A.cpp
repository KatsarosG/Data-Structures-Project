#include "init.h"
#include "basicFunctions.h"
#include "searchFunctions.h"
#include "PartII.A.h"
#include <list>
#include <string.h>
#include <ostream>
using namespace std;

void QuestionA1(list<Node>&);
void QuestionA2(list<Node>&);
void QuestionA3(list<Node>&);
void QuestionA4(list<Node>&);

int PartIIA(Region regionArray[], list<Node> &nodeVector) {
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
		cout << "Error: Option '" << action << "' not found." << endl << endl;
		return 1;
	}
	
	// Exit Part II A with exit code 2 for successfull run
	return 2;

}

void QuestionA1(list<Node> &nodeVector) {
    inorderTraversal(nodeVector, nodeVector.begin());
    cout << endl;

}

void QuestionA2(list<Node> &nodeVector) {
	string searchString;
	cout << "Type Region name to search: ";
	getline(cin >> ws, searchString); // Input searchString for region
	list<Node>::iterator found = searchTree(nodeVector, searchString, nodeVector.begin()); // found = index of region, nodeVector.end(): not Found
	if (found != nodeVector.end()) {		// if found
		int searchPeriod;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		if (searchPeriod > 2004 && searchPeriod < 2023) {
			int births;
			births = found->region.period(searchPeriod)->births; // get births of found region and period
			cout << "Births in " << searchString << " on " << searchPeriod << " are: " << births << endl << endl; // print output
		} else {
			cout << "Year must be between 2005 and 2022!" << endl << endl;
		}
	} else {
		cout << "Region Not Found!" << endl << endl;
	}
}

void QuestionA3(list<Node> &nodeVector) {
	string searchString;
	cout << "Type Region name to modify: ";
	getline(cin >> ws, searchString); // Input searchString for region
	list<Node>::iterator found = searchTree(nodeVector, searchString, nodeVector.begin()); // found = index of region, -1: not Found
	if (found != nodeVector.end()) {		// if found
		int searchPeriod = 0;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		if (searchPeriod > 2004 && searchPeriod < 2023) {
			int births;
			cout << "Type new Birth cout for year " << searchPeriod << ": ";
			cin >> births;
			found->region.period(searchPeriod)->births = births;
			cout << endl;
			found->region.totalBirths = 0;
			found->region.calculateTotalBirths();
		} else {
			cout << "Year must be between 2005 and 2022!" << endl << endl;
		}
	} else {
		cout << "Region Not Found!" << endl << endl;
	}
}

void QuestionA4(list<Node> &nodeVector) {
	list<Node>::iterator found;
    string searchString;
    cout << "Type Region name to delete: ";
    getline(cin >> ws, searchString); // Input searchString for region
    found = searchTree(nodeVector, searchString, nodeVector.begin()); // found = index of region, -1: not Found

    if (found != nodeVector.end()) {        // if found
		if (found->right != nodeVector.end()) { // if right child exists:
			//find order successor
			list<Node>::iterator orderSuccessor = findOrderSuccessor(nodeVector, found->right);
			swap(found->region, orderSuccessor->region);
			if (found->right->left == nodeVector.end()) {
				orderSuccessor->right->parent = found;
				found->right = orderSuccessor->right;
			} else {
				if (orderSuccessor->right == nodeVector.end()) {
					orderSuccessor->parent->left = nodeVector.end();
				} else {
					orderSuccessor->parent->left = orderSuccessor->right;
					orderSuccessor->right->parent = orderSuccessor->parent;
				}
			}
			nodeVector.erase(orderSuccessor);
		} else if (found->left != nodeVector.end()) { // if right child does not exist but left child exist
			list<Node>::iterator left = found->left;
			list<Node>::iterator parent = found->parent;
			nodeVector.erase(found);
			if (parent->left == found) {
				parent->left = left;
				left->parent = parent;
			} else {
				parent->right = left;
				left->parent = parent;
			}		
		} else { // if no childs
			list<Node>::iterator parent = found->parent;
			if (parent->left == found) {
				parent->left = nodeVector.end();
			} else {
				parent->right = nodeVector.end();
			}		
			nodeVector.erase(found);
		}
		cout << endl;

    } else {
        cout << "Region Not Found!" << endl << endl;
    }
}

