#pragma once
#ifndef INIT_H

#include <iostream>
#include <string>
#define NUMOFENTRIES 648

using namespace std;

struct Row {
	int period;
	bool BirthDeath;	// True = Birth, False = Death
	string region;
	int count;
};

#endif
