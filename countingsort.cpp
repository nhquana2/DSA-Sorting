#include "sorting.h"
using namespace std;

void countingSort(int a[], int n) {
    int maxx = -1;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx , a[i]);
    }
    int *c = new int[maxx + 1];
    for (int i = 0; i < maxx; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
    for (int i = 1; i < maxx + 1; i++) {
        c[i] += c[i - 1];
    }
    int *o = new int[n];
    for (int i = n - 1; i >= 0; i--) {
		o[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	for (int i = 0; i < n; i++) {
		a[i] = o[i];
	}
    delete[] c;
}

void countingSort(int a[], int n, int& comparison) {
    comparison = 0;
    int maxx = -1;
    for (int i = 0; ++comparison && i < n; i++) {
        maxx = max(maxx , a[i]);
    }
    int *c = new int[maxx + 1];
    for (int i = 0; ++comparison && i < maxx; i++) {
        c[i] = 0;
    }
    for (int i = 0; ++comparison && i < n; i++) {
        c[a[i]]++;
    }
    for (int i = 1; ++comparison && i < maxx + 1; i++) {
        c[i] += c[i - 1];
    }
    int *o = new int[n];
    for (int i = n - 1; ++comparison && i >= 0; i--) {
		o[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	for (int i = 0; ++comparison && i < n; i++) {
		a[i] = o[i];
	}
    delete[] c;
}