#include "sorting.h"

// Original function
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Function with comparision counter
void insertionSort(int a[], int n, int &comparision) {
    comparision = 0;

    int i, j, key;
	for (i = 1; ++comparision && i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while ((++comparision && j >= 0) && (++comparision && a[j] > key))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

