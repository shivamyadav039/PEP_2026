#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[5] = {2,5,3,2,8};
    linearSearch(arr, 5, 8);
    return 0;
