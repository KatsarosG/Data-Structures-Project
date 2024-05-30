#pragma once
#ifndef SEARCHFUNCTIONS_H

#include <fstream>
#include <sstream>

#include "init.h"

// Function to print regions with births in a given range
void birthsInRangeBinary(int b1, int b2, Region arr[]);
void birthsInRangeInterpolation(int b1, int b2, Region arr[]);

void birthsInRangeBIS(int b1, int b2, Region arr[]);
void birthsInRangeOptBIS(int b1, int b2, Region arr[]);


#endif
