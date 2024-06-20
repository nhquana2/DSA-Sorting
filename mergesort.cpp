#include "sorting.h"


void Merge(int a[], int l, int mid, int r) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (a[i] < a[j])
            arr[k++] = a[i++];
        else
            arr[k++] = a[j++];
    }
    while (i <= mid) {
            arr[k++] = a[i++];
    }
    while (j <= r) {
            arr[k++] = a[j++];
    }

    for (int i = 0; i < k; i++) {
        a[l++] = arr[i];
    }

    delete[] arr;
}

void MergeSort(int a[], int l, int r) {
    if (l >= r) 
        return;

    int mid = (l + r) / 2;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);

    Merge(a, l, mid, r);
}

void mergeSort(int a[], int n) {
    MergeSort(a, 0, n - 1);
}

//comparison counter version

void Merge(int a[], int l, int mid, int r, int &comparison) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (++comparison && i <= mid && ++comparison && j <= r) {
        if (++comparison && a[i] < a[j])
                arr[k++] = a[i++];
        else
                arr[k++] = a[j++];
    }
    while (++comparison && i <= mid) {
            arr[k++] = a[i++];
    }
    while (++comparison && j <= r) {
            arr[k++] = a[j++];
    }

    for (int i = 0; ++comparison && i < k; i++) {
        a[l++] = arr[i];
    }
}

void MergeSort(int a[], int l, int r, int& comparison) {
        if (++comparison && l >= r) 
            return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid, comparison);
        MergeSort(a, mid + 1, r, comparison);
        Merge(a, l, mid, r, comparison);
}

void mergeSort(int a[], int n, int &comparison) {
    MergeSort(a, 0, n - 1, comparison);
}
