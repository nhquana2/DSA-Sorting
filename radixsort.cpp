#include "sorting.h"
using namespace std;
int getMax(int a[], int n)
{
    int maxx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxx)
            maxx = a[i];
    return maxx;
}
int getMin(int a[], int n)
{
    int minn = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < minn)
            minn = a[i];
    return minn;
}
void countingSort(int a[], int n, int exp, int minn, int& comparison) {
    int* o = new int[n];
    int c[10] = {0};
    
    for (int i = 0; ++comparison && i < n; i++) {
        c[((a[i] - minn) / exp % 10)]++;
    }
    
    for (int i = 1; ++comparison && i < 10; i++)
        c[i] += c[i - 1];
    
    for (int i = n - 1; ++comparison && i >= 0; i--) {
        o[c[((a[i] - minn) / exp % 10)] - 1] = a[i];
        c[((a[i] - minn) / exp % 10)]--;
    }

    for (int i = 0; ++comparison && i < n; i++)
        a[i] = o[i];
    
    delete[] o;
}
void radixSort(int a[], int n) {
    int minn = getMin(a, n);
    
    int* shiftedArr = new int[n];
    for (int i = 0; i < n; i++) {
        shiftedArr[i] = a[i] - minn;
    }
    
    int maxx = getMax(a, n);
    int temp = 0;
    for (int exp = 1; maxx / exp > 0; exp *= 10)
        countingSort(shiftedArr, n, exp, minn, temp);
    
    for (int i = 0; i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }
    
    delete[] shiftedArr;
}
void radixSort(int a[], int n, int& comparison) {
    int minn = getMin(a, n);
    
    int* shiftedArr = new int[n];
    for (int i = 0; i < n; i++) {
        shiftedArr[i] = a[i] - minn;
    }
    
    int maxx = getMax(a, n);
    comparison = 0;
    for (int exp = 1; ++comparison && maxx / exp > 0; exp *= 10)
        countingSort(shiftedArr, n, exp, minn, comparison);
    
    for (int i = 0; i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }
    
    delete[] shiftedArr;
}
