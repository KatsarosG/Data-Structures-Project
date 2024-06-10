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

void makeNodeVector(list<Node>&, Region[]);
void makeTree(list<Node>&, string);

void resetNode(vector<Node>&, int);
list<Node>::iterator findOrderSuccessor(list<Node>&, list<Node>::iterator);

void inorderTraversal(list<Node>&, list<Node>::iterator);

int hashingFunction(string, int);
void makeHashTable(list<Region>*, Region*);

#endif
