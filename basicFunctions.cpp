// Εδώ μπενουν τα Function Definitions, δηλαδή τα σώματα των συναρτίσεων που δηλώθηκαν στο basicFunctions.h

#include "basicFunctions.h"
#include "init.h"

string inputLine;
string inputData;

void readFile(ifstream &file, Row RowStructArray[]) {
	int lineCount = 0;
	getline(file, inputLine); 
	while (lineCount < NUMOFENTRIES) {
		getline(file, inputLine); 
		stringstream ss(inputLine);
		getline(ss, inputData, ',');
		RowStructArray[lineCount].period = stoi(inputData);
		getline(ss, inputData, ',');
		RowStructArray[lineCount].BirthDeath = (inputData == "Births")? true : false;
		getline(ss, inputData, ',');
		RowStructArray[lineCount].region = inputData;
		getline(ss, inputData, ',');
		RowStructArray[lineCount].count = stoi(inputData);
		lineCount++;
	}
}

void printRegionArrayTotalBirths(Region arr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << arr[i].name << ": " << arr[i].totalBirths << endl;
	}
}

void printRegionArrayTotalDeaths(Region arr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << arr[i].name << ": " << arr[i].totalDeaths << endl;
	}
}

void printDataAtIndex(int n, Row RowStructArray[]) {
	cout << "Data at Line: " << n << endl << "\t";
	cout << RowStructArray[n].period << " " << RowStructArray[n].BirthDeath << " " << RowStructArray[n].region << " " << RowStructArray[n].count << endl;
}

void makeRegionArray(Region regionArray[], Row rowArray[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert region names
		regionArray[i].name = rowArray[i].region;	
	}	
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert year births for each region
		for (int year = 0; year < 18; year++){
			regionArray[i].periodArray[year].births = rowArray[i+(year*NUMOFREGIONS*2)].count; //  PARADEIGMA: 3η PERIOXH 4hs xronias einai i=2 kai year=3	
		}
	}
	for (int i = 0; i < NUMOFREGIONS; i++) {	// insert year deaths for each region
		for (int year = 0; year < 18; year++){
			regionArray[i].periodArray[year].deaths = rowArray[(i+NUMOFREGIONS)+(year*NUMOFREGIONS*2)].count;// to idio gia deaths 	
		}
	}
}

void calcTotalBirths(Region regionArray[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		regionArray[i].calculateTotalBirths();
	}
}

void calcTotalDeaths(Region regionArray[]) {
		for(int i = 0; i < NUMOFREGIONS; i++){
        regionArray[i].calculateTotalDeaths();
		}
}

// Part II
void makeNodeVector(list<Node> &lst, Region regArr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		Node tempNode;
		tempNode.region = regArr[i];
		tempNode.left = lst.end();
		tempNode.right = lst.end();
		tempNode.parent = lst.end();
		lst.push_back(tempNode);
	}
}

void findRelationByRegion(list<Node> &lst, list<Node>::iterator i, list<Node>::iterator k) {
	if (i->region.name.compare(k->region.name) > 0) {
		if (k->right == lst.end()) {
			i->parent = k;
			k->right = i;
		} else {
			findRelationByRegion(lst, i, k->right);
		}
	} else {
		if (k->left == lst.end()) {
			i->parent = k;
			k->left = i;
		} else {
			findRelationByRegion(lst, i, k->left);
		}
	}
}

void findRelationByBirths(list<Node> &lst, list<Node>::iterator i, list<Node>::iterator k) {
	if (i->region.totalBirths > k->region.totalBirths) {
		if (k->right == lst.end()) {
			i->parent = k;
			k->right = i;
		} else {
			findRelationByBirths(lst, i, k->right);
		}
	} else {
		if (k->left == lst.end()) {
			i->parent = k;
			k->left = i;
		} else {
			findRelationByBirths(lst, i, k->left);
		}
	}
}

void makeTree(list<Node> &vec, string index) {
	if (index == "region") {
		for (list<Node>::iterator i = next(vec.begin()); i != vec.end(); ++i) {
			findRelationByRegion(vec, i, vec.begin());
		}
	} else if (index == "births") {
		for (list<Node>::iterator i = next(vec.begin()); i != vec.end(); ++i) {
			findRelationByBirths(vec, i, vec.begin());
		}
	}
}

list<Node>::iterator findOrderSuccessor(list<Node> &lst, list<Node>::iterator k) {
	if (k->left == lst.end()) {
		return k;
	} else {
		return findOrderSuccessor(lst, k->left);
	}
}

void inorderTraversal(list<Node> &lst, list<Node>::iterator k) {
	if (k->left != lst.end()) {
		inorderTraversal(lst, k->left);
	}
	if (k->right != lst.end()) {
		inorderTraversal(lst, k->right);
	}
	cout << k->region.name << ": " << k->region.totalBirths << endl;
}

int hashingFunction(string key, int m) {
	int sum = 0;
	for (int i = 0; i < key.size(); i++) {
		sum += key[i];
	}
	return (sum%m);
}
 void makeHashTable(list<Region> list[], Region arr[]) {
	for (int i = 0; i < NUMOFREGIONS; i++) {
		int hash = hashingFunction(arr[i].name, M);
		list[hash].push_back(arr[i]);
	}
 }
