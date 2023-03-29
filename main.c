#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binarySearch(char arr[], int low, int high, char key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }
        else {
            return binarySearch(arr, mid + 1, high, key);
        }
    }
    return -1;
}

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

void quickSort(char array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quickSort(array, low, pivot_index - 1);
        quickSort(array, pivot_index + 1, high);
    }
}

int main(int argc, char **argv) {
    if (argc == 4) {
        int array_size = strtol(argv[1], NULL, 10);
        char array[array_size];
        char character[2];
        strcpy(array, argv[2]);
        strcpy(character, argv[3]);
        quickSort(array, 0, array_size - 1);
        int num = binarySearch(array, 0, array_size - 1, 'z');
        printf("%d", num);
    } else
        printf("wrong number of arguments");
}