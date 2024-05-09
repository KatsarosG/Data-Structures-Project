#pragma once
#include <vector>
#ifndef INIT_H

#include <iostream>
#include <string>
#define NUMOFENTRIES 648
#define NUMOFYEARS 18
#define NUMOFREGIONS 18

using namespace std;

struct Row {
	int period;
	bool BirthDeath;	// True = Birth, False = Death
	string region;
	int count;
};

// e.g. greece.period(2024).births

struct Period {
	int births;
	int deaths;
};

struct Region {
	string name;
	Period periodArray[NUMOFYEARS];
<<<<<<< Updated upstream
=======
	int totalBirths;
	int totalDeaths;
>>>>>>> Stashed changes
	Period period(int year) {	// Transitions year to array index. e.g. 2005 -> 0, 2006 -> 1 ...
		int index;
		if (year < 2005 || year > 2022) {
			cout << "Error: Year must be between 2005 and 2022\n";
		} else {
			index = year - 2005; 
		}
		return periodArray[index];
	}
<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes
};

#endif
