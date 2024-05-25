#include "searchFunctions.h"
#include "init.h"
#include <algorithm>
#include <iostream>

using namespace std;

int binarySearch(Region arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid].totalBirths == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid].totalBirths < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int binaryInterpolationSearch(Region arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right && x >= arr[left].totalBirths && x <= arr[right].totalBirths) {
        if (left == right) {
            if (arr[left].totalBirths == x) return left;
            return -1;
        }

        int pos = left + ((double)(x - arr[left].totalBirths) * (right - left) / 
                        (arr[right].totalBirths - arr[left].totalBirths));

        if (arr[pos].totalBirths == x)
            return pos;

        if (arr[pos].totalBirths < x)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1; 
}

void birthsInRange(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
    cout << "USING BIN SEARCH " << endl;
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
        result = binarySearch(arr, 0, NUMOFREGIONS - 1, b1);
    } while (result == -1 && b1 <= b2);
  
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
    cout << "USING INTERPOLATION SEARCH " << endl;

// Calculate the index of the left bound (b1)
    int left = binaryInterpolationSearch(arr, NUMOFREGIONS, b1);
    if (left == -1) {
     cout << "No Births Found At This Range!" << endl;
    return;
}

// Calculate the index of the right bound (b2)
    int right = binaryInterpolationSearch(arr, NUMOFREGIONS, b2);
    if (right == -1) {
     cout << "No Births Found At This Range!" << endl;
    return;
}
    int numRegionsInRange = right - left + 1;
    cout << "Number of regions within the birth count range [" << b1 << ", " << b2 << "]: " << numRegionsInRange << endl;


}


