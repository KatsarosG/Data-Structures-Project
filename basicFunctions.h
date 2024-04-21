#pragma once
#ifndef BASICFUNCTIONS_H

#include <fstream>
#include <sstream>

#include "init.h"


void readFile(ifstream&, Row*);
void printDataAtIndex(int, Row*);

void makeRegionArray(Region*, Row*);

#endif
