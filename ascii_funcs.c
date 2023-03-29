#include "ascii_funcs.h"

int is_printable(const char array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (array[i] > 126 || array[i] < 33) {
            return 0;
        }
    }
    return 1;
}