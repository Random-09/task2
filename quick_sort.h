#ifndef TASK2_QUICK_SORT_H
#define TASK2_QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *first_char, char *second_char);

int partition(char array[], int low, int high);

void quick_sort(char array[], int low, int high);

#endif
