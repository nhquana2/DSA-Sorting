#include "sorting.h"

Record getRecord(int a[], int n, void (*sortFunction)(int[], int, int&)) {
    Record record;
    record.comparision = 0;
    record.time = 0;
    clock_t start, end;
    start = clock();
    sortFunction(a, n, record.comparision);
    end = clock();
    record.time = (end - start) * 1000 / CLOCKS_PER_SEC;
    return record;
}