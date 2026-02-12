// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i = n-1; i >= 0; i--){
        //remove all elements smaller than or equal to current;
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();   // FIXED
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
    vector<int> res = nextGreaterElement(arr);

    for(int x : res){
        cout << x << " ";
    }

    return 0;
}



https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1



class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
         for(int i=n-1;i>=0;i--){
             while(!st.empty() && st.top()<=arr[i]){
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
};


https://leetcode.com/problems/next-greater-element-i/



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(mp[nums1[i]]);
        }
        return result;
        
    }
};