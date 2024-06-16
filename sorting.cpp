#include "sorting.h"

Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, int&), void (*sortFunction)(int[], int)) {
    Record record;
    record.comparision = 0;
    record.time = 0;
    sortFunctionCmp(a, n, record.comparision);
    clock_t start, end;
    start = clock();
    sortFunction(a, n);
    end = clock();
    record.time = (end - start) * 1000 / CLOCKS_PER_SEC;
    return record;
}