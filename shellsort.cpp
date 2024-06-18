#include "sorting.h"

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
 
            int j;            
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
             
            a[j] = temp;
        }
    }
}

void shellSort(int a[], int n, int &comparision) {
    comparision = 0;
    for (int gap = n / 2; ++comparision && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparision && i < n; i++)
        {
            int tmp = a[i];

            int j;
            for (j = i; (++comparision && j >= gap) && (++comparision && a[j - gap] > tmp); j -= gap)
                a[j] = a[j - gap];

            a[j] = tmp;
        }
    }
}