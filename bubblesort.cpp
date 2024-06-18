#include "sorting.h"

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int a[], int n){
    for (int i = 1; i < n; i++){
            for (int j = n - 1; j >= i; j--){
                if (a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
            }
        }
}

//comparison counter version

void bubbleSort(int a[], int n, int &comparison){
    for (int i = 1; ++comparison && i < n; i++){
            for (int j = n - 1; ++comparison && j >= i; j--){
                if (++comparison && a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
            }
        }
}

