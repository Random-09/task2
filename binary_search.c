#include "binary_search.h"


int binary_search(char array[], int low, int high, char index) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == index)
            return mid;
        else if (array[mid] > index)
            return binary_search(array, low, mid - 1, index);
        else
            return binary_search(array, mid + 1, high, index);
    }
    return -1;
}