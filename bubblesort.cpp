#include "sorting.h"

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j+1] < a[j]) 
                swap(a[j+1], a[j]);
        }
    }
}

//comparison counter version

void bubbleSort(int a[], int n, int &comparison) {
    for (int i = 1; ++comparison && i < n; i++) {
        for (int j = n - 1; ++comparison && j >= i; j--) {
            if (++comparison && a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}

