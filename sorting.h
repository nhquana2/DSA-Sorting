#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Record {
    int comparision;
    int time; // in milliseconds
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

// Prototype for functions with comparision counter
void selectionSort(int a[], int n, int &comparision);
void insertionSort(int a[], int n, int &comparision);
void bubbleSort(int a[], int n, int &comparision);
void shakerSort(int a[], int n, int &comparision);
void shellSort(int a[], int n, int &comparision);
void heapSort(int a[], int n, int &comparision);
void mergeSort(int a[], int n, int &comparision);
void quickSort(int a[], int n, int &comparision);
void countingSort(int a[], int n, int &comparision);
void radixSort(int a[], int n, int &comparision);
void flashSort(int a[], int n, int &comparision);

