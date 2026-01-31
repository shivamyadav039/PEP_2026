// #include <iostream>
// using namespace std;
// void fun(int n){
//     if(n<0) return;
//     fun(n-1);
//     if(n%2==0)
//         cout<<n<<" ";
// }
// int main(){
//     int n;
//     cin>>n;
//     fun(n);
// }

#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
}


#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n);
}



// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool sorted(int arr[], int size) {
    if (size == 0 || size == 1) return true;
    if (arr[0] > arr[1]) return false;
    return sorted(arr + 1, size - 1);
}

int sumArr(int arr[], int size, int sum, int i) {
    if (i == size) return sum;
    return sumArr(arr, size, sum + arr[i], i + 1);
}
bool search(int arr[],int size,int k){
    if(size==0) return false;
    if(arr[0]==k) return true;
    return search(arr+1,size-1,k);
}

int main() {
    int arr[] = {4, 5, 6, 8, 9, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sorted(arr, n) << endl;
    cout << sumArr(arr, n, 0, 0) << endl;
    cout<<search(arr,n,4);
}


