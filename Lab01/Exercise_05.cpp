#include <cstdlib>

double *maxValue(double *arr, int size) {
    double *max = arr;
    if (arr == NULL || size == 0) {
        return NULL;
    }

    for (int i = 0; i < size; ++i) 
        *max = *(arr + i) > *max ? *(arr + i) : *max;

    return max;
}