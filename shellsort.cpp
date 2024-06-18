#include "sorting.h"

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int tmp = a[i];
 
            int j;            
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
            }
             
            a[j] = tmp;
        }
    }
}

void shellSort(int a[], int n, int &comparison) {
    comparison = 0;
    for (int gap = n / 2; ++comparison && gap > 0; gap /= 2) {
        for (int i = gap; ++comparison && i < n; i++) {
            int tmp = a[i];

            int j;
            for (j = i; (++comparison && j >= gap) && (++comparison && a[j - gap] > tmp); j -= gap) {
                a[j] = a[j - gap];
            }

            a[j] = tmp;
        }
    }
}