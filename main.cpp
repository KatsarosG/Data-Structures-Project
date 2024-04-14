#include "init.h"
#include "basicFunctions.h"
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];

int main() {
	readFile(DataFile, dataArray);
	printDataAtIndex(647, dataArray);	// example of reading at line 647 (last line)
	printDataAtIndex(0, dataArray);		// example of reading at line 0 (first line)
	cout << dataArray[1].region << endl;	// example of accessing data at line 1
	DataFile.close();
}

