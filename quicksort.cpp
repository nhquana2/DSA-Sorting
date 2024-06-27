#include "sorting.h"

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// Original function
int partition(int a[], int l, int r) {
    int p = r;  
    r = r - 1;        

    while (l <= r) {
        // Find the first element >= pivot from the left
        while (a[l] < a[p] && l <= r) {
            l++;
        }

        // Find the first element <= pivot from the right
        while (a[r] > a[p] && l <= r) {
            r--;
        }

        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    swap(a[l], a[p]);
    return l;
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;
 
    int p = partition(a, l, r);

    QuickSort(a, l, p - 1);
    QuickSort(a, p + 1, r);
}

void quickSort(int a[], int n) {
    QuickSort(a, 0, n-1);
}


// Function with comparison counter
int partition(int a[], int l, int r, long long &comparison) {
    int p = r;  
    r = r - 1;        

    while (++comparison && l <= r) {
        // Find the first element >= pivot from the left
        while ((++comparison && a[l] < a[p]) && (++comparison && l <= r)) {
            l++;
        }

        // Find the first element <= pivot from the right
        while ((++comparison && a[r] > a[p]) && (++comparison && l <= r)) {
            r--;
        }

        if (++comparison && l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    swap(a[l], a[p]);
    return l;
}

void QuickSort(int a[], int l, int r, long long &comparison) {
    if (++comparison && l >= r) return;
 
    int p = partition(a, l, r, comparison);

    QuickSort(a, l, p - 1, comparison);
    QuickSort(a, p + 1, r, comparison);
}

void quickSort(int a[], int n, long long &comparison) {
    comparison = 0;
    QuickSort(a, 0, n - 1, comparison);
}

