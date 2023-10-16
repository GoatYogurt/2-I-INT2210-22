#include <iostream>
using namespace std;

//Selection Sort
void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int iMin = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[iMin]) {
                iMin = j;
            }
        }
        if (iMin != i) {
            swap(a[iMin], a[i]);
        }
    }
}

//Insertion Sort
void insertionSort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
            while(j > 0 && a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                j--;
            }
    }
}

//Bubble Sort
void bubbleSort(int a[], int size) {
    int i, j, flag;
    for (i = 0; i < size - 1; i++) {
        flag = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
//Merge Sort*

//Quick Sort
int partition(int a[], int left, int right, int pivot) {
    int i = left, j = left;
    while (j < right) {
        while (a[i] < pivot) i++;
        j = i;
        while (a[j] > pivot) j++;
        int doiCho = a[i];
        a[i] = a[j];
        a[j] = doiCho;
    }
    return i;
}

void quickSort(int a[], int left, int right) {
    int pivot = a[right];
    if (left < right) {
        int vachNgan = partition(a, left, right, pivot);
        quickSort(a, left, vachNgan - 1);
        quickSort(a, vachNgan + 1, right);
    }
}

