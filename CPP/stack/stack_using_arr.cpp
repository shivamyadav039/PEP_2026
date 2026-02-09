#include <iostream>
using namespace std;
class Mystack{
    public:
    int *arr;
    int top;
    int size;
    Mystack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int val){
        if(top == size-1){
            cout<<"Stack overflow";
            return;
        }
        top++;
        arr[top]=val;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow";
            return;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1){
            return true ;
        }
        return false;
    }
    
};
int main(){
    Mystack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek();