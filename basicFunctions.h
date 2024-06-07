#pragma once
#ifndef BASICFUNCTIONS_H

#include <fstream>
#include <sstream>
#include <list>

#include "init.h"


void readFile(ifstream&, Row*);
void printDataAtIndex(int, Row*);
void printRegionArrayTotalBirths(Region*);
void printRegionArrayTotalDeaths(Region*);

void makeRegionArray(Region*, Row*);
void calcTotalBirths(Region*);
void calcTotalDeaths(Region*);

vector<Node> makeNodeVector(Region[]);
void makeTree(vector<Node>&, string);

void resetNode(vector<Node>&, int);
int findOrderSuccessor(vector<Node>&, int);

void inorderTraversal(const vector<Node> &vec, int index);

int hashingFunction(string, int);
void makeHashTable(list<Region>*, Region*);

#endif
