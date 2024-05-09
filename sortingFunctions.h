// Sorting Functions Declarations

#pragma once
#ifndef SORTINGFUNCTIONS_H

#include "init.h"
// Εδώ μπένουν οι δηλώσεις των συναρτήσεων
void mergeSort(Region*, int, int);

int splitArr(Region arr[], int low, int high);

void quickSort(Region arr[], int low, int high);

#endif
