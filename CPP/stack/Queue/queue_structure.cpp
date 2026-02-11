#include<iostream>
using namespace std;

class Queue{
public:
    int *arr;
    int f;
    int r;
    int size;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        f = -1;
        r = -1;
    }

    void enqueue(int val){
        if(r == size-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(f == -1) f = 0;
        r++;
        arr[r] = val;
    }

    void dequeue(){
        if(f == -1 || f > r){
            cout<<"Queue underflow"<<endl;
            return;
        }
        f++;
    }

    int peek(){
        if(f == -1 || f > r){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool isEmpty(){
        return (f == -1 || f > r);
    }
};

int main(){
    Queue st(5);

    st.enqueue(10);
    st.enqueue(20);
    st.enqueue(30);

    cout<<st.peek()<<endl;

    st.dequeue();
    cout<<st.peek()<<endl;

    st.dequeue();
    st.dequeue();
    st.dequeue();

    return 0;
}
