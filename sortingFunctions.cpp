// Sorting Functions Definitions, Bodies
#include "sortingFunctions.h"
#include "init.h"
#include <algorithm>

// Εδώ μπένουν τα σώματα των συναρτήσεων
void merge(Region arr[], int l, int m, int r) {
	int leftArraySize = m - l + 1;
	int rightArraySize = r - m;

	// Temp Arrays:
	Region leftArray[leftArraySize];
	Region rightArray[rightArraySize];

	//copy data to temp arrays
	int i, j, k;
	for (i = 0; i < leftArraySize; i++)
		leftArray[i] = arr[l + i];
	for (j = 0; j < rightArraySize; j++) {
		rightArray[j] = arr[m + 1 + j];
	}
	// Merge temp arrays
	i = 0;
	j = 0;
	k = l;
	while (i < leftArraySize && j < rightArraySize)
		arr[k++] = (leftArray[i].totalBirths < rightArray[j].totalBirths) ? leftArray[i++] : rightArray[j++];
	
	// Add remaining elements
	while (i < leftArraySize) {
		arr[k++] = leftArray[i++];
	}
	while (j < rightArraySize) {
		arr[k++] = rightArray[j++];
	}
}

void mergeSort(Region arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

