#include "sorting.h"

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, long long&), void (*sortFunction)(int[], int)) {
    Record record;
    record.comparison = 0;
    record.time = 0;
    int *b = new int[n];
    copyArray(a, b, n);
    sortFunctionCmp(a, n, record.comparison);
    auto start = high_resolution_clock::now();
    sortFunction(b, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    record.time = duration.count();
    delete[] b;
    return record;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mn_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn_index]) {
                mn_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[mn_index];
        a[mn_index] = temp;
    }
}

void selectionSort(int a[], int n, long long &comparison) {
    comparison = 0;
    for (int i = 0; ++comparison && i < n - 1; i++) {
        int mn_index = i;
        for (int j = i + 1; ++comparison && j < n; j++) {
            if (++comparison && a[j] < a[mn_index]) {
                mn_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[mn_index];
        a[mn_index] = temp;
    }
}

// Original function
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Function with comparison counter
void insertionSort(int a[], int n, long long &comparison) {
    comparison = 0;

    int i, j, key;
	for (i = 1; ++comparison && i < n; i++) {
		key = a[i];
		j = i - 1;

		while ((++comparison && j >= 0) && (++comparison && a[j] > key)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}


void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j+1] < a[j]) 
                swap(a[j+1], a[j]);
        }
    }
}

//comparison counter version

void bubbleSort(int a[], int n, long long &comparison) {
    for (int i = 0; ++comparison && i < n - 1; i++) {
        for (int j = 0; ++comparison && j < n - 1 - i; j++) {
            if (++comparison && a[j+1] < a[j])
                swap(a[j+1], a[j]);
        }
    }
}

void shakerSort(int a[], int n) {
	int left = 0;
	int right = n - 1;
	int k = 0;

	while (left < right) {
		bool isSwapped = false;
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				k = i;
				isSwapped = true;
			}
		}

		if (isSwapped == false) break;
		right = k;

		isSwapped = false;
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				k = i;
				isSwapped = true;
			}
		}
		if (isSwapped == false) break;
			left = k;
		}
}

void shakerSort(int a[], int n, long long& comparison) {
    comparison = 0;
	int left = 0;
    int right = n - 1;
    int k = 0;

    while (++comparison && left < right) {
        bool isSwapped = false;
        for (int i = left; ++comparison && i < right; i++) {
            if (++comparison && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
                isSwapped = true;
            }
        }

        if (++comparison && isSwapped == false) break;
        right = k;

        isSwapped = false;
        for (int i = right; ++comparison && i > left; i--) {
            if (++comparison && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
                isSwapped = true;
            }
        }

        if (++comparison && isSwapped == false) break;

        left = k;
    }
}

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int tmp = a[i];
 
            int j;            
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
            }
             
            a[j] = tmp;
        }
    }
}

void shellSort(int a[], int n, long long &comparison) {
    comparison = 0;
    for (int gap = n / 2; ++comparison && gap > 0; gap /= 2) {
        for (int i = gap; ++comparison && i < n; i++) {
            int tmp = a[i];

            int j;
            for (j = i; (++comparison && j >= gap) && (++comparison && a[j - gap] > tmp); j -= gap) {
                a[j] = a[j - gap];
            }

            a[j] = tmp;
        }
    }
}

void maxHeapify(int a[], int i, int n) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mx = i;

    if (l <= n-1 && a[l] > a[mx]) {
        mx = l;
    }

    if (r <= n-1 && a[r] > a[mx]) {
        mx = r;
    }

    if (mx != i) {
        swap(a[i], a[mx]);
        maxHeapify(a, mx, n);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = (n/2)-1; i >= 0; --i) {
        maxHeapify(a, i, n);
    }
}

void heapSort(int a[], int n) {

    buildMaxHeap(a, n);
    int sz = n;

    while (sz) {
        swap(a[0], a[sz-1]);
        --sz;
        maxHeapify(a, 0, sz);
    }
}

//Comparison version

void maxHeapify(int a[], int i, int n, long long &comparison) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mx = i;

    if (++comparison && l <= n-1 && ++comparison && a[l] > a[mx]) {
        mx = l;
    }

    if (++comparison && r <= n-1 && ++comparison && a[r] > a[mx]) {
        mx = r;
    }

    if (++comparison && mx != i) {
        swap(a[i], a[mx]);
        maxHeapify(a, mx, n, comparison);
    }
}

void buildMaxHeap(int a[], int n, long long &comparison) {
    for (int i = (n/2)-1; ++comparison && i >= 0; --i) {
        maxHeapify(a, i, n, comparison);
    }
}

void heapSort(int a[], int n, long long &comparison) {
    comparison = 0;
    buildMaxHeap(a, n, comparison);
    int sz = n;

    while (++comparison && sz) {
        swap(a[0], a[sz-1]);
        --sz;
        maxHeapify(a, 0, sz, comparison);
    }
}

void Merge(int a[], int l, int mid, int r) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (a[i] < a[j])
            arr[k++] = a[i++];
        else
            arr[k++] = a[j++];
    }
    while (i <= mid) {
            arr[k++] = a[i++];
    }
    while (j <= r) {
            arr[k++] = a[j++];
    }

    for (int i = 0; i < k; i++) {
        a[l++] = arr[i];
    }

    delete[] arr;
}

void MergeSort(int a[], int l, int r) {
    if (l >= r) 
        return;

    int mid = (l + r) / 2;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);

    Merge(a, l, mid, r);
}

void mergeSort(int a[], int n) {
    MergeSort(a, 0, n - 1);
}

//comparison counter version

void Merge(int a[], int l, int mid, int r, long long &comparison) {
    int* arr = new int[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (++comparison && i <= mid && ++comparison && j <= r) {
        if (++comparison && a[i] < a[j])
                arr[k++] = a[i++];
        else
                arr[k++] = a[j++];
    }
    while (++comparison && i <= mid) {
            arr[k++] = a[i++];
    }
    while (++comparison && j <= r) {
            arr[k++] = a[j++];
    }

    for (int i = 0; ++comparison && i < k; i++) {
        a[l++] = arr[i];
    }
}

void MergeSort(int a[], int l, int r, long long& comparison) {
        if (++comparison && l >= r) 
            return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid, comparison);
        MergeSort(a, mid + 1, r, comparison);
        Merge(a, l, mid, r, comparison);
}

void mergeSort(int a[], int n, long long &comparison) {
    MergeSort(a, 0, n - 1, comparison);
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// Original function
int partition(int a[], int l, int r) {
    int p = r;  
    r = r - 1;        

    while (l <= r) {
        // Find the first element >= pivot from the left
        while (a[l] < a[p] && l <= r) {
            l++;
        }

        // Find the first element <= pivot from the right
        while (a[r] > a[p] && l <= r) {
            r--;
        }

        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    swap(a[l], a[p]);
    return l;
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;
 
    int p = partition(a, l, r);

    QuickSort(a, l, p - 1);
    QuickSort(a, p + 1, r);
}

void quickSort(int a[], int n) {
    QuickSort(a, 0, n-1);
}


// Function with comparison counter
int partition(int a[], int l, int r, long long &comparison) {
    int p = r;  
    r = r - 1;        

    while (++comparison && l <= r) {
        // Find the first element >= pivot from the left
        while ((++comparison && a[l] < a[p]) && (++comparison && l <= r)) {
            l++;
        }

        // Find the first element <= pivot from the right
        while ((++comparison && a[r] > a[p]) && (++comparison && l <= r)) {
            r--;
        }

        if (++comparison && l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    swap(a[l], a[p]);
    return l;
}

void QuickSort(int a[], int l, int r, long long &comparison) {
    if (++comparison && l >= r) return;
 
    int p = partition(a, l, r, comparison);

    QuickSort(a, l, p - 1, comparison);
    QuickSort(a, p + 1, r, comparison);
}

void quickSort(int a[], int n, long long &comparison) {
    comparison = 0;
    QuickSort(a, 0, n - 1, comparison);
}

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

void countingSort(int a[], int n, long long& comparison) {
    comparison = 0;
    int maxx = INT_MIN;
    int minn = INT_MAX;
    for (int i = 0; ++comparison && i < n; i++) {
        maxx = max(maxx , a[i]);
        ++comparison;
        minn = min(minn, a[i]);
        ++comparison;
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

int getMax(int a[], int n)
{
    int maxx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxx)
            maxx = a[i];
    return maxx;
}
int getMax(int a[], int n, long long& comparison)
{
    int maxx = a[0];
    for (int i = 1; ++comparison && i < n; i++)
        if ( ++comparison && a[i] > maxx)
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
int getMin(int a[], int n, long long& comparison)
{
    int minn = a[0];
    for (int i = 1; ++comparison && i < n; i++)
        if ( ++comparison && a[i] < minn)
            minn = a[i];
    return minn;
}
void countingSort(int a[], int n, int exp, int minn) {
    int* o = new int[n];
    int c[10] = {0};
    
    for (int i = 0;  i < n; i++) {
        c[((a[i] - minn) / exp % 10)]++;
    }
    
    for (int i = 1;  i < 10; i++)
        c[i] += c[i - 1];
    
    for (int i = n - 1;  i >= 0; i--) {
        o[c[((a[i] - minn) / exp % 10)] - 1] = a[i];
        c[((a[i] - minn) / exp % 10)]--;
    }

    for (int i = 0;  i < n; i++)
        a[i] = o[i];
    
    delete[] o;
}
void countingSort(int a[], int n, int exp, int minn, long long& comparison) {
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
    long long temp = 0;
    for (int exp = 1; maxx / exp > 0; exp *= 10)
        countingSort(shiftedArr, n, exp, minn);
    
    for (int i = 0; i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }
    
    delete[] shiftedArr;
}
void radixSort(int a[], int n, long long& comparison) {
     comparison = 0;

    int minn = getMin(a, n, comparison);
    
    int* shiftedArr = new int[n];
    for (int i = 0; ++comparison && i < n; i++) {
        shiftedArr[i] = a[i] - minn;
    }
    
    int maxx = getMax(a, n, comparison);
    for (int exp = 1; ++comparison && maxx / exp > 0; exp *= 10)
        countingSort(shiftedArr, n, exp, minn, comparison);
    
    for (int i = 0; ++comparison && i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }
    
    delete[] shiftedArr;
}

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

void flashSort(int a[], int n, long long& comparison) {
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