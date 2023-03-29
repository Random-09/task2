#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int is_printable(const char array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (array[i] > 126 || array[i] < 33) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    if (argc == 4) {
        int array_size = strtol(argv[1], NULL, 10);
        char array[array_size];
        char character = *argv[3];
        strcpy(array, argv[2]);
        if (is_printable(array, array_size)) {
            quick_sort(array, 0, array_size - 1);
            int index = binary_search(array, 0, array_size - 1, character);
            if (index != -1)
                printf("Index of character %c in sorted array is: %d", character, index);
            else
                printf("Character not found");
        } else
            printf("Please choose printable ASCII symbols");
    } else
        printf("Wrong number of arguments");
}