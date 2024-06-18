#include "sorting.h"


void Merge(int a[], int l, int mid, int r) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r){
        if (a[i] < a[j])
            arr[k++] = a[i++];
        else
            arr[k++] = a[j++];
        }
    while (i <= mid){
            arr[k++] = a[i++];
    }
    while (j <= r){
            arr[k++] = a[j++];
    }

    for (int i = 0; i < k; i++){
        a[l++] = arr[i];
    }

    delete[] arr;
}

void MergeSort(int a[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    Merge(a, l, mid, r);
}

void mergeSort(int a[], int n) {
    MergeSort(a, 0, n - 1);
}

//comparision counter version

void Merge(int a[], int l, int mid, int r, int &comparision) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (++comparision && i <= mid && ++comparision && j <= r){
        if (++comparision && a[i] < a[j])
                arr[k++] = a[i++];
        else
                arr[k++] = a[j++];
        }
    while (++comparision && i <= mid){
            arr[k++] = a[i++];
    }
    while (++comparision && j <= r){
            arr[k++] = a[j++];
    }

    for (int i = 0; ++comparision && i < k; i++){
        a[l++] = arr[i];
    }
}

void MergeSort(int a[], int l, int r, int& comparision) {
        if (++comparision && l >= r) return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid, comparision);
        MergeSort(a, mid + 1, r, comparision);
        Merge(a, l, mid, r, comparision);
}

void mergeSort(int a[], int n, int &comparision){
    MergeSort(a, 0, n - 1, comparision);
}
