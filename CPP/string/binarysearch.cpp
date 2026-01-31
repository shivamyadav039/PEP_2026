#include <iostream>
using namespace std;
bool binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    if(start > end) return false;
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) 
            return true;
        else if (arr[mid] < key)
            return binarySearch(arr + mid + 1, end - mid, key);
        else
            return binarySearch(arr, mid, key);    

}