// Sorting Functions Definitions, Bodies

#include "sortingFunctions.h"

// Εδώ μπένουν τα σώματα των συναρτήσεων
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