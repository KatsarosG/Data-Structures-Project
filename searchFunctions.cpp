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

void birthsinRegion(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
        result = binarySearch(arr, 0, NUMOFREGIONS - 1, b1);
    } while (result == -1 && b1 <= b2);
	

	cout << result << " : " << b1 << " | " << b2 << endl;
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
}
