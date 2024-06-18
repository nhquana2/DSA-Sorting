#include "sorting.h"

using namespace std;

void printArr(int a[], int n){
    for (int i =0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(int argc, char *argv[]) {
    //testing only
    cout << "hello world\n";
    int a[] = {5, 4, 999, 3, 2, 1, 100, 1000};

    // int n = sizeof(a)/sizeof(a[0]); 

    // int cnt = 0;

    // Record rs = getRecord(a, n, flashSort, flashSort);

    // printArr(a, 8);
    // cout << endl << "flash sort doneee with running time " << rs.time << " and " << rs.comparison << " comparisons";

    return 0;
}