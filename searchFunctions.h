#pragma once
#ifndef SEARCHFUNCTIONS_H

#include <fstream>
#include <sstream>

#include "init.h"

int binarySearch(Region arr[], int low, int high, int x);

// Function to print regions with births in a given range
void birthsinRegion(int b1, int b2, Region arr[]);


#endif