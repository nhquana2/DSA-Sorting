#include "sorting.h"

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mn_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn_index]) {
                mn_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[mn_index];
        a[mn_index] = temp;
    }
}

void selectionSort(int a[], int n, long long &comparison) {
    comparison = 0;
    for (int i = 0; ++comparison && i < n - 1; i++) {
        int mn_index = i;
        for (int j = i + 1; ++comparison && j < n; j++) {
            ++comparison;
            if (++comparison && a[j] < a[mn_index]) {
                mn_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[mn_index];
        a[mn_index] = temp;
    }
}