#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val){
        Node* node = new Node(val);

        if(rear == NULL){
            front = rear = node;
            return;
        }

        rear->next = node;
        rear = node;
    }

    void dequeue(){
        if(front == NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if(front == NULL){
            rear = NULL;
        }

        delete temp;
    }

    int peek(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<q.peek()<<endl;

    q.dequeue();
    cout<<q.peek()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
