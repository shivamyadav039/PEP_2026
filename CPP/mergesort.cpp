#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotindex = start + count;
    swap(arr[pivotindex], arr[start]);

    int i = start, j = end;

    while (i < pivotindex && j > pivotindex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotindex && j > pivotindex)
            swap(arr[i], arr[j]);
    }

    return pivotindex;
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) return;

    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}

int main() {
    int arr[] = {2, 5, 6, 9, 10, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for (int i : arr)
        cout << i << " ";
}
 