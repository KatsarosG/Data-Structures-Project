// Sorting Functions Definitions, Bodies
#include "sortingFunctions.h"
#include "init.h"
#include <algorithm>

// Εδώ μπένουν τα σώματα των συναρτήσεων
//QuickSort
int splitArr(Region arr[], int low, int high) {
    int pivot = arr[high].totalBirths;
    int i = low - 1;

    if (low <= high) {
        for (int j = low; j < high; j++) {
            if (arr[j].totalBirths <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
    }
    return (i + 1);
}

void quickSort(Region arr[], int low, int high) {
    if (low < high) {
        int pivoti = splitArr(arr, low, high);

        quickSort(arr, low, pivoti - 1);
        quickSort(arr, pivoti + 1, high);
    }
}

//MergeSort
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

//Counting Sort
void countingSort(Region arr[], int calculateTotalDeaths()) {
	int output[10];
  	int count[10];
  	int max = arr[0];

  // Find the largest element of the array
  	for (int i = 1; i < size; i++) {
    	if (arr[i] > max)
    		max = arr[i];
  	}

  // Initialize count array with all zeros.
  	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
  	}

  // Store the count of each element
  	for (int i = 0; i < size; i++) {
    	count[arr[i]]++;
  	}

  // Store the cummulative count of each array
  	for (int i = 1; i <= max; i++) {
    	count[i] += count[i - 1];
  	}

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  	for (int i = size - 1; i >= 0; i--) {
    	output[count[arr[i]] - 1] = arr[i];
    	count[arr[i]]--;
  	}

  // Copy the sorted elements into original array
  	for (int i = 0; i < size; i++) {
    	arr[i] = output[i];
  	}
}
