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
void heapify(Region regionArray[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && regionArray[left].totalDeaths > regionArray[largest].totalDeaths)
        largest = left;

    // If right child is larger than largest so far
    if (right < n && regionArray[right].totalDeaths > regionArray[largest].totalDeaths)
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(regionArray[i], regionArray[largest]);

        // Recursively heapify the affected sub-tree
        heapify(regionArray, n, largest);
    }
}

void heapSort(Region regionArray[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(regionArray, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(regionArray[0], regionArray[i]);

        // call max heapify on the reduced heap
        heapify(regionArray, i, 0);
    }
}

int findMaxDeaths(Region regionArray[]) {
	int max = regionArray[0].totalDeaths;
	for (int i = 0; i < NUMOFREGIONS; i++) {
		if (regionArray[i].totalDeaths > max)
			max = regionArray[i].totalDeaths;
	}
	return max;
}

void countingSort(Region arrayIn[], Region arrayOut[]) {
	int k = findMaxDeaths(arrayIn);
	int C[k];
	Region B[NUMOFREGIONS];
	// Initialize array C = [0, 0, ..., 0]
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}
	
	// C[[A[i]]] <- Εμφανίσεις της A[i]
	for (int j = 0; j < NUMOFREGIONS; j++) {
		C[arrayIn[j].totalDeaths] = C[arrayIn[j].totalDeaths]+1;
	}
	// C <- A[j], A[j] <= i
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i-1];
	}
	for (int i = NUMOFREGIONS-1; i >= 0; i--) {
			arrayOut[C[arrayIn[i].totalDeaths]-1] = arrayIn[i];
			C[arrayIn[i].totalDeaths] = arrayIn[i].totalDeaths;
	}
}
