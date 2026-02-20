// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i = 0; i <n; i++){
        //remove all elements smaller than or equal to current;
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();   
        }

        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }
    return nge;
}

int main() {
    vector<int> arr = {4,5,2,10,8};
    vector<int> res = previousSmallerElement(arr);

    for(int x : res){
        cout << x << " ";
    }

    return 0;
}
