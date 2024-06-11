#include "searchFunctions.h"
#include "init.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>

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

void birthsInRangeBinary(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
	// Find First Element In Range
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
        result = binarySearch(arr, 0, NUMOFREGIONS - 1, b1);
    } while (result == -1 && b1 <= b2);
 	
	// Print Results
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
}

int binaryInterpolationSearch(Region arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right && x >= arr[left].totalBirths && x <= arr[right].totalBirths) {
        if (left == right) {
            if (arr[left].totalBirths == x) return left;
            return -1;
        }
		int pos = left + (((double)(right - left) / (arr[right].totalBirths - arr[left].totalBirths)) * (x - arr[left].totalBirths));

        if (arr[pos].totalBirths == x)
            return pos;

        if (arr[pos].totalBirths < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return -1; 
}

void birthsInRangeInterpolation(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
	// Find First Element In Range
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
        result = binaryInterpolationSearch(arr, NUMOFREGIONS, b1);
    } while (result == -1 && b1 <= b2);
 	
	// Print Results
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
}

//BIS with no optimization
int BIS(Region arr[], int x) {
	int left = 0;
	int right = NUMOFREGIONS - 1;
	int size = right - left + 1;
	int next = ceil(size*(float(x - arr[left].totalBirths) / (arr[right].totalBirths - arr[left].totalBirths)));
	
	// If x <= max
	if (x <= arr[NUMOFREGIONS-1].totalBirths) while (x != arr[next].totalBirths) {
		int i = 0;
		size = right - left + 1;
		// If size <= 3 : Direct Search
		if (size <= 3) {
			for (int j = left; j <= right; j++) {
				if (x == arr[j].totalBirths) {
					//Success!
					return j;
				}
			}
			//If not returned then Fail
			return -1;
		}
		// If x > arr[next] : step by +sqrt(size)
		if (x >= arr[next].totalBirths) {
			int tempRight, tempLeft;
			int tempIndex = next + i*sqrt(size);
			while (x > arr[tempIndex].totalBirths && tempIndex < right) {
				i = i + 1;////////////////
				tempRight = tempIndex;
				tempLeft = tempIndex;
				tempIndex = next + i*sqrt(size);
			}
			
			right = next + i*sqrt(size);
			left = next + (i-1)*sqrt(size);
		} else if (x < arr[next].totalBirths) {
			// If x < arr[next] : step by -sqrt(size)
			int tempIndex = next - i*sqrt(size);
			while (x < arr[tempIndex].totalBirths && tempIndex > left) {
				i += 1;////////// i = 2 * i
				tempIndex = next - i*sqrt(size);
			}
			right = next - (i - 1)*sqrt(size);
			left = next - i*sqrt(size);
		}
		next = left + ceil((right - left + 1) * (float(x - arr[left].totalBirths) / (arr[right].totalBirths - arr[left].totalBirths)));
	}
	if (x == arr[next].totalBirths) {
		// Success!
		return next;
	} else {
		// Fail
		return -1;
	}
}

//BIS with no Optimization
void birthsInRangeBIS(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
	// Find First Element In Range
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
		result = BIS(arr, b1);
    } while (result == -1 && b1 <= b2);
 	
	// Print Results
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
}

// This Version of optBIS Is broken. Working one is at github branch: OptBIS
int optBIS(Region arr[], int x) {
	int left = 0;
	int right = NUMOFREGIONS - 1;
	int size = right - left + 1;
	int next = ceil(size*(float(x - arr[left].totalBirths) / (arr[right].totalBirths - arr[left].totalBirths)));
	
	// If x <= max
	if (x <= arr[NUMOFREGIONS-1].totalBirths) while (x != arr[next].totalBirths) {
		int i = 0;
		size = right - left + 1;
		// If size <= 3 : Direct Search
		if (size <= 3) {
			for (int j = left; j <= right; j++) {
				if (x == arr[j].totalBirths) {
					//Success!
					return j;
				}
			}
			//If not returned then Fail
			return -1;
		}
		// If x > arr[next] : step by +sqrt(size)
		if (x >= arr[next].totalBirths) {
			int tempRight, tempLeft;
			int tempIndex = next + i*sqrt(size);
			while (x > arr[tempIndex].totalBirths && tempIndex < right) {
				i = (2 * i)+1;	// May need fix;
				tempRight = tempIndex;
				tempLeft = tempIndex;
				tempIndex = next + i*sqrt(size);
			}
			
			right = next + i*sqrt(size);
			left = next + (i-1)*sqrt(size);
		} else if (x < arr[next].totalBirths) {
			// If x < arr[next] : step by -sqrt(size)
			int tempIndex = next - i*sqrt(size);
			while (x < arr[tempIndex].totalBirths && tempIndex > left) {
				i = (2 * i)+1; // May need fix;
				tempIndex = next - i*sqrt(size);
			}
			right = next - (i - 1)*sqrt(size);
			left = next - i*sqrt(size);
		}
		next = left + ceil((right - left + 1) * (float(x - arr[left].totalBirths) / (arr[right].totalBirths - arr[left].totalBirths)));
	}
	if (x == arr[next].totalBirths) {
		// Success!
		return next;
	} else {
		// Fail
		return -1;
	}
}

void birthsInRangeOptBIS(int b1, int b2, Region arr[]) {
    int result;
    b1 = b1 - 1;
	// Find First Element In Range
    do {
        b1 = b1 + 1; // Increment to avoid an if statement
		result = optBIS(arr, b1);
    } while (result == -1 && b1 <= b2);
 	
	// Print Results
	if (result >= 0 && b1 <= b2) {
		for (int i = result; i < NUMOFREGIONS && arr[i].totalBirths <= b2; i++) {
			cout << arr[i].name << ": " << arr[i].totalBirths << endl;
		}
	} else {
		cout << "No Births Found At This Range!" << endl;
	}
}
list<Node>::iterator searchTree(list<Node> &vec, string reg, list<Node>::iterator k) {
	if (reg.compare(k->region.name) == 0) {
		return k;
	} else if (reg.compare(k->region.name) > 0) {
		if (k->right != vec.end()) {
			return searchTree(vec, reg, k->right);
		} else {
			list<Node>::iterator u = vec.end();
			return vec.end();
		}
	} else {
		if (k->left != vec.end()) {
			return searchTree(vec, reg, k->left);
		} else {
			return vec.end();
		}
	}	
}
