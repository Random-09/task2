#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char *first, char *second) {
    char temporary = *first;
    *first = *second;
    *second = temporary;
}

int partition(char array[], int low, int high) {
    char pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(char array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}


int main(int argc, char *argv[]) {
    if (argc == 4) {
        int array_size = strtol(argv[1], NULL, 10);
        char array[array_size];
        char character[1];                                                  // <-- Try to fix
        strcpy(array, argv[2]);
        strcpy(character, argv[3]);

    } else
        printf("Wrong number of arguments!");
}
