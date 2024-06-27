#include "sorting.h"

using namespace std;

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    int n = 1000;
    int *a = new int[n];

    GenerateData(a, n, 1);
    Record record = getRecord(a, n, bubbleSort, bubbleSort);
    cout << "Bubble Sort (sorted)\n";
    cout << "Comparisons: " << record.comparison << endl;
    cout << "Time: " << record.time << " milli" << endl;

    GenerateData(a, n, 2);
    record = getRecord(a, n, bubbleSort, bubbleSort);
    cout << "Bubble Sort (reverse)\n";
    cout << "Comparisons: " << record.comparison << endl;
    cout << "Time: " << record.time << " milli" << endl;

    //printArr(a, n);

    return 0;
}