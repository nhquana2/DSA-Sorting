#include "sorting.h"

int getK(int a, int m, int max, int min) {
    return 1ll * (m - 1) * (a - min) / (max - min);
}

void flashSort(int a[], int n) {
    if (n <= 1) 
        return;

    // Step 1
    int m = n * 0.45;
    if (m <= 2)
        m = 2;

    int* bucket = new int[m];
    for (int i = 0; i < m; ++i) {
        bucket[i] = 0;
    }

    int max = a[0], min = a[0];
    for (int i = 1; i < n; ++i) {
        if (max < a[i]) max = a[i];
        if (min > a[i]) min = a[i];
    }

    if (max == min) {
        delete[] bucket;
        return;
    }

    for (int i = 0; i < n; ++i) {
        ++bucket[getK(a[i], m, max, min)];
    }
    for (int i = 1; i < m; ++i) {
        bucket[i] += bucket[i - 1];
    }

    // Step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i], m, max, min);
        while (i >= bucket[k]) {
            k = getK(a[++i], m, max, min);
        }
        int z = a[i];
        while (i != bucket[k]) {
            k = getK(z, m, max, min);
            int y = a[bucket[k] - 1];
            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }

    // Step 3
    for (int k = 1; k < m; ++k) {
        for (int i = bucket[k] - 2; i >= bucket[k - 1]; --i) {
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] bucket;
}

// Comparison counter version

void flashSort(int a[], int n, int& comparison) {
    if (++comparison && n <= 1)
        return;

    // Step 1
    int m = n * 0.45;
    if (++comparison && m <= 2)
        m = 2;

    int* bucket = new int[m];
    for (int i = 0; ++comparison && i < m; ++i)
        bucket[i] = 0;

   int max = a[0], min = a[0];
    for (int i = 1; ++comparison && i < n; ++i) {
        if (++comparison && max < a[i]) max = a[i];
        else if (++comparison && min > a[i]) min = a[i];
    }

    if (++comparison && max == min) {
        delete[] bucket;
        return;
    }

    for (int i = 0; ++comparison && i < n; ++i)
        ++bucket[getK(a[i], m, max, min)];
    for (int i = 1; ++comparison && i < m; ++i)
        bucket[i] += bucket[i - 1];

    // Step 2
    int count = 0;
    int i = 0;
    while (++comparison && count < n) {
        int k = getK(a[i], m, max, min);
        while (++comparison && i >= bucket[k])
            k = getK(a[++i], m, max, min);
        
        int z = a[i];
        while (++comparison && i != bucket[k]) {
            k = getK(z, m, max, min);
            int y = a[bucket[k] - 1];
            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }

    // Step 3
    for (int k = 1; ++comparison && k < m; ++k) {
        for (int i = bucket[k] - 2; ++comparison && i >= bucket[k - 1]; --i) {
            if (++comparison && a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (++comparison && t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] bucket;
}
