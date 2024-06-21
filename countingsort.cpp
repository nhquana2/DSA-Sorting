#include "sorting.h"
using namespace std;

void countingSort(int a[], int n) {
    int maxx = INT_MIN;
    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx , a[i]);
        minn = min(minn, a[i]);
    }
    int range = maxx - minn + 1;
    int *c = new int[range + 1];
    for (int i = 0; i < range; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i] - minn]++;
    }
    for (int i = 1; i < range; i++) {
        c[i] += c[i - 1];
    }
    int *o = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        o[c[a[i] - minn] - 1] = a[i];
        c[a[i] - minn]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = o[i];
    }
    delete[] c;
    delete[] o;
}

void countingSort(int a[], int n, int& comparison) {
    comparison = 0;
    int maxx = INT_MIN;
    int minn = INT_MAX;
    for (int i = 0; ++comparison && i < n; i++) {
        maxx = max(maxx , a[i]);
        minn = min(minn, a[i]);
    }
    int range = maxx - minn + 1;
    int *c = new int[range + 1];
    for (int i = 0; ++comparison && i < range; i++) {
        c[i] = 0;
    }
    for (int i = 0; ++comparison && i < n; i++) {
        c[a[i] - minn]++;
    }
    for (int i = 1; ++comparison && i < range; i++) {
        c[i] += c[i - 1];
    }
    int *o = new int[n];
    for (int i = n - 1; ++comparison && i >= 0; i--) {
        o[c[a[i] - minn] - 1] = a[i];
        c[a[i] - minn]--;
    }
    for (int i = 0; ++comparison && i < n; i++) {
        a[i] = o[i];
    }
    delete[] c;
    delete[] o;
}