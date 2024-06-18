#include "sorting.h"
using namespace std;
// cannot sort negative elements
int getMax(int a[], int n)
{
    int maxx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxx)
            maxx = a[i];
    return maxx;
}

void countingSort_Modified(int a[], int n, int exp, int& comparison)
{

    int o[1000];
    int i, c[10] = { 0 };


    for (i = 0; ++comparison && i < n; i++)
        c[(a[i] / exp) % 10]++;

    for (i = 1; ++comparison && i < 10; i++)
        c[i] += c[i - 1];

    for (i = n - 1; ++comparison && i >= 0; i--) {
        o[c[(a[i] / exp) % 10] - 1] = a[i];
        c[(a[i] / exp) % 10]--;
    }

    for (i = 0; ++comparison && i < n; i++)
        a[i] = o[i];
}

void radixSort(int a[], int n)
{
    int temp = 0;
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort_Modified(a, n, exp, temp);
}
void radixSort(int a[], int n, int& comparison)
{
    int m = getMax(a, n);
    for (int exp = 1; ++comparison && m / exp > 0; exp *= 10)
        countingSort_Modified(a, n, exp, comparison);
}
