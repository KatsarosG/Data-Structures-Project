#include "init.h"
#include "basicFunctions.h"
#include "PartII.B.h"
#include <list>
#include <vector>
using namespace std;

void QuestionB1(list<Node>::iterator, const list<Node>&);
void QuestionB2(list<Node>::iterator, const list<Node>&);

int PartIIB(list<Node> &nodeVector) {
	// Take user input
	string action;
	cout << "What do you want to do? [min/max/exit/help]: "; 
	cin >> action; 
	// perform action
	if (action.compare("help") == 0) {
		cout << "min	Find region with minimum count of births." << endl 
			<< "max	Find region with maximum count of births." << endl << endl;
	} else if (action.compare("min") == 0) {
		QuestionB1(nodeVector.begin(), nodeVector);
	} else if (action.compare("max") == 0) {
		QuestionB2(nodeVector.begin(), nodeVector);
	} else if (action.compare("exit") == 0) {
		return 0;
	} else {
		cout << "Error: Option '" << action << "' not found." << endl << endl;
		return 1;
	}
	return 2;
}

void QuestionB1(list<Node>::iterator i, const list<Node> &nodeVector) {
	if (i->left == nodeVector.end()) {
		cout << "Region with least total births: " << i->region.name << " with " << i->region.totalBirths << " total births." << endl << endl;
	} else {
		QuestionB1(i->left, nodeVector);
	}
}

void QuestionB2(list<Node>::iterator i, const list<Node> &nodeVector) {
	if (i->right == nodeVector.end()) {
		cout << "Region with most total births: " << i->region.name << " with " << i->region.totalBirths << " total births." << endl << endl;
	} else {
		QuestionB2(i->right, nodeVector);
	}
}
