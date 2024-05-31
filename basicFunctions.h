#pragma once
#ifndef BASICFUNCTIONS_H

#include <fstream>
#include <sstream>

#include "init.h"


void readFile(ifstream&, Row*);
void printDataAtIndex(int, Row*);
void printRegionArrayTotalBirths(Region*);
void printRegionArrayTotalDeaths(Region*);

void makeRegionArray(Region*, Row*);
void calcTotalBirths(Region*);
void calcTotalDeaths(Region*);

vector<Node> makeNodeVector(Region[]);
void findRelation(vector<Node>&, int, int);
void makeTree(vector<Node>&);

void resetNode(vector<Node> &vec,int i);

#endif
