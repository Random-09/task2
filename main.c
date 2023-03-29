#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quick_sort.h"
#include "binary_search.h"
#include "ascii_funcs.h"

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