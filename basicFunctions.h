#pragma once
#ifndef BASICFUNCTIONS_H

#include <fstream>
#include <sstream>

#include "init.h"


void readFile(ifstream&, Row*);
void printDataAtIndex(int, Row*);
void printRegionArray(Region*);

void makeRegionArray(Region*, Row*);
void calcTotalBirths(Region*);
void calcTotalDeaths(Region*);


#endif
