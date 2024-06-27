#include "sorting.h"

Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, long long&), void (*sortFunction)(int[], int)) {
    Record record;
    record.comparison = 0;
    record.time = 0;
    sortFunctionCmp(a, n, record.comparison);
    auto start = high_resolution_clock::now();
    sortFunction(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    record.time = duration.count();
    return record;
}