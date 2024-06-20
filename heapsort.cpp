#include "sorting.h"

void maxHeapify(int a[], int i, int n) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mx = i;

    if (l <= n-1 && a[l] > a[mx]) {
        mx = l;
    }

    if (r <= n-1 && a[r] > a[mx]) {
        mx = r;
    }

    if (mx != i) {
        swap(a[i], a[mx]);
        maxHeapify(a, mx, n);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = (n/2)-1; i >= 0; --i) {
        maxHeapify(a, i, n);
    }
}

void heapSort(int a[], int n) {

    buildMaxHeap(a, n);
    int sz = n;

    while (sz) {
        swap(a[0], a[sz-1]);
        --sz;
        maxHeapify(a, 0, sz);
    }
}

//Comparison version

void maxHeapify(int a[], int i, int n, int &comparison) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mx = i;

    if (++comparison && l <= n-1 && ++comparison && a[l] > a[mx]) {
        mx = l;
    }

    if (++comparison && r <= n-1 && ++comparison && a[r] > a[mx]) {
        mx = r;
    }

    if (++comparison && mx != i) {
        swap(a[i], a[mx]);
        maxHeapify(a, mx, n, comparison);
    }
}

void buildMaxHeap(int a[], int n, int &comparison) {
    for (int i = (n/2)-1; ++comparison && i >= 0; --i) {
        maxHeapify(a, i, n, comparison);
    }
}

void heapSort(int a[], int n, int &comparison) {
    comparison = 0;
    buildMaxHeap(a, n, comparison);
    int sz = n;

    while (++comparison && sz) {
        swap(a[0], a[sz-1]);
        --sz;
        maxHeapify(a, 0, sz, comparison);
    }
}
