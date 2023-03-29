#include "quick_sort.h"

void swap(char *first_char, char *second_char) {
    char temporary = *first_char;
    *first_char = *second_char;
    *second_char = temporary;
}

int partition(char array[], int low, int high) {
    char pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(char array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
    }
}