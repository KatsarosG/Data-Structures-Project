#pragma once
#include <vector>
#ifndef INIT_H

#include <iostream>
#include <string>
#define NUMOFENTRIES 648
#define NUMOFYEARS 18
#define NUMOFREGIONS 18
#define M 11

using namespace std;

struct Row {
	int period;
	bool BirthDeath;	// True = Birth, False = Death
	string region;
	int count;
};

struct Period {
	int births;
	int deaths;
};

struct Region {
	string name;
	Period periodArray[NUMOFYEARS];

	int totalBirths;
	int totalDeaths;

	Period *period(int year) {	// Transitions year to array index. e.g. 2005 -> 0, 2006 -> 1 ...
		int index;
		if (year < 2005 || year > 2022) {
			cout << "Error: Year must be between 2005 and 2022\n";
		} else {
			index = year - 2005; 
		}
		return &periodArray[index];
	}

	void calculateTotalBirths() {
		for (int i = 0; i < NUMOFYEARS; i++) {
			totalBirths += periodArray[i].births;
		}
	}
	void calculateTotalDeaths(){
		for (int i = 0; i < NUMOFYEARS; i++){
			totalDeaths += periodArray[i].deaths;
		}
	}
};

struct Node {
	Region region;
	int left;
	int right;
	int parent;
};

#endif
