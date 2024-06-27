#include "sorting.h"


void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j+1] < a[j]) 
                swap(a[j+1], a[j]);
        }
    }
}

//comparison counter version

void bubbleSort(int a[], int n, long long &comparison) {
    for (int i = 0; ++comparison && i < n - 1; i++) {
        for (int j = 0; ++comparison && j < n - 1 - i; j++) {
            if (++comparison && a[j+1] < a[j])
                swap(a[j+1], a[j]);
        }
    }
}

