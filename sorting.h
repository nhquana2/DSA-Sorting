#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Record {
    int comparison;
    long long time; // in nanoseconds
};

//function which returns Record struct of each sorting algorithm, passing the sorting function as a pointer
Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, int&), void (*sortFunction)(int[], int));

// Prototype for original functions
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void shakerSort(int a[], int n);
void shellSort(int a[], int n);
void heapSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);
void countingSort(int a[], int n);
void radixSort(int a[], int n);
void flashSort(int a[], int n);

// Prototype for functions with comparison counter
void selectionSort(int a[], int n, int &comparison);
void insertionSort(int a[], int n, int &comparison);
void bubbleSort(int a[], int n, int &comparison);
void shakerSort(int a[], int n, int &comparison);
void shellSort(int a[], int n, int &comparison);
void heapSort(int a[], int n, int &comparison);
void mergeSort(int a[], int n, int &comparison);
void quickSort(int a[], int n, int &comparison);
void countingSort(int a[], int n, int &comparison);
void radixSort(int a[], int n, int &comparison);
void flashSort(int a[], int n, int &comparison);

