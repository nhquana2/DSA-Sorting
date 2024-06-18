#include "sorting.h"

const int mxN = 1E6;
int bucket[mxN];

int getK(int a, int m, int max, int min){
    return 1ll * (m - 1) * (a - min) / (max - min);
}

void flashSort(int a[], int n){
    if (n <= 1) 
        return;
    //step 1
    int m = n * 0.45;
    if (m <= 2)
        m = 2;

    for (int i = 0; i < m; ++i){
        bucket[i] = 0;
    }

    int max = a[0], min = a[0];

    for (int i = 1; i < n; ++i){
        if (max < a[i]) max = a[i];
        if (min > a[i]) min = a[i];
    }

    if (max == min)
        return;

    for (int i = 0; i < n; ++i){
        ++bucket[getK(a[i], m, max, min)];
    }
    for (int i = 1; i < m; ++i){
        bucket[i] += bucket[i - 1];
    }
    //step 2
    int count = 0;
    int i = 0;

    while (count < n){
        int k = getK(a[i], m, max, min);

        while (i >= bucket[k]){
            k = getK(a[++i], m, max, min);
        }

        int z = a[i];

        while (i != bucket[k]){
            k = getK(z, m, max, min);
            int y = a[bucket[k] - 1];
            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }
    //step 3
    for (int k = 1; k < m; ++k){
        for (int i = bucket[k] - 2; i >= bucket[k - 1]; --i){
            if (a[i] > a[i + 1]){
                int t = a[i], j = i;
                while (t > a[j + 1]){
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }
}

//comparision counter version

void flashSort(int a[], int n, int& comparision){
    if (++comparision && n <= 1)
        return;
    //step 1
    int m = n * 0.45;
    if (++comparision && m <= 2)
        m = 2;

    for (int i = 0; ++comparision && i < m; ++i)
        bucket[i] = 0;

    int max = a[0], min = a[0];

    for (int i = 1; ++comparision && i < n; ++i){
        if (++comparision && max < a[i]) max = a[i];
        else if (++comparision && min > a[i]) min = a[i];
    }

    if (++comparision && max == min)
        return;

    for (int i = 0; ++comparision && i < n; ++i)
        ++bucket[getK(a[i], m, max, min)];
    for (int i = 1; ++comparision && i < m; ++i)
        bucket[i] += bucket[i - 1];

    //step 2
    int count = 0;
    int i = 0;

    while (++comparision && count < n){
        int k = getK(a[i], m, max, min);

        while (++comparision && i >= bucket[k])
            k = getK(a[++i], m, max, min);

        int z = a[i];

        while (++comparision && i != bucket[k]){
            k = getK(z, m, max, min);

            int y = a[bucket[k] - 1];

            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }
    //step 3
    for (int k = 1; ++comparision && k < m; ++k){
        for (int i = bucket[k] - 2; ++comparision && i >= bucket[k - 1]; --i){
            if (++comparision && a[i] > a[i + 1]){
                int t = a[i], j = i;
                while (++comparision && t > a[j + 1]){
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }
}