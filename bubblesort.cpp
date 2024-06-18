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

//comparision counter version

void bubbleSort(int a[], int n, int &comparision){
    for (int i = 1; ++comparision && i < n; i++){
            for (int j = n - 1; ++comparision && j >= i; j--){
                if (++comparision && a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
            }
        }
}

