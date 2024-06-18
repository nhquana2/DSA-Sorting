#include "sorting.h"

using namespace std;

void printArr(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(int argc, char *argv[]) {
    //testing only
    cout << "hello world\n";
    int a[] = {5, 4, 999, 3, 2, 1, 100, 1000};

    Record record = getRecord(a, 8, bubbleSort, bubbleSort);
    cout << "Bubble Sort\n";
    cout << "Comparisons: " << record.comparison << endl;
    cout << "Time: " << record.time << " nanoseconds" << endl;
    printArr(a, 8);

    return 0;
}