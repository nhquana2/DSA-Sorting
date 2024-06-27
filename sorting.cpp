#include "sorting.h"

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, long long&), void (*sortFunction)(int[], int)) {
    Record record;
    record.comparison = 0;
    record.time = 0;
    int *b = new int[n];
    copyArray(a, b, n);
    sortFunctionCmp(a, n, record.comparison);
    auto start = high_resolution_clock::now();
    sortFunction(b, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    record.time = duration.count();
    delete[] b;
    return record;
}