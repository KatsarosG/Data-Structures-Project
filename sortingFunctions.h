// Sorting Functions Declarations

#pragma once
#ifndef SORTINGFUNCTIONS_H

#include "init.h"
// Εδώ μπένουν οι δηλώσεις των συναρτήσεων
void mergeSort(Region*, int, int);

void quickSort(Region arr[], int low, int high);
void heapSort(Region arr[], int n);

void countingSort(Region arrayIn[], Region arrayOut[]);

#endif
