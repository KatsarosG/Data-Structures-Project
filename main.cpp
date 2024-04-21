#include "init.h"
#include "basicFunctions.h"
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];

int main() {
	readFile(DataFile, dataArray);
	printDataAtIndex(647, dataArray);	// example of reading at line 647 (last line)
	printDataAtIndex(0, dataArray);		// example of reading at line 0 (first line)
	cout << "Data at index 1: " <<dataArray[1].region << endl;	// example of accessing data at line 1
	DataFile.close();
	
	makeRegionArray(regionArray, dataArray);
	cout << "Region: " << regionArray[0].name << " Births: " << regionArray[0].periodArray[1].births << endl;	// example of 1st region, 2nd year, births
	cout << "testtt\n";	
	cout << "Region: " << regionArray[17].name << " Deaths: " << regionArray[17].periodArray[1].deaths << endl;	// example of 18th region, 2nd year, deaths
}

